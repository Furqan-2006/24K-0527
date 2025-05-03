#include <iostream>
#include <string>
#include <any>
#include <stdexcept>

using namespace std;

class BadTypeException : public exception
{
    const char *what() const noexcept override
    {
        return "BadTypeException: Incorrect type requested!";
    }
};

class TypeSafeContainer
{
private:
    any var;

public:
    template <typename T>
    void store(const T val)
    {
        var = val;
    }

    template <typename T>
    T get()
    {
        try
        {
            return any_cast<T>(var);
        }
        catch (const std::bad_any_cast &)
        {
            throw BadTypeException();
        }
    }
};
int main()
{
    TypeSafeContainer container;
    container.store<string>("Hello");

    cout << container.get<string>() << endl;
    cout << container.get<int>() << endl;

    return 0;
}