/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Point
*/

#pragma once

#include <Lights/ILight.hpp>

namespace Light
{
    class Point : public ILight {
        public:
            Point(Math::Vector3D p);
            ~Point();

            const std::string &getType();
            double getIntensity();
        private:
            Math::Vector3D _p;
            const std::string _type;
    };
} // namespace Light
