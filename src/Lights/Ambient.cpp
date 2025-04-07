/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Ambient
*/

#include "Ambient.hpp"

namespace Light
{
    Ambient::Ambient(double in) : _intensity(in), _type("ambient") {}

    Ambient::~Ambient() {}

    const std::string &Ambient::getType() {
        return _type;
    }

    double Ambient::getIntensity() {
        return _intensity;
    }
} // namespace Light
