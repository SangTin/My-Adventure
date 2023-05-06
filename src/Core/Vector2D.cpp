#include <Core/Vector2D.hpp>

Vector2D::Vector2D(double x, double y){
    this->x = x;
    this->y = y;
}

Vector2D& Vector2D::operator +=(const Vector2D other){
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2D& Vector2D::operator -=(const Vector2D other){
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vector2D& Vector2D::operator *=(const Vector2D other){
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}

Vector2D& Vector2D::operator /=(const Vector2D other){
    this->x /= other.x;
    this->y /= other.y;
    return *this;
}

Vector2D& Vector2D::operator *=(const double a){
    this->x *= a;
    this->y *= a;
    return *this;
}

Vector2D operator +(Vector2D a, const Vector2D b){
    a += b;
    return a;
}

Vector2D operator -(Vector2D a, const Vector2D b){
    a -= b;
    return a;
}

Vector2D operator *(Vector2D a, const Vector2D b){
    a *= b;
    return a;
}

Vector2D operator /(Vector2D a, const Vector2D b){
    a /= b;
    return a;
}

Vector2D operator *(Vector2D a, const double b){
    a *= b;
    return a;
}

std::ostream& operator <<(std::ostream& stream, const Vector2D& vec){
    stream << "( " << vec.x << ", " << vec.y << ")";
    return stream;
}