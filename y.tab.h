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
extern YYSTYPE yylval;
