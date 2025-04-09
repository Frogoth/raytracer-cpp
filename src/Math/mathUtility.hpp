/*
** EPITECH PROJECT, 2025
** raytracer-cpp
** File description:
** MathUtility
*/

#pragma once

#include "../../main.hpp"

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degreesToRadians(double degrees) {
    return degrees * pi / 180.0;
}
