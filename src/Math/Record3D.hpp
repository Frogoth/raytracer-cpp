/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Record3D
*/

#pragma once
#include "Vector3D.hpp"

namespace Math
{
    class Record3D {
        public:
            Vector3D p;
            Vector3D normal;
            double t;
    };
} // namespace Math
