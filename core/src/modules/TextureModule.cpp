/*
** EPITECH PROJECT, 2022
** MeshModule.cpp
** File description:
** MeshModule.cpp
*/


#include "../../include/modules/TextureModule.hpp"
#include "polymorph/engine/types.hpp"
#include "PluginCore.hpp"
#include <filesystem>

polymorph::engine::render2D::TextureModuleImpl::TextureModuleImpl(api::PluginManager &Plugins)
: ATextureModule(Plugins)
{
    _pluginManager = &Plugins;
    _loadModules();
    _color = engine::Color{255, 255, 255, 255};
}

polymorph::engine::render2D::TextureModuleImpl::TextureModuleImpl(
        polymorph::engine::safe_ptr<polymorph::engine::AComponent> component,
        std::shared_ptr<myxmlpp::Node> node)
        : ATextureModule(component, node)
{
    _pluginManager = &component->Plugin;
    _loadModules();
    build();
    if (_color.r == 0 && _color.g == 0 && _color.b == 0 && _color.a == 0)
        setColor(engine::Color{255, 255, 255, 255});
    loadTexture(_filepath);
    if (_crop.width == 0 && _crop.height == 0)
        _crop = {_crop.x, _crop.y, _texture->getTextureWidth(), _texture->getTextureHeight()};
    setCrop(_crop);
}

polymorph::engine::render2D::TextureModuleImpl::TextureModuleImpl(
        polymorph::engine::safe_ptr<polymorph::engine::api::APluginConfig> config,
        std::shared_ptr<myxmlpp::Node> node)
        : ATextureModule(config, node)
{
    _pluginManager = &config->Plugin;
    _loadModules();
    build();
    if (_color.r == 0 && _color.g == 0 && _color.b == 0 && _color.a == 0)
        setColor(engine::Color{255, 255, 255, 255});
    loadTexture(_filepath);
    if (_crop.width == 0 && _crop.height == 0)
        _crop = {_crop.x, _crop.y, _texture->getTextureWidth(), _texture->getTextureHeight()};
    setCrop(_crop);
}


void polymorph::engine::render2D::TextureModuleImpl::build()
{
    _setProperty("_filepath", _filepath);
    _setProperty("_color", _color);
    _setProperty("_crop", _crop);
}

void polymorph::engine::render2D::TextureModuleImpl::saveAll()
{
    saveProperty("_filepath", _filepath);
    saveProperty("_color", _color);
    saveProperty("_crop", _crop);
}



void polymorph::engine::render2D::TextureModuleImpl::setPosition(engine::Vector2 position)
{
	_texture->setPosition(position.x, position.y);
}

void polymorph::engine::render2D::TextureModuleImpl::setScale(engine::Vector2 scale)
{
    this->scale = scale;
	_flipTextureToImage();
	//_image->setScale(scale.x, scale.y);
	_flipImageToTexture();
}

void polymorph::engine::render2D::TextureModuleImpl::setCrop(engine::Rect crop)
{
    if (crop.width == 0 || crop.height == 0)
        return;
	//_flipTextureToImage();
    _crop = crop;
	//_image->crop(crop.x, crop.y, crop.width, crop.height);
	//_flipImageToTexture();
    _texture->setTextureRect(crop.x, crop.y, crop.width, crop.height);
}

polymorph::engine::Rect polymorph::engine::render2D::TextureModuleImpl::getCrop()
{
    /*
    _flipTextureToImage();
    auto r = Rect(_crop.x, _crop.y, _image->getWCrop(), _image->getHCrop());
    _flipImageToTexture(); */
    return _crop;
}

void polymorph::engine::render2D::TextureModuleImpl::draw()
{
    _texture->draw(_color.r, _color.g, _color.b, _color.a);
}

void polymorph::engine::render2D::TextureModuleImpl::_flipTextureToImage()
{
	//_image = std::unique_ptr<polymorph::graphical::IImageModule>(_c_image_from_texture(*_texture));
    //_texture = nullptr;
}

void polymorph::engine::render2D::TextureModuleImpl::_flipImageToTexture()
{
    //_texture = std::unique_ptr<polymorph::graphical::ITextureModuleImpl>(_c_texture_from_image(*_image));
    //_image = nullptr;
}

polymorph::engine::Color polymorph::engine::render2D::TextureModuleImpl::getColor() const
{
    return _color;
}

void polymorph::engine::render2D::TextureModuleImpl::setColor(polymorph::engine::Color color)
{
    _color = color;
}

void polymorph::engine::render2D::TextureModuleImpl::_loadModules()
{
    if (_c_texture || !_pluginManager)
        return;
    _c_texture = _pluginManager->getSymbol<graphical::Symbols::createTextureDEF>(graphical::Symbols::createTexture);
    //_c_texture_from_image = GraphicalAPI::loadSymbol<TextureModuleImplFromImageLoader, GraphicalAPI>("createTextureModuleImplFromImage");
    //_c_image = GraphicalAPI::loadSymbol<ImageModuleLoader, GraphicalAPI>("createImageModule");
    //_c_image_from_texture = GraphicalAPI::loadSymbol<ImageModuleFromTextureLoader, GraphicalAPI>("createImageModuleFromTexture");
}

polymorph::graphical::ITexture &polymorph::engine::render2D::TextureModuleImpl::getTexture() const
{
    return *_texture;
}

float polymorph::engine::render2D::TextureModuleImpl::getTextureWidth()
{
    return _texture->getTextureWidth();
}

float polymorph::engine::render2D::TextureModuleImpl::getTextureHeight()
{
    return _texture->getTextureHeight();
}

void polymorph::engine::render2D::TextureModuleImpl::loadTexture(std::string filePath)
{
    _filepath = _pluginManager->getAssetManager().tryResolve(filePath);
    if (_filepath.empty()) {
        _filepath = _pluginManager->getAssetManager().tryResolve(fallBackTexture);
        if (!_filepath.empty())
            debug::Logger::Log("[render-2D] Missing texture path, using default texture!", debug::Logger::MINOR);
        else
            debug::Logger::Log("[render-2D] Missing texture path and unable to load default texture ! A crash can occur!", debug::Logger::MAJOR);
    }
    _texture = std::unique_ptr<polymorph::graphical::ITexture>(_c_texture(_filepath));
    _crop = {_crop.x, _crop.y, _texture->getTextureWidth(), _texture->getTextureHeight()};
    setCrop(_crop);
}

/*
polymorph::graphical::Vector2 polymorph::graphical::TextureModuleImpl::getSize()
{
    return {_crop.width * _scale.x, _crop.height * _scale.y};
}
*/