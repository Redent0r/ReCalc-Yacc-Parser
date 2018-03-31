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
#define MEM_ADRESS_NOT_FOUND -1

  int yyline=0;
  int yycolumn=0;

  struct {
    char name[100];
    int type; /* 0 for int, 1 for string*/
    int initialized; /* boolean behaviour*/
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
	  if(strcmp(s, memory[i].name) == 0) /* if names are equal */
	    return i;
	  ++i;
	}
      return MEM_ADRESS_NOT_FOUND;
    }
  
#line 39 "recalc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int sv;
  char * s
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 63 "y.tab.c"

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

#define ICONSTnumber 257
#define PLUSnumber 258
#define MINUSnumber 259
#define TIMESnumber 260
#define DIVnumber 261
#define IDnumber 262
#define PRINTnumber 263
#define PROGRAMnumber 264
#define ISnumber 265
#define BEGINnumber 266
#define ENDnumber 267
#define VARINTnumber 268
#define VARSTRnumber 269
#define DOTnumber 270
#define SEMInumber 271
#define LPARENnumber 272
#define COMMAnumber 273
#define RPARENnumber 274
#define EQnumber 275
#define STRINGnumber 276
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    5,    6,    6,    7,
    7,    7,    7,    7,    8,    8,    8,    9,    9,    9,
    4,   11,   11,   10,   10,    3,   12,   12,   12,   12,
};
static const short yylen[] = {                            2,
    6,    3,    2,    1,    1,    1,    3,    1,    1,    3,
    3,    1,    1,    1,    3,    3,    1,    1,    1,    3,
    2,    3,    1,    1,    1,    2,    2,    1,    3,    2,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,   24,   25,    0,
    0,    4,    5,    6,    0,    0,    0,    0,    0,    0,
    8,    0,    0,    0,   17,   26,    1,    0,    0,   21,
    7,    0,    0,   27,    0,    0,    0,    0,    2,    0,
   29,   20,   19,   18,    0,    0,   15,   16,   22,
};
static const short yydgoto[] = {                          2,
   10,   11,   12,   13,   14,   22,   23,   24,   25,   15,
   30,   26,
};
static const short yysindex[] = {                      -234,
 -237,    0, -227, -214, -180, -232, -239,    0,    0, -209,
 -208,    0,    0,    0, -197, -212,    0,    0, -212, -200,
    0, -239, -173, -169,    0,    0,    0, -180, -192,    0,
    0, -239, -181,    0, -178, -178, -178, -178,    0, -197,
    0,    0,    0,    0, -169, -169,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -257, -250,    0,    0,
    0, -208, -196, -230,    0,    0,    0, -170, -201,    0,
    0, -171,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -223, -203,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   73,    0,    0,    0,    0,   71,   82,   60,   61,    0,
   63,  -16,
};
#define YYTABLESIZE 103
static const short yytable[] = {                         14,
   14,   14,   19,   19,   14,   34,   13,   13,   13,   18,
   18,   13,   14,   14,   14,   41,   14,   17,   14,   13,
   13,   13,   18,   13,    3,   13,   12,   12,   12,    1,
   19,   12,   20,   10,   10,   10,   21,    4,   10,   12,
   12,   12,   16,   12,   17,   12,   10,   10,   10,   18,
   10,    5,   10,   11,   11,   11,   17,   27,   11,   20,
    9,   18,   28,   21,   29,    9,   11,   11,   11,   23,
   11,   20,   11,    9,    9,    9,   35,   36,   43,    9,
   40,    6,    7,   44,   35,   36,   31,    8,    9,   32,
   37,   38,   42,   20,   45,   46,    3,   47,   48,   30,
   39,   33,   49,
};
static const short yycheck[] = {                        257,
  258,  259,  260,  261,  262,   22,  257,  258,  259,  260,
  261,  262,  270,  271,  272,   32,  274,  257,  276,  270,
  271,  272,  262,  274,  262,  276,  257,  258,  259,  264,
  270,  262,  272,  257,  258,  259,  276,  265,  262,  270,
  271,  272,  275,  274,  257,  276,  270,  271,  272,  262,
  274,  266,  276,  257,  258,  259,  257,  267,  262,  272,
  257,  262,  271,  276,  262,  262,  270,  271,  272,  271,
  274,  272,  276,  270,  271,  272,  258,  259,  257,  276,
  273,  262,  263,  262,  258,  259,   16,  268,  269,   19,
  260,  261,  274,  272,   35,   36,  267,   37,   38,  271,
   28,   20,   40,
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ICONSTnumber","PLUSnumber",
"MINUSnumber","TIMESnumber","DIVnumber","IDnumber","PRINTnumber",
"PROGRAMnumber","ISnumber","BEGINnumber","ENDnumber","VARINTnumber",
"VARSTRnumber","DOTnumber","SEMInumber","LPARENnumber","COMMAnumber",
"RPARENnumber","EQnumber","STRINGnumber",
};
static const char *yyrule[] = {
"$accept : program",
"program : PROGRAMnumber IDnumber ISnumber BEGINnumber body ENDnumber",
"body : statement SEMInumber body",
"body : statement SEMInumber",
"statement : print_statement",
"statement : variable_declaration",
"statement : assignment",
"assignment : IDnumber EQnumber r_value",
"r_value : STRINGnumber",
"r_value : expr",
"expr : expr PLUSnumber t",
"expr : expr MINUSnumber t",
"expr : t",
"expr : IDnumber",
"expr : ICONSTnumber",
"t : t TIMESnumber f",
"t : t DIVnumber f",
"t : f",
"f : IDnumber",
"f : ICONSTnumber",
"f : LPARENnumber expr RPARENnumber",
"variable_declaration : type var_list",
"var_list : IDnumber COMMAnumber var_list",
"var_list : IDnumber",
"type : VARINTnumber",
"type : VARSTRnumber",
"print_statement : PRINTnumber print_argument",
"print_argument : r_value print_argument",
"print_argument : r_value",
"print_argument : DOTnumber r_value print_argument",
"print_argument : DOTnumber r_value",

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
#line 125 "recalc.y"

int main(void) {return yyparse();}

int yyerror(char *s) {return fprintf(stderr, "YACC:%s\n",s);}

int yywrap()
{
  return(1);
}
#line 282 "y.tab.c"

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
#line 62 "recalc.y"
	{printf("%s was parsed succesfully\n", yystack.l_mark[-4]);}
break;
case 7:
#line 76 "recalc.y"
	{
  /*char * id = $1;*/
}
break;
case 9:
#line 82 "recalc.y"
	{yyval = yystack.l_mark[0]; printf("r_value: %d\n", yyval);}
break;
case 12:
#line 88 "recalc.y"
	{yyval = yystack.l_mark[0]; printf("expr: %d\n", yyval);}
break;
case 17:
#line 95 "recalc.y"
	{yyval = yystack.l_mark[0]; printf("t: %d\n", yyval);}
break;
case 18:
#line 98 "recalc.y"
	{/*$$ = $1; printf("int var detected: %d\n", $$);*/}
break;
case 19:
#line 99 "recalc.y"
	{yyval = yystack.l_mark[0]; printf("f: %d\n", yyval);}
break;
case 20:
#line 100 "recalc.y"
	{}
break;
#line 522 "y.tab.c"
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
