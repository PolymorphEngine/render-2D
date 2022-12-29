/*
** EPITECH PROJECT, 2020
** SpriteAnimatorComponent
** File description:
** header for SpriteAnimator.c
*/


#pragma once

#include <functional>
#include "polymorph/engine/types.hpp"
#include "polymorph/engine/core.hpp"
#include "../../core/include/modules/SpriteAnimation.hpp"
#include "../drawables/SpriteRendererComponent.hpp"

namespace polymorph::engine::render2D
{
    class SpriteAnimatorComponent : public AComponent
    {
        public:
            SpriteAnimatorComponent(engine::GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
            : AComponent(node, gameObject) {};
            
            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            SpriteRenderer targetGraphics;
            std::vector<SpriteAnimation> animations;
            std::string currentAnimation;

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:

            virtual void startAnimation(std::string animationName) = 0;

            virtual void addAnimCallBack(ASpriteAnimation::AnimationCallBack callback, std::string animationName = "") = 0;

            virtual void clearAnimationCallbacks(std::string name = "") = 0;

            virtual void setAnimationFrameTime(std::string name, float frameTime) = 0;

            virtual float getAnimationFrameTime(std::string name) = 0;

        private:

            //////////////////////--------------------------/////////////////////////

    };
}