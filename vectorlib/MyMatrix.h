#include "MyVector.h"

template <class T>
class Matrix : public Vector<Vector<T>>
{
public:
    Matrix() : Vector<Vector<T>>() {};
    Matrix(int _r) : Vector<Vector<T>>(_r)
    {
        for (int i = 0; i < _r; i++)
        {
            this->x[i].length = _r - i;
            this->x[i].SetStartIndex(i);
            this->x[i].x = new T[_r - i];
            for (int j = 0; j < _r - i; j++)
                this->x[i].x[j] = 0;

        }
    };

    Matrix(const Matrix& _m)
    {
        this->length = _m.length;
        this->x = new Vector<T>[this->length];
        for (int i = 0; i < this->length; i++)
            this->x[i] = _m.x[i];
    };
    Matrix(const Vector<Vector<T>>& _m) : Vector<Vector<T>>(_m)
    {
        for (int i = 0; i < this->Length(); i++)
        {
            Vector<T> result(_m.x[i]);
            this->x[i] = result;
        }
    };
    
    Matrix(int _r, T a) : Matrix<T>(_r)
    {
        for (int i = 0; i < _r; i++)
            for (int j = i; j < _r; j++)
                this->x[i][j] = a;
    };

    int get_rows()
    {
        return this->Length();
    };

    Matrix<T>& operator =(Matrix<T>& _m)
    {
        if (this == &_m)
            return *this;

        for (int i = 0; i < this->length; i++)
            this->x[i].~Vector();
        delete[] this->x;

        this->length = _m.Length();

        this->x = new Vector<T>[this->length];

        for (int i = 0; i < this->length; i++)
            this->x[i] = _m[i];
    };

    Vector<T>& operator [](const int i)
    {
        if (i > this->length || i < 0)
            throw length_error("Incorrect index");
        return this->x[i];
    };
    Matrix<T> operator +(Matrix<T>& _m)
    {
        if (this->length != _m.Length())
            throw "Matrices' sizes aren't equal";

        Matrix<T> result(this->length);
        for (int i = 0; i < this->length; i++)
            result[i] = this->x[i] + _m[i];

        return result;
    };
    Matrix<T> operator -(Matrix<T>& _m)
    {
        if (this->length != _m.Length())
            throw "Matrices' sizes aren't equal";

        Matrix<T> result(this->length);
        for (int i = 0; i < this->length; i++)
            result[i] = this->x[i] - _m[i];

        return result;
    };
    bool operator ==(const Matrix<T>& _m) const
    {
        if (this->length != _m.Length())
            return false;
        else
            for (int i = 0; i < this->length; i++)
                if (this->x[i] != _m.x[i])
                    return false;
        return true;
    };
    bool operator !=(const Matrix<T>& _m) const
    {
        return !((*this) == _m);
    };
    Matrix<T> operator *(Matrix<T>& _m) //алгоритм умножения треугольных матриц 
    {
        if (this->length != _m.Length())
            throw "Can't multiply";

        Matrix<T> result(this->length);
        T t;
        for (int i = 0; i < this->length; i++)
            for (int j = 0; j < this->length - i; j++)
            {
                t = 0; // i = 1; j = 1;
                for (int k = i; k < j + i + 1; k++)
                    t += x[i].x[k - i] * _m[k].x[j - k + i];
                result[i].x[j] = t;
            }


        return result;
    }
    Matrix<T> operator *(T n)
    {
        Matrix<T> result(this->length);
        for (int i = 0; i < this->length; i++)
            result[i] = this->x[i] * n;

        return result;
    };

    template <class T1>
    friend ostream& operator<< (ostream& ostr, const Matrix<T1>& A)
    {
        for (int i = 0; i < A.Length(); i++)
        {
            for (int k = 0; k < i; k++)
                ostr << "0 ";
            for (int j = i; j < A.x[i].Length() + i; j++)
                ostr << A.x[i][j] << " ";

            ostr << endl;
        }

        return ostr;
    };
    template <class T1>
    friend istream& operator >> (istream& istr, Matrix<T1>& A)
    {
        for (int i = 0; i < A.Length(); i++)
            istr >> A.x[i];
        return istr;
    };

};
