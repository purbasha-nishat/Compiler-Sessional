%option noyywrap

%x MULTILINESTATE

%x SINGLELINE

%x STRINGSTATE

%{
#include<bits/stdc++.h>
#include "1705067_ST.cpp"
#include "y.tab.h"
using namespace std;

extern YYSTYPE yylval;
extern SymbolTable *table;
extern ofstream logout;
extern ofstream errorfile;
extern int line_count;
extern int error_calc;
void yyerror(char *);


int error_count = 0;
int error_line;



%}

WHITESPACE [ \t\f\r\v]+ 
SPECIALCHAR ((\\n)|(\\a)|(\\t)|(\\b)|(\\v)|(\\r)|(\\f)|(\\0)|(\\\\)|(\\\')|(\\\"))
LETTER [a-zA-Z]
DIGIT [0-9]
NEWLINE (\r)?(\n)
FLOAT {DIGIT}*(\.{DIGIT}*)?([Ee][+-]?{DIGIT}+)?
INTEGER {DIGIT}+
ID ({LETTER}|[_])({LETTER}|{DIGIT}|[_])*
DECIMALPOINTERROR {DIGIT}*(\.{DIGIT}*)+([Ee][+-]?([\.]*{DIGIT}*)*)*
ILLFORMERROR {DIGIT}*(\.{DIGIT}*)?([Ee][+-]?([\.]*{DIGIT}*)*)*
MULTICHARACTER (\')([^\'\n]|{SPECIALCHAR}){2,}(\')
EMPTYCHARACTER (\')(\')
UNFINISHEDCHARACTER (\')(([^\'\n])*|{SPECIALCHAR}*)({NEWLINE})
INVALIDPREFIXSUFFIX {DIGIT}*(\.{DIGIT}*)?([Ee][+-]?{DIGIT}+)?(({LETTER}|[_])({LETTER}|{DIGIT}|[_])*)+


%%

{WHITESPACE} {}

{NEWLINE} {line_count++;}

{EMPTYCHARACTER} {
			/*
			logout<<"Error at line no "<< line_count<< ": Empty character constant error "<< yytext<<endl;
			logout<<endl;
			error_count++;
			*/
		}
		

(\")	{
		/*
		str1 = yytext;
		str2 = yytext;
		error_line = line_count;
		BEGIN STRINGSTATE;
		*/
	}


<STRINGSTATE>{SPECIALCHAR}	{
			/*
			char c;
			string str;
			str = yytext;
			if(str.compare("\\t")==0)
				 c = '\t';
			else if(str.compare("\\n")==0)
				 c = '\n';
			else if(str.compare("\\a")==0)
				 c = '\a';
			else if(str.compare("\\f")==0)
				 c = '\f';
			else if(str.compare("\\r")==0)
				 c = '\r';
			else if(str.compare("\\b")==0)
				 c = '\b';
			else if(str.compare("\\v")==0)
				 c = '\v';
			else if(str.compare("\\0")==0)
				 c = '\n';
			else if(str.compare("\\\\")==0)
				 c = '\\';
			else if(str.compare("\\\'")==0)
				 c = '\'';
			else if(str.compare("\\\"")==0)
				 c = '\"';
			str1 = str1 + c;
			str2 = str2 + yytext; 
			*/
		}
		
<STRINGSTATE>{NEWLINE} { 
		/*
		line_count++;
		logout<<"Error at line no "<< error_line << ": Unterminated String "<< str2 <<endl;
		logout<<endl;
		error_count++;
		BEGIN INITIAL;
		*/
		
	}
<STRINGSTATE><<EOF>>  { 
		/*
		logout<<"Error at line no "<< error_line << ": Unterminated String "<< str2 <<endl;
		logout<<endl;
		error_count++;
		BEGIN INITIAL;
		*/
		
	}
	
<STRINGSTATE>((\\){NEWLINE})	{ 
		/*
		line_count++;
		str2 = str2 + yytext;
		*/
	}


<STRINGSTATE>(\") { 
		/*
		str1 = str1 + yytext;
		str2 = str2 + yytext;
		tokenout<<"<STRING, "<<str1<<"> ";
		logout<<"Line no "<< error_line <<": Token <STRING> Lexeme "<< str2<<" found"<<" --> <STRING, "<<str1<<"> "<<endl;
		logout<<endl;
		BEGIN INITIAL;
		*/
			
	}
<STRINGSTATE>. { 
		/*
		str1 = str1 + yytext;
		str2 = str2 + yytext;
		*/
	}

(\/\*)	{	
		/*
		str3 = yytext;
		error_line = line_count;
		BEGIN MULTILINESTATE;
		*/
	}


<MULTILINESTATE>{NEWLINE} {
		/*
		str3 = str3 + yytext;
		line_count++;
		*/
		}

<MULTILINESTATE>(\*\/)	{
		/*
		str3 = str3 + yytext;
		logout<<"Line no "<< error_line <<": Token <COMMENT> Lexeme "<< str3<<" found"<<endl;
		logout<<endl;
		BEGIN INITIAL;
		*/
	}

<MULTILINESTATE><<EOF>> {
		/*
		logout<<"Error at line no "<< error_line << ": Unterminated Comment "<< str3 <<endl;
		logout<<endl;
		error_count++;
		BEGIN INITIAL;
		*/
		}	

<MULTILINESTATE>. {
		//str3 = str3 + yytext;
		}
	
(\/\/)	{
			
	//	logout<<"Line no "<< line_count<< ": Token <COMMENT> Lexeme ";
	//	logout<<yytext;
		BEGIN SINGLELINE;
		
	}


<SINGLELINE>((\\){NEWLINE})	{
			
		//	logout<<yytext;
			line_count++;
			BEGIN SINGLELINE;
			
		}

<SINGLELINE>{NEWLINE}	{
				
		//	logout<<" found"<<endl;
		//	logout<<endl;
			line_count++;
			BEGIN INITIAL;
			
		}

<SINGLELINE><<EOF>>	{
				
		//	logout<<" found"<<endl;
		//	logout<<endl;
			BEGIN INITIAL;
			
		}

<SINGLELINE>.	{
			//logout<<yytext;
		}


"if"	{	
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("IF");
			yylval.si = s;
			return IF;
			
		}
		
"else"	{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("ELSE");
			yylval.si = s;
			return ELSE;	
		}
"for"	{	
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("FOR");
			yylval.si = s;
			return FOR;
			
		}

"while" {
		 	SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("WHILE");
			yylval.si = s;
			return WHILE;	
		}

"int"	{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("INT");
			yylval.si = s;
			return INT;
		}

"float" {
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("FLOAT");
			yylval.si = s;
			return FLOAT;
		}

"void"	{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("VOID");
			yylval.si = s;
			return VOID;
		}
"return" {
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("RETURN");
			yylval.si = s;
			return RETURN;
		}

"printf" {
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("PRINTLN");
			yylval.si = s;
			return PRINTLN;
		}
{ID}		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("ID");
			yylval.si = s;
			return ID;
			
		}
		
{INTEGER} 	{		
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("CONST_INT");
			yylval.si = s;
			return CONST_INT;	
		}

{FLOAT}	{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("CONST_FLOAT");
			yylval.si = s;
			return CONST_FLOAT;

		}

{ILLFORMERROR} {
			/*
			logout<<"Error at line no "<< line_count<< ": Ill formed number "<< yytext<<endl;
			logout<<endl;
			error_count++;
			*/
	
 		}
		
{DECIMALPOINTERROR} {
			/*
			logout<<"Error at line no "<< line_count<< ": Too many decimal points "<< yytext<<endl;
			logout<<endl;
			error_count++;
			*/

                }


{INVALIDPREFIXSUFFIX} {
			/*
			logout<<"Error at line no "<< line_count<< ": Invalid prefix on ID or invalid suffix on Number "<< yytext<<endl;
			logout<<endl;
			error_count++;
			*/
		}		


"*"		|
"/"		|

"%"		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("MULOP");
			yylval.si = s;
			return MULOP;
		}
"++"		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("INCOP");
			yylval.si = s;
			return INCOP;
		}

"--"		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("DECOP");
			yylval.si = s;
			return DECOP;
		}
"+"		|

"-"		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("ADDOP");
			yylval.si = s;
			return ADDOP;
		} 

		

"<=" 		|
">="		|
"<"		|
">"		|
"=="		|
"!="		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("RELOP");
			yylval.si = s;
			return RELOP;
		} 		

"="		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("ASSIGNOP");
			yylval.si = s;
			return ASSIGNOP;
		} 
		
"&&"		|
"||"		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("LOGICOP");
			yylval.si = s;
			return LOGICOP;
		} 

"!"		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("NOT");
			yylval.si = s;
			return NOT;
		} 

"("		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("LPAREN");
			yylval.si = s;
			return LPAREN;
		} 

")"		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("RPAREN");
			yylval.si = s;
			return RPAREN;
		} 

"{"		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("LCURL");
			yylval.si = s;
			return LCURL;
			
		} 

"}"		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("RCURL");
			yylval.si = s;
			return RCURL;
		} 

"["		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("LTHIRD");
			yylval.si = s;
			return LTHIRD;
		}

"]"		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("RTHIRD");
			yylval.si = s;
			return RTHIRD;
		} 

","		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("COMMA");
			yylval.si = s;
			return COMMA;
		} 

";"		{
			SymbolInfo *s = new SymbolInfo();
			s->setName(yytext);
        		s->setType("SEMICOLON");
			yylval.si = s;
			return SEMICOLON;
		} 



(\')([^\n\a\f\r\b\v\0\\\\\\\'\\\"])(\') {
			/*
			tokenout<<"<CONST_CHAR, "<<yytext[1]<<"> ";
			logout<<"Line no "<< line_count<< ": Token <CONST_CHAR> Lexeme "<< yytext<<" found"<<" --> <CONST_CHAR, "<<yytext[1]<<"> "<<endl;
			logout<<endl;
			t = sb.insert(yytext,"CONST_CHAR");
			if(t)
				sb.PrintAll();
			*/
		}


(\'){SPECIALCHAR}(\')	{
			/*
			char c;
			string str;
			str = yytext;
			if(str.compare("\'\\t\'")==0)
				 c = '\t';
			else if(str.compare("\'\\n\'")==0)
				 c = '\n';
			else if(str.compare("\'\\a\'")==0)
				 c = '\a';
			else if(str.compare("\'\\f\'")==0)
				 c = '\f';
			else if(str.compare("\'\\r\'")==0)
				 c = '\r';
			else if(str.compare("\'\\b\'")==0)
				 c = '\b';
			else if(str.compare("\'\\v\'")==0)
				 c = '\v';
			else if(str.compare("\'\\0\'")==0)
				 c = '\n';
			else if(str.compare("\'\\\\\'")==0)
				 c = '\\';
			else if(str.compare("\'\\\'\'")==0)
				 c = '\'';
			else if(str.compare("\'\\\"\'")==0)
				 c = '\"';	
			tokenout<<"<CONST_CHAR, "<<c<<"> ";
			logout<<"Line no "<< line_count<< ": Token <CONST_CHAR> Lexeme "<< yytext<<" found"<<" --> <CONST_CHAR, "<<c<<"> "<<endl;;
			logout<<endl;
			t = sb.insert(yytext,"CONST_CHAR");
			if(t)
				sb.PrintAll();		
			*/
		}


{MULTICHARACTER} {
			/*
			logout<<"Error at line no "<< line_count<< ": Multi character constant error "<< yytext<<endl;
			logout<<endl;
			error_count++;
			*/
		}
{UNFINISHEDCHARACTER}	{
			/*
			logout<<"Error at line no "<< line_count<< ": Unterminated character "<< yytext<<endl;
			line_count++;
			error_count++;
			*/
		}		

[\a\b\0] {}

.	{       /*
		logout<<"Error at line no "<< line_count<< ": Unrecognized character "<< yytext<<endl;
		logout<<endl;
		error_count++;
		*/
	}


<<EOF>> { 
		
		return 0;
	}


%%

