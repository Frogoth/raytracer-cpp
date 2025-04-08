/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** ConfigParser
*/

#ifndef CONFIGPARSER_HPP_
    #define CONFIGPARSER_HPP_
    #include "../../main.hpp"
    #include "../RayTracer/Scene.hpp"
    #include "../Hittable/Sphere.hpp"
    #include "../Hittable/Plane.hpp"
    #include "../Lights/Ambient.hpp"
    #include "../Lights/Diffuse.hpp"
    #include "../Lights/Point.hpp"

namespace CfgParser {
    class ConfigParser {
        public:
            ConfigParser(std::string path);
            ~ConfigParser();
            RayTracer::Scene &getScene();

            class fileOpenException : public std::exception {
                public:
                    fileOpenException(const std::string &message);
                    const char *what() const noexcept override;
                private:
                    const std::string _message;
            };

        private:
            void parseFile();
            void parseSphere(const libconfig::Setting &s);
            void parsePlane(const libconfig::Setting &p);
            void parseCamera(const libconfig::Setting &c);
            void parseScene(const libconfig::Setting &s);
            void parseLights(const libconfig::Setting &l);
            void parseAmbient(const libconfig::Setting &amb);
            void parseDiffuse(const libconfig::Setting &dif);
            void parsePoint(const libconfig::Setting &poi);

            RayTracer::Scene _scene;
            libconfig::Config _cfg;
    };
} // namespace Config

#endif /* !CONFIGPARSER_HPP_ */
