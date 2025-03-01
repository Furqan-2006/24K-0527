#include <iostream>
using namespace std;

class Matrix
{
    int rows;
    int cols;

public:
    int **matrix;
    Matrix() // default constructor
    {
        rows = 0;
        cols = 0;
    }

    Matrix(int rows, int cols) // Parameterized constructor
    {
        this->rows = rows;
        this->cols = cols;
        this->matrix = new int *[rows];
        
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix &m) // Copy Constructor
    {
        this->rows = m.rows;
        this->cols = m.cols;

        this->matrix = new int *[rows];
        for (int i = 0; i < this->rows; i++)
        {
            matrix[i] = new int[this->cols];
        }

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                matrix[i][j] = m.matrix[i][j];
            }
        }
    }
    Matrix(Matrix &&m) // move constructor
    {
        this->rows = m.rows;
        this->cols = m.cols;
        this->matrix = m.matrix;

        m.matrix = nullptr;
        m.rows = 0;
        m.cols = 0;
    }

    ~Matrix() // destructor
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // member  functions

    int getRows()
    {
        return rows;
    }

    int getCols()
    {
        return cols;
    }

    void fill(int val)
    {

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {

                this->matrix[i][j] = 4;
            }
        }
    }

    void transpose()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = matrix[j][i];
            }
        }
    }
};

int main()
{
    Matrix m1(2, 4);
    m1.fill(4);

    for (int i = 0; i < m1.getRows(); i++)
    {
        for (int j = 0; j < m1.getCols(); j++)
        {
            cout << m1.matrix[i][j] << "  ";
        }
        cout << "\n";
    }

    return 0;
}