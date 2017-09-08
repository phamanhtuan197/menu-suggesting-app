#include "fstream"
#include "support.cpp"
#include "ingredient.cpp"
#include "meal.cpp" 
#include "meals_list.cpp"


int init_data()
{
    //read the lists of ingredient
    ingredients_list insList;
    insList.init();
    ifstream ifs1("data/ingredients_list.txt");
    int n;
    ifs1 >> n;
    for (int i = 0; i < n; ++i)
    {
        string tmp;
        ifs1 >> tmp;
        insList.add_ingredient(tmp, i);
    }
    //cout << "insList.size() = " << insList.size() << endl;
    insList.print();
    //read the list of meals
    meals_list mealsList;
    mealsList.init();
    ifstream ifs2("data/meals_list.txt");
    ifstream ifs3("data/method.txt");
    ifs2 >> n;
    for (int i = 0; i < n; ++i)
    {
        string name; 
        ifs2 >> name;
        int m; ifs3 >> m;
        ingredients_list tmp; tmp.init();
        for (int j = 0; j < m; ++j)
        {
            string in;
            ifs3 >> in;
            tmp.add_ingredient(in, insList.getIndex(in));
        }
        mealsList.add_meal(make_meal(tmp, insList.size()), name);
    }
    mealsList.print();
    ifs1.close();
    ifs2.close();
    ifs3.close();
    
    
    meals_list tmpMealsList; tmpMealsList.init();
    tmpMealsList.add_meal(make_meal(make_ingredient("thit", 0), 6), "thit");
    tmpMealsList.add_ingredient(make_ingredient("rau", 2),mealsList);
    tmpMealsList.print();
    tmpMealsList.add_ingredient(make_ingredient("muoi", 4), mealsList);
    tmpMealsList.add_ingredient(make_ingredient("dau_an", 5), mealsList);
    tmpMealsList.print();
    
}
