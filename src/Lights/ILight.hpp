/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** ILight
*/

#pragma once
#include "../Math/Vector3D.hpp"

namespace Light
{
    class ILight {
        public:
            virtual ~ILight() = default;
            virtual const std::string &getType() = 0;
            virtual double getIntensity() = 0;
    };
} // namespace Light
