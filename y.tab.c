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
        if(memory[i].initialized == 0) /* found empty space                                                 */
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
  
#line 68 "recalc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int sv;
  char * s;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 85 "y.tab.c"

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
    0,    5,    5,    6,    6,    6,    9,    9,    7,    3,
    3,    3,    2,    2,    2,    1,    1,    1,    8,   11,
   11,   11,    4,    4,   10,   10,   10,   10,   10,   10,
   10,
};
static const short yylen[] = {                            2,
    6,    0,    3,    1,    1,    1,    3,    3,    2,    3,
    3,    1,    3,    3,    1,    1,    1,    3,    2,    0,
    2,    3,    1,    1,    0,    2,    3,    2,    3,    2,
    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    2,    0,   25,    1,   23,   24,
    0,   20,    0,    4,    5,    6,    0,    0,    0,    3,
    0,    0,   30,   17,   16,   15,    0,    0,    8,   16,
    0,    0,   31,   16,    0,    0,    0,    0,    0,    0,
   22,   18,   13,   14,    0,    0,
};
static const short yydgoto[] = {                          2,
   26,   27,   28,   12,    6,   13,   14,   15,   16,   17,
   19,
};
static const short yysindex[] = {                      -254,
 -260,    0, -240, -239,    0, -216,    0,    0,    0,    0,
 -238,    0, -233,    0,    0,    0, -201, -194, -237,    0,
 -191, -217,    0,    0,    0,    0, -256, -226,    0,    0,
 -226, -203,    0,    0, -226, -220, -217, -217, -217, -217,
    0,    0,    0,    0, -256, -256,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -215,    0, -183,    0,
    0,    0,    0,    0,    0,    0, -257, -213,    0,    0,
 -182, -262,    0,    0, -204,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -248, -228,
};
static const short yygindex[] = {                         0,
   -4,   38,  -16,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 87
static const short yytable[] = {                         12,
   12,   31,   37,   38,   35,   36,   21,    1,   10,   10,
   12,   12,   12,   21,   12,    3,   12,   12,   12,   10,
   10,   10,    4,   10,    5,   10,   10,   10,   11,   11,
   39,   40,   43,   44,   18,   20,   39,   40,   32,   11,
   11,   11,    0,   11,    7,   11,   11,   11,    8,    9,
   10,   42,   22,    9,   28,   28,   28,   24,   30,   11,
   28,   28,   28,   29,   29,   29,   21,   41,   22,   29,
   29,   29,   23,   24,   25,   22,   45,   46,   22,   29,
   24,   30,   33,   24,   34,   19,    7,
};
static const short yycheck[] = {                        257,
  258,   18,  259,  260,   21,   22,  269,  262,  257,  258,
  268,  269,  270,  276,  272,  276,  274,  275,  276,  268,
  269,  270,  263,  272,  264,  274,  275,  276,  257,  258,
  257,  258,   37,   38,  273,  269,  257,  258,  276,  268,
  269,  270,   -1,  272,  261,  274,  275,  276,  265,  266,
  267,  272,  270,  269,  268,  269,  270,  275,  276,  276,
  274,  275,  276,  268,  269,  270,  268,  271,  270,  274,
  275,  276,  274,  275,  276,  270,   39,   40,  270,  274,
  275,  276,  274,  275,  276,  269,  269,
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
"print_statement : PRINTnumber print_argument",
"expr : expr PLUSnumber t",
"expr : expr MINUSnumber t",
"expr : t",
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
"print_argument :",
"print_argument : print_argument IDnumber",
"print_argument : print_argument DOTnumber IDnumber",
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
#line 194 "recalc.y"

int main(void) {return yyparse();}

int yyerror(char *s) {return fprintf(stderr, "YACC:%s\n",s);}

int yywrap() {return(1);}
#line 300 "y.tab.c"

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
#line 83 "recalc.y"
	{printf("%s was parsed succesfully\n", yystack.l_mark[-4].s);}
break;
case 7:
#line 99 "recalc.y"
	{
  int memAdress = getMemAdress(yystack.l_mark[-2].s); 
  /*printf("expr:%d\n");*/
  memory[memAdress].value.i = yystack.l_mark[0].sv;
  printf("assignment: %s = %d\n", yystack.l_mark[-2].s, memory[memAdress].value.i);
}
break;
case 10:
#line 115 "recalc.y"
	{yyval.sv = (yystack.l_mark[-2].sv + yystack.l_mark[0].sv);}
break;
case 11:
#line 116 "recalc.y"
	{yyval.sv = (yystack.l_mark[-2].sv - yystack.l_mark[0].sv);}
break;
case 12:
#line 117 "recalc.y"
	{yyval.sv = yystack.l_mark[0].sv; /*printf("expr: %d\n", $$);*/}
break;
case 13:
#line 121 "recalc.y"
	{yyval.sv = (yystack.l_mark[-2].sv * yystack.l_mark[0].sv);}
break;
case 14:
#line 122 "recalc.y"
	{yyval.sv = (yystack.l_mark[-2].sv / yystack.l_mark[0].sv);}
break;
case 15:
#line 123 "recalc.y"
	{yyval.sv = yystack.l_mark[0].sv; /*printf("t: %d\n", $$);*/}
break;
case 16:
#line 128 "recalc.y"
	{
  int memAdress = getMemAdress(yystack.l_mark[0].s);
  /*printf("memAdress=%d", memAdress);*/ 
  yyval.sv = memory[memAdress].value.i;
}
break;
case 17:
#line 133 "recalc.y"
	{yyval.sv = yystack.l_mark[0].sv; /*printf("f: %d\n", $$);*/}
break;
case 18:
#line 134 "recalc.y"
	{yyval.sv = yystack.l_mark[-1].sv; /*printf("f: %d\n", $$);*/}
break;
case 21:
#line 143 "recalc.y"
	{initialize_var(yystack.l_mark[0].s, declaration_type); printf("initialized: %s\n", yystack.l_mark[0].s);}
break;
case 22:
#line 144 "recalc.y"
	{initialize_var(yystack.l_mark[-1].s, declaration_type); printf("initialized: %s\n", yystack.l_mark[-1].s);}
break;
case 23:
#line 148 "recalc.y"
	{yyval.sv = TYPE_INT; declaration_type = TYPE_INT; /*printf("type: %s\n", $1);*/}
break;
case 24:
#line 149 "recalc.y"
	{yyval.sv = TYPE_STRING; declaration_type = TYPE_STRING; /*printf("type: %s\n", $$);*/}
break;
case 26:
#line 161 "recalc.y"
	{
  int memAdress = getMemAdress(yystack.l_mark[0].s);
  printf("memAdress: %d\n", memAdress);
  if (memAdress == MEM_ADRESS_NOT_FOUND) 
    {
      printf("%s not initialized\n", yystack.l_mark[0].s);
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
break;
case 30:
#line 188 "recalc.y"
	{printf("%s", yystack.l_mark[0].s);}
break;
case 31:
#line 190 "recalc.y"
	{printf("%s", yystack.l_mark[0].s);}
break;
#line 605 "y.tab.c"
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
