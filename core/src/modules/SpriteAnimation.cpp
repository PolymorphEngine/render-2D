/*
** EPITECH PROJECT, 2022
** SpriteAnimationImpl.cpp
** File description:
** SpriteAnimationImpl.cpp
*/


#include "../include/modules/SpriteAnimation.hpp"

void polymorph::engine::render2D::SpriteAnimationImpl::addEndAnimCallBack(
        polymorph::engine::render2D::SpriteAnimationImpl::AnimationCallBack callback)
{
    _callBacks.push_back(callback);
}

void polymorph::engine::render2D::SpriteAnimationImpl::invokeCallBacks()
{
    for (auto &c : _callBacks)
        c();
}

void polymorph::engine::render2D::SpriteAnimationImpl::nextFrame()
{
    if (nbFrames == 1)
        return;
    if (reversed) {
        if (currentFrame > 0) {
            _currentFrame.x -= _width;
            sprite->setCrop(_currentFrame);
            currentFrame--;
        } else {
            _currentFrame.x = _width * (nbFrames - 1);
            sprite->setCrop(_currentFrame);
            invokeCallBacks();
            currentFrame = nbFrames - 1;
        }
    } else {
        if (currentFrame < nbFrames) {
            _currentFrame.x += _width;
            sprite->setCrop(_currentFrame);
            currentFrame++;
        } else {
            _currentFrame.x = 0;
            sprite->setCrop(_currentFrame);
            invokeCallBacks();
            currentFrame = 0;
        }
    }
}

void polymorph::engine::render2D::SpriteAnimationImpl::clear()
{
    _callBacks.clear();
}

void polymorph::engine::render2D::SpriteAnimationImpl::setAnimationFrameTime(float frameTime)
{
    this->frameTime = frameTime;
}

polymorph::engine::render2D::SpriteAnimationImpl::SpriteAnimationImpl(
api::PluginManager &Plugins) : ASpriteAnimation(Plugins)
{
    this->animationName = "default";
    this->nbFrames = 1;
    this->yOffset = 0;
    this->frameTime = 0.1f;
    this->reversed = false;
}

void polymorph::engine::render2D::SpriteAnimationImpl::build()
{
    _setProperty("sprite", sprite);
    _setProperty("nbFrames", nbFrames);
    _setProperty("reversed", reversed);
    _setProperty("animationName", animationName);
    _setProperty("frameTime", frameTime);
    _setProperty("yOffset", yOffset);
}

void polymorph::engine::render2D::SpriteAnimationImpl::saveAll()
{
    saveProperty("sprite", sprite);
    saveProperty("nbFrames", nbFrames);
    saveProperty("reversed", reversed);
    saveProperty("animationName", animationName);
    saveProperty("frameTime", frameTime);
    saveProperty("yOffset", yOffset);
}

polymorph::engine::render2D::SpriteAnimationImpl::SpriteAnimationImpl(
        polymorph::engine::safe_ptr<polymorph::engine::AComponent> component,
        std::shared_ptr<myxmlpp::Node> node)
        : ASpriteAnimation(component, node)
{
    build();
    if (nbFrames == 1)
        _width = sprite->getTextureWidth();
    else
        _width = sprite->getTextureWidth() / static_cast<float>(nbFrames);
    _height = sprite->getTextureHeight();
    if (nbFrames == 1)
        _currentFrame = {0, 0, _width , _height};
    else
    {
        if (reversed)
            _currentFrame = {_width * (nbFrames - 1), yOffset, _width , _height};
        else
            _currentFrame = {0, yOffset, _width , _height};
    }
    sprite->setCrop(_currentFrame);
}

polymorph::engine::render2D::SpriteAnimationImpl::SpriteAnimationImpl(
        polymorph::engine::safe_ptr<polymorph::engine::api::APluginConfig> config,
        std::shared_ptr<myxmlpp::Node> node)
        : ASpriteAnimation(config, node)
{
    build();
    if (nbFrames == 1)
        _width = sprite->getTextureWidth();
    else
        _width = sprite->getTextureWidth() / static_cast<float>(nbFrames);
    _height = sprite->getTextureHeight();
    if (nbFrames == 1)
        _currentFrame = {0, 0, _width , _height};
    else
    {
        if (reversed)
            _currentFrame = {_width * (nbFrames - 1), yOffset, _width , _height};
        else
            _currentFrame = {0, yOffset, _width , _height};
    }
    sprite->setCrop(_currentFrame);
}
