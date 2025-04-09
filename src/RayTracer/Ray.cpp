/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Ray
*/

#include <RayTracer/Ray.hpp>

namespace RayTracer
{
    Ray::Ray() {
        _origin = Math::Point3D();
        _direction = Math::Vector3D();
    }

    Ray::Ray(Math::Point3D p, Math::Vector3D v) : _origin(p), _direction(v) {}

    Ray::Ray(Ray &&other) {
        _origin = std::move(other._origin);
        _direction = std::move(other._direction);
    }

    Ray::Ray(const Ray &other) {
        _origin = other._origin;
        _direction = other._direction;
    }

    Ray::~Ray() {}

    const Math::Point3D &Ray::getOrigin() const {
        return _origin;
    }

    const Math::Vector3D &Ray::getDirection() const {
        return _direction;
    }

    Math::Point3D Ray::pointAt(double t) const {
        Math::Vector3D tmpDirection = _direction;
        Math::Vector3D tmpOrigin = _origin;
        return tmpOrigin + (tmpDirection * t);
    }

    Ray &Ray::operator=(Ray &&other) {
        this->_origin = std::move(other._origin);
        this->_direction = std::move(other._direction);
        return *this;
    }

    Ray Ray::operator=(const Ray &other) {
        Ray newray;
        newray._origin = other._origin;
        newray._direction = other._direction;
        return newray;
    }

} // namespace RayTracer
