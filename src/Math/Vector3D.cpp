/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

namespace Math
{
    Vector3D::Vector3D() : _x(0), _y(0), _z(0) {}

    Vector3D::Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}

    Vector3D::Vector3D(Vector3D &&other) {
        _x = std::move(other._x);
        _y = std::move(other._y);
        _z = std::move(other._z);
    }

    Vector3D::Vector3D(const Vector3D &other) {
        _x = other._x;
        _y = other._y;
        _z = other._z;
    }

    Vector3D::~Vector3D() {}


    double Vector3D::length() const {
        return (std::sqrt(lengthSquared()));
    }

    double Vector3D::lengthSquared() const {
        return (std::pow(_x, 2) + std::pow(_y, 2) + std::pow(_z, 2));
    }

    double Vector3D::dot(Vector3D &other) const {
        return ((this->_x * other._x) + (this->_y * other._y) + (this->_z * other._z));
    }

    double Vector3D::dot(const Vector3D &other) const {
        return ((this->_x * other._x) + (this->_y * other._y) + (this->_z * other._z));
    }

    Vector3D Vector3D::unitVector() const {
        Vector3D cp = *this;
        return cp / cp.length();
    }

    Vector3D Vector3D::unitVector(const Vector3D &v) {
        Vector3D cp = v;
        return cp / cp.length();
    }

    Vector3D &Vector3D::operator=(Vector3D &&other) {
        this->_x = std::move(other._x);
        this->_y = std::move(other._y);
        this->_z = std::move(other._z);
        return *this;
    }

    Vector3D &Vector3D::operator=(const Vector3D &other) {
        this->_x = other._x;
        this->_y = other._y;
        this->_z = other._z;
        return *this;
    }

    Vector3D Vector3D::operator+(const Vector3D &other) {
        Vector3D newVec;
        newVec._x = this->_x + other._x;
        newVec._y = this->_y + other._y;
        newVec._z = this->_z + other._z;
        return newVec;
    }

    Vector3D &Vector3D::operator+=(const Vector3D &other) {
        this->_x += other._x;
        this->_y += other._y;
        this->_z += other._z;
        return *this;
    }

    Vector3D Vector3D::operator-(const Vector3D &other) const {
        Vector3D newVec;
        newVec._x = this->_x - other._x;
        newVec._y = this->_y - other._y;
        newVec._z = this->_z - other._z;
        return newVec;
    }

    Vector3D &Vector3D::operator-=(const Vector3D &other) {
        this->_x -= other._x;
        this->_y -= other._y;
        this->_z -= other._z;
        return *this;
    }

    Vector3D Vector3D::operator*(const Vector3D &other) {
        Vector3D newVec;
        newVec._x = this->_x * other._x;
        newVec._y = this->_y * other._y;
        newVec._z = this->_z * other._z;
        return newVec;
    }

    Vector3D &Vector3D::operator*=(const Vector3D &other) {
        this->_x *= other._x;
        this->_y *= other._y;
        this->_z *= other._z;
        return *this;
    }

    Vector3D Vector3D::operator/(const Vector3D &other) {
        Vector3D newVec;
        newVec._x = this->_x / other._x;
        newVec._y = this->_y / other._y;
        newVec._z = this->_z / other._z;
        return newVec;
    }

    Vector3D &Vector3D::operator/=(const Vector3D &other) {
        this->_x /= other._x;
        this->_y /= other._y;
        this->_z /= other._z;
        return *this;
    }

    Vector3D operator*(double t, const Vector3D &v) {
        return Vector3D(v._x * t, v._y * t, v._z * t);
    }

    Vector3D Vector3D::operator*(double f) {
        Vector3D newVec;
        newVec._x = this->_x * f;
        newVec._y = this->_y * f;
        newVec._z = this->_z * f;
        return newVec;
    }

    Vector3D &Vector3D::operator*=(double f) {
        this->_x *= f;
        this->_y *= f;
        this->_z *= f;
        return *this;
    }

    Vector3D Vector3D::operator/(double f) {
        Vector3D newVec;
        newVec._x = this->_x / f;
        newVec._y = this->_y / f;
        newVec._z = this->_z / f;
        return newVec;
    }

    Vector3D &Vector3D::operator/=(double f) {
        this->_x /= f;
        this->_y /= f;
        this->_z /= f;
        return *this;
    }

    Vector3D Vector3D::operator-() const {
        return Vector3D(-_x, -_y, -_z);
    }

    inline Vector3D operator/(const Vector3D &v, double t) {
        return (1/t) * v;
    }

} // namespace Math
