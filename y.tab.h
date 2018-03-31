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
extern YYSTYPE yylval;
