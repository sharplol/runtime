// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.tab.hh
 ** Define the  ::sqf::parser::config::bison ::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 33 "parser.y"

    #ifdef __GNUG__
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wall"
    #endif
    #ifdef _MSC_VER
        #pragma warning(push, 0)
    #endif
     namespace sqf::runtime
     {
          class runtime;
     }
     namespace sqf::parser::config
     {
          class parser;
     }
     namespace sqf::parser::config::bison
     {
        enum class astkind
        {
            ENDOFFILE = -3,
            INVALID = -2,
            __TOKEN = -1,
            NA = 0,
            STATEMENTS,
            CLASS_DEF,
            CLASS_DEF_EXT,
            CLASS,
            CLASS_EXT,
            DELETE_CLASS,
            FIELD,
            FIELD_ARRAY,
            FIELD_ARRAY_APPEND,
            NUMBER_DECIMAL,
            NUMBER_HEXADECIMAL,
            STRING,
            IDENT,
            ARRAY,
            ANYSTRING,
            ANY
        };
        struct astnode
        {
            ::sqf::parser::config::tokenizer::token token;
            astkind kind;
            std::vector<astnode> children;

            astnode() : token(), kind(astkind::NA) { }
            astnode(astkind kind) : token(), kind(kind) { }
            astnode(::sqf::parser::config::tokenizer::token t) : token(t), kind(astkind::__TOKEN) { }
            astnode(astkind kind, ::sqf::parser::config::tokenizer::token t) : token(t), kind(kind) { }

            void append(astnode node)
            {
                children.push_back(node);
            }
            void append_children(const astnode& other)
            { 
                for (auto node : other.children)
                {
                    append(node); 
                } 
            }
        };
     }

#line 116 "parser.tab.hh"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 9 "parser.y"
namespace sqf { namespace parser { namespace config { namespace bison  {
#line 246 "parser.tab.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // statements
      // statement
      // classdef
      // deleteclass
      // classbody
      // field
      // ident
      // string
      // number
      // array
      // arrayvalue
      // arrayvaluelist
      // anyval
      // anyarr
      // anyp
      // anyarray
      // anyvalue
      char dummy1[sizeof (::sqf::parser::config::bison::astnode)];

      // "delete"
      // "class"
      // "{"
      // "}"
      // "("
      // ")"
      // "["
      // "]"
      // ":"
      // ";"
      // ","
      // "+="
      // "="
      // IDENT
      // NUMBER
      // HEXNUMBER
      // STRING
      // ANY
      char dummy2[sizeof (tokenizer::token)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END_OF_FILE = 0,               // END_OF_FILE
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    INVALID = 258,                 // INVALID
    DELETE = 259,                  // "delete"
    CLASS = 260,                   // "class"
    CURLYO = 261,                  // "{"
    CURLYC = 262,                  // "}"
    ROUNDO = 263,                  // "("
    ROUNDC = 264,                  // ")"
    SQUAREO = 265,                 // "["
    SQUAREC = 266,                 // "]"
    COLON = 267,                   // ":"
    SEMICOLON = 268,               // ";"
    COMMA = 269,                   // ","
    PLUSEQUAL = 270,               // "+="
    EQUAL = 271,                   // "="
    IDENT = 272,                   // IDENT
    NUMBER = 273,                  // NUMBER
    HEXNUMBER = 274,               // HEXNUMBER
    STRING = 275,                  // STRING
    ANY = 276                      // ANY
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 22, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // END_OF_FILE
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_INVALID = 3,                           // INVALID
        S_DELETE = 4,                            // "delete"
        S_CLASS = 5,                             // "class"
        S_CURLYO = 6,                            // "{"
        S_CURLYC = 7,                            // "}"
        S_ROUNDO = 8,                            // "("
        S_ROUNDC = 9,                            // ")"
        S_SQUAREO = 10,                          // "["
        S_SQUAREC = 11,                          // "]"
        S_COLON = 12,                            // ":"
        S_SEMICOLON = 13,                        // ";"
        S_COMMA = 14,                            // ","
        S_PLUSEQUAL = 15,                        // "+="
        S_EQUAL = 16,                            // "="
        S_IDENT = 17,                            // IDENT
        S_NUMBER = 18,                           // NUMBER
        S_HEXNUMBER = 19,                        // HEXNUMBER
        S_STRING = 20,                           // STRING
        S_ANY = 21,                              // ANY
        S_YYACCEPT = 22,                         // $accept
        S_start = 23,                            // start
        S_separators = 24,                       // separators
        S_statements = 25,                       // statements
        S_statement = 26,                        // statement
        S_classdef = 27,                         // classdef
        S_deleteclass = 28,                      // deleteclass
        S_classbody = 29,                        // classbody
        S_field = 30,                            // field
        S_ident = 31,                            // ident
        S_string = 32,                           // string
        S_number = 33,                           // number
        S_array = 34,                            // array
        S_arrayvalue = 35,                       // arrayvalue
        S_arrayvaluelist = 36,                   // arrayvaluelist
        S_anyval = 37,                           // anyval
        S_anyarr = 38,                           // anyarr
        S_anyp = 39,                             // anyp
        S_anyarray = 40,                         // anyarray
        S_anyvalue = 41                          // anyvalue
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
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
        value.move< ::sqf::parser::config::bison::astnode > (std::move (that.value));
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
        value.move< tokenizer::token > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ::sqf::parser::config::bison::astnode&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ::sqf::parser::config::bison::astnode& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, tokenizer::token&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const tokenizer::token& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
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
        value.template destroy< ::sqf::parser::config::bison::astnode > ();
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
        value.template destroy< tokenizer::token > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, tokenizer::token v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const tokenizer::token& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    parser (::sqf::parser::config::tokenizer &tokenizer_yyarg, ::sqf::parser::config::bison::astnode& result_yyarg, ::sqf::parser::config::parser& actual_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_OF_FILE (location_type l)
      {
        return symbol_type (token::END_OF_FILE, std::move (l));
      }
#else
      static
      symbol_type
      make_END_OF_FILE (const location_type& l)
      {
        return symbol_type (token::END_OF_FILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INVALID (location_type l)
      {
        return symbol_type (token::INVALID, std::move (l));
      }
#else
      static
      symbol_type
      make_INVALID (const location_type& l)
      {
        return symbol_type (token::INVALID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DELETE (tokenizer::token v, location_type l)
      {
        return symbol_type (token::DELETE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DELETE (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::DELETE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (tokenizer::token v, location_type l)
      {
        return symbol_type (token::CLASS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CLASS (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::CLASS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CURLYO (tokenizer::token v, location_type l)
      {
        return symbol_type (token::CURLYO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CURLYO (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::CURLYO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CURLYC (tokenizer::token v, location_type l)
      {
        return symbol_type (token::CURLYC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CURLYC (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::CURLYC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ROUNDO (tokenizer::token v, location_type l)
      {
        return symbol_type (token::ROUNDO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ROUNDO (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::ROUNDO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ROUNDC (tokenizer::token v, location_type l)
      {
        return symbol_type (token::ROUNDC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ROUNDC (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::ROUNDC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SQUAREO (tokenizer::token v, location_type l)
      {
        return symbol_type (token::SQUAREO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SQUAREO (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::SQUAREO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SQUAREC (tokenizer::token v, location_type l)
      {
        return symbol_type (token::SQUAREC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SQUAREC (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::SQUAREC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (tokenizer::token v, location_type l)
      {
        return symbol_type (token::COLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::COLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (tokenizer::token v, location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::SEMICOLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (tokenizer::token v, location_type l)
      {
        return symbol_type (token::COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUSEQUAL (tokenizer::token v, location_type l)
      {
        return symbol_type (token::PLUSEQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PLUSEQUAL (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::PLUSEQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (tokenizer::token v, location_type l)
      {
        return symbol_type (token::EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENT (tokenizer::token v, location_type l)
      {
        return symbol_type (token::IDENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENT (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::IDENT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (tokenizer::token v, location_type l)
      {
        return symbol_type (token::NUMBER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::NUMBER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HEXNUMBER (tokenizer::token v, location_type l)
      {
        return symbol_type (token::HEXNUMBER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HEXNUMBER (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::HEXNUMBER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (tokenizer::token v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANY (tokenizer::token v, location_type l)
      {
        return symbol_type (token::ANY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ANY (const tokenizer::token& v, const location_type& l)
      {
        return symbol_type (token::ANY, v, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const { return yyla_; }
      symbol_kind_type token () const { return yyla_.kind (); }
      const location_type& location () const { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 125,     ///< Last index in yytable_.
      yynnts_ = 20,  ///< Number of nonterminal symbols.
      yyfinal_ = 19 ///< Termination state number.
    };


    // User arguments.
    ::sqf::parser::config::tokenizer &tokenizer;
    ::sqf::parser::config::bison::astnode& result;
    ::sqf::parser::config::parser& actual;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
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
      15,    16,    17,    18,    19,    20,    21
    };
    // Last valid token kind.
    const int code_max = 276;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
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
        value.copy< ::sqf::parser::config::bison::astnode > (YY_MOVE (that.value));
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
        value.copy< tokenizer::token > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
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
        value.move< ::sqf::parser::config::bison::astnode > (YY_MOVE (s.value));
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
        value.move< tokenizer::token > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

#line 9 "parser.y"
} } } } //  ::sqf::parser::config::bison 
#line 1849 "parser.tab.hh"


// "%code provides" blocks.
#line 24 "parser.y"

    #ifdef __GNUG__
        #pragma GCC diagnostic pop
    #endif
    #ifdef _MSC_VER
        #pragma warning(pop)
    #endif

#line 1862 "parser.tab.hh"


#endif // !YY_YY_PARSER_TAB_HH_INCLUDED
