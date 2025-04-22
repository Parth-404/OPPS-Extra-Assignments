/*Make a class named Fruit with a data member to calculate the number of fruits in a basket. Create
 two other class named Apples and Mangoes to calculate the number of apples and mangoes in the
 basket. Print the number of fruits of each type and the total number of fruits in the basket.*/
 
#include<bits/stdc++.h>
using namespace std;

class Basket 
{
    public:
    int totalFruits = 0;

    void calculateTotal(int applesCount, int mangoesCount)
    {
        totalFruits = applesCount + mangoesCount;
        cout << "Total number of fruits: " << totalFruits << endl;
    }
};

class Apples : public Basket
{
    public:
    int applesCount = 0;

    Apples(int count)
    {
        applesCount += count;
        cout << "Apples: " << applesCount << endl;
    }

    int getAppleCount()
    {
        return applesCount;
    }
};

class Mangoes : public Basket
{
    public:
    int mangoesCount = 0;

    Mangoes(int count)
    {
        mangoesCount += count;
        cout << "Mangoes: " << mangoesCount << endl;
    }

    int getMangoCount()
    {
        return mangoesCount;
    }
};

int main()
{
    Apples appleBasket(5);
    Mangoes mangoBasket(7);

    Basket totalBasket;
    totalBasket.calculateTotal(appleBasket.getAppleCount(), mangoBasket.getMangoCount());

    return 0;
}
