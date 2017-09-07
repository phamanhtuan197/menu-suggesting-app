#include "fstream"
#include "support.cpp"
#include "ingredient.cpp"
#include "meal.cpp" 
#include "meals_list.cpp"


int init_data(ingredients_list &insList, meals_list &mealsList, meal &input)
{
    //read the lists of ingredient
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
        mealsList.add_meal(make_meal(tmp), name);
    }
    mealsList.print();
    ifs1.close();
    ifs2.close();
    ifs3.close();
    
    //read the input
    ifstream ifs4("data/input.txt");
    ifs4 >> n;
    for (int i = 0; i < n; ++i)
    {
        string tmp;
        ifs4 >> tmp;
        input.add_ingredient(make_ingredient(tmp, insList.getIndex(tmp)));
    }
    ifs4.close();
    input.print();
    cout << "/!\\ Init ok " << endl;
}

//init is good 2017-09-08 08:50 GMT + 7
