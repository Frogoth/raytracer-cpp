/*
** EPITECH PROJECT, 2025
** raytracer-cpp
** File description:
** Interval
*/

#pragma once

#include <Math/mathUtility.hpp>

namespace Math
{
    class Interval {
        public:
            Interval();
            Interval(double min, double max);
            ~Interval();

            double size() const;
            bool contains (double x) const;
            bool surrounds(double x) const;
            double clamp(double x) const;

            double _min;
            double _max;

            static const Interval _empty;
            static const Interval _universe;
    };
} // namespace Math
