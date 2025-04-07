/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Ambient
*/

#pragma once
#include "ILight.hpp"

namespace Light
{
    class Ambient : public ILight {
        public:
            Ambient(double in);
            ~Ambient();
            const std::string &getType();
            double getIntensity();
        private:
            double _intensity;
            const std::string _type;
    };
} // namespace Light
