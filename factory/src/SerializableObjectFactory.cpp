/*
** EPITECH PROJECT, 2022
** SerializableObjectFactory.cpp
** File description:
** SerializableObjectFactory.cpp
*/

#include "SerializableObjectFactory.hpp"
#include "modules/TextModule.hpp"
#include "modules/TextureModule.hpp"
#include "modules/SpriteAnimation.hpp"

polymorph::engine::api::SerializableObjectFactory::SerializableObjectFactory()
: ASerializableObjectFactory()
{
}

void polymorph::engine::api::SerializableObjectFactory::_registerEmptyBuildables(
        std::unordered_map<std::string, std::function<std::shared_ptr<ASerializableObject>(
                PluginManager&)>> &emptyBuildables)
{
    emptyBuildables.emplace("Text", makeEmpty<render2D::TextModuleImpl>());
    emptyBuildables.emplace("Texture", makeEmpty<render2D::TextureModuleImpl>());
    emptyBuildables.emplace("SpriteAnimation", makeEmpty<render2D::SpriteAnimationImpl>());
}

void polymorph::engine::api::SerializableObjectFactory::_registerCObjectBuildables(
        std::unordered_map <std::string, std::function<std::shared_ptr<ASerializableObject>(
                safe_ptr<AComponent>,
                std::shared_ptr<myxmlpp::Node>)>> &componentBuildables)
{
    componentBuildables.emplace("Text", makeCObject<render2D::TextModuleImpl>());
    componentBuildables.emplace("Texture", makeCObject<render2D::TextureModuleImpl>());
    componentBuildables.emplace("SpriteAnimation", makeCObject<render2D::SpriteAnimationImpl>());
}

void polymorph::engine::api::SerializableObjectFactory::_registerPObjectBuildables(
        std::unordered_map <std::string, std::function<std::shared_ptr<ASerializableObject>(
                safe_ptr<APluginConfig>,
                std::shared_ptr<myxmlpp::Node>)>> &configBuildables)
{
    configBuildables.emplace("Text", makePObject<render2D::TextModuleImpl>());
    configBuildables.emplace("Texture", makePObject<render2D::TextureModuleImpl>());
    configBuildables.emplace("SpriteAnimation", makePObject<render2D::SpriteAnimationImpl>());
}
