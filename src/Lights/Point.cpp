/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Point
*/

#include "Point.hpp"

namespace Light
{
    Point::Point(Math::Vector3D p) : _p(p), _type("point") {}

    Point::~Point() {}

    const std::string &Point::getType() {
        return _type;
    }

    double Point::getIntensity() {
        return (1.0);
    }
} // namespace Light
