#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    vector<vector<int>> elements;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        elements.resize(rows, vector<int>(cols, 0));
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void setElement(int i, int j, int value)
    {

        if ((i >= 0 && i < rows) && (j >= 0 && j < cols))
        {
            elements[i][j] = value;
        }
        else
        {
            cout << "Invalid position!";
        }
    }

    void display() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrix add(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrices cannot be added!" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }

    Matrix multiply(const Matrix &other) const
    {
        if (cols != other.rows)
        {
            cout << "Matrices cannot be multiplied!" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }
};

int main()
{
    int r1, r2, c1, c2;

    cout << "Enter rows and columns for the first Matrix: ";
    cin >> r1 >> c1;
    Matrix m1(r1, c1);

    cout << "Enter elements of the matrix: " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            int val;
            cin >> val;
            m1.setElement(i, j, val);
        }
    }

    cout << "Enter rows and columns for the second Matrix: ";
    cin >> r2 >> c2;
    Matrix m2(r2, c2);

    cout << "Enter elements of the matrix: " << endl;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            int val;
            cin >> val;
            m2.setElement(i, j, val);
        }
    }

    cout << "Matrix 1: " << endl;
    m1.display();
    cout << "Matrix 2: " << endl;
    m2.display();

    cout << "\n Matrix Addition Result: " << endl;
    Matrix sum = m1.add(m2);
    sum.display();

    cout << "\n Matrix Multiplication Result: " << endl;
    Matrix product = m1.multiply(m2);
    product.display();

    return 0;
}