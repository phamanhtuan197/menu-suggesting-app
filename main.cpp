#include "ingredient.cpp"
#include "support.cpp"
#include "meals_list.cpp"
#include "exception.cpp"
#include "meal.cpp"
#include "init.cpp"
int main()
{
    ingredients_list insList;
    meals_list mealsList;
    meal input;
	init_data(insList, mealsList, input);
    // now for like a buffalo
    for (map<string, meal>::iterator it = mealsList.inssm.begin(); it != mealsList.inssm.end(); ++it)
    {
        string name = it -> first;
        meal m = (meal) (it -> second);
        bool good = true;
        for (set<int> :: iterator jt = m.ingredients.begin(); jt != m.ingredients.end(); ++jt)
        {
            if (input.exists(*jt))
            {
                //find for now
            }
            else
            {
                good = false;
                break;
            }
        }
        if (good == true)
        {
            cout << "find a meal you can cook: " << name << endl;
        }
    }
}
