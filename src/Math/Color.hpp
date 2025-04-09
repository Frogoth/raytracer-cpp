/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-tom.rudolf
** File description:
** Color
*/

#pragma once

#include "../../main.hpp"
#include "Vector3D.hpp"

namespace Math
{
    using Color = Vector3D;
    std::ostream &operator<<(std::ostream &os, const Color &c);
} // namespace Math
