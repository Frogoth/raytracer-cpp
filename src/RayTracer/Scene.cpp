/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Scene
*/

#include <RayTracer/Scene.hpp>

namespace RayTracer
{
    Scene::Scene() {}

    Scene::~Scene() {}

    // void Scene::addLight(std::shared_ptr<Light::ILight> l) {
    //     this->_lights.push_back(l);
    // }

    void Scene::addCam(Camera c) {
        _cam = c;
    }

    void Scene::render() {
        std::ofstream File("renders/test.ppm");
        int imageWidth = _cam._iPixelW;
        int imageHeight = _cam._iPixelH;

        // first line in file
        File << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

        for (int j = 0; j < imageHeight; j++) {
            // progress indicator
            std::clog << "\rScanlines remaining: " << (imageHeight - j) << '/' << imageHeight << ' ' << std::flush;
            for (int i = 0; i < imageWidth; i++) {
                Math::Color pixelColor(0, 0, 0);
                for (int sample = 0; sample < _cam._samplesPerPixels; sample++) {
                    RayTracer::Ray ray = _cam.getRay(i, j);
                    pixelColor += _cam.rayColor(ray, _world);
                }
                Math::Color drawPixel = pixelColor * _cam._pixelSamplesScale;
                File << drawPixel << "\n";
            }
        }
        // end of progress indicator
        std::clog << "\rDone.                                  \n";
    }

    bool Scene::isPrimEmpty() {
        return _world.objects.empty();
    }
} // namespace RayTracer
