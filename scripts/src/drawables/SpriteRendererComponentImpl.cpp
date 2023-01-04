/*
** EPITECH PROJECT, 2020
** SpriteRendererComponentImpl.cpp
** File description:
** SpriteRendererComponentImpl.cpp
*/

#include "drawables/SpriteRendererImpl.hpp"

namespace polymorph::engine::render2D
{
    void SpriteRendererImpl::draw()
    {
        sprite->setPosition(engine::Vector2(transform->getPosition()) + offset);
        sprite->draw();
    }

    void SpriteRendererImpl::build()
    {
        _setProperty("sprite", sprite);
        _setProperty("offset", offset);
    }

    void SpriteRendererImpl::saveAll()
    {
        saveProperty("sprite", sprite);
    }


}