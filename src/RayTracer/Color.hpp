/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Color
*/

#pragma once
#include "../../main.hpp"

namespace RayTracer
{
    class Color {
        public:
            Color();
            Color(double generic);
            Color(double r, double g, double b);
            ~Color();

            double _r;
            double _g;
            double _b;

            Color operator+(const Color &other);
            Color operator*(double d);

            friend Color operator*(double t, const Color &v);

    };
    std::ostream &operator<<(std::ostream &os, const Color &c);
} // namespace RayTracer
