/*
  Saul Paredes
  sbp14c
 */

%{
#include <stdio.h>
#include <string.h>
  int yyline=0;
  int yycolumn=0;
  %}

%union {
  int sv;
  char * s;
}

%token <sv> ICONSTnumber
%token  PRINTnumber PROGRAMnumber ISnumber BEGINnumber ENDnumber VARINTnumber VARSTRnumber
%token DIVnumber DOTnumber SEMInumber LPARENnumber MINUSnumber TIMESnumber COMMAnumber RPARENnumber
%token PLUSnumber EQnumber STRINGnumber IDnumber 

%% // rules

program : PROGRAMnumber IDnumber ISnumber BEGINnumber body ENDnumber
{printf("name of program: %s\n", $2);}
;

body : statement body
| statement
;

statement : print_statement
;


print_statement : PRINTnumber STRINGnumber SEMInumber {printf("body recognized\n");}
; 

%%

int main(void) {return yyparse();}

int yyerror(char *s) {return fprintf(stderr, "YACC:%s\n",s);}

int yywrap()
{
  return(1);
}
