/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** IPrimitive
*/

#pragma once
    #include "../Math/Vector3D.hpp"
    #include "../RayTracer/Ray.hpp"
    #include "../Math/Record3D.hpp"
    #include "../RayTracer/Color.hpp"

namespace Primitive {
    class IPrimitive {
        public:
            virtual ~IPrimitive() = default;
            virtual double hits(RayTracer::Ray &r) = 0;
            virtual Math::Vector3D &getOrigin() = 0;
            virtual RayTracer::Color &getColor() = 0;
    };
} // namespace Primitive
