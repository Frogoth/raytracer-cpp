/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** main
*/

#include <main.hpp>
#include <RayTracer/Camera.hpp>
#include <Hittable/LCylinder.hpp>
#include <Hittable/Sphere.hpp>
#include <RayTracer/Scene.hpp>
#include <Config/ConfigParser.hpp>

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
