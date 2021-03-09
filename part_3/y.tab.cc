// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

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


// First part of user declarations.
#line 3 "862012666-862083506.y" // lalr1.cc:404

#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<utility>
#include "y.tab.hh"
	
	void yyerror(const char *msg);
	extern int currLine;
	extern int currPos;
	FILE * yyin;
	
	std::map<std::string, std::pair<std::string, unsigned>> symbols;
	
	std::string make_label() {
		static unsigned count;
		std::ostringstream s;
		s << "l" << count << std::endl;
		count++;
		return s.str();
	}
	std::string make_temp() {
		static unsigned count;
		std::ostringstream s;
		s << "t" << count << std::endl;
		count++;
		return s.str();
	}

#line 69 "y.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "y.tab.hh"

// User implementation prologue.

#line 83 "y.tab.cc" // lalr1.cc:412


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



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 150 "y.tab.cc" // lalr1.cc:479

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
        std::string yyr = "";
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
              // Fall through.
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


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
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

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 155 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Statement).IR = (yystack_[0].value.Statement).IR;
		}
#line 615 "y.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 159 "862012666-862083506.y" // lalr1.cc:859
    {

			  }
#line 623 "y.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 162 "862012666-862083506.y" // lalr1.cc:859
    {
				std::ostringstream s;
				s << (yystack_[1].value.Statement).IR << std::endl;
				s << (yystack_[0].value.Statement).IR << std::endl;
				(yylhs.value.Statement).IR = s.str();
			}
#line 634 "y.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 179 "862012666-862083506.y" // lalr1.cc:859
    {
		
			std::stringstream s;
			s << (yystack_[10].value.Identifier).identifier << std::endl;
			
			s << (yystack_[7].value.DeclarationBlock).IR << std::endl;
			
			s << (yystack_[4].value.DeclarationBlock).IR << std::endl;
			
			s << (yystack_[1].value.Statement).IR<< std::endl;
			
			
			
			//Free the symbols and temps
			
			s << "endfunc" << std::endl;
			
			(yylhs.value.Statement).IR = s.str();
		}
#line 658 "y.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 200 "862012666-862083506.y" // lalr1.cc:859
    {}
#line 664 "y.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 201 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.DeclarationBlock).IR = (yystack_[0].value.DeclarationBlock).IR;
			(yylhs.value.DeclarationBlock).variables = (yystack_[0].value.DeclarationBlock).IR;
		}
#line 673 "y.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 207 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.DeclarationBlock).IR = (yystack_[1].value.Declaration).IR;
			for(unsigned i = 0; i < (yystack_[1].value.Declaration).identifiers.size(); i++) {
				(yylhs.value.DeclarationBlock).variables.push_back(make_tuple((yystack_[1].value.Declaration).identifiers[i], (yystack_[1].value.Declaration).type, (yystack_[1].value.Declaration).size));
			}
		}
#line 684 "y.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 213 "862012666-862083506.y" // lalr1.cc:859
    {
			std::stringstream s;
			s << (yystack_[2].value.Declaration).IR;
			s << (yystack_[0].value.DeclarationBlock).IR;
			(yylhs.value.DeclarationBlock).IR = s.str();
			
			(yylhs.value.DeclarationBlock).variables = (yystack_[2].value.Declaration).variables;
			
			for(unsigned i = 0; i < (yystack_[2].value.Declaration).identifiers.size(); i++) {
				(yylhs.value.DeclarationBlock).variables.push_back(make_tuple((yystack_[2].value.Declaration).identifiers[i], (yystack_[2].value.Declaration).type, (yystack_[2].value.Declaration).size));
			}
		}
#line 701 "y.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 227 "862012666-862083506.y" // lalr1.cc:859
    {}
#line 707 "y.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 228 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Statement).IR = (yystack_[0].value.Statement).IR;
		}
#line 715 "y.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 233 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Statement).IR = (yystack_[1].value.Statement).IR;
		}
#line 723 "y.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 236 "862012666-862083506.y" // lalr1.cc:859
    {
			std::stringstream s;
			s << (yystack_[2].value.Statement).IR;
			s << (yystack_[0].value.Statement).IR;
			(yylhs.value.Statement).IR = s.str();
		}
#line 734 "y.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 244 "862012666-862083506.y" // lalr1.cc:859
    {
		
				(yylhs.value.Declaration).identifiers = (yystack_[2].value.IdentifierBlock).identifiers;
				(yylhs.value.Declaration).type = (yystack_[0].value.DeclarationType).type;
				(yylhs.value.Declaration).size = (yystack_[0].value.DeclarationType).size;
				
				std::stringstream s;
				if((yylhs.value.Declaration).size > 0) {
					for(unsigned i = 0; i < (yylhs.value.Declaration).identifiers.size(); i++) {
						std::string identifier = (yylhs.value.Declaration).identifiers[i];
						
						//Check if already in symbol table
						
						//Make a temp
						std::string temp = make_temp();
						s << ". " << temp << std::endl;
						
						//Add to symbol table
						
						//Make sure to free the symbol table entry and temp
					}
				} else {
					for(unsigned i = 0; i < (yylhs.value.Declaration).identifiers.size(); i++) {
						std::string identifier = (yylhs.value.Declaration).identifiers[i];
						
						//Check if already in symbol table
						
						//Make a temp
						std::string temp = make_temp();
						s << ".[] " << temp << ", " << (yystack_[0].value.DeclarationType).size << std::endl;
						
						//Add to symbol table
						
						//Make sure to free the symbol table entry and temp
					}
				}
				(yylhs.value.Declaration).IR = s.str();
		}
#line 777 "y.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 284 "862012666-862083506.y" // lalr1.cc:859
    {
				(yylhs.value.DeclarationType).type = "integer";
				(yylhs.value.DeclarationType).size = 0;
		}
#line 786 "y.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 288 "862012666-862083506.y" // lalr1.cc:859
    {
				(yylhs.value.DeclarationType).type = "integer";
				(yylhs.value.DeclarationType).size = atoi((yystack_[3].value.dval));
		}
#line 795 "y.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 294 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.IdentifierBlock).identifiers.push_back((yystack_[0].value.Identifier));
		}
#line 803 "y.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 297 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.IdentifierBlock).identifiers = (yystack_[0].value.IdentifierBlock).identifiers;
			(yylhs.value.IdentifierBlock).identifiers.push_back((yystack_[2].value.Identifier));
		}
#line 812 "y.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 303 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Identifier).identifier = (yystack_[0].value.ident);
		}
#line 820 "y.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 308 "862012666-862083506.y" // lalr1.cc:859
    {
			std::stringstream s;
			
			//Lookup from symbol table
			std::string temp = lookup((yystack_[2].value.Var).identifier);
			
			unsigned index = (yystack_[2].value.Var).index;
			if(index != -1) {
				s << "=[] " << temp << ", " << (yystack_[0].value.Expression).ret_name << ", " << index << std::endl;
			} else {
				s << "= " << temp << ", " << (yystack_[0].value.Expression).ret_name << std::endl;
			}
			(yylhs.value.Statement).IR = s.str();
		}
#line 839 "y.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 322 "862012666-862083506.y" // lalr1.cc:859
    {
			//TO DO: Make sure $ entries are properly indexed
			//Remove $0
			
			std::string label0 = make_label();
			std::string label1 = make_label();
			std::stringstream s;
			
			//Condition
			s << (yystack_[3].value.Expression).IR;
			//Jump into branch
			s << "?:=" << label0 << ", " << (yystack_[3].value.Expression).ret_name << std::endl;
			
			//Skip branch
			s << ":= " << label1 << std::endl;
			
			//Branch
			s << ":" << label0 << std::endl;
			s << (yystack_[1].value.Statement).IR;
			
			//Finally
			s << ": " << label1 << std::endl;
			
			(yylhs.value.Statement).IR = s.str();
		}
#line 869 "y.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 347 "862012666-862083506.y" // lalr1.cc:859
    {
			std::string label0 = make_label();
			std::string label1 = make_label();
			std::string label2 = make_label();
			std::stringstream s;
			
			//Condition
			s << (yystack_[5].value.Expression).IR;
			//Jump into branch
			s << "?:=" << label0 << ", " << (yystack_[5].value.Expression).ret_name << std::endl;
			
			//Jump into else
			s << ":= " << label1 << std::endl;
			
			//Branch
			s << ":" << label0 << std::endl;
			s << (yystack_[3].value.Statement).IR;
			
			//Jump to finally
			s << ":= " << label2 << std::endl;
			
			//Else
			s << ": " << label1 << std::endl;
			
			//Finally
			s << ": " << label2 << std::endl;
			s << (yystack_[1].value.Statement).IR;
			(yylhs.value.Statement).IR = s.str();
			
		}
#line 904 "y.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 377 "862012666-862083506.y" // lalr1.cc:859
    {
			std::string label_body = make_label();
			std::string label_condition = make_label();
			
			std::ostringstream s;
			s << ":= " << label_condition << std::endl;
			s << ": " << label_body << std::endl; 
			s << (yystack_[1].value.Statement).IR << std::endl;
			s << ": " << label_condition << std::endl;
			s << (yystack_[3].value.Expression).IR << std::endl;
			s << "?:= " << label_body << (yystack_[3].value.Expression).ret_name << std::endl;
			
			(yylhs.value.Statement).IR = s.str();
		}
#line 923 "y.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 391 "862012666-862083506.y" // lalr1.cc:859
    {
			std::string label_body = make_label();
			std::string label_condition = make_label();
			
			std::ostringstream s;
			s << ": " << label_body << std::endl; 
			s << (yystack_[3].value.Statement).IR << std::endl;
			s << ": " << label_condition << std::endl;
			s << (yystack_[0].value.Expression).IR << std::endl;
			s << "?:= " << label_body << (yystack_[0].value.Expression).ret_name << std::endl;
			
			(yylhs.value.Statement).IR = s.str();
		}
#line 941 "y.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 404 "862012666-862083506.y" // lalr1.cc:859
    {
			std::stringstream s;
			for(unsigned i = 0; i < (yystack_[0].value.VarBlock).variables.size(); i++) {
				auto var = (yystack_[0].value.VarBlock).variables[i];
				if(var.second == "") {
					s << ".< " << var.first << std::endl;
				} else {
					s << ".[]< " << var.first << ", " << var.second << std::endl;
				}
			}
			(yylhs.value.Statement).IR = s.str();
		}
#line 958 "y.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 416 "862012666-862083506.y" // lalr1.cc:859
    {
			std::stringstream s;
			for(unsigned i = 0; i < (yystack_[0].value.VarBlock).variables.size(); i++) {
				auto var = (yystack_[0].value.VarBlock).variables[i];
				if(var.second == "") {
					s << ".> " << var.first << std::endl;
				} else {
					s << ".[]> " << var.first << ", " << var.second << std::endl;
				}
			}
			(yylhs.value.Statement).IR = s.str();
		}
#line 975 "y.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 428 "862012666-862083506.y" // lalr1.cc:859
    {
	  
		}
#line 983 "y.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 431 "862012666-862083506.y" // lalr1.cc:859
    {
			std::stringstream s;
			s << "ret " << (yystack_[0].value.Expression).ret_name << std::endl;
			(yylhs.value.Statement).IR = s.str();
		}
#line 993 "y.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 438 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Expression).IR = (yystack_[0].value.Expression).IR;
			(yylhs.value.Expression).ret_name = (yystack_[0].value.Expression).ret_name;
		}
#line 1002 "y.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 442 "862012666-862083506.y" // lalr1.cc:859
    {
			std::string temp = make_temp();
	  
			std::ostringstream s;
			s << (yystack_[2].value.Expression).IR << std::endl;
			s << (yystack_[0].value.Expression).IR << std::endl;
			s << "|| " << temp << ", " << (yystack_[2].value.Expression).ret_name << ", " << (yystack_[0].value.Expression).ret_name << std::endl;
			(yylhs.value.Expression).IR = s.str();
			(yylhs.value.Expression).ret_name = temp;
		}
#line 1017 "y.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 454 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Expression).IR = (yystack_[0].value.Expression).IR;
			(yylhs.value.Expression).ret_name = (yystack_[0].value.Expression).ret_name;
		}
#line 1026 "y.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 458 "862012666-862083506.y" // lalr1.cc:859
    {
			std::string temp = make_temp();
	  
			std::ostringstream s;
			s << (yystack_[2].value.Expression).IR << std::endl;
			s << (yystack_[0].value.Expression).IR << std::endl;
			s << "&& " << temp << ", " << (yystack_[2].value.Expression).ret_name << ", " << (yystack_[0].value.Expression).ret_name << std::endl;
			(yylhs.value.Expression).IR = s.str();
			(yylhs.value.Expression).ret_name = temp;
		}
#line 1041 "y.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 470 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Expression).IR = (yystack_[0].value.Expression).IR;
			(yylhs.value.Expression).ret_name = (yystack_[0].value.Expression).ret_name;
		}
#line 1050 "y.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 474 "862012666-862083506.y" // lalr1.cc:859
    {
			std::string temp = make_temp();
	  
			std::ostringstream s;
			s << (yystack_[0].value.Expression).IR << std::endl;
			s << "! " << temp << ", " << (yystack_[0].value.Expression).ret_name << std::endl;
			(yylhs.value.Expression).IR = s.str();
			(yylhs.value.Expression).ret_name = temp;
	  }
#line 1064 "y.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 485 "862012666-862083506.y" // lalr1.cc:859
    {
			std::string temp = make_temp();
	  
			std::ostringstream s;
			s << (yystack_[2].value.Expression).IR << std::endl;
			s << (yystack_[0].value.Expression).IR << std::endl;
			s << (yystack_[1].value.Operator).op << temp << ", " << (yystack_[2].value.Expression).ret_name << ", " << (yystack_[0].value.Expression).ret_name << std::endl;
			(yylhs.value.Expression).IR = s.str();
			(yylhs.value.Expression).ret_name = temp;
		}
#line 1079 "y.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 495 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Expression).ret_name = "true";
		}
#line 1087 "y.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 498 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Expression).ret_name = "false";
		}
#line 1095 "y.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 501 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Expression).IR = (yystack_[1].value.Expression).IR;
			(yylhs.value.Expression).ret_name = (yystack_[1].value.Expression).ret_name;
		}
#line 1104 "y.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 507 "862012666-862083506.y" // lalr1.cc:859
    { (yylhs.value.Operator).op = "=="; }
#line 1110 "y.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 508 "862012666-862083506.y" // lalr1.cc:859
    { (yylhs.value.Operator).op = "!="; }
#line 1116 "y.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 509 "862012666-862083506.y" // lalr1.cc:859
    { (yylhs.value.Operator).op = "<"; }
#line 1122 "y.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 510 "862012666-862083506.y" // lalr1.cc:859
    { (yylhs.value.Operator).op = ">"; }
#line 1128 "y.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 511 "862012666-862083506.y" // lalr1.cc:859
    { (yylhs.value.Operator).op = "<="; }
#line 1134 "y.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 512 "862012666-862083506.y" // lalr1.cc:859
    { (yylhs.value.Operator).op = ">="; }
#line 1140 "y.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 515 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Expression).IR = (yystack_[0].value.Expression).IR;
			(yylhs.value.Expression).ret_name = (yystack_[0].value.Expression).ret_name;
		}
#line 1149 "y.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 519 "862012666-862083506.y" // lalr1.cc:859
    { 
			std::ostringstream s;
			s << (yystack_[2].value.Expression).IR << std::endl;
			s << (yystack_[0].value.Expression).IR << std::endl;
			
			std::string temp = make_temp();
			s << "+ " << temp << ", " << (yystack_[2].value.Expression).ret_name << ", " << (yystack_[0].value.Expression).ret_name << std::endl;
			
			(yylhs.value.Expression).IR = s.str();
			(yylhs.value.Expression).ret_name = temp;
		}
#line 1165 "y.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 530 "862012666-862083506.y" // lalr1.cc:859
    {
			std::ostringstream s;
			s << (yystack_[2].value.Expression).IR << std::endl;
			s << (yystack_[0].value.Expression).IR << std::endl;
			
			std::string temp = make_temp();
			s << "- " << temp << ", " << (yystack_[2].value.Expression).ret_name << ", " << (yystack_[0].value.Expression).ret_name << std::endl;
			
			(yylhs.value.Expression).IR = s.str();
			(yylhs.value.Expression).ret_name = temp;
		}
#line 1181 "y.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 543 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Expression).IR = (yystack_[0].value.Expression).IR;
			(yylhs.value.Expression).ret_name = (yystack_[0].value.Expression).ret_name;
		}
#line 1190 "y.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 547 "862012666-862083506.y" // lalr1.cc:859
    {
			std::ostringstream s;
			s << (yystack_[2].value.Expression).IR << std::endl;
			s << (yystack_[0].value.Expression).IR << std::endl;
			
			std::string temp = make_temp();
			s << "* " << temp << ", " << (yystack_[2].value.Expression).ret_name << ", " << (yystack_[0].value.Expression).ret_name << std::endl;
			
			(yylhs.value.Expression).IR = s.str();
			(yylhs.value.Expression).ret_name = temp;
		}
#line 1206 "y.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 558 "862012666-862083506.y" // lalr1.cc:859
    {
			std::ostringstream s;
			s << (yystack_[2].value.Expression).IR << std::endl;
			s << (yystack_[0].value.Expression).IR << std::endl;
			
			std::string temp = make_temp();
			s << "/ " << temp << ", " << (yystack_[2].value.Expression).ret_name << ", " << (yystack_[0].value.Expression).ret_name << std::endl;
			
			(yylhs.value.Expression).IR = s.str();
			(yylhs.value.Expression).ret_name = temp;
		}
#line 1222 "y.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 569 "862012666-862083506.y" // lalr1.cc:859
    {
			std::ostringstream s;
			s << (yystack_[2].value.Expression).IR << std::endl;
			s << (yystack_[0].value.Expression).IR << std::endl;
			
			std::string temp = make_temp();
			s << "% " << temp << ", " << (yystack_[2].value.Expression).ret_name << ", " << (yystack_[0].value.Expression).ret_name << std::endl;
			
			(yylhs.value.Expression).IR = s.str();
			(yylhs.value.Expression).ret_name = temp;
		}
#line 1238 "y.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 582 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Expression).IR = (yystack_[0].value.Expression).IR;
			(yylhs.value.Expression).ret_name = (yystack_[0].value.Expression).ret_name;
		}
#line 1247 "y.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 586 "862012666-862083506.y" // lalr1.cc:859
    {
			std::string temp = make_temp();
			
			std::ostringstream s;
			s << (yystack_[0].value.Expression).IR << std::endl;
			s << "- " << temp << ", 0, " << (yystack_[0].value.Expression).ret_name;
			
			(yylhs.value.Expression).IR = s.str();
			(yylhs.value.Expression).ret_name = temp;
		}
#line 1262 "y.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 596 "862012666-862083506.y" // lalr1.cc:859
    {
			std::ostringstream s;
			for(const auto& e : (yystack_[1].value.ExpressionBlock).expressions) {
				s << e.IR << std::endl;
			}
			for(const auto& e : (yystack_[1].value.ExpressionBlock).expressions) {
				s << "param " << e.ret_name << std::endl;
			}
			std::string temp = make_temp();
			s << "call " << (yystack_[3].value.ident) << ", " << temp << std::endl;
			
			(yylhs.value.Expression).IR = s.str();
			(yylhs.value.Expression).ret_name = temp;
		}
#line 1281 "y.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 612 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Expression).ret_name = (yystack_[0].value.dval);
		}
#line 1289 "y.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 615 "862012666-862083506.y" // lalr1.cc:859
    {
			if((yystack_[0].value.Var).index != (unsigned)-1) {
				std::string temp = make_temp();
				std::ostringstream s;
				s << "=[] " << temp << ", " << (yystack_[0].value.Var).identifier << ", " << (yystack_[0].value.Var).index;
				(yylhs.value.Expression).IR = s.str();
				(yylhs.value.Expression).ret_name = temp;
			} else {
				(yylhs.value.Expression).ret_name = (yystack_[0].value.Var).ret_name;
			}
		}
#line 1305 "y.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 626 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.Expression).IR = (yystack_[1].value.Expression).IR;
			(yylhs.value.Expression).ret_name = (yystack_[1].value.Expression).ret_name;
		}
#line 1314 "y.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 632 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.ExpressionBlock).expressions.push_back((yystack_[0].value.Expression));
		}
#line 1322 "y.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 635 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.ExpressionBlock).expressions = (yystack_[0].value.ExpressionBlock).expressions;
			(yylhs.value.ExpressionBlock).expressions.push_back((yystack_[2].value.Expression));
		}
#line 1331 "y.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 641 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.VarBlock).variables.push_back(make_pair((yystack_[0].value.Var).identifier, (yystack_[0].value.Var).index));
		}
#line 1339 "y.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 644 "862012666-862083506.y" // lalr1.cc:859
    {
			(yylhs.value.VarBlock).variables = (yystack_[0].value.VarBlock).variables;
			(yylhs.value.VarBlock).variables.push_back(make_pair((yystack_[2].value.Var).identifier, (yystack_[2].value.Var).index));
		}
#line 1348 "y.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 650 "862012666-862083506.y" // lalr1.cc:859
    {
			auto pair = symbols.find((yystack_[0].value.Identifier));
			if(pair != symbols.end()) {
				(yylhs.value.Var).identifier = pair.second;
			} else {
				throw exception("invalid symbol");
			}
		}
#line 1361 "y.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 658 "862012666-862083506.y" // lalr1.cc:859
    {
			auto pair = symbols.find((yystack_[3].value.Identifier));
			if(pair != symbols.end()) {
				(yylhs.value.Var).identifier = pair.second;
			} else {
				throw exception("invalid symbol");
			}
			
			(yylhs.value.Var).index = (yystack_[1].value.Expression).ret_name;
		}
#line 1376 "y.tab.cc" // lalr1.cc:859
    break;


#line 1380 "y.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

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
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -62;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
       7,   -34,    18,   -62,     7,   -62,    -4,   -62,   -62,     8,
     -34,    14,   -62,    16,     4,    13,    28,   -34,   -10,   -34,
     -34,   -62,     3,   -62,   -62,   -62,    30,     1,    40,    31,
      12,    58,    27,    53,    27,    67,   -62,   -34,   -34,    59,
     -62,    39,    61,    74,    78,    27,   -62,   -62,    42,    64,
     -62,   -12,    95,    63,    65,   -62,    77,   -28,    48,   -62,
     -62,    53,   -62,   101,    12,   -62,    87,   -62,   -62,    53,
      12,    53,   -62,    73,    24,   -62,    53,   -62,    12,    27,
      27,   -62,   -62,   -62,   -62,   -62,   -62,    53,    53,    53,
      53,    53,    53,    76,    12,   106,   -34,    79,   -62,   -62,
     -62,   -62,    93,    80,    36,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   108,   114,   -62,   -62,    53,   -62,    12,
     -62,   -62,    27,   -62,   116,   -62,   -62
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     0,     2,     3,    19,     0,     1,     4,     0,
       6,     0,     7,     0,     0,    17,     0,     8,     0,     0,
       6,     9,     0,    15,    14,    18,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,    27,     0,     0,     0,
      11,    62,     0,     0,     0,     0,    36,    37,     0,    19,
      55,     0,     0,    29,    31,    33,     0,    45,    48,    52,
      56,     0,    28,     0,     0,    25,    60,    26,     5,     0,
      12,     0,    16,     0,     0,    34,     0,    53,     0,     0,
       0,    43,    44,    41,    42,    39,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    20,
      38,    57,    58,     0,     0,    30,    32,    35,    47,    46,
      49,    50,    51,     0,     0,    61,    63,     0,    54,     0,
      21,    23,     0,    59,     0,    24,    22
  };

  const signed char
  parser::yypgoto_[] =
  {
     -62,   -62,   121,   -62,   107,   109,   -62,   -61,   -62,   -62,
     110,    10,   -62,   -32,    50,   -62,    83,   -62,   -19,     5,
     -62,    81,    11,   -37,   -30
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    11,    12,    39,    40,    13,    24,
      14,    41,    42,    52,    53,    54,    55,    87,    56,    57,
      58,    59,   103,    65,    60
  };

  const unsigned char
  parser::yytable_[] =
  {
      43,    67,    63,    95,    22,    88,    89,    66,    66,    98,
       1,     6,    23,    73,    62,     5,    32,   104,     7,    33,
      15,    34,    35,     9,    10,    36,    74,    15,    61,    15,
      15,    16,    18,   113,    43,    37,    38,     5,    50,    19,
      43,   119,    93,    17,   120,    27,    20,   105,    43,    28,
      97,    29,    99,    81,    82,    83,    84,   102,   124,   115,
      30,     5,    85,    86,    43,   101,    66,    45,   107,   108,
     109,    46,    47,    44,    31,    48,    49,    50,    64,    51,
      68,    69,    45,    90,    91,    92,    46,    47,    70,    43,
     125,    49,    50,    61,    51,   110,   111,   112,   102,    71,
      72,    78,    49,    50,    76,    51,    81,    82,    83,    84,
      79,    80,    94,    96,   100,    85,    86,   101,   114,   117,
     121,   118,   116,   122,   126,     8,    21,    26,   123,    25,
     106,    75,    77
  };

  const unsigned char
  parser::yycheck_[] =
  {
      30,    38,    34,    64,    14,    33,    34,    37,    38,    70,
       3,     1,    22,    45,    33,    49,     4,    78,     0,     7,
      10,     9,    10,    27,    16,    13,    45,    17,    40,    19,
      20,    17,    28,    94,    64,    23,    24,    49,    50,    26,
      70,     5,    61,    27,     8,    42,    18,    79,    78,    19,
      69,    50,    71,    29,    30,    31,    32,    76,   119,    96,
      20,    49,    38,    39,    94,    41,    96,    40,    87,    88,
      89,    44,    45,    15,    43,    48,    49,    50,    11,    52,
      21,    42,    40,    35,    36,    37,    44,    45,    27,   119,
     122,    49,    50,    40,    52,    90,    91,    92,   117,    25,
      22,     6,    49,    50,    40,    52,    29,    30,    31,    32,
      47,    46,    11,    26,    41,    38,    39,    41,    12,    26,
      12,    41,    43,     9,     8,     4,    17,    20,   117,    19,
      80,    48,    51
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    55,    56,    57,    49,    65,     0,    56,    27,
      16,    58,    59,    62,    64,    65,    17,    27,    28,    26,
      18,    59,    14,    22,    63,    64,    58,    42,    19,    50,
      20,    43,     4,     7,     9,    10,    13,    23,    24,    60,
      61,    65,    66,    78,    15,    40,    44,    45,    48,    49,
      50,    52,    67,    68,    69,    70,    72,    73,    74,    75,
      78,    40,    72,    67,    11,    77,    78,    77,    21,    42,
      27,    25,    22,    67,    72,    70,    40,    75,     6,    47,
      46,    29,    30,    31,    32,    38,    39,    71,    33,    34,
      35,    36,    37,    72,    11,    61,    26,    72,    61,    72,
      41,    41,    72,    76,    61,    67,    68,    72,    72,    72,
      73,    73,    73,    61,    12,    77,    43,    26,    41,     5,
       8,    12,     9,    76,    61,    67,     8
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    54,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    63,    63,    64,    64,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    73,    73,
      73,    73,    74,    74,    74,    75,    75,    75,    76,    76,
      77,    77,    78,    78
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,    12,     0,     1,     2,     3,
       0,     1,     2,     3,     3,     1,     6,     1,     3,     1,
       3,     5,     7,     5,     6,     2,     2,     1,     2,     1,
       3,     1,     3,     1,     2,     3,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     4,     1,     1,     3,     1,     3,
       1,     3,     1,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "FUNCTION", "IF", "ELSE", "THEN",
  "RETURN", "ENDIF", "WHILE", "DO", "BEGINLOOP", "ENDLOOP", "BREAK",
  "ARRAY", "OF", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS",
  "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER", "READ", "WRITE",
  "ASSIGN", "COMMA", "SEMICOLON", "COLON", "LTE", "GTE", "LT", "GT", "SUB",
  "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "L_PAREN", "R_PAREN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "TRUE", "FALSE", "AND", "OR",
  "NOT", "IDENT", "NUMBER", "PLUS", "MINUS", "UMINUS", "$accept",
  "program", "function-block", "function", "declaration-block-optional",
  "declaration-block", "statement-block-optional", "statement-block",
  "declaration", "declaration-type", "identifier-block", "identifier",
  "statement", "bool-expr", "relation-and-expr", "relation-expr",
  "relation-expr-body", "comp", "expression", "multiplicative-expr",
  "term", "term-body", "expression-block", "var-block", "var", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   155,   155,   159,   162,   170,   200,   201,   207,   213,
     227,   228,   233,   236,   244,   284,   288,   294,   297,   303,
     308,   322,   347,   377,   391,   404,   416,   428,   431,   438,
     442,   454,   458,   470,   474,   485,   495,   498,   501,   507,
     508,   509,   510,   511,   512,   515,   519,   530,   543,   547,
     558,   569,   582,   586,   596,   612,   615,   626,   632,   635,
     641,   644,   650,   658
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
    };
    const unsigned int user_token_number_max_ = 308;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1885 "y.tab.cc" // lalr1.cc:1167
#line 669 "862012666-862083506.y" // lalr1.cc:1168


int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
   yyparse(); // Calls yylex() for tokens.
   return 0;
}

void yyerror(const char *msg) {
   printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}
