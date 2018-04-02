#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 7 "recalc.y"
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
    int type; /* 0 for int, 1 for string*/
    int initialized; /* boolean behaviour*/
    int declared; /* boolean behaviour*/
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
	if(strcmp(s, memory[i].name) == 0) /* if names are equal */
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
        if(memory[i].declared == 0) /* found empty space                                                 */
          {
	    memory[i].type = type;
	    strcpy(memory[i].name, s);
	    memory[i].declared = 1;
	    /*printf("initialize_var: %s initialized\n", memory[i].name);*/
	    return;
	  }
        ++i;
      }
  }
  
#line 75 "recalc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int sv;
  char * s;
  struct {
    int type;
    union {
      int sv;
      char * s;
    }val;
  }bi;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 99 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define PLUSnumber 257
#define MINUSnumber 258
#define TIMESnumber 259
#define DIVnumber 260
#define PRINTnumber 261
#define PROGRAMnumber 262
#define ISnumber 263
#define BEGINnumber 264
#define ENDnumber 265
#define VARINTnumber 266
#define VARSTRnumber 267
#define DOTnumber 268
#define SEMInumber 269
#define LPARENnumber 270
#define COMMAnumber 271
#define RPARENnumber 272
#define EQnumber 273
#define STRINGnumber 274
#define ICONSTnumber 275
#define IDnumber 276
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    4,    4,    5,    5,    5,    8,    8,    3,    3,
    3,    3,    2,    2,    2,    1,    1,    1,    7,   10,
   10,   10,    9,    9,    6,   11,   11,   11,   11,   11,
};
static const short yylen[] = {                            2,
    6,    0,    3,    1,    1,    1,    3,    3,    3,    3,
    1,    2,    3,    3,    1,    1,    1,    3,    2,    0,
    2,    3,    1,    1,    2,    0,    2,    3,    2,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    2,    0,   26,    1,   23,   24,
    0,    0,    4,    5,    6,   20,    0,    0,    3,    0,
    0,    0,    0,   29,   17,   16,   15,    0,    0,    8,
    0,    0,    0,   30,    0,    0,    0,    0,    0,    0,
   22,   18,   13,   14,    0,    0,
};
static const short yydgoto[] = {                          2,
   27,   28,   29,    6,   12,   13,   14,   15,   16,   20,
   17,
};
static const short yysindex[] = {                      -237,
 -242,    0, -226, -221,    0, -173,    0,    0,    0,    0,
 -215, -224,    0,    0,    0,    0, -206, -199,    0, -222,
 -268, -192, -185,    0,    0,    0,    0, -256, -252,    0,
 -252, -208, -256,    0, -252, -177, -268, -268, -268, -268,
    0,    0,    0,    0, -256, -256,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -204,    0,    0, -224,
    0,    0,    0,    0,    0,    0,    0, -257, -170,    0,
 -202, -253, -248,    0, -161,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -228, -219,
};
static const short yygindex[] = {                         0,
   23,   -7,   13,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 115
static const short yytable[] = {                         11,
   11,   23,   37,   38,   39,   40,   25,   26,   12,   12,
   11,   11,   11,   33,   11,   21,   11,   11,   11,   12,
   12,   12,   21,   12,    1,   12,   12,   12,    9,    9,
   31,   45,   46,    3,   35,   36,    4,   10,   10,    9,
    9,    9,    5,    9,   19,    9,    9,    9,   10,   10,
   10,   21,   10,   32,   10,   10,   10,   18,   21,   43,
   44,   22,   41,   23,   25,   21,    7,   24,   25,   26,
   23,    0,   21,    0,   30,   25,   26,   23,    0,   39,
   40,   34,   25,   26,   23,    0,    0,    7,    0,   25,
   26,    8,    9,   10,   42,    0,    0,   27,   27,   27,
    0,    0,   11,   27,   27,   27,   28,   28,   28,    0,
    0,    0,   28,   28,   28,
};
static const short yycheck[] = {                        257,
  258,  270,  259,  260,  257,  258,  275,  276,  257,  258,
  268,  269,  270,   21,  272,  269,  274,  275,  276,  268,
  269,  270,  276,  272,  262,  274,  275,  276,  257,  258,
   18,   39,   40,  276,   22,   23,  263,  257,  258,  268,
  269,  270,  264,  272,  269,  274,  275,  276,  268,  269,
  270,  258,  272,  276,  274,  275,  276,  273,  258,   37,
   38,  268,  271,  270,  269,  258,  269,  274,  275,  276,
  270,   -1,  258,   -1,  274,  275,  276,  270,   -1,  257,
  258,  274,  275,  276,  270,   -1,   -1,  261,   -1,  275,
  276,  265,  266,  267,  272,   -1,   -1,  268,  269,  270,
   -1,   -1,  276,  274,  275,  276,  268,  269,  270,   -1,
   -1,   -1,  274,  275,  276,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"PLUSnumber","MINUSnumber",
"TIMESnumber","DIVnumber","PRINTnumber","PROGRAMnumber","ISnumber",
"BEGINnumber","ENDnumber","VARINTnumber","VARSTRnumber","DOTnumber",
"SEMInumber","LPARENnumber","COMMAnumber","RPARENnumber","EQnumber",
"STRINGnumber","ICONSTnumber","IDnumber",
};
static const char *yyrule[] = {
"$accept : program",
"program : PROGRAMnumber IDnumber ISnumber BEGINnumber body ENDnumber",
"body :",
"body : body statement SEMInumber",
"statement : print_statement",
"statement : variable_declaration",
"statement : assignment",
"assignment : IDnumber EQnumber expr",
"assignment : IDnumber EQnumber STRINGnumber",
"expr : expr PLUSnumber t",
"expr : expr MINUSnumber t",
"expr : t",
"expr : MINUSnumber t",
"t : t TIMESnumber f",
"t : t DIVnumber f",
"t : f",
"f : IDnumber",
"f : ICONSTnumber",
"f : LPARENnumber expr RPARENnumber",
"variable_declaration : type var_list",
"var_list :",
"var_list : var_list IDnumber",
"var_list : var_list IDnumber COMMAnumber",
"type : VARINTnumber",
"type : VARSTRnumber",
"print_statement : PRINTnumber print_argument",
"print_argument :",
"print_argument : print_argument expr",
"print_argument : print_argument DOTnumber expr",
"print_argument : print_argument STRINGnumber",
"print_argument : print_argument DOTnumber STRINGnumber",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 341 "recalc.y"

int main(void) {return yyparse();}

int yyerror(char *s) {return fprintf(stderr, "line %d: %s\n", yyline, s);}

int yywrap() {return(1);}
#line 317 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 96 "recalc.y"
	{/*printf("%s was parsed succesfully\n", $2);*/}
break;
case 7:
#line 112 "recalc.y"
	{
  int memAdress = getMemAdress(yystack.l_mark[-2].s); 
  if(memAdress != MEM_ADRESS_NOT_FOUND)
    {
      if(yystack.l_mark[0].bi.type == TYPE_INT)
	{
	  memory[memAdress].value.i = yystack.l_mark[0].bi.val.sv;
	  memory[memAdress].initialized = 1;
	  /*printf("assignment: %s = %d\n", $1, memory[memAdress].value.i);*/
	}
      else
	{
	  /*printf("cant assign an expression to a string", $1, memory[memAdress].value.s);*/
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
break;
case 8:
#line 137 "recalc.y"
	{
  int memAdress = getMemAdress(yystack.l_mark[-2].s);
  if (memAdress != MEM_ADRESS_NOT_FOUND)
    {
      if(memory[memAdress].type == TYPE_STRING)
	{
	  strcpy(memory[memAdress].value.s, yystack.l_mark[0].s);
	  memory[memAdress].initialized = 1;
	  /*printf("assignment: %s = %s\n", $1, memory[memAdress].value.s);*/
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
break;
case 9:
#line 164 "recalc.y"
	{
  yyval.bi.type = TYPE_INT;
  if (yystack.l_mark[0].bi.type == TYPE_INT)
    yyval.bi.val.sv = (yystack.l_mark[-2].bi.val.sv + yystack.l_mark[0].bi.val.sv);
  else 
    {
      printf("Type error on line %d.\n", yyline);
      exit(1);
    }
}
break;
case 10:
#line 175 "recalc.y"
	{
  yyval.bi.type = TYPE_INT;
  if (yystack.l_mark[0].bi.type == TYPE_INT)
    yyval.bi.val.sv = (yystack.l_mark[-2].bi.val.sv - yystack.l_mark[0].bi.val.sv);
  else
    {
      printf("Type error on line %d.\n", yyline);
      exit(1);
    }
}
break;
case 11:
#line 186 "recalc.y"
	{
  int type = yyval.bi.type = yystack.l_mark[0].bi.type;
  if (type == TYPE_INT)
    yyval.bi.val.sv = yystack.l_mark[0].bi.val.sv;
  else if (type == TYPE_STRING)
    yyval.bi.val.s = yystack.l_mark[0].bi.val.s;
}
break;
case 12:
#line 193 "recalc.y"
	{yyval.bi.type = TYPE_INT; yyval.bi.val.sv = -yystack.l_mark[0].bi.val.sv; /*printf("expr: %d\n", $$);*/}
break;
case 13:
#line 198 "recalc.y"
	{
  yyval.bi.type = TYPE_INT;
  if (yystack.l_mark[0].bi.type == TYPE_INT)
    yyval.bi.val.sv = (yystack.l_mark[-2].bi.val.sv * yystack.l_mark[0].bi.val.sv);
  else 
    {
      printf("Type error on line %d.\n", yyline);
      exit(1);
    }
}
break;
case 14:
#line 209 "recalc.y"
	{
  yyval.bi.type = TYPE_INT;
  if (yystack.l_mark[0].bi.type == TYPE_INT)
    {
      int divisor = yystack.l_mark[0].bi.val.sv;
      if(divisor != 0)
	yyval.bi.val.sv = (yystack.l_mark[-2].bi.val.sv / yystack.l_mark[0].bi.val.sv); 
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
break;
case 15:
#line 228 "recalc.y"
	{
  int type = yyval.bi.type = yystack.l_mark[0].bi.type;
  if (type == TYPE_INT)
    yyval.bi.val.sv = yystack.l_mark[0].bi.val.sv; 
  else if (yystack.l_mark[0].bi.type == TYPE_STRING)
  /*printf("t: %d\n", $$);*/
    yyval.bi.val.s = yystack.l_mark[0].bi.val.s;
}
break;
case 16:
#line 240 "recalc.y"
	{
  int memAdress = getMemAdress(yystack.l_mark[0].s);
  /*printf("memAdress=%d\n", memAdress); */
  if(memAdress != MEM_ADRESS_NOT_FOUND)
    {
      if(memory[memAdress].initialized == 1) 
	{
	  int type = yyval.bi.type = memory[memAdress].type;
	  if(type == TYPE_INT)
	    yyval.bi.val.sv = memory[memAdress].value.i;
	  else if (type == TYPE_STRING)
	    yyval.bi.val.s = memory[memAdress].value.s;
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
break;
case 17:
#line 265 "recalc.y"
	{yyval.bi.val.sv = yystack.l_mark[0].sv; yyval.bi.type = TYPE_INT;/*printf("f: %d\n", $$);*/}
break;
case 18:
#line 267 "recalc.y"
	{
  int type = yyval.bi.type = yystack.l_mark[-1].bi.type;
  if(yystack.l_mark[-1].bi.type == TYPE_INT)
    yyval.bi.val.sv = yystack.l_mark[-1].bi.val.sv; /*printf("f: %d\n", $$);*/
  else if(yystack.l_mark[-1].bi.type == TYPE_STRING)
    yyval.bi.val.s = yystack.l_mark[-1].bi.val.s;
}
break;
case 21:
#line 283 "recalc.y"
	{
  initialize_var(yystack.l_mark[0].s, declaration_type); 
  /*printf("initialized %s as %d\n", $2, declaration_type);*/
}
break;
case 22:
#line 288 "recalc.y"
	{
  initialize_var(yystack.l_mark[-1].s, declaration_type); 
  /*printf("initialized: %s\n", $2);*/
}
break;
case 23:
#line 295 "recalc.y"
	{declaration_type = TYPE_INT; /*printf("type: %s\n", $1);*/}
break;
case 24:
#line 296 "recalc.y"
	{declaration_type = TYPE_STRING; /*printf("type: %s\n", $$);*/}
break;
case 25:
#line 301 "recalc.y"
	{printf("\n");}
break;
case 27:
#line 308 "recalc.y"
	{
  /*printf("using expr: %d", $2);*/
  if (yystack.l_mark[0].bi.type == TYPE_INT) printf("%d", yystack.l_mark[0].bi.val.sv);
  else if (yystack.l_mark[0].bi.type == TYPE_STRING) 
    {
      if ((*(yystack.l_mark[0].bi.val.s + strlen(yystack.l_mark[0].bi.val.s) - 1)) == '"')
	(*(yystack.l_mark[0].bi.val.s + strlen(yystack.l_mark[0].bi.val.s) - 1)) = '\0';
      printf("%s", yystack.l_mark[0].bi.val.s + 1);
      /*printf("%s", $2.val.s);*/
    }
}
break;
case 28:
#line 320 "recalc.y"
	{
  /*printf("using dot expr: "); */
  if (yystack.l_mark[0].bi.type == TYPE_INT) printf("%d", yystack.l_mark[0].bi.val.sv);
  else if (yystack.l_mark[0].bi.type == TYPE_STRING) 
    {
      if ((*(yystack.l_mark[0].bi.val.s + strlen(yystack.l_mark[0].bi.val.s) - 1)) == '"') 
	(*(yystack.l_mark[0].bi.val.s + strlen(yystack.l_mark[0].bi.val.s) - 1)) = '\0';
      printf("%s", yystack.l_mark[0].bi.val.s + 1);
      /*printf("%s", $3.val.s);*/
    }
}
break;
case 29:
#line 334 "recalc.y"
	{if ((*(yystack.l_mark[0].s + strlen(yystack.l_mark[0].s) - 1)) == '"') (*(yystack.l_mark[0].s + strlen(yystack.l_mark[0].s) - 1)) = '\0';printf("%s", yystack.l_mark[0].s+1);}
break;
case 30:
#line 336 "recalc.y"
	{if ((*(yystack.l_mark[0].s + strlen(yystack.l_mark[0].s) - 1)) == '"')(*(yystack.l_mark[0].s + strlen(yystack.l_mark[0].s) -1)) = '\0';printf("%s", yystack.l_mark[0].s+1);}
break;
#line 767 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
