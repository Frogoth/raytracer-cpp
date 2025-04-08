/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Color
*/

#include "Color.hpp"

namespace Math
{
    std::ostream &operator<<(std::ostream &os, const Color &c) {
        auto clamp = [](double x, double min, double max) {
            return x < min ? min : (x > max ? max : x);
        };

        double r = clamp(c._x, 0.0, 1.0);
        double g = clamp(c._y, 0.0, 1.0);
        double b = clamp(c._z, 0.0, 1.0);
        int rbyte = int(255.999 * r);
        int gbyte = int(255.999 * g);
        int bbyte = int(255.999 * b);
        os << rbyte << ' ' << gbyte << ' ' << bbyte;
        return os;
    }
} // namespace Math
