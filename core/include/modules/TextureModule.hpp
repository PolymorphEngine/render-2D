/*
** EPITECH PROJECT, 2020
** TextureModule.hpp
** File description:
** header for TextureModule.c
*/


#pragma once

#include <memory>
#include "polymorph/engine/types.hpp"
#include "polymorph/engine/api.hpp"
#include "polymorph/engine/render-modules.hpp"

namespace polymorph::engine::render2D
{
    class ATextureModule : public engine::api::AConfigurableSerializableObject
    {
        public:
            ATextureModule (safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node)
            : AConfigurableSerializableObject(component, node) {};
            ATextureModule (safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node)
            : AConfigurableSerializableObject(config, node) {};
            explicit ATextureModule(api::PluginManager &pluginManager)
            : AConfigurableSerializableObject(pluginManager) {};

            ~ATextureModule() override = default;
            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            engine::Vector2 scale = engine::Vector2(1, 1);


        protected:
            graphical::Symbols::createTextureDEF _c_texture = nullptr;
            api::PluginManager *_pluginManager = nullptr;

            std::unique_ptr<polymorph::graphical::ITexture> _texture;
            engine::Rect _crop;
            std::string _filepath;
            engine::Color _color;

            const std::string fallBackTexture = "missing.png";

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual void loadTexture(std::string filePath) = 0;

            virtual void setPosition(engine::Vector2 position) = 0;

            virtual void setScale(engine::Vector2 scale) = 0;

            virtual void setCrop(engine::Rect crop) = 0;

            virtual engine::Rect getCrop() = 0;

            virtual float getTextureWidth() = 0;

            virtual float getTextureHeight() = 0;

            virtual polymorph::graphical::ITexture &getTexture() const = 0;

            virtual void draw() = 0;

            virtual engine::Color getColor() const = 0;

            virtual void setColor(engine::Color color) = 0;

            //////////////////////--------------------------/////////////////////////

    };
    using Texture = std::shared_ptr<ATextureModule>;

    class TextureModuleImpl : public ATextureModule
    {
        public:
            TextureModuleImpl(safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node);
            TextureModuleImpl(safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node);

            void build() override;

            void saveAll() override;

            explicit TextureModuleImpl(api::PluginManager &pluginManager);
            
            ~TextureModuleImpl() override = default;
            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void loadTexture(std::string filePath) final;
            void setPosition(engine::Vector2 position) final;

            void setScale(engine::Vector2 scale) final;

            void setCrop(engine::Rect crop) final;

            engine::Rect getCrop() final;

            float getTextureWidth() final;

            float getTextureHeight() final;

            polymorph::graphical::ITexture &getTexture() const final;

            void draw() final;

            engine::Color getColor() const final;

            void setColor(engine::Color color) final;

        private:
            void _flipTextureToImage();

            void _flipImageToTexture();

            void _loadModules();

            //////////////////////--------------------------/////////////////////////

    };
}