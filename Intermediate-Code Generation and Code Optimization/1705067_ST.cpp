#ifndef ST
#define ST
#include<bits/stdc++.h>
using namespace std;


class SymbolInfo
{

    string name;
    string type;
    string identity;
    int array;
    int func;
    int defined;
    SymbolInfo *nextSymbol;
    vector<SymbolInfo*> paramlist;
public:
    string symbol;
    string code;
    
    SymbolInfo(){
        symbol = "";
        code = "";
    }
    SymbolInfo(string n, string t, string i, vector<SymbolInfo*> param, int arr=0, int f=0, int d=0 ){
        name = n;
        type = t;
        identity = i;
        array = arr;
        func = f;
        paramlist = param;
        defined = d;
        symbol = "";
        code = "";
        
    }
    void setName(string n)
    {
        name = n;
    }
    void setType(string t)
    {
        type = t;
    }
    void setIdentity(string i)
    {
        identity = i;
    }
    void setNextSymbol(SymbolInfo *s)
    {
        nextSymbol = s;
    }
    void setArray(int arr)
    {
        array = arr;
    }
    void setFunction(int f)
    {
        func = f;
    }
    void setDefined(int d)
    {
        defined = d;
    }
    string getName()
    {
        return name;
    }
    string getType()
    {
        return type;
    }
    string getIdentity()
    {
        return identity;
    }
    SymbolInfo* getNextSymbol()
    {
        return nextSymbol;
    }
    int getArray()
    {
        return array;
    }
    int getFunction()
    {
        return func;
    }
    int getDefined()
    {
        return defined;
    }
    void pushParam(SymbolInfo *temp){
        paramlist.push_back(temp);
    }
    vector<SymbolInfo*> returnVector()
    {   
        return paramlist;
    }
};

class ScopeTable
{

    int tableSize;
    SymbolInfo **table;
    ScopeTable *parentScope;
    string id;
    int childCount;

public:
    ScopeTable()
    {

        table = 0;
        childCount = 0;

    }

    void setSize(int size)
    {

        tableSize = size;
        table = new SymbolInfo*[tableSize];
        for(int i = 0; i < tableSize; i++)
        {
            table[i] = nullptr;
        }
    }

    void setID(int str)
    {

        id = to_string(str);

    }

    string getID()
    {

        return id;

    }

    int getChildCount()
    {
        return childCount;
    }

    void incChildCount()
    {

        childCount++;

    }

    void setParentScope(ScopeTable *sc)
    {

        parentScope = sc;

    }

    ScopeTable* getParentScope()
    {

        return parentScope;

    }

    int hashValue(string str, int bucket)
    {

        int sum = 0;
        for(int i = 0; i < str.length(); i++)
        {
            sum += str[i];
        }

        return sum%bucket;

    }

    bool insertSymbol(SymbolInfo *sym)
    {

        int bucket;
        int offset=0;
        int i;
        SymbolInfo *temp = new SymbolInfo(sym->getName(), sym->getType(), sym->getIdentity(), sym->returnVector(), sym->getArray(), sym->getFunction(), sym->getDefined());
        temp->symbol = sym->symbol;
        SymbolInfo *temp2;
        SymbolInfo *curr;
        string name;
        name = sym->getName();
        bucket = hashValue(name,tableSize);


        if( table[bucket] == nullptr)
        {
            table[bucket] = temp;
            temp->setNextSymbol(nullptr);
        }
        else
        {
            temp2 = table[bucket];

            while(temp2 != nullptr)
            {
                if(temp2->getName() == temp->getName())
                {
                    return false;
                }
                else
                {
                    curr = temp2;
                    temp2 = temp2->getNextSymbol();
                    offset++;
                }

            }
            curr->setNextSymbol(temp);
            temp->setNextSymbol(nullptr);
        }
        //logout<<"Inserted in ScopeTable# "<<id<<"  at position "<< bucket<< ", "<<offset<<endl;
        return true;

    }

    bool deleteSymbol(string name)
    {

        int bucket;
        int offset=0;
        SymbolInfo *temp;
        SymbolInfo *curr;
        bucket = hashValue(name,tableSize);

        temp = table[bucket];
        if(temp == nullptr)
        {
            //logout<<name<<" not found"<<endl;
            return false;
        }
        if(temp->getName() == name)
        {
            table[bucket] = temp->getNextSymbol();
            temp->setNextSymbol(nullptr);
            delete temp;

            //  logout<<"Found in ScopeTable# "<<id<<" at position "<<bucket<<", "<<offset<<endl;
            //  logout<<endl;
            //  logout<<"Deleted Entry "<<bucket<<", "<<offset<<" from current ScopeTable"<<endl;
            return true;
        }
        else
        {
            while(temp != nullptr)
            {
                if(temp->getName() == name)
                {
                    curr->setNextSymbol(temp->getNextSymbol());
                    temp->setNextSymbol(nullptr);
                    delete temp;

                    // logout<<"Found in ScopeTable# "<<id<<" at position "<<bucket<<", "<<offset<<endl;
                    // logout<<endl;
                    // logout<<"Deleted Entry "<<bucket<<", "<<offset<<" from current ScopeTable"<<endl;
                    return true;
                }
                else
                {
                    curr = temp;
                    temp = temp->getNextSymbol();
                    offset++;
                }

            }
        }
       
//   logout<<name<<" not found"<<endl;
        return false;

    }

    SymbolInfo* lookup(string name)
    {

        int bucket;
        int offset=0;
        SymbolInfo *temp;
        SymbolInfo *curr;
        bucket = hashValue(name,tableSize);

        temp = table[bucket];
        while(temp != nullptr)
        {
            if(temp->getName() == name)
            {
                // logout<<"Found in ScopeTable# "<<id<<" at position "<<bucket<< ", "<<offset<<endl;
                return temp;
            }
            else
            {
                temp = temp->getNextSymbol();
                offset++;
            }
        }
        return nullptr;

    }

    void print(ofstream& logout)
    {
        SymbolInfo *temp;
        logout<<"ScopeTable # "<<id<<endl;
        for(int i = 0; i < tableSize; i++)
        {
            temp = table[i];
            if(temp != nullptr)
            {
                logout<<" "<<i<<" --> ";
                while(temp != nullptr)
                {
                    logout<<"< "<<temp->getName()<<" , "<<temp->getType()<<" > ";
                    temp = temp->getNextSymbol();
                }
                logout<<endl;
            }
        }
        logout<<endl;
    }

    ~ScopeTable()
    {

        SymbolInfo *temp;
        for(int i = 0; i < tableSize; i++)
        {
            temp = table[i];
            while(temp != nullptr)
            {
                SymbolInfo *temp1 = temp;
                temp = temp->getNextSymbol();
                delete temp1;
            }
        }
        delete[] table;
    }

};


class SymbolTable
{

    ScopeTable *currScopeTable;
    int tablesize;
public:

    SymbolTable(int size, ofstream& logout)
    {
        tablesize = size;
        currScopeTable = nullptr;
        enterScope(logout);
    }

    ScopeTable* getCurrScope()
    {
        return currScopeTable;
    }
    void enterScope(ofstream& logout)
    {
        ScopeTable *scope;
        int child;
        string id;

        if(currScopeTable != nullptr)
        {
           // id = to_string(stoi(currScopeTable->getID())+1);
            /*currScopeTable->incChildCount();
            child = currScopeTable->getChildCount();
            id = id +"."+ to_string(child);*/


        }
        else
        {
           // id = to_string(0);
        }


        scope = new ScopeTable();
        scope->setSize(tablesize);
        scope->setParentScope(currScopeTable);
        //scope->setID(id);
        currScopeTable = scope;
        
        

    }

    void exitScope(ofstream& logout)
    {

        ScopeTable *scope;
        ScopeTable *curr;
        curr = currScopeTable;
        scope = currScopeTable->getParentScope();

        delete curr;
        currScopeTable = scope;

    }

    bool insert(SymbolInfo *sym)
    {

        if(currScopeTable->insertSymbol(sym))
            return true;
        else
        {
            //logout<<name<<" already exists in current ScopeTable."<<endl;
            //logout<<endl;
            return false;
        }

    }
    bool remove(string name)
    {

        if(currScopeTable->deleteSymbol(name))
            return true;
        else
            return false;

    }

    SymbolInfo* lookup(string name)
    {

        SymbolInfo *temp;
        ScopeTable *scope;

        scope = currScopeTable;

        while(scope != nullptr)
        {

            temp = scope->lookup(name);

            if(temp == nullptr)
            {
                scope = scope->getParentScope();
            }
            else
            {
                return temp;
            }
        }
//   logout<<"Not found"<<endl;
        return nullptr;
    }

    void PrintCurrScope(ofstream& logout)
    {

        currScopeTable->print(logout);

    }
    void PrintAll(ofstream& logout)
    {

        ScopeTable *scope;
        scope = currScopeTable;

        while(scope != nullptr)
        {
            //logout<<endl;
            scope->print(logout);
            //logout<<endl;
            scope = scope->getParentScope();

        }

    }

    ~SymbolTable()
    {

        while (currScopeTable)
        {
            ScopeTable *temp = currScopeTable;
            currScopeTable = currScopeTable->getParentScope();
            delete temp;
        }


    }

};

/*
int main()
{
    int bucket, i=0;
    string str;
    string tempStr;
    bool check;
    vector<string> sVector;

    fstream file;
    file.open("input1.txt");
    logout.open("output.txt");

    getline(file,str);
    bucket = stoi(str);
    SymbolTable sb(bucket);
    sb.enterScope();
    while(getline(file,str))
    {
        cout<<str<<endl;
        if(str.compare("\r") == 0)
        {
            cout<<"extra line"<<endl;
            continue;
        }

        stringstream s(str);
        i=0;
        while(s>>tempStr)
        {
            sVector.insert(sVector.begin()+i,tempStr);
            i++;
        }
        if(sVector.at(0) == "I")
        {
            logout<<str<<endl;
            logout<<endl;
            check = sb.insert(sVector.at(1),sVector.at(2));
            if(!check)
            {
                logout<<"< "<<sVector.at(1)<<", "<<sVector.at(2)<<">"<<" already exists in the current ScopeTable."<<endl;
            }

            logout<<endl;
        }
        else if(sVector.at(0) == "D")
        {
            logout<<str<<endl;
            logout<<endl;
            check = sb.remove(sVector.at(1));
            logout<<endl;

        }
        else if(sVector.at(0) == "S")
        {
            logout<<str<<endl;
            logout<<endl;
            sb.enterScope();
            logout<<endl;
        }
        else if(sVector.at(0) == "E")
        {
            logout<<str<<endl;
            logout<<endl;
            sb.exitScope();
            logout<<endl;

        }
        else if(sVector.at(0) == "L")
        {
            SymbolInfo *temp;
            temp = sb.lookup(sVector.at(1));
            logout<<endl;

        }
        else if(sVector.at(0) == "P")
        {
            logout<<str<<endl;
            logout<<endl;
            if(sVector.at(1) == "C")
            {
                sb.PrintCurrScope();
                logout<<endl;
            }
            else if(sVector.at(1) == "A")
                sb.PrintAll();

        }
        else
        {
            cout<<"INVALID option"<<endl;
        }

        sVector.clear();

    }
    file.close();
    logout.close();

    return 0;
}

*/
#endif // ST
