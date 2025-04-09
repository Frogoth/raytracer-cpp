/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Diffuse
*/

#include <Lights/Diffuse.hpp>

namespace Light
{
    Diffuse::Diffuse(double in) : _intensity(in), _type("diffuse") {}

    Diffuse::~Diffuse() {}

    const std::string &Diffuse::getType() {
        return _type;
    }

    double Diffuse::getIntensity() {
        return _intensity;
    }
} // namespace Light
