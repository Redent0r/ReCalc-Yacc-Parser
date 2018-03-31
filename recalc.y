/*
  Saul Paredes
  sbp14c
 */

%{
#include <stdio.h>
#include <string.h>

#define MAX_MEM_ADRESS 2000
#define MEM_ADRESS_NOT_FOUND -1

  int yyline=0;
  int yycolumn=0;

  struct {
    char name[100];
    int type; // 0 for int, 1 for string
    int initialized; // boolean behaviour
    union {
      char s[2000];
      int i;
    }value;
  }memory[MAX_MEM_ADRESS];

  getMemAdress(char * s)
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
  %}

%union {
  int sv;
  char * s
};

//%start program
  
%token ICONSTnumber 

%left PLUSnumber MINUSnumber
%left TIMESnumber DIVnumber

//token <sv> f
%token IDnumber

%token PRINTnumber PROGRAMnumber ISnumber BEGINnumber ENDnumber VARINTnumber VARSTRnumber
%token DOTnumber SEMInumber LPARENnumber COMMAnumber RPARENnumber
%token EQnumber STRINGnumber 

%% // rules

// main
program : PROGRAMnumber IDnumber ISnumber BEGINnumber body ENDnumber
{printf("%s was parsed succesfully\n", $2);}
;

body : statement SEMInumber body
| statement SEMInumber
;

statement : print_statement
| variable_declaration
| assignment
;

// assignment
assignment : IDnumber EQnumber r_value 
{
  //char * id = $1;
}
;

r_value : STRINGnumber
| expr {$$ = $1; printf("r_value: %d\n", $$);}
;

// math ops
expr :
expr PLUSnumber t | expr MINUSnumber t 
| t {$$ = $1; printf("expr: %d\n", $$);} 
| IDnumber
| ICONSTnumber
;

t:
t TIMESnumber f | t DIVnumber f 
| f {$$ = $1; printf("t: %d\n", $$);}
;

f: IDnumber {/*$$ = $1; printf("int var detected: %d\n", $$);*/}
| ICONSTnumber {$$ = $1; printf("f: %d\n", $$);}
| LPARENnumber expr RPARENnumber {}
;  

// var declaration
variable_declaration : type var_list
;

var_list : IDnumber COMMAnumber var_list
| IDnumber
;

type : VARINTnumber
| VARSTRnumber
;

//printing
print_statement : PRINTnumber print_argument
;

print_argument : 
r_value print_argument | r_value
| DOTnumber r_value print_argument | DOTnumber r_value 
; 

%%

int main(void) {return yyparse();}

int yyerror(char *s) {return fprintf(stderr, "YACC:%s\n",s);}

int yywrap()
{
  return(1);
}
