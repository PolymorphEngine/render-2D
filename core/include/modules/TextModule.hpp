/*
** EPITECH PROJECT, 2020
** TextModule.hpp
** File description:
** header for TextModule.c
*/


#pragma once

#include <memory>
#include "polymorph/engine/types.hpp"
#include "polymorph/engine/api.hpp"
#include "polymorph/engine/render-modules.hpp"

namespace polymorph::engine::render2D
{
    class ATextModule : public api::AConfigurableSerializableObject
    {
        public:
            ATextModule (safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node)
            : AConfigurableSerializableObject(component, node) {};
            ATextModule (safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node)
            : AConfigurableSerializableObject(config, node) {};
            explicit ATextModule(api::PluginManager &pluginManager)
            : AConfigurableSerializableObject(pluginManager) {};

            ~ATextModule() override = default;
            //////////////////////--------------------------/////////////////////////



            ///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        protected:
            
            graphical::Symbols::createTextDEF _c_text = nullptr;
            graphical::Symbols::createFontDEF _c_font = nullptr;

            std::unique_ptr<polymorph::graphical::IText> _text;
            std::unique_ptr<polymorph::graphical::IFont> _font;
            std::string _textString;
            std::string _fontFilepath;
            std::string _fallBackFontFilepath = "default_font.ttf";
            float _fontSize = 15;
            float _lineSpacing = 4;
            engine::Color _color;

            //////////////////////--------------------------/////////////////////////



            /////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual void setPosition(engine::Vector2 position) = 0;

            virtual void setString(const std::string &content) = 0;

            virtual std::string getString() = 0;

            virtual void setFont(const std::string &fontPath) = 0;

            virtual void setFontSize(float fontSize) = 0;

            virtual float getFontSize() = 0;

            virtual void setSpacing(float lineSpacing) = 0;

            virtual float getSpacing() = 0;

            virtual void setColor(engine::Color color) = 0;

            virtual engine::Color getColor() = 0;

            virtual void draw() = 0;
            //////////////////////--------------------------/////////////////////////

    };
    using Text = std::shared_ptr<ATextModule>;

    class TextModuleImpl : public ATextModule
    {
        public:


            TextModuleImpl (safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node);
            TextModuleImpl (safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node);
            explicit TextModuleImpl(api::PluginManager &pluginManager);

            ~TextModuleImpl() override = default;
            //////////////////////--------------------------/////////////////////////

            /////////////////////////////// METHODS /////////////////////////////////
        public:
            void setPosition(engine::Vector2 position) final;

            void setString(const std::string &content) final;

            std::string getString() final;

            void setFont(const std::string &fontPath) final;

            void setFontSize(float fontSize) final;

            float getFontSize() final;

            void setSpacing(float lineSpacing) final;

            float getSpacing() final;

            void setColor(engine::Color color) final;

            engine::Color getColor() final;

            void draw() final;
            
            void build() override;

            void saveAll() override;

        private:
            void _loadModules(api::PluginManager &Plugins);

            //////////////////////--------------------------/////////////////////////

    };
}
