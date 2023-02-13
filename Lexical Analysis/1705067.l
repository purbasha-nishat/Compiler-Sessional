%option noyywrap

%x MULTILINESTATE

%x SINGLELINE

%x STRINGSTATE

%{
#include<bits/stdc++.h>
#include "1705067_ST.cpp"
using namespace std;


int line_count=1;
int error_count = 0;
int error_line;
SymbolTable sb(7);

string str1="";
string str2="";
string str3="";
bool t;
ofstream tokenout;


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
			logout<<"Error at line no "<< line_count<< ": Empty character constant error "<< yytext<<endl;
			logout<<endl;
			error_count++;
		}
		

(\")	{

		str1 = yytext;
		str2 = yytext;
		error_line = line_count;
		BEGIN STRINGSTATE;
	}


<STRINGSTATE>{SPECIALCHAR}	{
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
		}
		
<STRINGSTATE>{NEWLINE} { 
		line_count++;
		logout<<"Error at line no "<< error_line << ": Unterminated String "<< str2 <<endl;
		logout<<endl;
		error_count++;
		BEGIN INITIAL;
		
	}
<STRINGSTATE><<EOF>>  { 
		logout<<"Error at line no "<< error_line << ": Unterminated String "<< str2 <<endl;
		logout<<endl;
		error_count++;
		BEGIN INITIAL;
		
	}
	
<STRINGSTATE>((\\){NEWLINE})	{ 
		line_count++;
		str2 = str2 + yytext;
	}


<STRINGSTATE>(\") { 
		str1 = str1 + yytext;
		str2 = str2 + yytext;
		tokenout<<"<STRING, "<<str1<<"> ";
		logout<<"Line no "<< error_line <<": Token <STRING> Lexeme "<< str2<<" found"<<" --> <STRING, "<<str1<<"> "<<endl;
		logout<<endl;
		BEGIN INITIAL;
			
	}
<STRINGSTATE>. { 
		str1 = str1 + yytext;
		str2 = str2 + yytext;
	}

(\/\*)	{
		str3 = yytext;
		error_line = line_count;
		BEGIN MULTILINESTATE;
	}


<MULTILINESTATE>{NEWLINE} {
		str3 = str3 + yytext;
		line_count++;
		}

<MULTILINESTATE>(\*\/)	{
		str3 = str3 + yytext;
		logout<<"Line no "<< error_line <<": Token <COMMENT> Lexeme "<< str3<<" found"<<endl;
		logout<<endl;
		BEGIN INITIAL;
	}

<MULTILINESTATE><<EOF>> {
		logout<<"Error at line no "<< error_line << ": Unterminated Comment "<< str3 <<endl;
		logout<<endl;
		error_count++;
		BEGIN INITIAL;
		}	

<MULTILINESTATE>. {str3 = str3 + yytext;}
	
(\/\/)	{	logout<<"Line no "<< line_count<< ": Token <COMMENT> Lexeme ";
		logout<<yytext;
		BEGIN SINGLELINE;
	}


<SINGLELINE>((\\){NEWLINE})	{
			logout<<yytext;
			line_count++;
			BEGIN SINGLELINE;
		}

<SINGLELINE>{NEWLINE}	{	
			logout<<" found"<<endl;
			logout<<endl;
			line_count++;
			BEGIN INITIAL;
		}

<SINGLELINE><<EOF>>	{	
			logout<<" found"<<endl;
			logout<<endl;
			BEGIN INITIAL;
		}

<SINGLELINE>.	{
			logout<<yytext;
		}


"if"	{
			tokenout<<"<IF> ";
			logout<<"Line no "<< line_count<< ": Token <IF> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
		
"else"	{
			tokenout<<"<ELSE> ";
			logout<<"Line no "<< line_count<< ": Token <ELSE> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"for"	{
			tokenout<<"<FOR> ";
			logout<<"Line no "<< line_count<< ": Token <FOR> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}

"while" {
			tokenout<<"<WHILE> ";
			logout<<"Line no "<< line_count<< ": Token <WHILE> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"do"	{
			tokenout<<"<DO> ";
			logout<<"Line no "<< line_count<< ": Token <DO> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"break" {
			tokenout<<"<BREAK> ";
			logout<<"Line no "<< line_count<< ": Token <BREAK> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"int"	{
			tokenout<<"<INT> ";
			logout<<"Line no "<< line_count<< ": Token <INT> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"char"	{
			tokenout<<"<CHAR> ";
			logout<<"Line no "<< line_count<< ": Token <CHAR> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"float" {
			tokenout<<"<FLOAT> ";
			logout<<"Line no "<< line_count<< ": Token <FLOAT> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"double" {
			tokenout<<"<DOUBLE> ";
			logout<<"Line no "<< line_count<< ": Token <DOUBLE> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"void"	{
			tokenout<<"<VOID> ";
			logout<<"Line no "<< line_count<< ": Token <VOID> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"return" {
			tokenout<<"<RETURN> ";
			logout<<"Line no "<< line_count<< ": Token <RETURN> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"switch" {
			tokenout<<"<SWITCH> ";
			logout<<"Line no "<< line_count<< ": Token <SWITCH> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"case"	{
			tokenout<<"<CASE> ";
			logout<<"Line no "<< line_count<< ": Token <CASE> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"default" {
			tokenout<<"<DEFAULT> ";
			logout<<"Line no "<< line_count<< ": Token <DEFAULT> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"continue" {
			tokenout<<"<CONTINUE> ";
			logout<<"Line no "<< line_count<< ": Token <CONTINUE> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}

{INTEGER} 	{		
				tokenout<<"<CONST_INT, "<<yytext<<"> ";
			 	logout<<"Line no "<< line_count<< ": Token <CONST_INT> Lexeme "<< yytext<<" found"<<endl;
			 	logout<<endl;
				t = sb.insert(yytext,"CONST_INT");
				if(t)
					sb.PrintAll();
		}

{FLOAT}	{
			tokenout<<"<CONST_FLOAT, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <CONST_FLOAT> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
			t = sb.insert(yytext,"CONST_FLOAT");
			if(t)
				sb.PrintAll();

		}

{ILLFORMERROR} {
			logout<<"Error at line no "<< line_count<< ": Ill formed number "<< yytext<<endl;
			logout<<endl;
			error_count++;
	
 		}
		
{DECIMALPOINTERROR} {
			logout<<"Error at line no "<< line_count<< ": Too many decimal points "<< yytext<<endl;
			logout<<endl;
			error_count++;

                }

{ID}		{
			tokenout<<"<ID, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <ID> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
			t = sb.insert(yytext,"ID");
			if(t)
				sb.PrintAll();
			
		}

{INVALIDPREFIXSUFFIX} {
			logout<<"Error at line no "<< line_count<< ": Invalid prefix on ID or invalid suffix on Number "<< yytext<<endl;
			logout<<endl;
			error_count++;
		}		


"*"		|
"/"		|

"%"		{
			tokenout<<"<MULOP, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <MULOP> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"++"		|

"--"		{
			tokenout<<"<INCOP, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <INCOP> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}
"+"		|

"-"		{
			tokenout<<"<ADDOP, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <ADDOP> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		} 

		

"<=" 		|
">="		|
"<"		|
">"		|
"=="		|
"!="		{
			tokenout<<"<RELOP, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <RELOP> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		} 		

"="		{
			tokenout<<"<ASSIGNOP, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <ASSIGNOP> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		} 
		
"&&"		|
"||"		{
			tokenout<<"<LOGICOP, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <LOGICOP> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		} 

"!"		{
			tokenout<<"<NOT, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <NOT> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		} 

"("		{
			tokenout<<"<LPAREN, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <LPAREN> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		} 

")"		{
			tokenout<<"<RPAREN, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <RPAREN> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		} 

"{"		{
			tokenout<<"<LCURL, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <LCURL> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
			sb.enterScope();
			
		} 

"}"		{
			tokenout<<"<RCURL, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <RCURL> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
			sb.exitScope();
		} 

"["		{
			tokenout<<"<LTHIRD, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <LTHIRD> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		}

"]"		{
			tokenout<<"<RTHIRD, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <RTHIRD> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		} 

","		{
			tokenout<<"<COMMA, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <COMMA> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		} 

";"		{
			tokenout<<"<SEMICOLON, "<<yytext<<"> ";
			logout<<"Line no "<< line_count<< ": Token <SEMICOLON> Lexeme "<< yytext<<" found"<<endl;
			logout<<endl;
		} 



(\')([^\n\a\f\r\b\v\0\\\\\\\'\\\"])(\') {
			tokenout<<"<CONST_CHAR, "<<yytext[1]<<"> ";
			logout<<"Line no "<< line_count<< ": Token <CONST_CHAR> Lexeme "<< yytext<<" found"<<" --> <CONST_CHAR, "<<yytext[1]<<"> "<<endl;
			logout<<endl;
			t = sb.insert(yytext,"CONST_CHAR");
			if(t)
				sb.PrintAll();
		}


(\'){SPECIALCHAR}(\')	{
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
			
		}


{MULTICHARACTER} {
			logout<<"Error at line no "<< line_count<< ": Multi character constant error "<< yytext<<endl;
			logout<<endl;
			error_count++;
		}
{UNFINISHEDCHARACTER}	{
			logout<<"Error at line no "<< line_count<< ": Unterminated character "<< yytext<<endl;
			line_count++;
			error_count++;
		}		

[\a\b\0] {}

.	{
		logout<<"Error at line no "<< line_count<< ": Unrecognized character "<< yytext<<endl;
		logout<<endl;
		error_count++;
	}

<<EOF>> { 
		sb.PrintAll();
		logout<<"Total Lines: "<<line_count<<endl;
		logout<<"Total Errors: "<<error_count<<endl;
		return 0;
	}


%%



int main(int argc,char *argv[]){
	
	if(argc!=2){
		cout<<"Please provide input file name and try again"<<endl;
		return 0;
	}
	
	FILE *file=fopen(argv[1],"r");
	if(file==NULL){
		cout<<"Cannot open specified file"<<endl;
		return 0;
	}
	tokenout.open("1705067_token.txt");
	logout<<endl;
	yyin= file;
	yylex();
	fclose(yyin);
	logout.close();
	tokenout.close();
	return 0;
}
