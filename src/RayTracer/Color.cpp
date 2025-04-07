/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Color
*/

#include "Color.hpp"

namespace RayTracer
{
    Color::Color() : _r(0), _g(0), _b(0) {}
    Color::Color(double generic) : _r(generic), _g(generic), _b(generic) {}
    Color::Color(double r, double g, double b) : _r(r), _g(g), _b(b) {}
    Color::~Color() {}

    Color Color::operator+(const Color &other) {
        float r = this->_r + other._r;
        float g = this->_g + other._g;
        float b = this->_b + other._b;

        r = (r > 1.0) ? 1.0 : r;
        g = (g > 1.0) ? 1.0 : g;
        b = (b > 1.0) ? 1.0 : b;

        return Color(r, g, b);
    }

    Color Color::operator*(double d) {
        float r = this->_r + d;
        float g = this->_g + d;
        float b = this->_b + d;

        r = (r > 1.0) ? 1.0 : r;
        g = (g > 1.0) ? 1.0 : g;
        b = (b > 1.0) ? 1.0 : b;

        return Color(r, g, b);
    }

    Color operator*(double t, const Color &c) {
        return Color(c._r * t, c._g * t, c._b * t);
    }

    std::ostream &operator<<(std::ostream &os, const Color &c) {
        double r = c._r;
        double g = c._g;
        double b = c._b;
        int rbyte = int(255.999 * r);
        int gbyte = int(255.999 * g);
        int bbyte = int(255.999 * b);
        os << rbyte << ' ' << gbyte << ' ' << bbyte;
        return os;
    }
} // namespace RayTracer
