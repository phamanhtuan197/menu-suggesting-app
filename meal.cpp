#pragma once
#include "support.cpp"
#include "ingredient.cpp"
#include <set>
#include <map>
class meal{
public:
    set<int> ingredients;
    int add_ingredient(ingredients_list insList)
    {
        for (map<int, string> :: iterator it = insList.insis.begin(); it != insList.insis.end(); ++it)
        {
            ingredients.insert(it -> first);
            //cout << "/!\\ " << it -> first << endl;
        }
    }
    bool exists(int ingredient_index)
    {
        if (ingredients.find(ingredient_index) != ingredients.end())
            return true;
        else return false;
    }
    int erase(int ingredient_index)
    {
        if (ingredients.find(ingredient_index) != ingredients.end())
        {
            ingredients.erase(ingredients.find(ingredient_index));
            return OK;
        }
        else 
            return NOT_EXISTS;
    }
    int print()
    {
        for (set<int> :: iterator it = ingredients.begin(); it != ingredients.end(); ++it)
            cout << (*it) << ", ";
        cout << endl;
    }
};

meal make_meal(ingredients_list insList)
{
    meal m;
    m.add_ingredient(insList);
    return m;
}
