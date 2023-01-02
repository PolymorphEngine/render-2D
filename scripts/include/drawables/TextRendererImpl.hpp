/*
** EPITECH PROJECT, 2020
** TextRendererComponent.hpp
** File description:
** header for TextRendererComponent.c
*/

#pragma once

#include <utility>

#include "TextRendererComponent.hpp"
#include "modules/TextModule.hpp"
#include "polymorph/engine/core.hpp"
#include "polymorph/engine/types.hpp"
#include "polymorph/engine/api.hpp"
#include <functional>

namespace polymorph::engine::render2D
{

    class TextRendererImpl : public TextRendererComponent
    {
        public:

            TextRendererImpl(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
            : TextRendererComponent(gameObject, node) {};

            void draw() override;

            void build() override;

            void saveAll() override;

    };
}
