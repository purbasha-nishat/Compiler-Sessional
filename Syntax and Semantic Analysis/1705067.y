%{
#include<bits/stdc++.h>
#include "1705067_ST.cpp"
using namespace std;



int yyparse(void);
int yylex(void);
extern FILE *yyin;

int line_count=1;
int error_calc=0;
ofstream logout;
ofstream errorfile;
vector<SymbolInfo*> parameter;
SymbolTable *table = new SymbolTable(30,logout);


void yyerror(char *s)
{
	logout<<"Syntax error at line no: "<< line_count<<endl;
}


%}

%union{
	int ival;
	SymbolInfo* si;
	vector<SymbolInfo*>* vs;
}


%token <si> IF FOR WHILE INT FLOAT VOID RETURN CONST_INT CONST_FLOAT ID MULOP INCOP DECOP ADDOP RELOP ASSIGNOP LOGICOP NOT 
%token <si> LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON PRINTLN

%type <vs> declaration_list var_declaration unit program start parameter_list func_declaration func_definition variable factor expression_statement expression 
%type <vs> term simple_expression rel_expression unary_expression statement statements compound_statement logic_expression argument_list arguments

%type <si> type_specifier

%nonassoc <si> LOWER_THAN_ELSE
%nonassoc <si> ELSE

%%


start : program
	{
		logout<<"Line "<< line_count<<": start : program "<<endl;
		logout<<endl;
		table->PrintAll(logout);
		errorfile<<"Total error: "<<error_calc<<endl;

		logout<<"Total lines: "<<line_count<<endl;
		logout<<"Total errors: "<<error_calc<<endl;
		
	}
	;

program : program unit{
		int i;
		logout<<"Line "<< line_count<<": program : program unit "<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for( i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
			
		}

		for( i = 0; i < $2->size(); i++){
			$$->push_back($2->at(i));
			logout<<$2->at(i)->getName();
		}
		logout<<endl;

		}
	| unit {
		logout<< "Line "<< line_count<<": program : unit "<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		
		}
	;
	
unit : var_declaration {
		logout<< "Line "<< line_count<<": unit : var_declaration"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
     | func_declaration{
		logout<< "Line "<< line_count<<": unit : func_declaration"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
     | func_definition{
		logout<< "Line "<< line_count<<": unit : func_definition"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		}
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON{
  			
			int i;
			SymbolInfo *sym = new SymbolInfo();
			SymbolInfo *temp = new SymbolInfo();
			temp = table->lookup($2->getName());
			if(temp == NULL){
				sym->setName($2->getName());
				sym->setType($2->getType());
				string iden = $1->getName();
				iden.pop_back();
				sym->setIdentity(iden);
				sym->setFunction(1);

				for(i = 0; i < $4->size(); i++){
					sym->pushParam($4->at(i));
				}
				
				table->insert(sym);
			}
			else{
				errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
				error_calc++;
			}
			
			
			logout<<"Line "<< line_count<<": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			$$->push_back($1);
			logout<<$1->getName();

			$$->push_back($2);
			logout<<$2->getName();

			$$->push_back($3);
			logout<<$3->getName();

			for(i = 0; i < $4->size(); i++){
				$$->push_back($4->at(i));
				logout<<$4->at(i)->getName();
			}

			$$->push_back($5);
			logout<<$5->getName();
			
			$6->setName($6->getName()+"\n");
			$$->push_back($6);
			logout<<$6->getName()<<endl;
			logout<<endl;
			table->enterScope(logout);
			table->exitScope(logout);
		   	}
		| type_specifier ID LPAREN RPAREN SEMICOLON{

			SymbolInfo *sym = new SymbolInfo();
			SymbolInfo *temp = new SymbolInfo();
			temp = table->lookup($2->getName());
			if(temp == NULL){
				sym->setName($2->getName());
				sym->setType($2->getType());
				string iden = $1->getName();
				iden.pop_back();
				sym->setIdentity(iden);
				sym->setFunction(1);
				table->insert(sym);
			}
			else{
				errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
				error_calc++;
			}
			
			

			logout<<"Line "<< line_count<<": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			$$->push_back($1);
			logout<<$1->getName();

			$$->push_back($2);
			logout<<$2->getName();

			$$->push_back($3);
			logout<<$3->getName();
			
			$$->push_back($4);
			logout<<$4->getName();
			
			$5->setName($5->getName()+"\n");
			$$->push_back($5);
			logout<<$5->getName()<<endl;
			logout<<endl;
			table->enterScope(logout);
			table->exitScope(logout);
		   	}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN 
	{ 
		int i;
		bool match = true;
		bool found;
		SymbolInfo *temp = new SymbolInfo();
		SymbolInfo *sym = new SymbolInfo();
		temp = table->lookup($2->getName());
		string iden = $1->getName();
		iden.pop_back();
		if(temp == NULL){
			
			sym->setName($2->getName());
			sym->setType($2->getType());
			string iden = $1->getName();
			iden.pop_back();
			sym->setIdentity(iden);
			sym->setFunction(1);
			sym->setDefined(1);
			for( i = 0; i < $4->size(); i++){
				sym->pushParam($4->at(i));
			}
			table->insert(sym);
		}
		else{
			if(temp->getFunction() == 0){
				errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
				error_calc++;
			}
			else {
				if(temp->getDefined() == 1){
					errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
					error_calc++;
				}
				else{
					$2->setIdentity(temp->getIdentity());
					$2->setFunction(1);
					$2->setDefined(1);
					for( i = 0; i < temp->returnVector().size(); i++){
						$2->pushParam(temp->returnVector().at(i));
					}
					found = table->remove(temp->getName());
					if(found){
						table->insert($2);
					}
					
					
					if(temp->getIdentity() != iden){
						errorfile<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<$2->getName()<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<$2->getName()<<endl<<endl;
						error_calc++;
					}

					if($4->size() == temp->returnVector().size()){
						for( i = 0; i < temp->returnVector().size(); i++){
						}
						for( i = 0; i < temp->returnVector().size(); i++){
							if($4->at(i)->getName() != temp->returnVector().at(i)->getName()){
								errorfile<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<$2->getName()<<endl<<endl;
								logout<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<$2->getName()<<endl<<endl;
								error_calc++;
								break;
							}
						}
					}
					else{
						errorfile<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<$2->getName()<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<$2->getName()<<endl<<endl;
						error_calc++;
					}
					
				}
					
			}
		}
		
		for(i = 0; i < $4->size(); i++){
			if($4->at(i)->getType() == "ID"){
				iden = $4->at(i-1)->getName();
				iden.pop_back();
				$4->at(i)->setIdentity(iden);
				parameter.push_back($4->at(i));
			}
		}
		logout<<endl;
		
	} 
	compound_statement
	{
		int i;
		logout<<"Line "<< line_count<<": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		$$->push_back($1);
		logout<<$1->getName();

		$$->push_back($2);
		logout<<$2->getName();

		$$->push_back($3);
		logout<<$3->getName();
		for(i = 0; i < $4->size(); i++){
			$$->push_back($4->at(i));
			logout<<$4->at(i)->getName();
			
		}
		$$->push_back($5);
		logout<<$5->getName();
		
		for(i = 0; i < $7->size(); i++){
			$$->push_back($7->at(i));
			logout<<$7->at(i)->getName();
			
		}
		logout<<endl;
	}
	| type_specifier ID LPAREN RPAREN 
		{ 
			SymbolInfo *temp = new SymbolInfo();;
			SymbolInfo *sym = new SymbolInfo();
			temp = table->lookup($2->getName());
			string iden = $1->getName();
			iden.pop_back();
			if(temp == NULL){
				sym->setName($2->getName());
				sym->setType($2->getType());
				
				sym->setIdentity(iden);
				sym->setFunction(1);
				sym->setDefined(1);
				table->insert(sym);
			}
			else{
				if(temp->getFunction() == 0){
					errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
					error_calc++;
				}
				else{
					if(temp->getDefined() == 1){
						errorfile<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Multiple declaration of "<<$2->getName()<<endl<<endl;
						error_calc++;
					}
					else{
						$2->setIdentity(temp->getIdentity());
						$2->setFunction(1);
						$2->setDefined(1);
						table->remove(temp->getName());
						table->insert($2);

						if(temp->getIdentity() != iden){
							errorfile<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<$2->getName()<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<$2->getName()<<endl<<endl;
							error_calc++;
						}
					}
				}
				
			}
			
		} 
		compound_statement
		{
			logout<<endl;

			int i;
			logout<<"Line "<< line_count<<": func_definition : type_specifier ID LPAREN RPAREN compound_statement"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			$$->push_back($1);
			logout<<$1->getName();

			$$->push_back($2);
			logout<<$2->getName();

			$$->push_back($3);
			logout<<$3->getName();
			
			$$->push_back($4);
			logout<<$4->getName();

			for(i = 0; i < $6->size(); i++){
				$$->push_back($6->at(i));
				logout<<$6->at(i)->getName();
		
			}
			logout<<endl;
		   	}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID{
			int i;
			$$ = new vector<SymbolInfo*>();
			bool error_count = false;
			for( i = 0; i < $1->size(); i++){
				if($1->at(i)->getType() == "Error"){
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					$$->push_back(point);
				}
			}
			if(error_count == false && $3->getType() == "VOID"){
				errorfile<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
			
			SymbolInfo *temp = new SymbolInfo();
			for(i = 0; i < $1->size(); i++){
				if($1->at(i)->getType() == "ID" && $1->at(i)->getName() == $4->getName() && error_count == false){
					errorfile<<"Error at line "<<line_count<<": Multiple Declaration of "<<$4->getName()<<" in parameter"<<endl<<endl;
				 	logout<<"Error at line "<<line_count<<": Multiple Declaration of "<<$4->getName()<<" in parameter"<<endl<<endl;
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					$$->push_back(point);
					break;
				}
			}
			
			logout<<"Line "<< line_count<<": parameter_list  : parameter_list COMMA type_specifier ID"<<endl;
			logout<<endl;
			

			for(i = 0; i < $1->size(); i++){
				$$->push_back($1->at(i));
				logout<<$1->at(i)->getName();
			}

			$$->push_back($2);
			logout<<$2->getName();

			$$->push_back($3);
			logout<<$3->getName();
			
			$$->push_back($4);
			logout<<$4->getName()<<endl;
			logout<<endl;
		   	}
		| parameter_list COMMA type_specifier{
			int i;
			$$ = new vector<SymbolInfo*>();
			bool error_count = false;
			for( i = 0; i < $1->size(); i++){
				if($1->at(i)->getType() == "Error"){
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					$$->push_back(point);
				}
			}
			if(error_count == false && $3->getType() == "VOID"){
				errorfile<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
			logout<<"Line "<< line_count<<": parameter_list  : parameter_list COMMA type_specifier"<<endl;
			logout<<endl;

			for(i = 0; i < $1->size(); i++){
				$$->push_back($1->at(i));
				logout<<$1->at(i)->getName();
			}

			$$->push_back($2);
			logout<<$2->getName();

			$$->push_back($3);
			logout<<$3->getName()<<endl;
			logout<<endl;
		   	}
 		| type_specifier ID{
			$$ = new vector<SymbolInfo*>();
			bool error_count = false;
			
			if(error_count == false && $1->getType() == "VOID"){
				errorfile<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
			logout<<"Line "<< line_count<<": parameter_list  : type_specifier ID"<<endl;
			logout<<endl;

			$$->push_back($1);
			logout<<$1->getName();

			$$->push_back($2);
			logout<<$2->getName()<<endl;
			logout<<endl;
		   	}
		| type_specifier{
			$$ = new vector<SymbolInfo*>();
			bool error_count = false;
			
			if(error_count == false && $1->getType() == "VOID"){
				errorfile<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Parameter type cannot be void "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
			logout<<"Line "<< line_count<<": parameter_list  : type_specifier"<<endl;
			logout<<endl;

			$$->push_back($1);
			logout<<$1->getName()<<endl;
			logout<<endl;
		   	}
 		;

 		
compound_statement : LCURL
			{
				int i;
				table->enterScope(logout); 
				if(parameter.size() != 0){
					for(i = 0; i < parameter.size(); i++){
						table->insert(parameter.at(i));
					}
					logout<<endl;
				}
				parameter.clear();
				
			}
			 statements RCURL{
			logout<<"Line "<< line_count<<": compound_statement : LCURL statements RCURL"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			$1->setName($1->getName()+"\n");
			$$->push_back($1);
			logout<<$1->getName()<<endl;

			for(int i = 0; i < $3->size(); i++){
				$$->push_back($3->at(i));
				logout<<$3->at(i)->getName();
			}

			$4->setName($4->getName()+"\n");
			$$->push_back($4);
			logout<<$4->getName()<<endl;
			logout<<endl;

			table->PrintAll(logout);
			table->exitScope(logout);

		   	}
 		    | LCURL 
			{
				int i;
				table->enterScope(logout); 
				if(parameter.size() != 0){
					for(i = 0; i < parameter.size(); i++){
						table->insert(parameter.at(i));
					}
					logout<<endl;
				}
				parameter.clear();
				
			}
			 RCURL{
			logout<<"Line "<< line_count<<": compound_statement : LCURL RCURL"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			$1->setName($1->getName()+"\n");
			$$->push_back($1);
			logout<<$1->getName()<<endl;

			$3->setName($3->getName()+"\n");
			$$->push_back($3);
			logout<<$3->getName()<<endl;
			logout<<endl;

			table->PrintAll(logout);
			table->exitScope(logout);
		   	}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON { 
			bool error_count = false;
			int i;
			$$ = new vector<SymbolInfo*>();
			logout<<"Line "<< line_count<<": var_declaration : type_specifier declaration_list SEMICOLON " <<endl;
			logout<<endl;
			for( i = 0; i < $2->size(); i++){
				if($2->at(i)->getType() == "Error"){
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					$$->push_back(point);
				}
			}
			if($1->getType() == "VOID" && error_count == false){
				errorfile<<"Error at line "<<line_count<<": Variable type cannot be void "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Variable type cannot be void "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
			

			$$->push_back($1);
			logout<<$1->getName();

			SymbolInfo *temp = new SymbolInfo();;
			SymbolInfo *sym = new SymbolInfo();

			string iden;

			for( i = 0; i < $2->size(); i++){
				$$->push_back($2->at(i));
				logout<<$2->at(i)->getName();
				if($2->at(i)->getType() == "ID")
				{	
					temp = table->getCurrScope()->lookup($2->at(i)->getName());
					if(temp == NULL && $1->getType() != "VOID" ){
						iden = $1->getName();
						iden.pop_back();
						$2->at(i)->setIdentity(iden);
						if( (i+1)<$2->size() && (i+3)<$2->size() && $2->at(i+1)->getType() == "LTHIRD" && $2->at(i+3)->getType() == "RTHIRD"){
							$2->at(i)->setArray(1);
							$2->at(i)->setFunction(0);
						}
						else{
							$2->at(i)->setArray(0);
							$2->at(i)->setFunction(0);
						}
						sym->setName($2->at(i)->getName());
						sym->setType($2->at(i)->getType());
						sym->setIdentity($2->at(i)->getIdentity());
						sym->setArray($2->at(i)->getArray());
						table->insert(sym);
					}
					
				}
			}

			$3->setName($3->getName()+"\n");
			$$->push_back($3);
			logout<<$3->getName()<<endl;
			logout<<endl;
			}
 		 ;
 		 
type_specifier	: INT { 
			logout<<"Line "<< line_count<<": type_specifier : INT"<<endl;
			logout<<endl;

			$1->setName($1->getName()+" ");
			logout<<$1->getName() <<endl;
			$$ =$1;

			logout<<endl;
			}
 		| FLOAT { 
			logout<< "Line "<<  line_count<<": type_specifier : FLOAT"<<endl;
			logout<<endl;

			$1->setName($1->getName()+" ");
			logout<<$1->getName() <<endl;
			$$ =$1;

			logout<<endl;
			}
 		| VOID { 
			logout<< "Line "<< line_count<<": type_specifier : VOID" <<endl;
			logout<<endl;

			$1->setName($1->getName()+" ");
			logout<<$1->getName() <<endl;
			$$ =$1;

			logout<<endl;
			}
 		;
 		
declaration_list : declaration_list COMMA ID{
			bool error_count = false;
			SymbolInfo *temp;
			temp = table->getCurrScope()->lookup($3->getName());
			if(temp != NULL){
				errorfile<<"Error at line "<<line_count<<": Multiple Declaration of "<<$3->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple Declaration of "<<$3->getName()<<endl<<endl;
				error_calc++;
				error_count = true;
			}

			logout<< "Line "<< line_count<<": declaration_list : declaration_list COMMA ID"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			if(error_count == true){
				SymbolInfo *temp1 = new SymbolInfo();
				temp1->setType("Error");
				$$->push_back(temp1);
			}

			for(int i = 0; i < $1->size(); i++){
				$$->push_back($1->at(i));
				logout<<$1->at(i)->getName();
			}

			$$->push_back($2);
			logout<<$2->getName();

			$$->push_back($3);
			logout<<$3->getName()<<endl;
			logout<<endl;
			}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD{
			bool error_count = false;
			SymbolInfo *temp;
			temp = table->getCurrScope()->lookup($3->getName());
			if(temp != NULL){
				errorfile<<"Error at line "<<line_count<<": Multiple Declaration of "<<$3->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple Declaration of "<<$3->getName()<<endl<<endl;
				error_calc++;
				error_count = true;
			}

			logout<< "Line "<< line_count<<": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			if(error_count == true){
				SymbolInfo *temp1 = new SymbolInfo();
				temp1->setType("Error");
				$$->push_back(temp1);
			}

			for(int i = 0; i < $1->size(); i++){
				$$->push_back($1->at(i));
				logout<<$1->at(i)->getName();
			}

			$$->push_back($2);
			logout<<$2->getName();

			$$->push_back($3);
			logout<<$3->getName();

			$$->push_back($4);
			logout<<$4->getName();

			$$->push_back($5);
			logout<<$5->getName();

			$$->push_back($6);
			logout<<$6->getName()<<endl;
			logout<<endl;
			}
 		  | ID { 
			bool error_count = false;
			SymbolInfo *temp = new SymbolInfo();
			temp = table->getCurrScope()->lookup($1->getName());
			if(temp != NULL){
				errorfile<<"Error at line "<<line_count<<": Multiple Declaration of "<<$1->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple Declaration of "<<$1->getName()<<endl<<endl;
				error_calc++;
				error_count = true;
			}

 		  	logout<< "Line "<< line_count<<": declaration_list : ID"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			if(error_count == true){
				SymbolInfo *temp1 = new SymbolInfo();
				temp1->setType("Error");
				$$->push_back(temp1);
			}

			$$->push_back($1);
			logout<<$1->getName() <<endl;
			logout<<endl;
			}
 		  | ID LTHIRD CONST_INT RTHIRD{
			bool error_count = false;
			SymbolInfo *temp = new SymbolInfo();
			temp = table->getCurrScope()->lookup($1->getName());
			if(temp != NULL){
				errorfile<<"Error at line "<<line_count<<": Multiple Declaration of "<<$1->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Multiple Declaration of "<<$1->getName()<<endl<<endl;
				error_calc++;
				error_count = true;
			}

			logout<<"Line "<< line_count<<": declaration_list : ID LTHIRD CONST_INT RTHIRD"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			if(error_count == true){
				SymbolInfo *temp1 = new SymbolInfo();
				temp1->setType("Error");
				$$->push_back(temp1);
			}

			$$->push_back($1);
			logout<<$1->getName();

			$$->push_back($2);
			logout<<$2->getName();

			$$->push_back($3);
			logout<<$3->getName();

			$$->push_back($4);
			logout<<$4->getName()<<endl;
			logout<<endl;
		   	}
 		  ;
 		  
statements : statement{
		logout<< "Line "<< line_count<<": statements : statement"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
	   | statements statement{
		int i;
		logout<< "Line "<< line_count<<": statements : statements statement"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for( i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
			
		}

		for( i = 0; i < $2->size(); i++){
			$$->push_back($2->at(i));
			logout<<$2->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
	   ;
	   
statement : var_declaration{
		logout<< "Line "<< line_count<<": statement : var_declaration"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
	  | expression_statement{
		logout<< "Line "<< line_count<<": statement : expression_statement"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
	  | compound_statement{
		logout<< "Line "<< line_count<<": statement : compound_statement"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
			
		}
		logout<<endl;
		}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement{
		int i;
		logout<< "Line "<< line_count<<": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		$$->push_back($1);
		logout<<$1->getName();

		$$->push_back($2);
		logout<<$2->getName();

		for(i = 0; i < $3->size(); i++){	
			if($3->at(i)->getType() == "SEMICOLON"){
				$3->at(i)->setName(";");
			}
			$$->push_back($3->at(i));
			logout<<$3->at(i)->getName();
		}

		for(i = 0; i < $4->size(); i++){
			if($4->at(i)->getType() == "SEMICOLON"){
				$4->at(i)->setName(";");
			}
			$$->push_back($4->at(i));
			logout<<$4->at(i)->getName();
		}
		
		for(i = 0; i < $5->size(); i++){
			$$->push_back($5->at(i));
			logout<<$5->at(i)->getName();
		}

		$$->push_back($6);
		logout<<$6->getName();

		for(i = 0; i < $7->size(); i++){
			$$->push_back($7->at(i));
			logout<<$7->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE{
		int i;
		logout<< "Line "<< line_count<<": statement : IF LPAREN expression RPAREN statement"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		$1->setName($1->getName()+" ");
		$$->push_back($1);
		logout<<$1->getName();

		$$->push_back($2);
		logout<<$2->getName();

		for(i = 0; i < $3->size(); i++){
			$$->push_back($3->at(i));
			logout<<$3->at(i)->getName();
		}

		$$->push_back($4);
		logout<<$4->getName();

		for(i = 0; i < $5->size(); i++){
			$$->push_back($5->at(i));
			logout<<$5->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
	  | IF LPAREN expression RPAREN statement ELSE statement{
		int i;
		logout<< "Line "<< line_count<<": statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();
		
		$1->setName($1->getName()+" ");
		$$->push_back($1);
		logout<<$1->getName();

		$$->push_back($2);
		logout<<$2->getName();

		for(i = 0; i < $3->size(); i++){
			$$->push_back($3->at(i));
			logout<<$3->at(i)->getName();
		}

		$$->push_back($4);
		logout<<$4->getName();

		for(i = 0; i < $5->size(); i++){
			$$->push_back($5->at(i));
			logout<<$5->at(i)->getName();
			
		}

		$6->setName($6->getName()+"\n");
		$$->push_back($6);
		logout<<$6->getName();

		for(i = 0; i < $7->size(); i++){
			$$->push_back($7->at(i));
			logout<<$7->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
	  | WHILE LPAREN expression RPAREN statement{
		int i;
		logout<< "Line "<< line_count<<": statement : WHILE LPAREN expression RPAREN statement"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		$1->setName($1->getName()+" ");
		$$->push_back($1);
		logout<<$1->getName();

		$$->push_back($2);
		logout<<$2->getName();

		for(i = 0; i < $3->size(); i++){
			$$->push_back($3->at(i));
			logout<<$3->at(i)->getName();
		}

		$$->push_back($4);
		logout<<$4->getName();

		for(i = 0; i < $5->size(); i++){
			$$->push_back($5->at(i));
			logout<<$5->at(i)->getName();
			
		}
		logout<<endl;
		logout<<endl;
		}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON{
			logout<<"Line "<< line_count<<": statement : PRINTLN LPAREN ID RPAREN SEMICOLON"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			SymbolInfo *temp = new SymbolInfo();
			temp = table->lookup($3->getName());
			if(temp == NULL){
				errorfile<<"Error at line "<<line_count<<": Undeclared variable "<<$3->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Undeclared variable "<<$3->getName()<<endl<<endl;
				error_calc++;
			}

			$$->push_back($1);
			logout<<$1->getName();

			$$->push_back($2);
			logout<<$2->getName();

			$$->push_back($3);
			logout<<$3->getName();

			$$->push_back($4);
			logout<<$4->getName();
			
			$5->setName($5->getName()+"\n");
			$$->push_back($5);
			logout<<$5->getName()<<endl;
			logout<<endl;
		   	}
	  | RETURN expression SEMICOLON{
			logout<<"Line "<< line_count<<": statement : RETURN expression SEMICOLON"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			$1->setName($1->getName()+" ");
			$$->push_back($1);
			logout<<$1->getName();

			for(int i = 0; i < $2->size(); i++){
				$$->push_back($2->at(i));
				logout<<$2->at(i)->getName();
			}

			$3->setName($3->getName()+"\n");
			$$->push_back($3);
			logout<<$3->getName()<<endl;
			logout<<endl;
		   	}
	  ;
	  
expression_statement 	: SEMICOLON{ 
		logout<< "Line "<< line_count<<": expression_statement 	: SEMICOLON"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		$1->setName($1->getName()+"\n");
		$$->push_back($1);
		logout<<$1->getName() <<endl;
		logout<<endl;
		}		
		| expression SEMICOLON{

			logout<< "Line "<< line_count<<": expression_statement 	: expression SEMICOLON"<<endl;
			logout<<endl;
			$$ = new vector<SymbolInfo*>();

			for(int i = 0; i < $1->size(); i++){
				$$->push_back($1->at(i));
				logout<<$1->at(i)->getName();
			}

			$2->setName($2->getName()+"\n");
			$$->push_back($2);
			logout<<$2->getName()<<endl;
			logout<<endl;
		}
		;
	  
variable : ID{ 
		logout<< "Line "<< line_count<<": variable : ID"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();
		bool error_count = false;
		SymbolInfo *temp = new SymbolInfo();
		temp = table->lookup($1->getName());
		if(temp == NULL){
			errorfile<<"Error at line "<<line_count<<": Undeclared variable "<<$1->getName()<<endl<<endl;
			logout<<"Error at line "<<line_count<<": Undeclared variable "<<$1->getName()<<endl<<endl;
			error_calc++;
			error_count = true;
			SymbolInfo *point = new SymbolInfo();
			point->setType("Error");
			$$->push_back(point);
		}
		else {
			if(temp->getArray() == 1){
				errorfile<<"Error at line "<<line_count<<": Type mismatch, "<<$1->getName()<<" is an array"<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Type mismatch, "<<$1->getName()<<" is an array"<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);	
			}
		}

		$$->push_back($1);
		logout<<$1->getName() <<endl;
		logout<<endl;
		}		
	 | ID LTHIRD expression RTHIRD{
		 	int i;
			$$ = new vector<SymbolInfo*>();
			bool error_count = false;
			logout<< "Line "<< line_count<<": variable : ID LTHIRD expression RTHIRD"<<endl;
			logout<<endl;
			for( i = 0; i < $3->size(); i++){
				if($3->at(i)->getType() == "Error"){
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					$$->push_back(point);
				}
			}

			SymbolInfo *temp = new SymbolInfo();
			temp = table->lookup($1->getName());
			if(temp == NULL){
				if(error_count == false){
					errorfile<<"Error at line "<<line_count<<": Undeclared variable "<<$1->getName()<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Undeclared variable "<<$1->getName()<<endl<<endl;
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					$$->push_back(point);
				}
				
			}
			else {
				if(temp->getArray() == 0 && error_count == false){
					errorfile<<"Error at line "<<line_count<<": "<<$1->getName()<<" is not an array"<<endl<<endl;
					logout<<"Error at line "<<line_count<<": "<<$1->getName()<<" is not an array"<<endl<<endl;	
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					$$->push_back(point);
				}
			}
			for(i = 0; i < $3->size(); i++){
				if($3->at(i)->getType() == "ID"){
					temp = table->lookup($3->at(i)->getName());
					if(temp->getIdentity() != "int" && error_count == false){
						errorfile<<"Error at line "<<line_count<<": Expression inside third brackets not an integer"<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Expression inside third brackets not an integer"<<endl<<endl;
						error_calc++;
						error_count = true;
						SymbolInfo *point = new SymbolInfo();
						point->setType("Error");
						$$->push_back(point);
						break;
					}
				}
				if($3->at(i)->getType() == "CONST_FLOAT"  && error_count == false){
					errorfile<<"Error at line "<<line_count<<": Expression inside third brackets not an integer"<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Expression inside third brackets not an integer"<<endl<<endl;
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					$$->push_back(point);
					break;
				}
			}

			$$->push_back($1);
			logout<<$1->getName();

			$$->push_back($2);
			logout<<$2->getName();

			for(i = 0; i < $3->size(); i++){
				$$->push_back($3->at(i));
				logout<<$3->at(i)->getName();
			}

			$$->push_back($4);
			logout<<$4->getName()<<endl;
			logout<<endl;
		}
	 ;
	 
expression : logic_expression{
		logout<< "Line "<< line_count<<": expression : logic_expression"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		
		}	
	   | variable ASSIGNOP logic_expression{
		int i,j;
		$$ = new vector<SymbolInfo*>();
		bool error_count = false;
		logout<< "Line "<< line_count<<": expression : variable ASSIGNOP logic_expression"<<endl;
		logout<<endl;

		for( i = 0; i < $1->size(); i++){
			if($1->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}

		for( i = 0; i < $3->size(); i++){
			if($3->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}

		SymbolInfo *temp = new SymbolInfo();
		SymbolInfo *temp2 = new SymbolInfo();
		for(i = 0; i < $1->size(); i++){
			if($1->at(i)->getType() == "ID"){
				temp = table->lookup($1->at(i)->getName());
				if(temp != NULL && temp->getArray() == 1){
					if((i+1)< $1->size() && $1->at(i+1)->getType() == "LTHIRD"){
						while($1->at(i)->getType() != "RTHIRD"){
							i++;
						}
					}
					
				}
				for(j = 0; j < $3->size(); j++){
					if(temp != NULL && temp->getIdentity() == "int"){
						if($3->at(j)->getType() == "CONST_FLOAT" && error_count == false){
							if($3->at(j)->getIdentity() == "INTEGER"){
								continue;
							}
							errorfile<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
							break;
						}
						if($3->at(j)->getType() == "ID"){
							if($3->at(j)->getIdentity() == "INTEGER"){
								continue;
							}
							temp2 = table->lookup($3->at(j)->getName());

							if(temp2 != NULL && temp2->getArray() == 1){
								if((j+1)< $3->size() && $3->at(j+1)->getType() == "LTHIRD"){
									while($3->at(j)->getType() != "RTHIRD"){
										j++;
									}
								}
								
							}
							else if(temp2 != NULL && temp2->getFunction() == 1){
								if((j+1)< $3->size() && $3->at(j+1)->getType() == "LPAREN"){
									while($3->at(j)->getType() != "RPAREN"){
										j++;
									}
								}
								
							}

							if(temp2 != NULL && temp2->getIdentity() == "void"){
								if( error_count == false){
									errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
									logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
									error_calc++;
									error_count = true;
									SymbolInfo *point = new SymbolInfo();
									point->setType("Error");
									$$->push_back(point);
									break;
								}
								
							}
							else if(temp2 != NULL && temp2->getIdentity() != "int"){
								if( error_count == false){
									errorfile<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
									logout<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
									error_calc++;
									error_count = true;
									SymbolInfo *point = new SymbolInfo();
									point->setType("Error");
									$$->push_back(point);
									break;
								}
								
							}
						}
						
					}
					else if(temp != NULL && temp->getIdentity() == "float"){
						if($3->at(j)->getType() == "CONST_INT" && error_count == false){
							if($3->at(j)->getIdentity() == "INTEGER"){
								continue;
							}
							
						}
						if($3->at(j)->getType() == "ID"){
							if($3->at(j)->getIdentity() == "INTEGER"){
								continue;
							}
							temp2 = table->lookup($3->at(j)->getName());

							if(temp2 != NULL && temp2->getArray() == 1){
								if((j+1)< $3->size() && $3->at(j+1)->getType() == "LTHIRD"){
									while($3->at(j)->getType() != "RTHIRD"){
										j++;
									}
								}
							}
							else if(temp2 != NULL && temp2->getFunction() == 1){
								if((j+1)< $3->size() && $3->at(j+1)->getType() == "LPAREN"){
									while($3->at(j)->getType() != "RPAREN"){
										j++;
									}
								}
								
							}

							if(temp2 != NULL && temp2->getIdentity() == "void"){
								if(error_count == false){
									errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
									logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
									error_calc++;
									error_count = true;
									SymbolInfo *point = new SymbolInfo();
									point->setType("Error");
									$$->push_back(point);
									break;
								}
								
							}
							else if(temp2 != NULL && temp2->getIdentity() != "float"){
								if(error_count == false){
									if(temp2->getIdentity() != "int"){
										
										errorfile<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
										logout<<"Error at line "<<line_count<<": Type Mismatch "<<endl<<endl;
										error_calc++;
										error_count = true;
										SymbolInfo *point = new SymbolInfo();
										point->setType("Error");
										$$->push_back(point);
										break;
									}
									
								}
								
							}
						}
						
					}
				}
			}
		}

		

		for(i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}

		$$->push_back($2);
		logout<<$2->getName();

		for(i = 0; i < $3->size(); i++){
			$$->push_back($3->at(i));
			logout<<$3->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}	
	   ;
			
logic_expression : rel_expression{
		logout<< "Line "<< line_count<<": logic_expression : rel_expression"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		
		}	
		| rel_expression LOGICOP rel_expression{
		 int i;
		 $$ = new vector<SymbolInfo*>();
		 bool error_count = false;

		

		for( i = 0; i < $1->size(); i++){
			if($1->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}

		for( i = 0; i < $3->size(); i++){
			if($3->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < $1->size(); i++){
			if($1->at(i)->getType() == "ID"){
				temp = table->lookup($1->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
						}
					}
				}
				
			}
		}

		for( i = 0; i < $3->size(); i++){
			if($3->at(i)->getType() == "ID"){
				temp = table->lookup($3->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
						}
					}
				}
				
			}
		}
		

		logout<< "Line "<< line_count<<": logic_expression : rel_expression LOGICOP rel_expression"<<endl;
		logout<<endl;

		for(i = 0; i < $1->size(); i++){
			$1->at(i)->setIdentity("INTEGER");
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}

		$$->push_back($2);
		logout<<$2->getName();

		for(i = 0; i < $3->size(); i++){
			$3->at(i)->setIdentity("INTEGER");
			$$->push_back($3->at(i));
			logout<<$3->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
		 ;
			
rel_expression	: simple_expression{
		logout<< "Line "<< line_count<<": rel_expression	: simple_expression"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		
		}
		| simple_expression RELOP simple_expression{
		int i;
		$$ = new vector<SymbolInfo*>();
		bool error_count = false;

		for( i = 0; i < $1->size(); i++){
			if($1->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}

		for( i = 0; i < $3->size(); i++){
			if($3->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < $1->size(); i++){
			if($1->at(i)->getType() == "ID"){
				temp = table->lookup($1->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
						}
					}
				}
				
			}
		}

		for( i = 0; i < $3->size(); i++){
			if($3->at(i)->getType() == "ID"){
				temp = table->lookup($3->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
						}
					}
				}
				
			}
		}
				 
		logout<< "Line "<< line_count<<": rel_expression	: simple_expression RELOP simple_expression"<<endl;
		logout<<endl;

		for(i = 0; i < $1->size(); i++){
			$1->at(i)->setIdentity("INTEGER");
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}

		$$->push_back($2);
		logout<<$2->getName();

		for(i = 0; i < $3->size(); i++){
			$3->at(i)->setIdentity("INTEGER");
			$$->push_back($3->at(i));
			logout<<$3->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
		;
				
simple_expression : term{
		logout<< "Line "<< line_count<<": simple_expression : term"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
		| simple_expression ADDOP term{
		int i;
		$$ = new vector<SymbolInfo*>();
		bool error_count = false;

		

		for( i = 0; i < $1->size(); i++){
			if($1->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}

		for( i = 0; i < $3->size(); i++){
			if($3->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < $1->size(); i++){
			if($1->at(i)->getType() == "ID"){
				temp = table->lookup($1->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
						}
					}
				}
				
			}
		}

		for( i = 0; i < $3->size(); i++){
			if($3->at(i)->getType() == "ID"){
				temp = table->lookup($3->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
						}
					}
				}
				
			}
		}
		

		logout<< "Line "<< line_count<<": simple_expression : simple_expression ADDOP term"<<endl;
		logout<<endl;
		

		for(i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}

		$$->push_back($2);
		logout<<$2->getName();

		for(i = 0; i < $3->size(); i++){
			$$->push_back($3->at(i));
			logout<<$3->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
		  ;
					
term :	unary_expression{
		logout<< "Line "<< line_count<<": term :	unary_expression"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
     |  term MULOP unary_expression{
		int i;
		$$ = new vector<SymbolInfo*>();
		bool error_count = false;

		for( i = 0; i < $1->size(); i++){
			if($1->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}

		for( i = 0; i < $3->size(); i++){
			if($3->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < $1->size(); i++){
			if($1->at(i)->getType() == "ID"){
				temp = table->lookup($1->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
						}
					}
				}
				
			}
		}

		for( i = 0; i < $3->size(); i++){
			if($3->at(i)->getType() == "ID"){
				temp = table->lookup($3->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
						}
					}
				}
				
			}
		}

		logout<< "Line "<< line_count<<": term :	term MULOP unary_expression"<<endl;
		logout<<endl;


		if($2->getName() == "%"){
			
			for(i = 0; i < $1->size(); i++){
				if($1->at(i)->getType() == "ID"){
					temp = table->lookup($1->at(i)->getName());
					if(temp != NULL){
						if(temp->getIdentity() == "float"  || temp->getIdentity() == "void"){
							if(error_count == false){
								errorfile<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
								logout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
								error_calc++;
								error_count = true;
								SymbolInfo *point = new SymbolInfo();
								point->setType("Error");
								$$->push_back(point);
							}
						}
					}
				}
				else{
					if($1->at(i)->getType() == "CONST_FLOAT" && error_count == false){
						errorfile<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
						error_calc++;
						error_count = true;
						SymbolInfo *point = new SymbolInfo();
						point->setType("Error");
						$$->push_back(point);
						break;
					}
				}
				
			}
		
			
			for(i = 0; i < $3->size(); i++){
				if($3->size() == 1 && $3->at(i)->getName() == "0" && error_count == false){
					errorfile<<"Error at line "<<line_count<<": Modulus by Zero "<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Modulus by Zero "<<endl<<endl;
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					$$->push_back(point);
					break;
				}
				if($3->at(i)->getType() == "ID"){
					temp = table->lookup($3->at(i)->getName());
					if(temp != NULL){
						if(temp->getIdentity() == "float"  || temp->getIdentity() == "void"){
							if(error_count == false){
								errorfile<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
								logout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
								error_calc++;
								error_count = true;
								SymbolInfo *point = new SymbolInfo();
								point->setType("Error");
								$$->push_back(point);
							}
						}
					}
				}
				else{
					if($3->at(i)->getType() == "CONST_FLOAT" && error_count == false){
						errorfile<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
						logout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator "<<endl<<endl;
						error_calc++;
						error_count = true;
						SymbolInfo *point = new SymbolInfo();
						point->setType("Error");
						$$->push_back(point);
						break;
					}
				}
				
			}
		}
		
		if($2->getName() == "/"){
			if($3->size() == 1 && $3->at(0)->getName() == "0"  && error_count == false){
				errorfile<<"Error at line "<<line_count<<": Divided by Zero "<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Divided by Zero "<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
				break;
			}
		}
		

		for(i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}

		$$->push_back($2);
		logout<<$2->getName();

		for(i = 0; i < $3->size(); i++){
			$$->push_back($3->at(i));
			logout<<$3->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;

   		}
     ;

unary_expression : ADDOP unary_expression{ 
		int i;
		$$ = new vector<SymbolInfo*>();
		bool error_count = false;
		
		for( i = 0; i < $2->size(); i++){
			if($2->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < $2->size(); i++){
			if($2->at(i)->getType() == "ID"){
				temp = table->lookup($2->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
						}
					}
				}
				
			}
		}

		logout<< "Line "<< line_count<<": unary_expression : ADDOP unary_expression "<<endl;
		logout<<endl;

		$$->push_back($1);
		logout<<$1->getName();

		for( i = 0; i < $2->size(); i++){
			$$->push_back($2->at(i));
			logout<<$2->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
		 | NOT unary_expression{ 
		int i;
		$$ = new vector<SymbolInfo*>();
		bool error_count = false;
		
		for( i = 0; i < $2->size(); i++){
			if($2->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}
		SymbolInfo *temp = new SymbolInfo();

		for( i = 0; i < $2->size(); i++){
			if($2->at(i)->getType() == "ID"){
				temp = table->lookup($2->at(i)->getName());
				if(temp != NULL){
					if(temp->getFunction() == 1 && temp->getIdentity() == "void"){
						if(error_count == false){
							errorfile<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Void function used in expression "<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
						}
					}
				}
				
			}
		}
		logout<< "Line "<< line_count<<": unary_expression : NOT unary_expression "<<endl;
		logout<<endl;
		

		$$->push_back($1);
		logout<<$1->getName();

		for(i = 0; i < $2->size(); i++){
			$$->push_back($2->at(i));
			logout<<$2->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
		 | factor{ 
		logout<< "Line "<< line_count<<": unary_expression : factor "<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
		;
	
factor	: variable{ 
		logout<< "Line "<< line_count<<": factor : variable"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
	| ID LPAREN argument_list RPAREN{ 
		int i,j;
		logout<< "Line "<< line_count<<": factor : ID LPAREN argument_list RPAREN"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();
		bool error_count = false;

		for( i = 0; i < $3->size(); i++){
			if($3->at(i)->getType() == "Error" && error_count == false){
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
		}
		
		SymbolInfo *temp = new SymbolInfo();
		SymbolInfo *temp1 = new SymbolInfo();
		SymbolInfo *temp2 = new SymbolInfo();
		temp = table->lookup($1->getName());
		if(temp == NULL){
			if(error_count == false){
				errorfile<<"Error at line "<<line_count<<": Undeclared function "<<$1->getName()<<endl<<endl;
				logout<<"Error at line "<<line_count<<": Undeclared function "<<$1->getName()<<endl<<endl;
				error_calc++;
				error_count = true;
				SymbolInfo *point = new SymbolInfo();
				point->setType("Error");
				$$->push_back(point);
			}
			
		}
		else{
			if(temp->getFunction() != 1){
				if(error_count == false){
					errorfile<<"Error at line "<<line_count<<": Undeclared function "<<$1->getName()<<endl<<endl;
					logout<<"Error at line "<<line_count<<": Undeclared function "<<$1->getName()<<endl<<endl;
					error_calc++;
					error_count = true;
					SymbolInfo *point = new SymbolInfo();
					point->setType("Error");
					$$->push_back(point);
				}
			}
			else{
				vector<SymbolInfo*> param_count;
				for(i = 0; i < temp->returnVector().size(); i++ ){
					
					if(temp->returnVector().at(i)->getType() == "INT" || temp->returnVector().at(i)->getType() == "FLOAT"){
						param_count.push_back(temp->returnVector().at(i));
					}
				}
				int j = 0;
				for(i = 0; i < $3->size(); i++){
					if($3->at(i)->getType() == "COMMA"){
						j++;				
					}
				}
				if(param_count.size() != (j+1) ){
					if(error_count == false){
						if(param_count.size()==0 && j == 0 && $3->size() == 0){
						}
						else{
							errorfile<<"Error at line "<<line_count<<": Total number of arguments mismatch in function "<<temp->getName()<<endl<<endl;
							logout<<"Error at line "<<line_count<<": Total number of arguments mismatch in function "<<temp->getName()<<endl<<endl;
							error_calc++;
							error_count = true;
							SymbolInfo *point = new SymbolInfo();
							point->setType("Error");
							$$->push_back(point);
						}
						
					}
					
				}
				else{
					j = 0;
					for(i = 0; i < $3->size(); i++){
						if($3->at(i)->getType() == "COMMA"){
							j++;				
						}
						else{
							if($3->at(i)->getType() == "ID"){
								temp1 = table->lookup($3->at(i)->getName());
								if(temp1 != NULL ){
									if(temp1->getArray() == 1){
										if((i+1)< $3->size() && $3->at(i+1)->getType() == "LTHIRD"){
											while($3->at(i)->getType() != "RTHIRD"){
												i++;
											}
										}
									}
									if(temp1->getFunction() == 1){
										if((i+1)< $3->size() && $3->at(i+1)->getType() == "LPAREN"){
											while($3->at(i)->getType() != "RPAREN"){
												i++;
											}
										}
									}
									
									if((temp1->getIdentity() == "float" || temp1->getIdentity() == "void" ) && param_count.at(j)->getType() == "INT"){
										if(error_count == false){
											errorfile<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
											logout<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
											error_calc++;
											error_count = true;
											SymbolInfo *point = new SymbolInfo();
											point->setType("Error");
											$$->push_back(point);
											break;
										}
									}
									else if(temp1->getIdentity() == "void" &&  param_count.at(j)->getType() == "FLOAT"){
										if(error_count == false){
										
												errorfile<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
												logout<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
												error_calc++;
												error_count = true;
												SymbolInfo *point = new SymbolInfo();
												point->setType("Error");
												$$->push_back(point);
												break;
											
											
										}
									}
									
								}
								
							}
							else{
								if($3->at(i)->getType() == "CONST_FLOAT" && param_count.at(j)->getType() == "INT"){
									if(error_count == false){
										errorfile<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
										logout<<"Error at line "<<line_count<<": "<<j+1<<"th argument mismatch in function "<<temp->getName()<<endl<<endl;
										error_calc++;
										error_count = true;
										SymbolInfo *point = new SymbolInfo();
										point->setType("Error");
										$$->push_back(point);
										break;
									}
	
								}
								
							}
							
						}
						
					}
				}
			}
			
			
			
		}

		$$->push_back($1);
		logout<<$1->getName();

		$$->push_back($2);
		logout<<$2->getName();

		if($3->size() > 0){
			for( i = 0; i < $3->size(); i++){
				$$->push_back($3->at(i));
				logout<<$3->at(i)->getName();
			}
		}
		$$->push_back($4);
		logout<<$4->getName()<<endl;
		logout<<endl;
		}
	| LPAREN expression RPAREN{ 
		logout<< "Line "<< line_count<<": factor : LPAREN expression RPAREN"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		$$->push_back($1);
		logout<<$1->getName();

		for(int i = 0; i < $2->size(); i++){
			$$->push_back($2->at(i));
			logout<<$2->at(i)->getName();
		}

		$$->push_back($3);
		logout<<$3->getName()<<endl;
		logout<<endl;
		}
	| CONST_INT{ 
		logout<<  "Line "<< line_count<<": factor : CONST_INT"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		$$->push_back($1);
		logout<<$1->getName() <<endl;
		logout<<endl;
		}
	| CONST_FLOAT{ 
		logout<< "Line "<< line_count<<": factor : CONST_FLOAT"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		$$->push_back($1);
		logout<<$1->getName() <<endl;
		logout<<endl;
		}
	| variable INCOP{ 
		logout<< "Line "<< line_count<<": factor : variable INCOP"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}

		$$->push_back($2);
		logout<<$2->getName() <<endl;

		logout<<endl;
		}
	| variable DECOP{ 
		logout<< "Line "<< line_count<<": factor : variable DECOP"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}

		$$->push_back($2);
		logout<<$2->getName() <<endl;

		logout<<endl;
		}
	;
	
argument_list : arguments{ 
		logout<< "Line "<< line_count<<": argument_list : arguments"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
			  |{ 
		logout<< "Line "<< line_count<<": argument_list : "<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();
		}
		;
	
arguments : arguments COMMA logic_expression{ 
		int i;
		logout<< "Line "<< line_count<<": arguments : arguments COMMA logic_expression"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}

		$$->push_back($2);
		logout<<$2->getName();
		
		for(i = 0; i < $3->size(); i++){
			$$->push_back($3->at(i));
			logout<<$3->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
	      | logic_expression{ 
		logout<< "Line "<< line_count<<": arguments : arguments COMMA logic_expression"<<endl;
		logout<<endl;
		$$ = new vector<SymbolInfo*>();

		for(int i = 0; i < $1->size(); i++){
			$$->push_back($1->at(i));
			logout<<$1->at(i)->getName();
		}
		logout<<endl;
		logout<<endl;
		}
	      ;
 

%%

int main(int argc,char *argv[]){
	
	FILE *file=fopen(argv[1],"r");
	if(file==NULL){
		cout<<"Cannot open specified file"<<endl;
		return 0;
	}
	logout.open("1705067_log.txt");
	errorfile.open("1705067_error.txt");
	yyin= file;
	yyparse();
	fclose(yyin);
	logout.close();
	errorfile.close();
	return 0;
	exit(0);
}

