// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 10 "parser.y"

    #ifdef __GNUG__
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wall"
    #endif
    #ifdef _MSC_VER
        #pragma warning(push, 0)
    #endif
    #include "tokenizer.hpp"
    #include <string>
    #include <vector>
    #include <algorithm>

#line 53 "parser.tab.cc"




#include "parser.tab.hh"


// Unqualified %code blocks.
#line 100 "parser.y"

    
    #include "../../runtime/runtime.h"
     namespace sqf::parser::config::bison
     {
          // Return the next token.
          parser::symbol_type yylex (::sqf::parser::config::tokenizer&);
     }

#line 72 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 9 "parser.y"
namespace sqf { namespace parser { namespace config { namespace bison  {
#line 165 "parser.tab.cc"

  /// Build a parser object.
  parser::parser (::sqf::parser::config::tokenizer &tokenizer_yyarg, ::sqf::parser::config::bison::astnode& result_yyarg, ::sqf::parser::config::parser& actual_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      tokenizer (tokenizer_yyarg),
      result (result_yyarg),
      actual (actual_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_classdef: // classdef
      case symbol_kind::S_deleteclass: // deleteclass
      case symbol_kind::S_classbody: // classbody
      case symbol_kind::S_field: // field
      case symbol_kind::S_ident: // ident
      case symbol_kind::S_string: // string
      case symbol_kind::S_number: // number
      case symbol_kind::S_array: // array
      case symbol_kind::S_arrayvalue: // arrayvalue
      case symbol_kind::S_arrayvaluelist: // arrayvaluelist
      case symbol_kind::S_anyval: // anyval
      case symbol_kind::S_anyarr: // anyarr
      case symbol_kind::S_anyp: // anyp
      case symbol_kind::S_anyarray: // anyarray
      case symbol_kind::S_anyvalue: // anyvalue
        value.YY_MOVE_OR_COPY< ::sqf::parser::config::bison::astnode > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DELETE: // "delete"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_CURLYO: // "{"
      case symbol_kind::S_CURLYC: // "}"
      case symbol_kind::S_ROUNDO: // "("
      case symbol_kind::S_ROUNDC: // ")"
      case symbol_kind::S_SQUAREO: // "["
      case symbol_kind::S_SQUAREC: // "]"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_PLUSEQUAL: // "+="
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_HEXNUMBER: // HEXNUMBER
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ANY: // ANY
        value.YY_MOVE_OR_COPY< tokenizer::token > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_classdef: // classdef
      case symbol_kind::S_deleteclass: // deleteclass
      case symbol_kind::S_classbody: // classbody
      case symbol_kind::S_field: // field
      case symbol_kind::S_ident: // ident
      case symbol_kind::S_string: // string
      case symbol_kind::S_number: // number
      case symbol_kind::S_array: // array
      case symbol_kind::S_arrayvalue: // arrayvalue
      case symbol_kind::S_arrayvaluelist: // arrayvaluelist
      case symbol_kind::S_anyval: // anyval
      case symbol_kind::S_anyarr: // anyarr
      case symbol_kind::S_anyp: // anyp
      case symbol_kind::S_anyarray: // anyarray
      case symbol_kind::S_anyvalue: // anyvalue
        value.move< ::sqf::parser::config::bison::astnode > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DELETE: // "delete"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_CURLYO: // "{"
      case symbol_kind::S_CURLYC: // "}"
      case symbol_kind::S_ROUNDO: // "("
      case symbol_kind::S_ROUNDC: // ")"
      case symbol_kind::S_SQUAREO: // "["
      case symbol_kind::S_SQUAREC: // "]"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_PLUSEQUAL: // "+="
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_HEXNUMBER: // HEXNUMBER
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ANY: // ANY
        value.move< tokenizer::token > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_classdef: // classdef
      case symbol_kind::S_deleteclass: // deleteclass
      case symbol_kind::S_classbody: // classbody
      case symbol_kind::S_field: // field
      case symbol_kind::S_ident: // ident
      case symbol_kind::S_string: // string
      case symbol_kind::S_number: // number
      case symbol_kind::S_array: // array
      case symbol_kind::S_arrayvalue: // arrayvalue
      case symbol_kind::S_arrayvaluelist: // arrayvaluelist
      case symbol_kind::S_anyval: // anyval
      case symbol_kind::S_anyarr: // anyarr
      case symbol_kind::S_anyp: // anyp
      case symbol_kind::S_anyarray: // anyarray
      case symbol_kind::S_anyvalue: // anyvalue
        value.copy< ::sqf::parser::config::bison::astnode > (that.value);
        break;

      case symbol_kind::S_DELETE: // "delete"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_CURLYO: // "{"
      case symbol_kind::S_CURLYC: // "}"
      case symbol_kind::S_ROUNDO: // "("
      case symbol_kind::S_ROUNDC: // ")"
      case symbol_kind::S_SQUAREO: // "["
      case symbol_kind::S_SQUAREC: // "]"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_PLUSEQUAL: // "+="
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_HEXNUMBER: // HEXNUMBER
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ANY: // ANY
        value.copy< tokenizer::token > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_classdef: // classdef
      case symbol_kind::S_deleteclass: // deleteclass
      case symbol_kind::S_classbody: // classbody
      case symbol_kind::S_field: // field
      case symbol_kind::S_ident: // ident
      case symbol_kind::S_string: // string
      case symbol_kind::S_number: // number
      case symbol_kind::S_array: // array
      case symbol_kind::S_arrayvalue: // arrayvalue
      case symbol_kind::S_arrayvaluelist: // arrayvaluelist
      case symbol_kind::S_anyval: // anyval
      case symbol_kind::S_anyarr: // anyarr
      case symbol_kind::S_anyp: // anyp
      case symbol_kind::S_anyarray: // anyarray
      case symbol_kind::S_anyvalue: // anyvalue
        value.move< ::sqf::parser::config::bison::astnode > (that.value);
        break;

      case symbol_kind::S_DELETE: // "delete"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_CURLYO: // "{"
      case symbol_kind::S_CURLYC: // "}"
      case symbol_kind::S_ROUNDO: // "("
      case symbol_kind::S_ROUNDC: // ")"
      case symbol_kind::S_SQUAREO: // "["
      case symbol_kind::S_SQUAREC: // "]"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_PLUSEQUAL: // "+="
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_HEXNUMBER: // HEXNUMBER
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ANY: // ANY
        value.move< tokenizer::token > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (tokenizer));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_classdef: // classdef
      case symbol_kind::S_deleteclass: // deleteclass
      case symbol_kind::S_classbody: // classbody
      case symbol_kind::S_field: // field
      case symbol_kind::S_ident: // ident
      case symbol_kind::S_string: // string
      case symbol_kind::S_number: // number
      case symbol_kind::S_array: // array
      case symbol_kind::S_arrayvalue: // arrayvalue
      case symbol_kind::S_arrayvaluelist: // arrayvaluelist
      case symbol_kind::S_anyval: // anyval
      case symbol_kind::S_anyarr: // anyarr
      case symbol_kind::S_anyp: // anyp
      case symbol_kind::S_anyarray: // anyarray
      case symbol_kind::S_anyvalue: // anyvalue
        yylhs.value.emplace< ::sqf::parser::config::bison::astnode > ();
        break;

      case symbol_kind::S_DELETE: // "delete"
      case symbol_kind::S_CLASS: // "class"
      case symbol_kind::S_CURLYO: // "{"
      case symbol_kind::S_CURLYC: // "}"
      case symbol_kind::S_ROUNDO: // "("
      case symbol_kind::S_ROUNDC: // ")"
      case symbol_kind::S_SQUAREO: // "["
      case symbol_kind::S_SQUAREC: // "]"
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_PLUSEQUAL: // "+="
      case symbol_kind::S_EQUAL: // "="
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_HEXNUMBER: // HEXNUMBER
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_ANY: // ANY
        yylhs.value.emplace< tokenizer::token > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // start: END_OF_FILE
#line 157 "parser.y"
                                                        { result = ::sqf::parser::config::bison::astnode{}; }
#line 766 "parser.tab.cc"
    break;

  case 3: // start: statements
#line 158 "parser.y"
                                                        { result = ::sqf::parser::config::bison::astnode{}; result.append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 772 "parser.tab.cc"
    break;

  case 4: // start: separators
#line 159 "parser.y"
                                                        { result = ::sqf::parser::config::bison::astnode{}; }
#line 778 "parser.tab.cc"
    break;

  case 5: // start: separators statements
#line 160 "parser.y"
                                                        { result = ::sqf::parser::config::bison::astnode{}; result.append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 784 "parser.tab.cc"
    break;

  case 8: // statements: statement
#line 165 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::STATEMENTS }; yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 790 "parser.tab.cc"
    break;

  case 9: // statements: statements separators
#line 166 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[1].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 796 "parser.tab.cc"
    break;

  case 10: // statements: statements separators statement
#line 167 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[2].value.as < ::sqf::parser::config::bison::astnode > (); yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 802 "parser.tab.cc"
    break;

  case 11: // statement: classdef
#line 169 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[0].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 808 "parser.tab.cc"
    break;

  case 12: // statement: field
#line 170 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[0].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 814 "parser.tab.cc"
    break;

  case 13: // statement: deleteclass
#line 171 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[0].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 820 "parser.tab.cc"
    break;

  case 14: // classdef: "class" ident
#line 174 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::CLASS_DEF, yystack_[1].value.as < tokenizer::token > () }; yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 826 "parser.tab.cc"
    break;

  case 15: // classdef: "class" ident ":" ident
#line 175 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::CLASS_DEF_EXT, yystack_[3].value.as < tokenizer::token > () }; yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[2].value.as < ::sqf::parser::config::bison::astnode > ()); yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 832 "parser.tab.cc"
    break;

  case 16: // classdef: "class" ident classbody
#line 176 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::CLASS, yystack_[2].value.as < tokenizer::token > () }; yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[1].value.as < ::sqf::parser::config::bison::astnode > ()); yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 838 "parser.tab.cc"
    break;

  case 17: // classdef: "class" ident ":" ident classbody
#line 177 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::CLASS_EXT, yystack_[4].value.as < tokenizer::token > () }; yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[3].value.as < ::sqf::parser::config::bison::astnode > ()); yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[1].value.as < ::sqf::parser::config::bison::astnode > ()); yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 844 "parser.tab.cc"
    break;

  case 18: // deleteclass: "delete" ident
#line 179 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::DELETE_CLASS, yystack_[1].value.as < tokenizer::token > () }; yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 850 "parser.tab.cc"
    break;

  case 19: // classbody: "{" "}"
#line 182 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::STATEMENTS }; }
#line 856 "parser.tab.cc"
    break;

  case 20: // classbody: "{" statements "}"
#line 183 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[1].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 862 "parser.tab.cc"
    break;

  case 21: // field: ident "=" anyvalue
#line 187 "parser.y"
     {
         yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::FIELD, yystack_[1].value.as < tokenizer::token > () };
         yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[2].value.as < ::sqf::parser::config::bison::astnode > ());
         if (yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ().children.size() == 1 && yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ().children[0].kind != astkind::ANY)
         {
            yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ().children[0]);
         }
         else
         {
            yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ());
         }
     }
#line 879 "parser.tab.cc"
    break;

  case 22: // field: ident "[" "]" "=" array
#line 199 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::FIELD_ARRAY, yystack_[1].value.as < tokenizer::token > () }; yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[4].value.as < ::sqf::parser::config::bison::astnode > ()); yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 885 "parser.tab.cc"
    break;

  case 23: // field: ident "[" "]" "+=" array
#line 200 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::FIELD_ARRAY_APPEND, yystack_[1].value.as < tokenizer::token > () }; yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[4].value.as < ::sqf::parser::config::bison::astnode > ()); yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 891 "parser.tab.cc"
    break;

  case 24: // ident: IDENT
#line 203 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::IDENT, yystack_[0].value.as < tokenizer::token > () }; }
#line 897 "parser.tab.cc"
    break;

  case 25: // ident: number
#line 204 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[0].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 903 "parser.tab.cc"
    break;

  case 26: // string: STRING
#line 206 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::STRING, yystack_[0].value.as < tokenizer::token > () }; }
#line 909 "parser.tab.cc"
    break;

  case 27: // number: NUMBER
#line 208 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::NUMBER_DECIMAL, yystack_[0].value.as < tokenizer::token > () }; }
#line 915 "parser.tab.cc"
    break;

  case 28: // number: HEXNUMBER
#line 209 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::NUMBER_HEXADECIMAL, yystack_[0].value.as < tokenizer::token > () }; }
#line 921 "parser.tab.cc"
    break;

  case 29: // array: "{" "}"
#line 211 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ARRAY }; }
#line 927 "parser.tab.cc"
    break;

  case 30: // array: "{" arrayvaluelist "}"
#line 212 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[1].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 933 "parser.tab.cc"
    break;

  case 31: // arrayvalue: array
#line 214 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[0].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 939 "parser.tab.cc"
    break;

  case 32: // arrayvalue: anyarray
#line 216 "parser.y"
          {
              if (yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ().children.size() == 1 && yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ().children[0].kind != astkind::ANY)
              {
                 yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ().children[0];
              }
              else
              {
                 yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ();
              }
          }
#line 954 "parser.tab.cc"
    break;

  case 33: // arrayvaluelist: arrayvalue
#line 227 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ARRAY }; yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 960 "parser.tab.cc"
    break;

  case 34: // arrayvaluelist: arrayvaluelist "," arrayvalue
#line 228 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[2].value.as < ::sqf::parser::config::bison::astnode > (); yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 966 "parser.tab.cc"
    break;

  case 35: // anyval: anyp
#line 230 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[0].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 972 "parser.tab.cc"
    break;

  case 36: // anyval: "{"
#line 231 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANY, yystack_[0].value.as < tokenizer::token > () }; }
#line 978 "parser.tab.cc"
    break;

  case 37: // anyval: "}"
#line 232 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANY, yystack_[0].value.as < tokenizer::token > () }; }
#line 984 "parser.tab.cc"
    break;

  case 38: // anyval: ","
#line 233 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANY, yystack_[0].value.as < tokenizer::token > () }; }
#line 990 "parser.tab.cc"
    break;

  case 39: // anyarr: anyp
#line 235 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[0].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 996 "parser.tab.cc"
    break;

  case 40: // anyp: "class"
#line 237 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANY, yystack_[0].value.as < tokenizer::token > () }; }
#line 1002 "parser.tab.cc"
    break;

  case 41: // anyp: "delete"
#line 238 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANY, yystack_[0].value.as < tokenizer::token > () }; }
#line 1008 "parser.tab.cc"
    break;

  case 42: // anyp: string
#line 239 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[0].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 1014 "parser.tab.cc"
    break;

  case 43: // anyp: ident
#line 240 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[0].value.as < ::sqf::parser::config::bison::astnode > (); }
#line 1020 "parser.tab.cc"
    break;

  case 44: // anyp: "["
#line 241 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANY, yystack_[0].value.as < tokenizer::token > () }; }
#line 1026 "parser.tab.cc"
    break;

  case 45: // anyp: "]"
#line 242 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANY, yystack_[0].value.as < tokenizer::token > () }; }
#line 1032 "parser.tab.cc"
    break;

  case 46: // anyp: ":"
#line 243 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANY, yystack_[0].value.as < tokenizer::token > () }; }
#line 1038 "parser.tab.cc"
    break;

  case 47: // anyp: "="
#line 244 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANY, yystack_[0].value.as < tokenizer::token > () }; }
#line 1044 "parser.tab.cc"
    break;

  case 48: // anyp: ANY
#line 245 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANY, yystack_[0].value.as < tokenizer::token > () }; }
#line 1050 "parser.tab.cc"
    break;

  case 49: // anyarray: anyarr
#line 247 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANYSTRING }; yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 1056 "parser.tab.cc"
    break;

  case 50: // anyarray: anyarray anyarr
#line 248 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[1].value.as < ::sqf::parser::config::bison::astnode > (); yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 1062 "parser.tab.cc"
    break;

  case 51: // anyvalue: anyval
#line 250 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = ::sqf::parser::config::bison::astnode{ astkind::ANYSTRING }; yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 1068 "parser.tab.cc"
    break;

  case 52: // anyvalue: anyvalue anyval
#line 251 "parser.y"
                                                        { yylhs.value.as < ::sqf::parser::config::bison::astnode > () = yystack_[1].value.as < ::sqf::parser::config::bison::astnode > (); yylhs.value.as < ::sqf::parser::config::bison::astnode > ().append(yystack_[0].value.as < ::sqf::parser::config::bison::astnode > ()); }
#line 1074 "parser.tab.cc"
    break;


#line 1078 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -19;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      11,   -19,    41,    41,   -19,   -19,   -19,   -19,     8,    90,
      10,   -19,   -19,   -19,   -19,    -6,   -19,   -19,     1,   -19,
     -19,    10,    90,    29,    27,   106,    41,   -19,   -19,     3,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,    27,   -19,     7,    15,    36,
      36,   -19,   -19,   -19,    45,   -19,   -19,   -19,   -19,   -19,
      -2,   -19,   -19,    81,   -19,    63,   -19,   -19
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     2,     0,     0,     6,    24,    27,    28,     0,     4,
       3,     8,    11,    13,    12,     0,    25,    18,    14,     1,
       7,     5,     9,     0,     0,     0,     0,    16,    10,     0,
      41,    40,    36,    37,    44,    45,    46,    38,    47,    26,
      48,    43,    42,    51,    35,    21,    19,     0,    15,     0,
       0,    52,    20,    17,     0,    23,    22,    29,    31,    33,
       0,    49,    39,    32,    30,     0,    50,    34
  };

  const signed char
  parser::yypgoto_[] =
  {
     -19,   -19,    53,    -8,    32,   -19,   -19,    22,   -19,     0,
     -19,   -19,   -14,     6,   -19,    31,     9,   -18,   -19,   -19
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     8,    22,    10,    11,    12,    13,    27,    14,    41,
      42,    16,    58,    59,    60,    43,    61,    62,    63,    45
  };

  const signed char
  parser::yytable_[] =
  {
      15,    21,    17,    18,    23,    64,    44,    25,    19,    15,
      24,     1,    65,    26,    52,     2,     3,    47,    49,    50,
       4,    25,    15,     4,     4,    15,    48,    44,     5,     6,
       7,    30,    31,    32,    33,    55,    56,    34,    35,    36,
      29,    37,    54,    38,     5,     6,     7,    39,    40,    30,
      31,    54,    57,     9,    28,    34,    35,    36,     5,     6,
       7,    38,     5,     6,     7,    39,    40,    30,    31,    54,
      53,    67,    66,    34,    35,    36,    51,     0,     0,    38,
       5,     6,     7,    39,    40,    30,    31,     0,     0,     0,
       0,    34,    35,    36,     2,     3,     0,    38,     5,     6,
       7,    39,    40,    20,     0,     0,     0,     5,     6,     7,
       2,     3,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     9,     2,     3,    10,     7,    24,     6,     0,     9,
      16,     0,    14,    12,     7,     4,     5,    25,    15,    16,
      13,     6,    22,    13,    13,    25,    26,    45,    17,    18,
      19,     4,     5,     6,     7,    49,    50,    10,    11,    12,
      11,    14,     6,    16,    17,    18,    19,    20,    21,     4,
       5,     6,     7,     0,    22,    10,    11,    12,    17,    18,
      19,    16,    17,    18,    19,    20,    21,     4,     5,     6,
      48,    65,    63,    10,    11,    12,    45,    -1,    -1,    16,
      17,    18,    19,    20,    21,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,     4,     5,    -1,    16,    17,    18,
      19,    20,    21,    13,    -1,    -1,    -1,    17,    18,    19,
       4,     5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19
  };

  const signed char
  parser::yystos_[] =
  {
       0,     0,     4,     5,    13,    17,    18,    19,    23,    24,
      25,    26,    27,    28,    30,    31,    33,    31,    31,     0,
      13,    25,    24,    10,    16,     6,    12,    29,    26,    11,
       4,     5,     6,     7,    10,    11,    12,    14,    16,    20,
      21,    31,    32,    37,    39,    41,     7,    25,    31,    15,
      16,    37,     7,    29,     6,    34,    34,     7,    34,    35,
      36,    38,    39,    40,     7,    14,    38,    35
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    22,    23,    23,    23,    23,    24,    24,    25,    25,
      25,    26,    26,    26,    27,    27,    27,    27,    28,    29,
      29,    30,    30,    30,    31,    31,    32,    33,    33,    34,
      34,    35,    35,    36,    36,    37,    37,    37,    37,    38,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    40,
      40,    41,    41
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     1,     2,     1,     2,
       3,     1,     1,     1,     2,     4,     3,     5,     2,     2,
       3,     3,     5,     5,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "END_OF_FILE", "error", "\"invalid token\"", "INVALID", "\"delete\"",
  "\"class\"", "\"{\"", "\"}\"", "\"(\"", "\")\"", "\"[\"", "\"]\"",
  "\":\"", "\";\"", "\",\"", "\"+=\"", "\"=\"", "IDENT", "NUMBER",
  "HEXNUMBER", "STRING", "ANY", "$accept", "start", "separators",
  "statements", "statement", "classdef", "deleteclass", "classbody",
  "field", "ident", "string", "number", "array", "arrayvalue",
  "arrayvaluelist", "anyval", "anyarr", "anyp", "anyarray", "anyvalue", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   157,   157,   158,   159,   160,   162,   163,   165,   166,
     167,   169,   170,   171,   174,   175,   176,   177,   179,   182,
     183,   186,   199,   200,   203,   204,   206,   208,   209,   211,
     212,   214,   215,   227,   228,   230,   231,   232,   233,   235,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   247,
     248,   250,   251
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 9 "parser.y"
} } } } //  ::sqf::parser::config::bison 
#line 1599 "parser.tab.cc"

#line 255 "parser.y"

#ifdef __GNUG__
    #pragma GCC diagnostic pop
#endif
#ifdef _MSC_VER
    #pragma warning(pop)
#endif

#include "config_parser.hpp"
namespace sqf::parser::config::bison
{
    void parser::error(const location_type& loc, const std::string& msg)
    {
        actual.__log(logmessage::config::ParseError({ *loc.begin.filename, static_cast<size_t>(loc.begin.line), static_cast<size_t>(loc.begin.column) }, msg));
    }
    inline parser::symbol_type yylex(::sqf::parser::config::tokenizer& tokenizer)
    {
         auto token = tokenizer.next();
         parser::location_type loc;
         loc.begin.line = token.line;
         loc.begin.column = token.column;
         loc.end.line = token.line;
         loc.end.column = token.column + token.contents.length();
         loc.begin.filename = loc.end.filename = token.path;

         switch (token.type)
         {
         case tokenizer::etoken::eof: return parser::make_END_OF_FILE(loc);
         case tokenizer::etoken::invalid: return parser::make_INVALID(loc);
         case tokenizer::etoken::m_line: return yylex(tokenizer);
         case tokenizer::etoken::i_comment_line: return yylex(tokenizer);
         case tokenizer::etoken::i_comment_block: return yylex(tokenizer);
         case tokenizer::etoken::i_whitespace: return yylex(tokenizer);
         
         case tokenizer::etoken::t_class: return parser::make_CLASS(token, loc);
         case tokenizer::etoken::t_delete: return parser::make_DELETE(token, loc);

         case tokenizer::etoken::s_curlyo: return parser::make_CURLYO(token, loc);
         case tokenizer::etoken::s_curlyc: return parser::make_CURLYC(token, loc);
         case tokenizer::etoken::s_edgeo: return parser::make_SQUAREO(token, loc);
         case tokenizer::etoken::s_edgec: return parser::make_SQUAREC(token, loc);
         case tokenizer::etoken::s_colon: return parser::make_COLON(token, loc);
         case tokenizer::etoken::s_semicolon: return parser::make_SEMICOLON(token, loc);
         case tokenizer::etoken::s_comma: return parser::make_COMMA(token, loc);
         case tokenizer::etoken::t_ident: return parser::make_IDENT(token, loc);

         case tokenizer::etoken::t_string_double: return parser::make_STRING(token, loc);
         case tokenizer::etoken::t_string_single: return parser::make_STRING(token, loc);
         case tokenizer::etoken::t_number: return parser::make_NUMBER(token, loc);
         case tokenizer::etoken::t_hexadecimal: return parser::make_HEXNUMBER(token, loc);
         case tokenizer::etoken::t_plus_equal: return parser::make_PLUSEQUAL(token, loc);
         case tokenizer::etoken::s_equal: return parser::make_EQUAL(token, loc);
         case tokenizer::etoken::any: return parser::make_ANY(token, loc);
         default:
             return parser::make_ANY(token, loc);
         }
     }
}
