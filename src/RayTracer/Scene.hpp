/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Scene
*/

#pragma once
#include "../Primitives/IPrimitive.hpp"
#include "../Primitives/Sphere.hpp"
#include "../Lights/ILight.hpp"
#include "../RayTracer/Camera.hpp"

namespace RayTracer
{
    class Scene {
        public:
            Scene();
            ~Scene();

        void traceThatRay();
        void addPrim(std::shared_ptr<Primitive::IPrimitive> p);
        void addLight(std::shared_ptr<Light::ILight> l);
        void addCam(Camera c);
        bool isPrimEmpty();

        private:
            std::vector<std::shared_ptr<Primitive::IPrimitive>> _prim;
            std::vector<std::shared_ptr<Light::ILight>> _lights;
            Camera _cam;
    };
} // namespace RayTracer
