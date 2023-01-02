/*
** EPITECH PROJECT, 2020
** SpriteRenderComponent.hpp
** File description:
** header for SpriteRenderComponent.c
*/

#ifndef ENGINE_SPRITERENDERERCOMPONENT_HPP
#define ENGINE_SPRITERENDERERCOMPONENT_HPP


#include "../ADrawable2dComponent.hpp"
#include "../../../core/include/modules/TextureModule.hpp"

namespace polymorph::engine::render2D
{
    class SpriteRendererComponent;
    using SpriteRenderer = safe_ptr<SpriteRendererComponent>;

    class SpriteRendererComponent : public ADrawable2dComponent
    {

        public:
            SpriteRendererComponent(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
            : ADrawable2dComponent(gameObject, node) {};
            
            Texture sprite;

    };
}

#endif //ENGINE_SPRITERENDERERCOMPONENT_HPP
