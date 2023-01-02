/*
** EPITECH PROJECT, 2020
** DrawableComponent.hpp
** File description:
** header for DrawableComponent.c
*/

#ifndef ENGINE_ADRAWABLE2DCOMPONENT_HPP
#define ENGINE_ADRAWABLE2DCOMPONENT_HPP

#include <functional>
#include <polymorph/engine/core.hpp>
#include <polymorph/engine/types.hpp>
#include <polymorph/engine/api.hpp>
#include <polymorph/engine/debug.hpp>

namespace polymorph::engine::render2D
{
    class ADrawable2dComponent : public AComponent
    {
////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit ADrawable2dComponent(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
                : AComponent(node, gameObject){};
            ~ADrawable2dComponent() override = default;

///////////////////////////--------------------------///////////////////////////



///////////////////////////////// Properties ///////////////////////////////////
        public:
            engine::Vector2 offset;
///////////////////////////--------------------------///////////////////////////



////////////////////////////////// Methods /////////////////////////////////////
        public:
            /**
             * @details An overridable method that's called once per frame in the game loop.
             */
            void update() override
            {};

            /**
             * @details An overridable method that's called once in the lifetime of the component.
             *          It is called before the games start (or upon component creation at runtime).
             * @warning Is called even if the enable state of the component is set to false on creation.
             */
            void onAwake() override
            {};

            /**
             * @details An overridable method that's called once in the lifetime of the component,
             *          It is called before the update method (or upon component creation at runtime).
             * @warning Is called ONLY when the enabled state of the component is passed to true.
             */
            void start() override
            {};

            /**
             * @details An overridable method that draws the component if its an drawable only.
             *          Called once per frame.
             */
            virtual void draw() = 0;
///////////////////////////--------------------------///////////////////////////


    };


}

#endif //ENGINE_ADRAWABLE2DCOMPONENT_HPP
