#include <Core/Vector2D.hpp>

Vector2D::Vector2D(double x, double y){
    this->x = x;
    this->y = y;
}

Vector2D& Vector2D::operator +=(const Vector2D &other){
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2D& Vector2D::operator -=(const Vector2D &other){
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vector2D& Vector2D::operator *=(const Vector2D &other){
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}

Vector2D& Vector2D::operator /=(const Vector2D &other){
    this->x /= other.x;
    this->y /= other.y;
    return *this;
}

Vector2D& Vector2D::operator +(const Vector2D &b){
    Vector2D res = *this;
    res += b;
    return res;
}

Vector2D& Vector2D::operator -(const Vector2D &b){
    Vector2D res = *this;
    res -= b;
    return res;
}

Vector2D& Vector2D::operator *(const Vector2D &b){
    Vector2D res = *this;
    res *= b;
    return res;
}

Vector2D& Vector2D::operator /(const Vector2D &b){
    Vector2D res = *this;
    res /= b;
    return res;
}

std::ostream& operator <<(std::ostream& stream, const Vector2D& vec){
    stream << "( " << vec.x << ", " << vec.y << ")";
    return stream;
}