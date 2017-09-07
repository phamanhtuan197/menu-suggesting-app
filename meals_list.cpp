#pragma once
#include "meal.cpp"
#include "support.cpp"
#include "ingredient.cpp"
#include <vector>
struct classcomp{
    bool operator()(meal a, meal b) { //meal a and meal b have to have the same length
        if (a.ingredients.size() < b.ingredients.size()) return true;
        else if (a.ingredients.size() > b.ingredients.size()) return false;
        set<int> :: iterator ita = a.ingredients.begin();
        set<int> :: iterator itb = b.ingredients.begin();
        for (; ita != a.ingredients.end() && itb != b.ingredients.end(); ++ita, ++itb)
        {
            if (*ita < *itb) return true;
            return false;
        }
        return false;
        //return true means a stand before b
        //return false means a stand after b
        //these seems equal but when map compare the ==
        //return true mean a before b so map.find() doesn't work
        //return false means a not before b -> recheck a not after b -> a == b
    }
};
        

class meals_list
{
public:
    map<meal, string, classcomp> insms;
    map<string, meal> inssm;
    int init(){return OK;}
    int add_meal(meal m, string name)
    {
            //cout << "adding meal " << m.get_bit_sequence() << " name " << name << endl;
            if (insms.find(m) != insms.end()) return err(ALREADY_EXISTS, "meal  data has already exists ");
            if (inssm.find(name) != inssm.end()) return err(ALREADY_EXISTS, "meal index has alredy exists");
            insms[m] = name;
            inssm[name] = m;
    }
    void erase(string name) {insms.erase(inssm[name]); inssm.erase(name);}
    void erase(meal m) {inssm.erase(insms[m]); insms.erase(m);}
    meal getMeal(string name)
    {
        if (inssm.find(name) != inssm.end()) return inssm[name];
        err(NOT_EXISTS, "meal name is not exists");
        return make_meal(make_ingredient("deadly", 9));
    }
    string getName(meal m)
    {
        if (insms.find(m) != insms.end()) return insms[m];
        err(NOT_EXISTS, "meal m is not exists");
        return getErrorString(NOT_EXISTS);
    }
    void print()
    {
        cout << "meals_list print out: size() = " << size() << endl;
        for (map<string, meal> :: iterator it = inssm.begin(); it != inssm.end(); ++it){
            cout << it -> first;
            cout << ": ";
            ((meal) (it -> second)).print();
            //cout << ((meal)(it -> second)).print() << endl;
            //cout will calculate the fomula first and then print out later, so, ingredients will be printed out first of all, and the ((meal)(it -> second)).print()  is the return of the function print() which means nothing
        }
        cout << "And reverse: " << endl;
        for (map<meal, string, classcomp> :: iterator it = insms.begin(); it != insms.end(); ++it){
            cout << it -> second << ": " ;
            ((meal)(it -> first)).print();
        }
        cout << endl;
    }
    int size()
    {
        return inssm.size();
    }
};
