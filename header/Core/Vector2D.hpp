#pragma once
#include <iostream>

struct Vector2D {
    double x, y;

    Vector2D(double x = 0, double y = 0);

    Vector2D& operator +=(const Vector2D other);
    Vector2D& operator -=(const Vector2D other);
    Vector2D& operator *=(const Vector2D other);
    Vector2D& operator /=(const Vector2D other);
    Vector2D& operator *=(const double a);

    friend Vector2D operator +(Vector2D a, const Vector2D b);
    friend Vector2D operator -(Vector2D a, const Vector2D b);
    friend Vector2D operator *(Vector2D a, const Vector2D b);
    friend Vector2D operator /(Vector2D a, const Vector2D b);
    friend Vector2D operator *(Vector2D a, const double b);
    friend std::ostream& operator <<(std::ostream& stream, const Vector2D& vec);
};