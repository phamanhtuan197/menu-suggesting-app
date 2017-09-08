#pragma once

#include "support.cpp"
#include <map>

class ingredients_list
{
public:
    map<string, int> inssi;
    map<int, string> insis;
    int init(){return OK;}
    int add_ingredient(string name, int index)
    {
            if (name == "") return err(INVALID_VALUE, "name variable cannot be empty"); if (index < 0) return err(INVALID_VALUE, "index must be equal or greater than 0");
            if (inssi.find(name) != inssi.end()) return err(ALREADY_EXISTS, "ingredient name has already exists");
            if (insis.find(index) != insis.end()) return err(ALREADY_EXISTS, "ingredient index has alredy exists");
            inssi[name] = index;
            insis[index] = name;
    }
    void erase(string name) {insis.erase(inssi[name]); inssi.erase(name);}
    void erase(int index) {inssi.erase(insis[index]); insis.erase(index);}
    int getIndex(string name)
    {
        if (inssi.find(name) != inssi.end()) return inssi[name];
        return err(NOT_EXISTS, "ingredient name is not exists");
    }
    string getName(int index)
    {
        if (insis.find(index) != insis.end()) return insis[index];
        err(NOT_EXISTS, "ingredient index is not exists");
        return getErrorString(NOT_EXISTS);
    }
    void print()
    {
        cout << "ingredients_list print out: size() = " << size() << endl;
        for (map<string, int> :: iterator it = inssi.begin(); it != inssi.end(); ++it)
            cout << it -> first << ": index = " << it -> second << endl;
        cout << "And reverse: " << endl;
        for (map<int, string> :: iterator it = insis.begin(); it != insis.end(); ++it)
            cout << it -> second << ": index = " << it -> first << endl;
        
        cout << endl;
    }
    int size()
    {
        return inssi.size();
    }
};

ingredients_list make_ingredient(string name, int index)
{
    ingredients_list r;
    r.init();
    r.add_ingredient(name, index);
    return r;
}
