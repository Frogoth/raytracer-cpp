/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Color
*/

#include <Math/Color.hpp>

namespace Math
{
    std::ostream &operator<<(std::ostream &os, const Color &c) {
        double r = c._x;
        double g = c._y;
        double b = c._z;

        static const Interval intensity(0.000, 0.999);

        int rbyte = int(256 * intensity.clamp(r));
        int gbyte = int(256 * intensity.clamp(g));
        int bbyte = int(256 * intensity.clamp(b));
        os << rbyte << ' ' << gbyte << ' ' << bbyte;
        return os;
    }
} // namespace Math
