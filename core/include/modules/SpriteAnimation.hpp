/*
** EPITECH PROJECT, 2020
** SpriteAnimation.hpp
** File description:
** header for SpriteAnimation.c
*/


#pragma once

#include <functional>
#include "../../scripts/include/ADrawable2dComponent.hpp"
#include "TextureModule.hpp"

namespace polymorph::engine::render2D
{

    class ASpriteAnimation : public api::AConfigurableSerializableObject
    {
        public:
            using AnimationCallBack = std::function<void(void)>;
            ASpriteAnimation(safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node)
            : AConfigurableSerializableObject(component, node) {};
            ASpriteAnimation(safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node)
            : AConfigurableSerializableObject(config, node) {};
            explicit ASpriteAnimation(api::PluginManager &pluginManager)
            : AConfigurableSerializableObject(pluginManager) {};
            ~ASpriteAnimation() override = default;


            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            std::string animationName;
            Texture sprite;
            int nbFrames;
            float yOffset;
            float frameTime;
            bool reversed;


        protected:
            engine::Rect _currentFrame;
            float _width;
            float _height;
            int currentFrame = 1;
            std::vector<AnimationCallBack> _callBacks;


            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual void addEndAnimCallBack(AnimationCallBack callback) = 0;

            virtual void invokeCallBacks() = 0;

            virtual void nextFrame() = 0;

            virtual void clear() = 0;

            virtual void setAnimationFrameTime(float frameTime) = 0;

        private:


            //////////////////////--------------------------/////////////////////////

    };
    using SpriteAnimation = std::shared_ptr<ASpriteAnimation>;
    
    class SpriteAnimationImpl : public ASpriteAnimation
    {
        public:
            SpriteAnimationImpl(safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node);
            SpriteAnimationImpl(safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node);
            explicit SpriteAnimationImpl(api::PluginManager &pluginManager);
            ~SpriteAnimationImpl() override = default;

            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void addEndAnimCallBack(AnimationCallBack callback) final;

            void invokeCallBacks() final;

            void build() override;

            void saveAll() override;

            void nextFrame() final;

            void clear() final;

            void setAnimationFrameTime(float frameTime) final;

            //////////////////////--------------------------/////////////////////////

    };
}
