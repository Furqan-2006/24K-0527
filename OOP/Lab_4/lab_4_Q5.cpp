#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MenuItem
{
    string itemName;
    string itemType;
    double itemPrice;
};

class CoffeeShop
{
private:
    string name;
    vector<string> orders;
    vector<MenuItem> menu;

public:
    CoffeeShop(string shopName) : name(shopName) {}

    void addMenuItem(MenuItem item)
    {
        menu.push_back(item);
    }

    void addOrder(string item)
    {
        bool found = false;
        for (MenuItem &m : menu)
        {
            if (m.itemName == item)
            {
                orders.push_back(item);
                cout << "Order placed." << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "This item is currently unavailable" << endl;
        }
    }

    void fulfillOrder()
    {
        if (orders.empty())
        {
            cout << "All orders have been fulfilled!" << endl;
        }
        else
        {
            cout << "The " << orders.front() << " is ready." << endl;
            orders.erase(orders.begin());
        }
    }

    void listOrders()
    {
        if (orders.empty())
        {
            cout << "No current orders." << endl;
        }
        else
        {
            for (const string &order : orders)
            {
                cout << order << endl;
            }
        }
    }

    double dueAmount()
    {
        double total = 0;
        for (string &order : orders)
        {
            for (MenuItem &m : menu)
            {
                if (m.itemName == order)
                {
                    total += m.itemPrice;
                }
            }
        }
        return total;
    }

    string cheapestItem()
    {
        if (menu.empty())
            return "No items in menu";

        MenuItem cheapest = menu[0];
        for (MenuItem &m : menu)
        {
            if (m.itemPrice < cheapest.itemPrice)
            {
                cheapest = m;
            }
        }
        return cheapest.itemName;
    }

    void drinkOnly()
    {
        bool found = false;
        for (MenuItem &m : menu)
        {
            if (m.itemType == "drink")
            {
                cout << m.itemName << endl;
                found = true;
            }
        }
        if (!found)
            cout << "No drinks available." << endl;
    }

    void foodOnly()
    {
        bool found = false;
        for (MenuItem &m : menu)
        {
            if (m.itemType == "food")
            {
                cout << m.itemName << endl;
                found = true;
            }
        }
        if (!found)
            cout << "No food available." << endl;
    }
};

int main()
{
    CoffeeShop shop("Java Cafe");

    shop.addMenuItem({"Coffee", "drink", 2.5});
    shop.addMenuItem({"Latte", "drink", 3.0});
    shop.addMenuItem({"Tea", "drink", 2.0});
    shop.addMenuItem({"Sandwich", "food", 5.0});
    shop.addMenuItem({"Cake", "food", 4.0});

    shop.addOrder("Coffee");
    shop.addOrder("Tea");
    shop.addOrder("Pizza");

    cout << "\nOrders:" << endl;
    shop.listOrders();

    shop.fulfillOrder();

    cout << "\nTotal due: $" << shop.dueAmount() << endl;

    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    cout << "\nDrinks available:" << endl;
    shop.drinkOnly();

    cout << "\nFood available:" << endl;
    shop.foodOnly();

    return 0;
}
