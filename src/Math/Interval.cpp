/*
** EPITECH PROJECT, 2025
** raytracer-cpp
** File description:
** Interval
*/

#include <Math/Interval.hpp>

namespace Math
{
    Interval::Interval() : _min(+infinity), _max(-infinity) {}

    Interval::Interval(double min, double max) : _min(min), _max(max) {}

    Interval::~Interval() {}

    double Interval::size() const {
        return _max - _min;
    }

    bool Interval::contains(double x) const {
        return _min <= x && x <= _max;
    }

    bool Interval::surrounds(double x) const {
        return _min < x && x < _max;
    }

    const Interval Interval::_empty = Interval(+infinity, -infinity);
    const Interval Interval::_universe = Interval(-infinity, +infinity);
} // namespace Math
