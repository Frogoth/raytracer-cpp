/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Record3D
*/

#pragma once

#include "../RayTracer/Ray.hpp"

namespace Math
{
    class Record3D {
        public:
            Vector3D p;
            Vector3D normal;
            double t;
            bool frontFace;

            void setFaceNormal(const RayTracer::Ray &r, const Vector3D &outwardNormal);
    };
} // namespace Math
