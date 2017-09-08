#pragma once
#include "support.cpp"
#include "ingredient.cpp"

class meal{
    bool *ingredient_matrix;
    int length;
public:
    int init(int length)
    {
        if (length < 1) return err(INVALID_VALUE, "length cannot be less than 1");
        ingredient_matrix = new bool[length];
        for (int i = 0; i < length; ++i)
            ingredient_matrix[i] = false;
        this -> length = length;
    }
    int get_length(){ return length;}
    int set_bit(int index, int value=1)
    {
        if (index >= this->length)
            return err(INVALID_VALUE, "index cannot be equal or greater than length");
        ingredient_matrix[index] = value;
    }
    int get_bit(int index)
    {
        if (index >= this->length)
            return err(INVALID_VALUE, "index cannot be equal or greater than length");
        return ingredient_matrix[index];
    }
    string get_bit_sequence()
    {
        string r = "";
        for (int i = 0; i < length; ++i)
            r.push_back((char) (ingredient_matrix[i] + '0'));
        return r;
    }
};

meal make_meal(ingredients_list insList, int max_number_ingredient = -1)
{
    if (max_number_ingredient < 1) err(INVALID_VALUE, "max number of ingredient cannot be less than 1");
    meal r;
    r.init (max_number_ingredient);
    for (map<int, string> :: iterator it = insList.insis.begin(); it != insList.insis.end(); ++it)
    {
        //cerr << "adding ingredient name " << it -> second << " index " << it -> first << endl;
        r.set_bit(it -> first);
    }
    return r;
}

meal operator+(meal m, ingredients_list insList)
{
    for (map<int, string> :: iterator it = insList.insis.begin(); it != insList.insis.end(); ++it)
    {
        //cerr << "adding ingredient name " << it -> second << " index " << it -> first << endl;
        m.set_bit(it -> first);
    }
    return m;
}
meal copy(meal source)
{
    meal r;
    int len = source.get_length();
    r. init(len);
    for (int i = 0; i < len; ++i)
    {
        r.set_bit(i, source.get_bit(i));
    }
    return r;
}
