/*
** EPITECH PROJECT, 2025
** raytracer-cpp
** File description:
** HittableList
*/

#pragma once

#include <main.hpp>
#include <Hittable/IHittable.hpp>

namespace Hittable
{
    class HittableList : public IHittable{
        public:
            HittableList();
            HittableList(std::shared_ptr<IHittable> object);
            ~HittableList();

            void clear();
            void add(std::shared_ptr<IHittable> object);
            bool hits(const RayTracer::Ray &r, Math::Interval ray_t, Math::Record3D &rec) const override;

        std::vector<std::shared_ptr<IHittable>> objects;

    };
} // namespace Hittable
