/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Scene
*/

#pragma once

#include <Hittable/HittableList.hpp>
#include <Hittable/Sphere.hpp>
#include <Lights/ILight.hpp>
#include <RayTracer/Camera.hpp>

namespace RayTracer
{
    class Scene {
        public:
            Scene();
            ~Scene();

        void render();
        void addLight(std::shared_ptr<Light::ILight> l);
        void addCam(Camera c);
        bool isPrimEmpty();

        Hittable::HittableList _world;
        private:
            Camera _cam;
    };
} // namespace RayTracer
