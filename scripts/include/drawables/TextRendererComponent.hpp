/*
** EPITECH PROJECT, 2020
** TextRendererComponent.hpp
** File description:
** header for TextRendererComponent.c
*/

#pragma once

#include "ADrawable2dComponent.hpp"
#include "modules/TextModule.hpp"

namespace polymorph::engine::render2D
{
    class TextRendererComponent;
    using TextRenderer = safe_ptr<TextRendererComponent>;

    class TextRendererComponent : public ADrawable2dComponent
    {
        public:
            TextRendererComponent(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
            : ADrawable2dComponent(gameObject, node) {};
            
            Text text;
    };
}
