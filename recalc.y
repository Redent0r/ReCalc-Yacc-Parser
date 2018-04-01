/*
  Saul Paredes
  sbp14c
 */

%{
#include <stdio.h>
#include <string.h>

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
        if(memory[i].initialized == 0) // found empty space                                                 
          {
	    memory[i].type = type;
	    strcpy(memory[i].name, s);
	    memory[i].initialized = 1;
	    printf("initialize_var: %s initialized\n", memory[i].name);
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
};
  
%token <sv> ICONSTnumber 
%token <s> IDnumber STRINGnumber

%type <sv> f t expr type

%% // rules

// main
program : 
PROGRAMnumber IDnumber ISnumber BEGINnumber body ENDnumber
{printf("%s was parsed succesfully\n", $2);}
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
  //printf("expr:%d\n");
  memory[memAdress].value.i = $3;
  printf("assignment: %s = %d\n", $1, memory[memAdress].value.i);
}
| IDnumber EQnumber STRINGnumber
;

//printing                                                                                                     
print_statement :
PRINTnumber print_argument
;

// math ops
expr : 
expr PLUSnumber t {$$ = ($1 + $3);} 
| expr MINUSnumber t {$$ = ($1 - $3);} 
| t {$$ = $1; /*printf("expr: %d\n", $$);*/} 
;

t:
t TIMESnumber f {$$ = ($1 * $3);} 
| t DIVnumber f {$$ = ($1 / $3);} 
| f {$$ = $1; /*printf("t: %d\n", $$);*/}
;

f: 
IDnumber 
{
  int memAdress = getMemAdress($1);
  /*printf("memAdress=%d", memAdress);*/ 
  $$ = memory[memAdress].value.i;
}
| ICONSTnumber {$$ = $1; /*printf("f: %d\n", $$);*/}
| LPARENnumber expr RPARENnumber{$$ = $2; /*printf("f: %d\n", $$);*/}
; 

// var declaration
variable_declaration : 
type var_list
;

var_list :
| var_list IDnumber {initialize_var($2, declaration_type); printf("initialized: %s\n", $2);}
| var_list IDnumber COMMAnumber {initialize_var($2, declaration_type); printf("initialized: %s\n", $2);}
;

type : 
VARINTnumber {$$ = TYPE_INT; declaration_type = TYPE_INT; /*printf("type: %s\n", $1);*/}
|VARSTRnumber {$$ = TYPE_STRING; declaration_type = TYPE_STRING; /*printf("type: %s\n", $$);*/}
;

/*
//printing
print_statement : 
PRINTnumber print_argument
;
*/

print_argument :
| print_argument IDnumber 
{
  int memAdress = getMemAdress($2);
  printf("memAdress: %d\n", memAdress);
  if (memAdress == MEM_ADRESS_NOT_FOUND) 
    {
      printf("%s not initialized\n", $2);
      exit(1);
    }
  else if (memory[memAdress].type == TYPE_INT)
    {
      int result = memory[memAdress].value.i;
      printf("%d", result);
    }
  else if (memory[memAdress].type == TYPE_STRING)
    {
      const char * result = memory[memAdress].value.s;
      printf("%s", result);
    }
}
| print_argument DOTnumber IDnumber

// expressions
| print_argument expr
| print_argument DOTnumber expr 

  // string literals
| print_argument STRINGnumber
{printf("%s", $2);}
| print_argument DOTnumber STRINGnumber
{printf("%s", $3);}
; 

%%

int main(void) {return yyparse();}

int yyerror(char *s) {return fprintf(stderr, "YACC:%s\n",s);}

int yywrap() {return(1);}
