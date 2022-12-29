/*
** EPITECH PROJECT, 2020
** SpriteRenderComponent.hpp
** File description:
** header for SpriteRenderComponent.c
*/

#ifndef ENGINE_SpriteRendererComponentImpl_HPP
#define ENGINE_SpriteRendererComponentImpl_HPP

#include <utility>

#include "modules/TextureModule.hpp"
#include "SpriteRendererComponent.hpp"
#include <functional>
#include <vector>

namespace polymorph::engine::render2D
{

    class SpriteRendererImpl : public SpriteRendererComponent
    {
        public:

            SpriteRendererImpl(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
            : SpriteRendererComponent(gameObject, node) {};

            void draw() override;

            void build() override;

            void saveAll() override;

    };
}

#endif //ENGINE_SpriteRendererComponentImpl_HPP
