#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class User
{
    string user_id;
    string first_name;
    string last_name;
    string address;
    string email;

public:
    User(string id, string fn, string ln, string ad, string em)
        : user_id(id), first_name(fn), last_name(ln), address(ad), email(em) {}

    string getFirstName() const
    {
        return first_name;
    }
    string getUserId() const
    {
        return user_id;
    }
};

class Product
{
    string product_id;
    string product_name;
    string description;
    double price;

public:
    Product(string id, string pn, string des, double pr)
        : product_id(id), product_name(pn), description(des), price(pr) {}

    string getProductName() const
    {
        return product_name;
    }
    string getProductId() const
    {
        return product_id;
    }
};

class Order
{
    string order_id;
    string user_id;
    string product_ordered;
    double total_paid;

public:
    Order(string id, string u, string po, double tp)
        : order_id(id), user_id(u), product_ordered(po), total_paid(tp) {}

    string getUserId() const
    {
        return user_id;
    }
    string getProductsOrdered() const { return product_ordered; }
};

class DBS
{
    vector<User> users;
    vector<Product> products;
    vector<Order> orders;

    vector<string> split(const string &line)
    {
        vector<string> tokens;
        string token;
        stringstream ss(line);
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }
        return tokens;
    };

public:
    void loadUsers(const string &filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "Failed to open users.csv file!" << endl;
            return;
        }
        string line;
        getline(file, line);
        while (getline(file, line))
        {
            auto fields = split(line);
            if (fields.size() >= 5)
            {
                users.emplace_back(fields[0], fields[1], fields[2], fields[3], fields[4]);
            }
        }
        file.close();
    }
    void loadProducts(const string &filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "Failed to open the products.csv file!" << endl;
            return;
        }
        string line;
        getline(file, line);
        while (getline(file, line))
        {
            auto fields = split(line);
            if (fields.size() >= 4)
            {
                products.emplace_back(fields[0], fields[1], fields[2], stod(fields[3]));
            }
        }
        file.close();
    }
    void loadOrders(const string &filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "Failed to open the orders.csv file!" << endl;
            return;
        }
        string line;
        getline(file, line);
        while (getline(file, line))
        {
            auto fields = split(line);
            if (fields.size() >= 4)
            {
                orders.emplace_back(fields[0], fields[1], fields[2], stod(fields[3]));
            }
        }
        file.close();
    }
    vector<string> getProducts(const string &firstName)
    {
        vector<string> product_names;
        string user_id;

        for (const auto &user : users)
        {
            if (user.getFirstName() == firstName)
            {
                user_id = user.getUserId();
                break;
            }
        }
        if (user_id.empty())
        {
            cout << "User Not Found!" << endl;
            return product_names;
        }
        vector<string> ordered_product_ids;
        for (const auto &order : orders)
        {
            if (order.getUserId() == user_id)
            {
                ordered_product_ids.push_back(order.getProductsOrdered());
            }
        }
        for (const auto &pid : ordered_product_ids)
        {
            for (const auto &product : products)
            {
                if (product.getProductId() == pid)
                {
                    product_names.push_back(product.getProductName());
                }
            }
        }
        return product_names;
    }
};

int main()
{
    DBS db;

    db.loadUsers("users.csv");
    db.loadProducts("products.csv");
    db.loadOrders("orders.csv");

    vector<string> products = db.getProducts("Linus");

    cout << "Products ordered by Linus:" << endl;
    for (const auto &product : products)
    {
        cout << "- " << product << endl;
    }

    return 0;
}