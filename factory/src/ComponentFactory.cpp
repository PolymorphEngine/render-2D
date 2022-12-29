/*
** EPITECH PROJECT, 2022
** ComponentFactory.cpp
** File description:
** ComponentFactory.cpp
*/

#include "ComponentFactory.hpp"
#include "drawables/TextRendererImpl.hpp"
#include "drawables/SpriteRendererImpl.hpp"
#include "animation/SpriteAnimatorImpl.hpp"

polymorph::engine::api::ComponentFactory::ComponentFactory() : AComponentFactory()
{
}

void polymorph::engine::api::ComponentFactory::_registerBuildables(
        std::unordered_map<std::string, polymorph::engine::api::AComponentFactory::FactoryLambda> &buildables)
{
    buildables.emplace("TextRenderer", make<render2D::TextRendererImpl>());
    buildables.emplace("SpriteRenderer", make<render2D::SpriteRendererImpl>());
    buildables.emplace("SpriteAnimator", make<render2D::SpriteAnimatorImpl>());
}