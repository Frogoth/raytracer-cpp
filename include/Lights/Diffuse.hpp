/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Diffuse
*/

#pragma once

#include <Lights/ILight.hpp>

namespace Light
{
    class Diffuse : public ILight {
        public:
            Diffuse(double in);
            ~Diffuse();

            const std::string &getType();
            double getIntensity();
        private:
            double _intensity;
            const std::string _type;
    };
} // namespace Light
