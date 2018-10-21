/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compiler_parser.ypp" /* yacc.c:339  */
 
    #define  YYDEBUG 1
    #include "compiler_headings.hpp"

    
    struct name_t {
        string type;
        string name;
    };

    struct func_t {
        name_t         def;
        vector<name_t> args;
        bool           has_returned;
        int            return_counter;
    };

    vector<name_t> vars_stack;
    vector<func_t> funcs_stack =    {
                                        {{"int",  "input"},   {},             true,  1}, // int input (void) {...}
                                        {{"void", "println"}, {{"int", "x"}}, false, 0}  // void println (int x) {...}
                                    };
    vector<string> args_acc,
                   expr_aux;

    int    nesting_counter  = 0,
           current_func     = -1;
    string next_scope_type  = "block",
           expr_acc         = "";

    void open_scope      (string t);
    bool create_var      (string t, string          n);
    bool get_var         (string n, name_t          &holder);
    bool create_func     (string t, string          n);
    bool get_func        (string n, func_t          &holder);
    bool comp_args       (func_t f, vector<string>* args);
    bool set_func_return ();
    void close_scope     ();

#line 106 "compiler_parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "compiler_parser.tab.hpp".  */
#ifndef YY_YY_COMPILER_PARSER_TAB_HPP_INCLUDED
# define YY_YY_COMPILER_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    ID = 259,
    COMMA = 260,
    ADD = 261,
    SUB = 262,
    MUL = 263,
    DIV = 264,
    L_PAR = 265,
    R_PAR = 266,
    L_BRA = 267,
    R_BRA = 268,
    L_CUR = 269,
    R_CUR = 270,
    SEMIC = 271,
    ASGN = 272,
    LT = 273,
    GT = 274,
    LTE = 275,
    GTE = 276,
    EQ = 277,
    NEQ = 278,
    IF = 279,
    ELSE = 280,
    WHILE = 281,
    RET = 282,
    INT = 283,
    VOID = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "compiler_parser.ypp" /* yacc.c:355  */

    long  int       number;
    const char*     type_name;
    const char*     identifier;
    const char*     symbol;
    const char*     keyword;
    vector<string>* arguments;

#line 185 "compiler_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILER_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "compiler_parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    76,    97,    98,   100,   101,   103,   125,
     148,   148,   149,   174,   175,   177,   177,   178,   180,   181,
     183,   206,   230,   231,   232,   234,   235,   237,   238,   240,
     241,   242,   243,   244,   246,   247,   248,   263,   264,   279,
     280,   282,   303,   336,   350,   357,   356,   387,   390,   389,
     415,   417,   418,   419,   420,   421,   422,   425,   424,   450,
     452,   453,   456,   455,   481,   483,   484,   486,   487,   488,
     489,   502,   525,   524,   567,   599,   600,   602,   615
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "COMMA", "ADD", "SUB",
  "MUL", "DIV", "L_PAR", "R_PAR", "L_BRA", "R_BRA", "L_CUR", "R_CUR",
  "SEMIC", "ASGN", "LT", "GT", "LTE", "GTE", "EQ", "NEQ", "IF", "ELSE",
  "WHILE", "RET", "INT", "VOID", "$accept", "program", "declaration_list",
  "declaration", "var_declaration", "fun_declaration", "$@1",
  "fun_decl_head", "type_specifier", "params", "$@2", "param_list",
  "param", "compound_stmt", "open_compd", "close_compd",
  "local_declarations", "statement_list", "statement", "selection_stmt",
  "selection_head", "iteration_stmt", "iteration_head", "scope_stmt",
  "return_stmt", "expression_stmt", "expression", "$@3",
  "simple_expression", "$@4", "relop", "additive_expression", "$@5",
  "addop", "term", "$@6", "mulop", "factor", "var", "$@7", "call", "args",
  "arg_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

#define YYPACT_NINF -54

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -26,   -54,   -54,    11,   -26,   -54,   -54,   -54,    -1,    31,
     -54,   -54,   -54,    39,   -26,    -2,   -54,    49,    56,   -54,
     -54,    60,   -54,    51,    54,   -26,    61,   -54,   -54,   -54,
      62,   -54,    48,   -26,   -54,   -54,   -54,    63,     3,     0,
     -54,    29,    33,   -54,   -54,    66,    67,    30,   -54,   -54,
     -54,   -54,    28,   -54,    28,   -54,   -54,    64,   -54,    50,
      12,   -54,    65,   -54,    33,   -54,    68,    33,    33,   -54,
      69,   -54,   -54,    53,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,    70,    78,    33,   -54,    73,    75,   -54,    28,    33,
      33,    33,    33,   -54,    33,    74,   -54,   -54,   -54,    52,
     -54,    12,   -54,   -54,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    13,    14,     0,     3,     5,     7,     6,    15,     0,
       1,     4,    17,     0,     0,     0,    10,     0,    16,    19,
      12,     0,     8,     0,    20,     0,     0,    23,    11,    25,
       0,    18,     0,    27,    21,     9,    26,     0,     0,     0,
      70,    71,     0,    24,    44,     0,     0,     0,    30,    22,
      28,    31,     0,    32,     0,    33,    29,     0,    47,    50,
      59,    64,    68,    69,    75,    72,     0,     0,     0,    41,
       0,    30,    39,    34,    37,    43,    60,    61,    53,    54,
      51,    52,    55,    56,    48,    57,    65,    66,    62,    45,
      78,     0,    76,     0,    67,     0,     0,    42,     0,     0,
       0,     0,     0,    74,     0,     0,    36,    38,    35,    49,
      68,    58,    63,    46,    77,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   -54,    84,    57,   -54,   -54,   -54,   -10,   -54,
     -54,   -54,    71,   -14,   -54,   -54,   -54,   -54,    55,   -54,
     -54,   -54,   -54,   -53,   -54,   -54,   -42,   -54,   -54,   -54,
     -54,    -8,   -54,   -54,   -11,   -54,   -54,    -9,   -52,   -54,
     -54,   -54,   -54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    23,     8,     9,    13,
      14,    18,    19,    71,    29,    49,    33,    38,    72,    51,
      52,    53,    54,    73,    55,    56,    57,   102,    58,    99,
      84,    59,   100,    85,    60,   101,    88,    61,    62,    93,
      63,    91,    92
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    74,     1,     2,    17,    70,    40,    41,    20,    28,
      21,    10,    21,    42,    22,    17,    22,    27,    43,    44,
      86,    87,    90,    37,    48,    95,    96,    45,    12,    46,
      47,    40,    41,    40,    41,    15,    40,    41,    42,    64,
      42,    65,    27,    42,    44,   108,    69,   110,   110,   110,
      16,   105,    45,    24,    46,    47,    76,    77,    76,    77,
     113,    25,   114,    26,    35,    27,    30,    39,    78,    79,
      80,    81,    82,    83,    32,    34,    67,    68,    98,    94,
      75,   103,    89,   104,   106,    97,   107,   115,    11,   111,
      36,   109,   112,    50,     0,     0,    31
};

static const yytype_int8 yycheck[] =
{
      42,    54,    28,    29,    14,    47,     3,     4,    10,    23,
      12,     0,    12,    10,    16,    25,    16,    14,    15,    16,
       8,     9,    64,    33,    38,    67,    68,    24,    29,    26,
      27,     3,     4,     3,     4,     4,     3,     4,    10,    10,
      10,    12,    14,    10,    16,    98,    16,    99,   100,   101,
      11,    93,    24,     4,    26,    27,     6,     7,     6,     7,
     102,     5,   104,     3,    16,    14,    12,     4,    18,    19,
      20,    21,    22,    23,    13,    13,    10,    10,    25,    11,
      16,    11,    17,     5,    11,    16,    11,    13,     4,   100,
      33,    99,   101,    38,    -1,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    29,    31,    32,    33,    34,    35,    37,    38,
       0,    33,    29,    39,    40,     4,    11,    38,    41,    42,
      10,    12,    16,    36,     4,     5,     3,    14,    43,    44,
      12,    42,    13,    46,    13,    16,    34,    38,    47,     4,
       3,     4,    10,    15,    16,    24,    26,    27,    43,    45,
      48,    49,    50,    51,    52,    54,    55,    56,    58,    61,
      64,    67,    68,    70,    10,    12,    56,    10,    10,    16,
      56,    43,    48,    53,    53,    16,     6,     7,    18,    19,
      20,    21,    22,    23,    60,    63,     8,     9,    66,    17,
      56,    71,    72,    69,    11,    56,    56,    16,    25,    59,
      62,    65,    57,    11,     5,    56,    11,    11,    53,    61,
      68,    64,    67,    56,    56,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    31,    32,    32,    33,    33,    34,    34,
      36,    35,    37,    38,    38,    40,    39,    39,    41,    41,
      42,    42,    43,    44,    45,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    49,    49,    50,    51,    52,    53,
      53,    54,    54,    55,    55,    57,    56,    56,    59,    58,
      58,    60,    60,    60,    60,    60,    60,    62,    61,    61,
      63,    63,    65,    64,    64,    66,    66,    67,    67,    67,
      67,    68,    69,    68,    70,    71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     1,     1,     1,     3,     6,
       0,     5,     3,     1,     1,     0,     2,     1,     3,     1,
       2,     4,     4,     1,     1,     0,     2,     0,     2,     1,
       1,     1,     1,     1,     2,     4,     4,     2,     4,     1,
       1,     2,     3,     2,     1,     0,     4,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     1,
       1,     1,     0,     4,     1,     1,     1,     3,     1,     1,
       1,     1,     0,     5,     4,     0,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 72 "compiler_parser.ypp" /* yacc.c:1646  */
    {
                                    ofstream tree_file (parser_tree_path, ofstream::out);
                                    if (tree_file.is_open()) { tree_file << ""; tree_file.close(); }
                                }
#line 1366 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 76 "compiler_parser.ypp" /* yacc.c:1646  */
    {

                                    name_t last_var  = vars_stack.back();
                                    func_t last_func = funcs_stack.back();

                                    //cout << "wrote tree to file " << parser_tree_path << endl;

                                    if ((last_var.name         == "main") &&
                                        (last_var.type         == "func") &&
                                        (last_func.def.name    == "main") &&
                                        (last_func.def.type    == "void") &&
                                        (last_func.args.size() == 0)     ) {

                                        write_to_tree("]\n"); 
                                    }
                                    else {
                                        yyerror("program didn't end with \"void main (void) {...}\"");
                                        YYERROR;
                                    }
                                }
#line 1391 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "compiler_parser.ypp" /* yacc.c:1646  */
    { 

                                                    string convert_1 ((yyvsp[-2].keyword)), //type
                                                           convert_2 ((yyvsp[-1].identifier)); //name

                                                    //free($1);
                                                    //free($2);

                                                    if (convert_1 != "void") {
                                                        //cout << "var name: " << convert_2 << endl;
                                                        if (create_var(convert_1, convert_2)) {
                                                            write_to_tree("[var-declaration [" + convert_1 + "][" + convert_2 + "]]"); 
                                                        }
                                                        else {
                                                            YYERROR;
                                                        }
                                                    }
                                                    else {
                                                        yyerror("cannot declare variable of type void");
                                                        YYERROR;
                                                    } 
                                                }
#line 1418 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 125 "compiler_parser.ypp" /* yacc.c:1646  */
    { 

                                                    string convert_1 ((yyvsp[-5].keyword)), //type
                                                           convert_2 ((yyvsp[-4].identifier)); //name

                                                    //free($1);
                                                    //free($2);

                                                    if (convert_1 != "void") {
                                                        //cout << "var name: " << convert_2 << endl;
                                                        if (create_var(convert_1 + "[]", convert_2)) {
                                                            write_to_tree("[var-declaration [" + convert_1 + "][" + convert_2 + "][" + to_string((yyvsp[-2].number)) + "]]");
                                                        }
                                                        else {
                                                            YYERROR;
                                                        }
                                                    }
                                                    else {
                                                        yyerror("cannot declare variable of type void");
                                                        YYERROR;
                                                    } 
                                                }
#line 1445 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 148 "compiler_parser.ypp" /* yacc.c:1646  */
    { write_to_tree("]"); }
#line 1451 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "compiler_parser.ypp" /* yacc.c:1646  */
    { write_to_tree("]"); }
#line 1457 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 149 "compiler_parser.ypp" /* yacc.c:1646  */
    {

                            string convert_1 ((yyvsp[-2].keyword)), //return type
                                   convert_2 ((yyvsp[-1].identifier)); //name

                            //free($1);
                            //free($2);
                            //cout << "func name: " << convert_2 << endl;
                            if (create_var("func", convert_2)) {
                                if (create_func(convert_1, convert_2)) {
                                    write_to_tree("[fun-declaration [" + convert_1 + "][" + convert_2 + "]");
                                    open_scope("params");
                                    write_to_tree("[params");
                                    next_scope_type = "func";
                                    current_func    = funcs_stack.size() - 1;
                                }
                                else {
                                    YYERROR;
                                }
                            }
                            else {
                                YYERROR;
                            }
                        }
#line 1486 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 177 "compiler_parser.ypp" /* yacc.c:1646  */
    { write_to_tree(" "); }
#line 1492 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 177 "compiler_parser.ypp" /* yacc.c:1646  */
    { /* cout << "params: " << $2 << endl; */ (yyval.number) = (yyvsp[0].number); }
#line 1498 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 178 "compiler_parser.ypp" /* yacc.c:1646  */
    { /* cout << "no params" << endl; */ (yyval.number) = 0; }
#line 1504 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 180 "compiler_parser.ypp" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + 1; /* counting parameters */ }
#line 1510 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 181 "compiler_parser.ypp" /* yacc.c:1646  */
    { (yyval.number) = 1; }
#line 1516 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 183 "compiler_parser.ypp" /* yacc.c:1646  */
    { 

                                            string convert_1 ((yyvsp[-1].keyword)), //type
                                                   convert_2 ((yyvsp[0].identifier)); //name

                                            //free($1);
                                            //free($2);

                                            if (convert_1 != "void") {
                                                //cout << "param name: " << convert_2 << endl;
                                                if (create_var(convert_1, convert_2)) {
                                                    write_to_tree("[param [" + convert_1 + "][" + convert_2 + "]]");
                                                    funcs_stack[current_func].args.push_back({convert_1, convert_2});
                                                }
                                                else {
                                                    YYERROR;
                                                }
                                            }
                                            else {
                                                yyerror("cannot declare variable of type void");
                                                YYERROR;
                                            }
                                        }
#line 1544 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 206 "compiler_parser.ypp" /* yacc.c:1646  */
    { 

                                            string convert_1 ((yyvsp[-3].keyword)), //type
                                                   convert_2 ((yyvsp[-2].identifier)); //name

                                            //free($1);
                                            //free($2);

                                            if (convert_1 != "void") {
                                                //cout << "param name: " << convert_2 << endl;
                                                if (create_var(convert_1 + "[]", convert_2)) {
                                                    write_to_tree("[param [" + convert_1 + "][" + convert_2 + "][\\[\\]]]");
                                                    funcs_stack[current_func].args.push_back({convert_1 + "[]", convert_2});
                                                }
                                                else {
                                                    YYERROR;
                                                }
                                            }
                                            else {
                                                yyerror("cannot declare variable of type void");
                                                YYERROR;
                                            }
                                        }
#line 1572 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 231 "compiler_parser.ypp" /* yacc.c:1646  */
    { write_to_tree("[compound-stmt "); open_scope(next_scope_type); next_scope_type = "block"; }
#line 1578 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 232 "compiler_parser.ypp" /* yacc.c:1646  */
    { write_to_tree("]"); close_scope(); }
#line 1584 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 246 "compiler_parser.ypp" /* yacc.c:1646  */
    { write_to_tree("]"); }
#line 1590 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 247 "compiler_parser.ypp" /* yacc.c:1646  */
    { write_to_tree("]"); }
#line 1596 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 248 "compiler_parser.ypp" /* yacc.c:1646  */
    {

                            string convert ((yyvsp[-1].type_name));

                            //free($3);
                            //cout << "if-then-else block" << endl;
                            write_to_tree("[selection-stmt " + expr_acc);
                            expr_acc = "";

                            if (convert != "int") {
                                yyerror("check in if statement doesn't resume to a valid value");
                                YYERROR;
                            }
                        }
#line 1615 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 263 "compiler_parser.ypp" /* yacc.c:1646  */
    { write_to_tree("]"); }
#line 1621 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 264 "compiler_parser.ypp" /* yacc.c:1646  */
    {

                            string convert ((yyvsp[-1].type_name));

                            //free($3);
                            //cout << "while block" << endl;
                            write_to_tree("[iteration-stmt " + expr_acc);
                            expr_acc = "";

                            if (convert != "int") {
                                yyerror("check in while statement doesn't resume to a valid value");
                                YYERROR;
                            }
                        }
#line 1640 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 282 "compiler_parser.ypp" /* yacc.c:1646  */
    {

                                    //cout << "return call" << endl;
                                    write_to_tree("[return-stmt]");

                                    if (set_func_return()) { // existing function to return
                                        if (funcs_stack[current_func].def.type != "void") { // non-void function
                                            yyerror("cannot do empty return for non-void function ");
                                            YYERROR;
                                        }
                                        else { // void function
                                            if (funcs_stack[current_func].return_counter > 1) { // already returned in this scope
                                                yyerror("multiple function returns in this scope");
                                                YYERROR;
                                            }
                                        }
                                    }
                                    else { // not inside a function
                                        YYERROR;
                                    }
                                }
#line 1666 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 303 "compiler_parser.ypp" /* yacc.c:1646  */
    {   

                                    string convert ((yyvsp[-1].type_name));

                                    //free($3);
                                    //cout << "return call" << endl;

                                    write_to_tree("[return-stmt " + expr_acc + "]");
                                    expr_acc = "";

                                    if (set_func_return()) { // existing function to return
                                        if (funcs_stack[current_func].def.type == "void") {
                                            yyerror("cannot do return with value for void function");
                                            YYERROR;
                                        }
                                        else {
                                            if (funcs_stack[current_func].return_counter > 1) {
                                                yyerror("multiple function returns in this scope");
                                                YYERROR;
                                            }
                                            else {
                                                if (convert != funcs_stack[current_func].def.type) {
                                                    yyerror("return of different value type from function");
                                                    YYERROR;
                                                }
                                            }
                                        }
                                    }
                                    else { // not inside a function
                                        YYERROR;
                                    } 
                                }
#line 1703 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 336 "compiler_parser.ypp" /* yacc.c:1646  */
    {

                                string convert ((yyvsp[-1].type_name));

                                if (convert != "int[]") {
                                    //cout << "expr_acc: " << expr_acc << endl;
                                    write_to_tree(expr_acc);
                                    expr_acc = "";
                                }
                                else {
                                    yyerror("expression resumes to array with no index");
                                    YYERROR;
                                }
                            }
#line 1722 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 350 "compiler_parser.ypp" /* yacc.c:1646  */
    { 
                                write_to_tree("[;]");
                                expr_acc = "";
                                (yyval.type_name) = strdup(string("void").c_str());
                            }
#line 1732 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 357 "compiler_parser.ypp" /* yacc.c:1646  */
    { expr_aux.push_back(expr_acc); expr_acc = ""; }
#line 1738 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 358 "compiler_parser.ypp" /* yacc.c:1646  */
    {  

                                            string convert_1 ((yyvsp[-3].type_name)),
                                                   convert_4 ((yyvsp[0].type_name));
                                            name_t holder;

                                            //free($1);
                                            //free($4);
                                            //cout << "assignment of " << convert_4 << " to " << convert_1 << endl;
                                            //cout << "head of assignment: " << expr_aux.back() << endl;
                                            //cout << "body of assignment: " << expr_acc << endl;

                                            expr_acc = "[= " + expr_aux.back() + expr_acc + "]";
                                            expr_aux.pop_back();

                                            if ((convert_1 != "int[]") && (convert_4 != "int[]")) {
                                                if (convert_1 == convert_4) {
                                                    (yyval.type_name) = strdup(convert_1.c_str());
                                                } 
                                                else {
                                                    yyerror("assignment of different value type from variable");
                                                    YYERROR;
                                                }
                                            }
                                            else {
                                                yyerror("trying to assign array pointer");
                                                YYERROR;
                                            }
                                        }
#line 1772 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 390 "compiler_parser.ypp" /* yacc.c:1646  */
    { expr_aux.push_back(expr_acc); expr_acc = ""; }
#line 1778 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 391 "compiler_parser.ypp" /* yacc.c:1646  */
    {

                                                string convert_1 ((yyvsp[-3].type_name)),
                                                       convert_2 ((yyvsp[-2].symbol)),
                                                       convert_4 ((yyvsp[0].type_name));

                                                //free($1);
                                                //free($2);
                                                //free($4);
                                                //cout << convert_2 << " operation" << endl;

                                                expr_acc =  "[" + convert_2 + " " +
                                                            expr_aux.back() + expr_acc + "]";
                                                
                                                expr_aux.pop_back();

                                                if ((convert_1 == "int") && (convert_4 == "int")) {
                                                    (yyval.type_name) = strdup(string("int").c_str());
                                                }
                                                else {
                                                    yyerror("illegal operation between " + convert_1 + " and " + convert_4);
                                                    YYERROR;
                                                }
                                            }
#line 1807 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 425 "compiler_parser.ypp" /* yacc.c:1646  */
    { expr_aux.push_back(expr_acc); expr_acc = ""; }
#line 1813 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 426 "compiler_parser.ypp" /* yacc.c:1646  */
    {

                                string convert_1 ((yyvsp[-3].type_name)),
                                       convert_2 ((yyvsp[-2].symbol)),
                                       convert_4 ((yyvsp[0].type_name));

                                //free($1);
                                //free($2);
                                //free($4);
                                //cout << convert_2 << " operation" << endl;

                                expr_acc =  "[" + convert_2 + " " +
                                            expr_aux.back() + expr_acc + "]";
                                
                                expr_aux.pop_back();

                                if ((convert_1 == "int") && (convert_4 == "int")) {
                                    (yyval.type_name) = strdup(string("int").c_str());
                                }
                                else {
                                    yyerror("illegal operation between " + convert_1 + " and " + convert_4);
                                    YYERROR;
                                }
                            }
#line 1842 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 456 "compiler_parser.ypp" /* yacc.c:1646  */
    { expr_aux.push_back(expr_acc); expr_acc = ""; }
#line 1848 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 457 "compiler_parser.ypp" /* yacc.c:1646  */
    {   

                                string convert_1 ((yyvsp[-3].type_name)),
                                       convert_2 ((yyvsp[-2].symbol)),
                                       convert_4 ((yyvsp[0].type_name));

                                //free($1);
                                //free($2);
                                //free($4);
                                //cout << convert_2 << " operation" << endl;

                                expr_acc =  "[" + convert_2 + " " +
                                            expr_aux.back() + expr_acc + "]";
                                
                                expr_aux.pop_back();

                                if ((convert_1 == "int") && (convert_4 == "int")) {
                                    (yyval.type_name) = strdup(string("int").c_str());
                                }
                                else {
                                    yyerror("illegal operation between " + convert_1 + " and " + convert_4);
                                    YYERROR;
                                }
                            }
#line 1877 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 486 "compiler_parser.ypp" /* yacc.c:1646  */
    { (yyval.type_name) = (yyvsp[-1].type_name); }
#line 1883 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 487 "compiler_parser.ypp" /* yacc.c:1646  */
    { /* string convert ($1); cout << "call var of type "  << convert << endl; */ (yyval.type_name) = (yyvsp[0].type_name); }
#line 1889 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 488 "compiler_parser.ypp" /* yacc.c:1646  */
    { /* string convert ($1); cout << "call func of type " << convert << endl; */ (yyval.type_name) = (yyvsp[0].type_name); }
#line 1895 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 489 "compiler_parser.ypp" /* yacc.c:1646  */
    { 
                                if (((yyvsp[0].number) < 2147483648)  &&
                                    ((yyvsp[0].number) > -2147483648)) {

                                    expr_acc += "[" + to_string((yyvsp[0].number)) + "]";
                                    (yyval.type_name) = strdup(string("int").c_str());
                                }
                                else {
                                    yyerror("constant out of limits for type int");
                                    YYERROR;
                                }
                            }
#line 1912 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 502 "compiler_parser.ypp" /* yacc.c:1646  */
    {   

                            string convert ((yyvsp[0].identifier));                                   
                            name_t holder;

                            //free($1);                         
                                                                
                            if (get_var(convert, holder)) {
                                if (holder.type != "func") {
                                    //cout << "use of var " << convert << endl;
                                    expr_acc += "[var [" + convert + "]]";
                                    (yyval.type_name) = strdup(holder.type.c_str());
                                }
                                else {
                                    yyerror("tried using function " + convert + " as var");
                                    YYERROR;
                                }
                            }                                  
                            else {                             
                                YYERROR;                        
                            }                                    
                        }
#line 1939 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 525 "compiler_parser.ypp" /* yacc.c:1646  */
    { string convert_1 ((yyvsp[-1].identifier)); expr_aux.push_back("[var [" + convert_1 + "]"); }
#line 1945 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 526 "compiler_parser.ypp" /* yacc.c:1646  */
    {

                            string convert_1 ((yyvsp[-4].identifier)),
                                   convert_4 ((yyvsp[-1].type_name));                                   
                            name_t holder;

                            //free($1);                         
                            //free($4);
                            //cout << "head of var: " << expr_aux.back() << endl;
                            //cout << "body of var: " << expr_acc        << endl;                        
                                                                
                            if (get_var(convert_1, holder)) {
                                if (holder.type != "func") {
                                    if (holder.type == "int[]") {
                                        if (convert_4 == "int") {
                                            expr_acc = expr_aux.back() + expr_acc + "]";
                                            //cout << "use of var " << convert_1 << "[n]" << endl;
                                            //cout << "full var: "  << expr_acc  << endl;
                                            expr_aux.pop_back(); 
                                            (yyval.type_name) = strdup(string("int").c_str());
                                        }
                                        else {
                                            yyerror("use of non-int index to access array " + convert_1);
                                            YYERROR;
                                        }
                                    }
                                    else {
                                        yyerror("variable " + convert_1 + " isn't an array");
                                        YYERROR;
                                    }
                                }
                                else {
                                    yyerror("tried using function " + convert_1 + " as var");
                                    YYERROR;
                                }                
                            }                                  
                            else {                             
                                YYERROR;                        
                            }
                        }
#line 1990 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 567 "compiler_parser.ypp" /* yacc.c:1646  */
    { 

                                    string convert ((yyvsp[-3].identifier));
                                    func_t holder;                         

                                    //free($1);
                                    //cout << "call of func " << convert    << endl;
                                    //cout << "args: "        << $3->size() << endl;

                                    if ((yyvsp[-1].arguments)->size() > 0) { expr_aux.back() = " " + expr_aux.back(); }
                                    
                                    expr_acc = "[call [" + convert + "][args" + expr_aux.back() + "]]";
                                    expr_aux.pop_back();

                                    if (get_func(convert, holder)) {

                                        //cout << "params: " << holder.args.size() << endl;

                                        if (!comp_args(holder, (yyvsp[-1].arguments))) {
                                            YYERROR;
                                        }
                                        else {
                                            (yyval.type_name) = strdup(holder.def.type.c_str());
                                        }

                                        args_acc.clear();                 
                                    }                                  
                                    else {                             
                                        YYERROR;                      
                                    }
                                }
#line 2026 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 599 "compiler_parser.ypp" /* yacc.c:1646  */
    { expr_aux.push_back(""); vector<string> empty; (yyval.arguments) = &empty; }
#line 2032 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 600 "compiler_parser.ypp" /* yacc.c:1646  */
    { (yyval.arguments) = (yyvsp[0].arguments); }
#line 2038 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 602 "compiler_parser.ypp" /* yacc.c:1646  */
    { 

                                    string convert ((yyvsp[0].type_name)); // <---
                                    
                                    //free($3);
                                    expr_acc = expr_aux.back() + expr_acc;
                                    expr_aux.pop_back();
                                    expr_aux.push_back(expr_acc);
                                    expr_acc = "";

                                    (yyvsp[-2].arguments)->push_back(convert); /* stacking arguments */
                                    (yyval.arguments) = (yyvsp[-2].arguments);
                                }
#line 2056 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 615 "compiler_parser.ypp" /* yacc.c:1646  */
    {

                                    string convert ((yyvsp[0].type_name));

                                    //free($1);
                                    expr_aux.push_back(expr_acc);
                                    expr_acc = "";

                                    args_acc.push_back(convert);
                                    (yyval.arguments) = &args_acc;
                                }
#line 2072 "compiler_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2076 "compiler_parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 627 "compiler_parser.ypp" /* yacc.c:1906  */


void yyerror (string message) {

    ofstream tree_file (parser_tree_path, ofstream::out);

    cerr << "line " << line_num << ": " << message << endl;
    if (tree_file.is_open()) { tree_file << ""; tree_file.close(); } 
}

void open_scope (string t) {
    //cout << "opening scope of " << t << endl;
    vars_stack.push_back({t, "###"}); // push scope marker
    nesting_counter++;
};

string closest_scope_type () {
    
    for (int i = vars_stack.size() - 1; i >= 0; i--) { // traverse back until global scope
        
        if (vars_stack[i].name == "###") {
            return vars_stack[i].type;
        }
    }

    return "global";
}

int get_var_index_full (string n) {

    for (int i = vars_stack.size() - 1; i >= 0; i--) { // traverse back until global scope
        
        if (vars_stack[i].name == n) {
            return i;
        }
    }

    return -1;
}

int get_var_index_closest (string n) {

    int i = vars_stack.size() - 1;

    for ( ; (i >= 0) && (vars_stack[i].name != "###"); i--) { // traverse back to closest scope marker
        if (vars_stack[i].name == n) {
            return i;
        }
    }

    if (closest_scope_type() == "func") {
        for ( ; (i >= 0) && (vars_stack[i].type != "params"); i--) { // traverse back to parameters scope if in function
            if (vars_stack[i].name == n) {
                return i;
            }
        }
    }

    return -1;
}

bool create_var (string t, string n) {

    int i = get_var_index_closest(n);
        
    if (i >= 0) {
        yyerror("var " + n + " already declared in this scope");
        return false;
    }

    //cout << "pushing var " << n << " of type " << t << endl;
    vars_stack.push_back({t, n});
    return true;
}


bool get_var (string n, name_t &holder) {

    int i = get_var_index_full(n);
    
    if (i >= 0) {
        holder = vars_stack[i];
        return true;
    }

    yyerror("var " + n + " wasn't declared in this scope");
    return false;
}

bool create_func (string t, string n) {

    for (auto i:funcs_stack) {
        if (i.def.name == n) {
            yyerror("func " + n + " already declared in this scope");
            return false;
        }
    }

    funcs_stack.push_back({{t, n}, {}, false, 0});
    return true;
}

bool get_func (string n, func_t &holder) {

    for (auto i:funcs_stack) {
        if (i.def.name == n) {
            holder = i;
            return true;
        }
    }

    yyerror("func " + n + " wasn't declared in this scope");
    return false;
}

bool comp_args (func_t f, vector<string>* args) {

    if (f.args.size() == args->size()) {

        for (unsigned int i = 0; i < f.args.size(); i++) {
            if (f.args[i].type != (*args)[i]) {
                yyerror("argument " + (*args)[i] + " of different type from parameter " + f.args[i].type);
                return false;
            }
        }

        return true;
    }

    yyerror("different number of arguments passed to function");
    return false;
}

bool set_func_return () {

    if (current_func >= 0) {
        funcs_stack[current_func].has_returned = true;
        funcs_stack[current_func].return_counter++;
        return true;
    }

    yyerror("no current function to return");
    return false;
}

void close_scope () {

    if ((current_func >= 0)) {
        if ((funcs_stack[current_func].return_counter > 0)) { // decrementing conditional return in this scope
            //cout << "discard conditional returns" << endl;
            funcs_stack[current_func].return_counter = 0;
        }
        else if ((funcs_stack[current_func].def.type != "void") &&
                 (closest_scope_type()               == "func")) {
            
            cout << "line " << line_num << ": --warning-- you might not be returning a value for non-void function" << endl;
        }
    }

    while ((vars_stack.size() > 0) && (vars_stack.back().name != "###")) { // pop everything after the closer scope marker
        //cout << "pop var " << vars_stack.back().name << endl;
        vars_stack.pop_back();
    }

    if ((vars_stack.back().name == "###") && (vars_stack.back().type == "func")) { // it's a function block


        if ((funcs_stack[current_func].def.type != "void")) {
            if (!funcs_stack[current_func].has_returned) {
                yyerror("closing non-void function without returning a value");
                return;
            }
        }

        //cout << "closing of " << vars_stack.back().type << " scope" << endl;
        vars_stack.pop_back(); // pop the scope marker
        current_func = -1;
        close_scope(); // pop function parameters
        return;
    }

    //cout << "closing of " << vars_stack.back().type << " scope" << endl;
    vars_stack.pop_back(); // pop the scope marker
    nesting_counter--;
}

void print_symbol_table () {

    string output = "[ ";

    for (auto i:vars_stack) {
        if (i.name != "###") { output += i.name + " "; }
        else { output += "<" + i.type + "> "; }
    }

    output += "]";
    cout << output << endl;
}

void write_to_tree (string s) {
    ofstream tree_file (parser_tree_path, ofstream::app);
    tree_file << s;
    tree_file.close();
}
