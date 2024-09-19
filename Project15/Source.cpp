#include<iostream> 
#include "Time.h"
using namespace std;
//Создать класс для работы с матрицами. 
//Предусмотреть, как минимум, функции для сложения матриц,  
//умножения матриц, транспонирования матриц, присваивания матриц друг другу(конструктор копирования),  
// установка и получение произвольного элемента матрицы(доступ через индексы). 

class Matrix
{
    int** ptr;
    int str; 
    int st; 

public:

    Matrix()
    {
        ptr = nullptr;
        str = st = 0;
    }
    Matrix(int _str, int _st)
    {
        str = _str;
        st = _st;
        ptr = new int* [str];

        for (int i = 0; i < str; i++)
        {
            ptr[i] = new int[st] {0};
        }

    }
    void Index(int x, int y)
    {
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < st; j++)
            {
                if (x == i && y == j)
                {
                    cout << "Index (" << x << ", " << y << ") - " << ptr[i][j] << endl;
                }
            }
        }
    }
    void Input()
    {
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < st; j++)
            {
                ptr[i][j] = rand() % 10;
            }
        }
    }
    void Print()const
    {
        cout << "Matrix: " << endl;
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < st; j++)
            {
                cout << ptr[i][j] << "\t";
            }
            cout << endl << endl;
        }
    }
    void Sum(const Matrix& obj)const
    {

        if (str == obj.str && st == obj.st)
        {
            Matrix rez(str, st);
            for (int i = 0; i < str; i++)
            {
                for (int j = 0; j < st; j++)
                {
                    rez.ptr[i][j] = ptr[i][j] + obj.ptr[i][j];
                }
            }
            cout << "Sum: " << endl;
            rez.Print();
            // return rez;
        }
        else
        {
            cout << "Invalid" << endl;
            // return *this;
        }
    }
    void Mult(const Matrix& obj)const
    {
        if (str == obj.st)
        {
            Matrix rez(str, st);
            for (int i = 0; i < str; i++)
            {
                for (int j = 0; j < obj.st; j++)
                {
                    for (int k = 0; k < st; k++)
                    {
                        rez.ptr[i][j] += ptr[i][k] * obj.ptr[k][j];
                    }
                }
            }
            cout << "Mult: " << endl;
            rez.Print();
            //return rez;
        }
        else
        {
            cout << "Invalid" << endl;
            // return *this;
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < str; i++)
        {
            delete[]ptr[i];
        }
        delete[] ptr;
        cout << "Destructor\n";
    }

};

int main()
{
    srand(time(0));
    Matrix obj1(3, 3);
    Matrix obj2(5, 3);
    Matrix obj3(3, 3);
    Matrix obj4 = obj1;


    obj1.Input();
    obj2.Input();
    obj3.Input();

    obj1.Print();

    obj1.Index(0, 2);

    obj2.Print();
    obj3.Print();
    obj4.Print();


    obj1.Sum(obj3);
    obj1.Mult(obj2);

}