/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Vector3D
*/

#pragma once
#include "../../main.hpp"

namespace Math
{
    class Vector3D {
        public:
            Vector3D();
            Vector3D(double x, double y, double z);
            Vector3D(Vector3D &&other);
            Vector3D(const Vector3D &other);
            ~Vector3D();

            double _x;
            double _y;
            double _z;

            double length() const;
            double lengthSquared() const;
            double dot(Vector3D &other);
            Vector3D unitVector();
            Vector3D unitVector(const Vector3D &v);

        Vector3D &operator=(Vector3D &&other);
        Vector3D &operator=(const Vector3D &other);

        Vector3D operator+(const Vector3D &other);
        Vector3D &operator+=(const Vector3D &other);
        Vector3D operator-(const Vector3D &other);
        Vector3D &operator-=(const Vector3D &other);
        Vector3D operator*(const Vector3D &other);
        Vector3D &operator*=(const Vector3D &other);
        Vector3D operator/(double f);
        Vector3D operator/(const Vector3D &other);
        Vector3D &operator/=(const Vector3D &other);
        friend Vector3D operator*(double t, const Vector3D &v);
        Vector3D operator*(double f);
        Vector3D &operator*=(double f);
        Vector3D &operator/=(double f);
    };
    std::ostream &operator<<(std::ostream &os, const Vector3D &v);

    using Point3D = Vector3D;

} // namespace Math
