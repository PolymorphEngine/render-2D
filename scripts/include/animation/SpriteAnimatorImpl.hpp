/*
** EPITECH PROJECT, 2020
** SpriteAnimatorComponent
** File description:
** header for SpriteAnimator.c
*/


#pragma once

#include <functional>
#include "animation/SpriteAnimatorScript.hpp"

namespace polymorph::engine::render2D
{
    
    class SpriteAnimatorImpl : public SpriteAnimatorComponent
    {
        public:
            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
            SpriteAnimatorImpl(GameObject &gameObject, std::shared_ptr<myxmlpp::Node> node);
            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////

        private:
            engine::time::Timer _timer;
            SpriteAnimation _currentAnimation;
            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void build() override;

            void saveAll() override;

            void start() override;

            void update() override;

            void startAnimation(std::string animationName) override;

            void addAnimCallBack(ASpriteAnimation::AnimationCallBack callback,
            std::string animationName = "") override;

            void clearAnimationCallbacks(std::string name = "") override;

            void setAnimationFrameTime(std::string name, float frameTime) override;

            float getAnimationFrameTime(std::string name) override;

        private:

            //////////////////////--------------------------/////////////////////////

    };
}
