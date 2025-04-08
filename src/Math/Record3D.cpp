/*
** EPITECH PROJECT, 2025
** raytracer-cpp
** File description:
** Record3D
*/

#include "Record3D.hpp"

namespace Math
{
    void Record3D::setFaceNormal(const RayTracer::Ray &r, const Vector3D &outwardNormal) {
        frontFace = r.getDirection().dot(outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
} // namespace Math
