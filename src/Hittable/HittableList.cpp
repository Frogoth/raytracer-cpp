/*
** EPITECH PROJECT, 2025
** raytracer-cpp
** File description:
** HittableList
*/

#include <Hittable/HittableList.hpp>

namespace Hittable
{
    HittableList::HittableList() {}
    HittableList::HittableList(std::shared_ptr<IHittable> object) {
        add(object);
    }
    HittableList::~HittableList() {}

    void HittableList::clear() {
        objects.clear();
    }

    void HittableList::add(std::shared_ptr<IHittable> object) {
        objects.push_back(object);
    }

    bool HittableList::hits(const RayTracer::Ray &r, Math::Interval ray_t, Math::Record3D &rec) const {
        Math::Record3D tmpRec;
        bool hitAnything = false;
        double closestSoFar = ray_t._max;

        for (const auto &object : objects) {
            if (object->hits(r, Math::Interval(ray_t._min, closestSoFar), tmpRec)) {
                hitAnything = true;
                closestSoFar = tmpRec.t;
                rec = tmpRec;
            }
        }

        return hitAnything;
    }

} // namespace Hittable
