/*
** EPITECH PROJECT, 2020
** TextRendererComponent.cpp
** File description:
** TextRendererComponent.cpp
*/

#include "drawables/TextRendererImpl.hpp"

namespace polymorph::engine::render2D
{

    void TextRendererImpl::draw()
    {
        text->setPosition(engine::Vector2(transform->getPosition()) + offset);
        text->draw();
    }

    void TextRendererImpl::build()
    {
        _setProperty("text", text);
    }

    void TextRendererImpl::saveAll()
    {
        saveProperty("text", text);
    }

}