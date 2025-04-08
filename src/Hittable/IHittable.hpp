/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** IHittable
*/

#pragma once
    #include "../Math/Vector3D.hpp"
    #include "../RayTracer/Ray.hpp"
    #include "../Math/Record3D.hpp"
    #include "../Math/Color.hpp"

namespace Hittable {
    class IHittable {
        public:
            virtual ~IHittable() = default;
            virtual bool hits(const RayTracer::Ray &r, double rayTmin, double rayTmax, Math::Record3D &rec) const = 0;
    };
} // namespace Hittable
