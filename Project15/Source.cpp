#include<iostream> 
#include "Time.h"
using namespace std;
//Ñîçäàòü êëàññ äëÿ ðàáîòû ñ ìàòðèöàìè. 
//Ïðåäóñìîòðåòü, êàê ìèíèìóì, ôóíêöèè äëÿ ñëîæåíèÿ ìàòðèö,  
//óìíîæåíèÿ ìàòðèö, òðàíñïîíèðîâàíèÿ ìàòðèö, ïðèñâàèâàíèÿ ìàòðèö äðóã äðóãó(êîíñòðóêòîð êîïèðîâàíèÿ),  
// óñòàíîâêà è ïîëó÷åíèå ïðîèçâîëüíîãî ýëåìåíòà ìàòðèöû(äîñòóï ÷åðåç èíäåêñû). 
template <class T>
class Matrix
{
    T** ptr;
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
        ptr = new T * [str];

        for (int i = 0; i < str; i++)
        {
            ptr[i] = new T[st]{ 0 };
        }

    }
    Matrix(const Matrix& obj)
    {
        str = obj.str;
        st = obj.st;
        ptr = new T * [str];

        for (int i = 0; i < str; i++)
        {
            ptr[i] = new T[st]{ 0 };
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
                ptr[i][j] = rand() % 100;
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
        }
        else
        {
            cout << "Invalid" << endl;
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
class Point
{
    int x;
    int y;
    friend ostream& operator<<(ostream& os, Point& obj);
public:
    Point()
    {
        x = y = 0;
    }
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    void Input()
    {
        x = rand() % 100;
        y = rand() % 100;
    }
    void Print()const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
ostream& operator<<(ostream& os, Point& obj)
{
    os << obj.x << "\t";
    os << obj.y << "\t";
    return os;
}
int main()
{
    srand(time(0));
    /*Matrix <int> obj1(3, 3);
    Matrix <double> obj2(5, 3);
    Matrix <int> obj3(3, 3);
    Matrix <double> obj4(2, 2);
    Matrix <double> obj5 = obj4;


    obj1.Input();
    obj2.Input();
    obj3.Input();

    obj1.Print();

    obj1.Index(0, 2);

    obj2.Print();
    obj3.Print();
    obj4.Print();
    obj5.Print();


    obj1.Sum(obj3);
    obj2.Mult(obj5);*/
    Matrix<Point>obj6(2, 2);
    obj6.Input();
    obj6.Print();
}