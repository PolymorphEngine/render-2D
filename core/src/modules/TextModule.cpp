/*
** EPITECH PROJECT, 2022
** TextModule.cpp
** File description:
** TextModule.cpp
*/


#include <polymorph/engine/types.hpp>
#include "../../include/modules/TextModule.hpp"


void polymorph::engine::render2D::TextModuleImpl::setPosition(engine::Vector2 position)
{
	_text->setPosition(position.x, position.y);
}

void polymorph::engine::render2D::TextModuleImpl::setString(const std::string &content)
{
	_text->setText(content);
	_textString = content;
}

std::string polymorph::engine::render2D::TextModuleImpl::getString()
{
	return _textString;
}

void polymorph::engine::render2D::TextModuleImpl::setFont(const std::string &fontPath)
{
    _fontFilepath = fontPath;
    _font = std::unique_ptr<polymorph::graphical::IFont>(_c_font(_fontFilepath));
}

void polymorph::engine::render2D::TextModuleImpl::setFontSize(float fontSize)
{
	_fontSize = fontSize;
}

float polymorph::engine::render2D::TextModuleImpl::getFontSize()
{
	return _fontSize;
}

void polymorph::engine::render2D::TextModuleImpl::setSpacing(float lineSpacing)
{
	_lineSpacing = lineSpacing;
}

float polymorph::engine::render2D::TextModuleImpl::getSpacing()
{
	return _lineSpacing;
}

void polymorph::engine::render2D::TextModuleImpl::setColor(engine::Color color)
{
	_color = color;
    _text->setColor(color.r, color.g, color.b, color.a);
}

polymorph::engine::Color polymorph::engine::render2D::TextModuleImpl::getColor()
{
	return _color;
}

void polymorph::engine::render2D::TextModuleImpl::draw()
{
	_text->draw(*_font, _fontSize, _lineSpacing);
}

void polymorph::engine::render2D::TextModuleImpl::_loadModules(api::PluginManager &Plugins)
{
    if (_c_text && _c_font)
        return;
    _c_text = Plugins.getSymbol<graphical::Symbols::createTextDEF>(graphical::Symbols::createText);
    _c_font = Plugins.getSymbol<graphical::Symbols::createFontDEF>(graphical::Symbols::createFont);
}




polymorph::engine::render2D::TextModuleImpl::TextModuleImpl(
        polymorph::engine::safe_ptr<polymorph::engine::AComponent> component,
        std::shared_ptr<myxmlpp::Node> node)
        : ATextModule(component, node)
{
    _loadModules(component->Plugin);
    build();
    _text = std::unique_ptr<polymorph::graphical::IText>(_c_text(_textString));
    setFont(_fontFilepath);
    setFontSize(_fontSize);
    setSpacing(_lineSpacing);
    setColor(_color);
}

polymorph::engine::render2D::TextModuleImpl::TextModuleImpl(
        polymorph::engine::safe_ptr<polymorph::engine::api::APluginConfig> config,
        std::shared_ptr<myxmlpp::Node> node)
        : ATextModule(config, node)
{
    _loadModules(config->Plugin);
    build();
    _text = std::unique_ptr<polymorph::graphical::IText>(_c_text(_textString));
    setFont(_fontFilepath);
    setFontSize(_fontSize);
    setSpacing(_lineSpacing);
    setColor(_color);
}



polymorph::engine::render2D::TextModuleImpl::TextModuleImpl(
        polymorph::engine::api::PluginManager &pluginManager)
        : ATextModule(pluginManager)
{
    _loadModules(pluginManager);
    _fontSize = 30;
    _lineSpacing = 5;
    _textString = "";
    _fontFilepath = "";
    _text = std::unique_ptr<polymorph::graphical::IText>(_c_text(_textString));
    _font = std::unique_ptr<polymorph::graphical::IFont>(_c_font(_fontFilepath));
    setFontSize(_fontSize);
    setSpacing(_lineSpacing);
    setColor(engine::Color(255, 255, 255, 255));
}

void polymorph::engine::render2D::TextModuleImpl::build()
{
    _setProperty("_textString", _textString);
    _setProperty("_fontFilepath", _fontFilepath);
    _fontFilepath = this->_plugin.getAssetManager().tryResolve(_fontFilepath);
    if (_fontFilepath.empty())
    {
        _fontFilepath = this->_plugin.getAssetManager().tryResolve(_fallBackFontFilepath);
        if (!_fontFilepath.empty())
            debug::Logger::Log("[render-2D] Missing font, using default font!", debug::Logger::MINOR);
        else
            debug::Logger::Log("[render-2D] Failed to load default font, crash may occur!", debug::Logger::MAJOR);
    }

    _setProperty("_fontSize", _fontSize);
    _setProperty("_lineSpacing", _lineSpacing);
    if (_lineSpacing == 0)
        _lineSpacing = 1;
    _setProperty("_color", _color);
}

void polymorph::engine::render2D::TextModuleImpl::saveAll()
{
    saveProperty("_textString", _textString);
    saveProperty("_fontFilepath", _fontFilepath);
    saveProperty("_fontSize", _fontSize);
    saveProperty("_lineSpacing", _lineSpacing);
    saveProperty("_color", _color);
}