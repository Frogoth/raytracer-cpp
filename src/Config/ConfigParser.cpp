/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** ConfigParser
*/

#include <Config/ConfigParser.hpp>

namespace CfgParser {

    ConfigParser::ConfigParser(std::string path) {
        try {
            _cfg.readFile(path.c_str());
            parseFile();
        } catch (const libconfig::ParseException &e) {
            throw fileOpenException(e.what());
        } catch (const libconfig::FileIOException &e) {
            throw fileOpenException(e.what());
        }
    }

    ConfigParser::~ConfigParser(){}

    void ConfigParser::parseFile() {
        const libconfig::Setting &root = _cfg.getRoot();
        parseCamera(root["camera"]);
        parseScene(root["scene"]);
        if (_scene.isPrimEmpty()) {
            throw libconfig::ParseException(root.getSourceFile(), 0, "prim vector empty");
        }
    }

    RayTracer::Scene &ConfigParser::getScene() {
        return this->_scene;
    }

    void ConfigParser::parseScene(const libconfig::Setting &s) {
        std::string type;

        for (auto &seine : s) {
            if (seine.exists("type")) {
                seine.lookupValue("type", type);
                if (type == "sphere")
                    parseSphere(seine);
                if (seine.exists("plane"))
                    parsePlane(seine);
                // parseLights(seine);
            }
        }
    }

    void ConfigParser::parseSphere(const libconfig::Setting& spheres) {
        double x = 0;
        double y = 0;
        double z = 0;
        double r = 0;
        double red = 0;
        double green = 0;
        double blue = 0;

        const libconfig::Setting &center = spheres.lookup("center");
        const libconfig::Setting &color = spheres.lookup("color");
        center.lookupValue("x", x);
        center.lookupValue("y", y);
        center.lookupValue("z", z);
        spheres.lookupValue("radius", r);
        Math::Vector3D v(x, y, z);
        color.lookupValue("r", red);
        color.lookupValue("g", green);
        color.lookupValue("b", blue);
        Math::Color elcolor(red, green, blue);
        Hittable::Sphere newSphere(v, r, elcolor);
        _scene._world.add(std::make_shared<Hittable::Sphere>(newSphere));
    }

    void ConfigParser::parsePlane(const libconfig::Setting& planes)
    {
        std::string axe;
        double pos = 0;
        Math::Vector3D v;
        double r = 0;
        double g = 0;
        double b = 0;

        const libconfig::Setting& color = planes["color"];
        planes.lookupValue("axis", axe);
        planes.lookupValue("pos", pos);
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        Math::Color elcolor(r, g, b);
        if (axe == "Z")
            Math::Vector3D v(0, 0, 1);
        if (axe == "Y")
            Math::Vector3D v(0, 1, 0);
        if (axe == "X")
            Math::Vector3D v(1, 0, 0);
        Hittable::Plane newPlane(v, pos, elcolor);
        _scene._world.add(std::make_shared<Hittable::Plane>(newPlane));
    }

    void ConfigParser::parseCamera(const libconfig::Setting& c)
    {
        int l = 0;
        int h = 0;
        double x = 0;
        double y = 0;
        double z = 0;
        double f = 0;
        const libconfig::Setting &a = c["resolution"];
        const libconfig::Setting &b = c["position"];
        const libconfig::Setting &d = c["rotation"];

        a.lookupValue("width", l);
        a.lookupValue("height", h);
        b.lookupValue("x", x);
        b.lookupValue("y", y);
        b.lookupValue("z", z);
        Math::Vector3D p(x, y, z);
        d.lookupValue("x", x);
        d.lookupValue("y", y);
        d.lookupValue("z", z);
        Math::Vector3D r(x, y, z);
        c.lookupValue("fieldOfView", f);
        RayTracer::Camera camera(l, h, p, f, r);
        this->_scene.addCam(camera);
    }

    // void ConfigParser::parseLights(const libconfig::Setting &lights) {
    //     std::string type;
    //     if (lights.exists("type")) {
    //         lights.lookupValue("type", type);
    //         if (type == "ambient")
    //             parseAmbient(lights);
    //         if (type == "diffuse")
    //             parseDiffuse(lights);
    //         if (type == "point")
    //             parsePoint(lights);
    //     }
    // }

    // void ConfigParser::parseAmbient(const libconfig::Setting &amb) {
    //     double in = 0;
    //     amb.lookupValue("intensity", in);
    //     Light::Ambient newLight(in);
    //     _scene.addLight(std::make_shared<Light::Ambient>(newLight));
    // }

    // void ConfigParser::parseDiffuse(const libconfig::Setting &dif) {
    //     double in = 0;
    //     dif.lookupValue("intensity", in);
    //     Light::Diffuse newLight(in);
    //     _scene.addLight(std::make_shared<Light::Diffuse>(newLight));
    // }

    // void ConfigParser::parsePoint(const libconfig::Setting &poi) {
    //     double x = 0;
    //     double y = 0;
    //     double z = 0;

    //     poi.lookupValue("x", x);
    //     poi.lookupValue("y", y);
    //     poi.lookupValue("z", z);
    //     Math::Vector3D ppos(x, y ,z);
    //     Light::Point newLight(ppos);
    //     _scene.addLight(std::make_shared<Light::Point>(newLight));
    // }

    ConfigParser::fileOpenException::fileOpenException(const std::string &message) : _message("Parsing error: " + message) {}

    const char *ConfigParser::fileOpenException::what() const noexcept {
        return _message.c_str();
    }
}
