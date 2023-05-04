#pragma once
#include <iostream>

struct Vector2D {
    double x, y;

    Vector2D(double x = 0, double y = 0);

    Vector2D& operator +=(const Vector2D &other);
    Vector2D& operator -=(const Vector2D &other);
    Vector2D& operator *=(const Vector2D &other);
    Vector2D& operator /=(const Vector2D &other);
    template <typename T> inline Vector2D& operator *=(const T a){
        this->x *= a;
        this->y *= a;
        return *this;
    }

    Vector2D& operator +(const Vector2D &other);
    Vector2D& operator -(const Vector2D &other);
    Vector2D& operator *(const Vector2D &other);
    Vector2D& operator /(const Vector2D &other);
    template <typename T> inline Vector2D& operator *(const T a){
        Vector2D res = *this;
        res *= x;
        return res;
    }

    friend std::ostream& operator <<(std::ostream& stream, const Vector2D& vec);
};