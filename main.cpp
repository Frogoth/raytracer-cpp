/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** main
*/

#include "main.hpp"
#include "src/RayTracer/Camera.hpp"
#include "src/Hittable/LCylinder.hpp"
#include "src/Hittable/Sphere.hpp"
#include "src/RayTracer/Scene.hpp"
#include "src/Config/ConfigParser.hpp"

int main(int ac, char **av)
{
    RayTracer::Scene scene;
    if (ac != 2)
        return 84;
    try {
        CfgParser::ConfigParser parser(av[1]);
        scene = parser.getScene();
    } catch (CfgParser::ConfigParser::fileOpenException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    scene.traceThatRay();
    return 0;
}
