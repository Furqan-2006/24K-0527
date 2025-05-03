#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class DimensionMismatchError : public exception
{
public:
    const char *what() const noexcept override
    {
        return "DimensionMismatchError: Matrix dimensions do not match.";
    }
};

template <typename T>
class Matrix
{
    vector<vector<T>> data;
    int rows, cols;

public:
    Matrix(int rows, int cols, const T &initial = T())
        : rows(rows), cols(cols), data(rows, vector<T>(cols, initial)) {}

    T &at(int row, int col)
    {
        if (row >= rows || col >= cols)
            throw out_of_range("Matrix range out of bounds");
        return data[row][col];
    }

    const T &at(int row, int col) const
    {
        if (row >= rows || col >= cols)
            throw out_of_range("Matrix range out of bounds");
        return data[row][col];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    Matrix operator+(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchError();

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix &other) const
    {
        if (cols != other.rows)
            throw DimensionMismatchError();

        Matrix result(rows, other.cols, T());
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }
};

int main()
{
    Matrix<int> m1(2, 2, 1);
    Matrix<int> m2(2, 2, 2);

    try
    {
        Matrix<int> m3 = m1 * m2;
        for (int i = 0; i < m3.getRows(); i++)
        {
            for (int j = 0; j < m3.getCols(); j++)
            {
                cout << m3.at(i, j) << " ";
            }
            cout << endl;
        }
        Matrix<int> m4 = m1 + m2;
        for (int i = 0; i < m3.getRows(); i++)
        {
            for (int j = 0; j < m3.getCols(); j++)
            {
                cout << m3.at(i, j) << " ";
            }
            cout << endl;
        }
    }
    catch (const DimensionMismatchError &e)
    {
        cerr << e.what() << endl;
    }
    catch (const exception &e)
    {
        cerr << "Other error: " << e.what() << endl;
    }

    return 0;
}
