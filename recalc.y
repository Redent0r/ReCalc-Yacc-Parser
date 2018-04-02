/*
  Saul Paredes
  sbp14c
 */

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEM_ADRESS 2000
#define MAX_STRING_LENGTH 2000
#define MEM_ADRESS_NOT_FOUND -1
#define TYPE_INT 0
#define TYPE_STRING 1

  int yyline=1;
  int yycolumn=1;

  int declaration_type=0;

  struct {
    char name[100];
    int type; // 0 for int, 1 for string
    int initialized; // boolean behaviour
    int declared; // boolean behaviour
    union {
      char s[2000];
      int i;
    }value;
  }memory[MAX_MEM_ADRESS];

  int getMemAdress(const char * s)
  {
    int i = 0;
    while (i < MAX_MEM_ADRESS)
      {
	if(strcmp(s, memory[i].name) == 0) // if names are equal 
	  return i;
	++i;
	}
    return MEM_ADRESS_NOT_FOUND;
  }
  
  void initialize_var(const char * s, int type) 
  {
    int i = 0;
    while (i < MAX_MEM_ADRESS)
      {
	if(strcmp(s, memory[i].name) == 0) 
	  {
	    printf("Duplicate declaration on line %d.\n", yyline);
	    exit(1);
	  }
        if(memory[i].declared == 0) // found empty space                                                 
          {
	    memory[i].type = type;
	    strcpy(memory[i].name, s);
	    memory[i].declared = 1;
	    //printf("initialize_var: %s initialized\n", memory[i].name);
	    return;
	  }
        ++i;
      }
  }
  %}

%start program

%left PLUSnumber MINUSnumber
%left TIMESnumber DIVnumber

%token PRINTnumber PROGRAMnumber ISnumber BEGINnumber ENDnumber VARINTnumber VARSTRnumber DOTnumber SEMInumber LPARENnumber COMMAnumber RPARENnumber EQnumber STRINGnumber 

%union {
  int sv;
  char * s;
  struct {
    int type;
    union {
      int sv;
      char * s;
    }val;
  }bi;
};
  
%token <sv> ICONSTnumber 
%token <s> IDnumber STRINGnumber

%type <bi> f t expr
%% // rules

// main
program : 
PROGRAMnumber IDnumber ISnumber BEGINnumber body ENDnumber
{/*printf("%s was parsed succesfully\n", $2);*/}
;

body :
| body statement SEMInumber
;

statement : 
print_statement
| variable_declaration
| assignment
;

// assignment
assignment : 
IDnumber EQnumber expr 
{
  int memAdress = getMemAdress($1); 
  if(memAdress != MEM_ADRESS_NOT_FOUND)
    {
      if($3.type == TYPE_INT)
	{
	  memory[memAdress].value.i = $3.val.sv;
	  memory[memAdress].initialized = 1;
	  //printf("assignment: %s = %d\n", $1, memory[memAdress].value.i);
	}
      else
	{
	  //printf("cant assign an expression to a string", $1, memory[memAdress].value.s);
	  printf("Type error on line %d.\n", yyline);
	  exit(1);
	}
    }
  else
    {
      printf("%s has not been declared\n");
      exit(1);
    }
}

| IDnumber EQnumber STRINGnumber
{
  int memAdress = getMemAdress($1);
  if (memAdress != MEM_ADRESS_NOT_FOUND)
    {
      if(memory[memAdress].type == TYPE_STRING)
	{
	  strcpy(memory[memAdress].value.s, $3);
	  memory[memAdress].initialized = 1;
	  //printf("assignment: %s = %s\n", $1, memory[memAdress].value.s);
	}
      else 
	{
	  printf("Type error on line %d.\n", yyline);
	  exit(1);
	}
    }
  else 
    {
      printf("Referencing an undeclared variable on line %d. \n", yyline);
      exit(1);
    }
}
;

// math ops
expr : 
expr PLUSnumber t 
{
  $$.type = TYPE_INT;
  if ($3.type == TYPE_INT)
    $$.val.sv = ($1.val.sv + $3.val.sv);
  else 
    {
      printf("Type error on line %d.\n", yyline);
      exit(1);
    }
} 
| expr MINUSnumber t 
{
  $$.type = TYPE_INT;
  if ($3.type == TYPE_INT)
    $$.val.sv = ($1.val.sv - $3.val.sv);
  else
    {
      printf("Type error on line %d.\n", yyline);
      exit(1);
    }
} 
| t 
{
  int type = $$.type = $1.type;
  if (type == TYPE_INT)
    $$.val.sv = $1.val.sv;
  else if (type == TYPE_STRING)
    $$.val.s = $1.val.s;
} 
| MINUSnumber t {$$.type = TYPE_INT; $$.val.sv = -$2.val.sv; /*printf("expr: %d\n", $$);*/}
;

t:
t TIMESnumber f 
{
  $$.type = TYPE_INT;
  if ($3.type == TYPE_INT)
    $$.val.sv = ($1.val.sv * $3.val.sv);
  else 
    {
      printf("Type error on line %d.\n", yyline);
      exit(1);
    }
} 
| t DIVnumber f 
{
  $$.type = TYPE_INT;
  if ($3.type == TYPE_INT)
    {
      int divisor = $3.val.sv;
      if(divisor != 0)
	$$.val.sv = ($1.val.sv / $3.val.sv); 
      else 
	{
	  printf("Dividing by zero on line %d.\n", yyline);
	  exit(1);
	}
    }
  else {
    printf("Type error on line %d.\n", yyline);
    exit(1);
  }
}
| f 
{
  int type = $$.type = $1.type;
  if (type == TYPE_INT)
    $$.val.sv = $1.val.sv; 
  else if ($1.type == TYPE_STRING)
  /*printf("t: %d\n", $$);*/
    $$.val.s = $1.val.s;
}
;

f:
IDnumber 
{
  int memAdress = getMemAdress($1);
  //printf("memAdress=%d\n", memAdress); 
  if(memAdress != MEM_ADRESS_NOT_FOUND)
    {
      if(memory[memAdress].initialized == 1) 
	{
	  int type = $$.type = memory[memAdress].type;
	  if(type == TYPE_INT)
	    $$.val.sv = memory[memAdress].value.i;
	  else if (type == TYPE_STRING)
	    $$.val.s = memory[memAdress].value.s;
	}
      else 
	{
	  printf("Referencing an uninitialized variable on line %d. \n", yyline);
	  exit(1);
	}
    }
  else
    {
      printf("Referencing an undeclared variable on line %d. \n", yyline);
      exit(1);
    }
}
| ICONSTnumber {$$.val.sv = $1; $$.type = TYPE_INT;/*printf("f: %d\n", $$);*/}
| LPARENnumber expr RPARENnumber
{
  int type = $$.type = $2.type;
  if($2.type == TYPE_INT)
    $$.val.sv = $2.val.sv; /*printf("f: %d\n", $$);*/
  else if($2.type == TYPE_STRING)
    $$.val.s = $2.val.s;
}
;

// var declaration
variable_declaration : 
type var_list
;

var_list :
| var_list IDnumber 
{
  initialize_var($2, declaration_type); 
  //printf("initialized %s as %d\n", $2, declaration_type);
}
| var_list IDnumber COMMAnumber 
{
  initialize_var($2, declaration_type); 
  /*printf("initialized: %s\n", $2);*/
}
;

type : 
VARINTnumber {declaration_type = TYPE_INT; /*printf("type: %s\n", $1);*/}
|VARSTRnumber {declaration_type = TYPE_STRING; /*printf("type: %s\n", $$);*/}
;

//printing                                                                                                     
print_statement :
PRINTnumber print_argument {printf("\n");}
;

print_argument :

// expressions
| print_argument expr 
{
  //printf("using expr: %d", $2);
  if ($2.type == TYPE_INT) printf("%d", $2.val.sv);
  else if ($2.type == TYPE_STRING) 
    {
      if ((*($2.val.s + strlen($2.val.s) - 1)) == '"')
	(*($2.val.s + strlen($2.val.s) - 1)) = '\0';
      printf("%s", $2.val.s + 1);
      //printf("%s", $2.val.s);
    }
}
| print_argument DOTnumber expr 
{
  //printf("using dot expr: "); 
  if ($3.type == TYPE_INT) printf("%d", $3.val.sv);
  else if ($3.type == TYPE_STRING) 
    {
      if ((*($3.val.s + strlen($3.val.s) - 1)) == '"') 
	(*($3.val.s + strlen($3.val.s) - 1)) = '\0';
      printf("%s", $3.val.s + 1);
      //printf("%s", $3.val.s);
    }
}
  
  // string literals
| print_argument STRINGnumber
{if ((*($2 + strlen($2) - 1)) == '"') (*($2 + strlen($2) - 1)) = '\0';printf("%s", $2+1);}
| print_argument DOTnumber STRINGnumber
{if ((*($3 + strlen($3) - 1)) == '"')(*($3 + strlen($3) -1)) = '\0';printf("%s", $3+1);}
;
//*/ 

%%

int main(void) {return yyparse();}

int yyerror(char *s) {return fprintf(stderr, "line %d: %s\n", yyline, s);}

int yywrap() {return(1);}
