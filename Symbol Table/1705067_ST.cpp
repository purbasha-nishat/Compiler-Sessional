#include<bits/stdc++.h>
using namespace std;

ofstream file2;

class SymbolInfo
{

    string name;
    string type;
    SymbolInfo *nextSymbol;
public:
    void setName(string n)
    {
        name = n;
    }
    void setType(string t)
    {
        type = t;
    }
    void setNextSymbol(SymbolInfo *s)
    {
        nextSymbol = s;
    }
    string getName()
    {
        return name;
    }
    string getType()
    {
        return type;
    }
    SymbolInfo* getNextSymbol()
    {
        return nextSymbol;
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
    ScopeTable();
    void setSize(int size);
    void setID(string str);
    string getID();
    int getChildCount();
    void incChildCount();
    void setParentScope(ScopeTable *sc);
    ScopeTable* getParentScope();
    int hashValue(string str, int bucket);
    bool insertSymbol(string name, string type);
    bool deleteSymbol(string name);
    SymbolInfo* lookup(string name);
    void print();
    ~ScopeTable();

};

ScopeTable :: ScopeTable()
{

    table = 0;
    childCount = 0;

}

void ScopeTable :: setSize(int size)
{

    tableSize = size;
    table = new SymbolInfo*[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = nullptr;
    }
}

void ScopeTable :: setID(string str)
{

    id = str;

}

string ScopeTable :: getID()
{

    return id;

}

int ScopeTable :: getChildCount()
{
    return childCount;
}

void ScopeTable :: incChildCount()
{

    childCount++;

}

void ScopeTable :: setParentScope(ScopeTable *sc)
{

    parentScope = sc;

}

ScopeTable* ScopeTable :: getParentScope()
{

    return parentScope;

}

int ScopeTable :: hashValue(string str, int bucket)
{

    int sum = 0;
    for(int i = 0; i < str.length(); i++)
    {
        sum += str[i];
    }

    return sum%bucket;

}

bool ScopeTable :: insertSymbol(string name, string type)
{

    int bucket;
    int offset=0;
    SymbolInfo *temp = new SymbolInfo();
    SymbolInfo *temp2;
    SymbolInfo *curr;
    bucket = hashValue(name,tableSize);

    temp->setName(name);
    temp->setType(type);

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
    file2<<"Inserted in ScopeTable# "<<id<<"  at position "<< bucket<< ", "<<offset<<endl;
    return true;

}

bool ScopeTable :: deleteSymbol(string name)
{

    int bucket;
    int offset=0;
    SymbolInfo *temp;
    SymbolInfo *curr;
    bucket = hashValue(name,tableSize);

    temp = table[bucket];
    if(temp == nullptr)
    {
        file2<<name<<" not found"<<endl;
        return false;
    }
    if(temp->getName() == name)
    {
        table[bucket] = temp->getNextSymbol();
        temp->setNextSymbol(nullptr);
        delete temp;

        file2<<"Found in ScopeTable# "<<id<<" at position "<<bucket<<", "<<offset<<endl;
        file2<<endl;
        file2<<"Deleted Entry "<<bucket<<", "<<offset<<" from current ScopeTable"<<endl;

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

                file2<<"Found in ScopeTable# "<<id<<" at position "<<bucket<<", "<<offset<<endl;
                file2<<endl;
                file2<<"Deleted Entry "<<bucket<<", "<<offset<<" from current ScopeTable"<<endl;

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
    file2<<name<<" not found"<<endl;
    return false;

}

SymbolInfo* ScopeTable :: lookup(string name)
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
            file2<<"Found in ScopeTable# "<<id<<" at position "<<bucket<< ", "<<offset<<endl;
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

void ScopeTable :: print()
{
    SymbolInfo *temp;
    file2<<"ScopeTable # "<<id<<endl;
    for(int i = 0; i < tableSize; i++)
    {
        file2<<i<<" --> ";
        temp = table[i];
        while(temp != nullptr)
        {
            file2<<" < "<<temp->getName()<<" : "<<temp->getType()<<" > ";
            temp = temp->getNextSymbol();
        }
        file2<<endl;
    }
}

ScopeTable ::~ScopeTable()
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

class SymbolTable
{

    ScopeTable *currScopeTable;
public:
    SymbolTable();
    void enterScope(int size);
    void exitScope();
    bool insert(string name, string type);
    bool remove(string name);
    SymbolInfo* lookup(string name);
    void PrintCurrScope();
    void PrintAll();
    ~SymbolTable();

};

SymbolTable :: SymbolTable()
{

    currScopeTable = nullptr;
}


void SymbolTable :: enterScope(int size)
{
    ScopeTable *scope;
    int child;
    string id;

    if(currScopeTable != nullptr)
    {
        id = currScopeTable->getID();
        currScopeTable->incChildCount();
        child = currScopeTable->getChildCount();
        id = id +"."+ to_string(child);

    }
    else
    {
        id = to_string(1);
    }


    scope = new ScopeTable();
    scope->setSize(size);
    scope->setParentScope(currScopeTable);
    scope->setID(id);
    currScopeTable = scope;

    if(id != "1")
        file2<<"New ScopeTable with id "<<id<<" created"<<endl;

}

void SymbolTable :: exitScope()
{

    ScopeTable *scope;
    ScopeTable *curr;
    curr = currScopeTable;
    scope = currScopeTable->getParentScope();
    file2<<"ScopeTable with id "<<currScopeTable->getID()<<" removed"<<endl;

    delete curr;
    currScopeTable = scope;

}

bool SymbolTable :: insert(string name, string type)
{

    if(currScopeTable->insertSymbol(name,type))
        return true;
    else
        return false;

}
bool SymbolTable :: remove(string name)
{

    if(currScopeTable->deleteSymbol(name))
        return true;
    else
        return false;

}

SymbolInfo* SymbolTable :: lookup(string name)
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
    file2<<"Not found"<<endl;
    return nullptr;
}

void SymbolTable :: PrintCurrScope()
{

    currScopeTable->print();

}
void SymbolTable :: PrintAll()
{

    ScopeTable *scope;
    scope = currScopeTable;

    while(scope != nullptr)
    {
        file2<<endl;
        scope->print();
        file2<<endl;
        scope = scope->getParentScope();

    }

}

SymbolTable :: ~SymbolTable()
{

    while (currScopeTable)
    {
        ScopeTable *temp = currScopeTable;
        currScopeTable = currScopeTable->getParentScope();
        delete temp;
    }


}

int main()
{
    int bucket, i=0;
    string str;
    string tempStr;
    bool check;
    vector<string> sVector;
    SymbolTable sb;

    fstream file;
    file.open("input.txt");
    file2.open("output.txt");

    getline(file,str);
    bucket = stoi(str);
    sb.enterScope(bucket);
    while(getline(file,str))
    {
        cout<<str<<endl;

        stringstream s(str);
        i=0;
        while(s>>tempStr)
        {
            sVector.insert(sVector.begin()+i,tempStr);
            i++;
        }
        if(sVector.at(0) == "I")
        {
            file2<<str<<endl;
            file2<<endl;
            check = sb.insert(sVector.at(1),sVector.at(2));
            if(!check)
            {
                file2<<"< "<<sVector.at(1)<<", "<<sVector.at(2)<<">"<<" already exists in the current ScopeTable."<<endl;
            }

            file2<<endl;
        }
        else if(sVector.at(0) == "D")
        {
            file2<<str<<endl;
            file2<<endl;
            check = sb.remove(sVector.at(1));
            file2<<endl;

        }
        else if(sVector.at(0) == "S")
        {
            file2<<str<<endl;
            file2<<endl;
            sb.enterScope(bucket);
            file2<<endl;
        }
        else if(sVector.at(0) == "E")
        {
            file2<<str<<endl;
            file2<<endl;
            sb.exitScope();
            file2<<endl;

        }
        else if(sVector.at(0) == "L")
        {
            SymbolInfo *temp;
            temp = sb.lookup(sVector.at(1));
            file2<<endl;

        }
        else if(sVector.at(0) == "P")
        {
            file2<<str<<endl;
            file2<<endl;
            if(sVector.at(1) == "C")
            {
                sb.PrintCurrScope();
                file2<<endl;
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

    return 0;
}

