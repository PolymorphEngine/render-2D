/*
** EPITECH PROJECT, 2020
** SpriteAnimatorImpl
** File description:
** header for SpriteAnimator.c
*/


#include "animation/SpriteAnimatorImpl.hpp"

namespace polymorph::engine::render2D
{
    SpriteAnimatorImpl::SpriteAnimatorImpl(engine::GameObject &gameObject, std::shared_ptr<myxmlpp::Node> node)
            : _timer(Game, 0), SpriteAnimatorComponent(gameObject, node)
    {}

    // Called only once when the Script is enabled the first time
    void SpriteAnimatorImpl::start()
    {
        startAnimation(currentAnimation);
    }

    // Called every frame by the engine
    void SpriteAnimatorImpl::update()
    {
        _timer.tick();
        if (animations.empty() || !_currentAnimation)
            return;
        if (_timer.timeIsUp(true))
            _currentAnimation->nextFrame();
    }

    void SpriteAnimatorImpl::startAnimation(std::string animationName)
    {
        if (animations.empty())
            return;
        if (!animationName.empty() && animations.size() > 1) {
            auto it = std::find_if(animations.begin(), animations.end(),
                [&animationName](SpriteAnimation x) {
                    return x->animationName == animationName;
                });
            if (it != animations.end())
                _currentAnimation = *it;
            else
                throw debug::ExceptionLogger("Cannot find animation to start with name : " + animationName);
        } else if (animations.size() > 0 && animations.front())
            _currentAnimation = animations.front();
        else
            throw debug::ExceptionLogger("No animation to start for entity named: "+ gameObject->getName());
        if (_currentAnimation) {
            currentAnimation = animationName;
            _timer = time::Timer(time, _currentAnimation->frameTime);
            targetGraphics->sprite = _currentAnimation->sprite;
        }
    }

    void SpriteAnimatorImpl::addAnimCallBack(
            ASpriteAnimation::AnimationCallBack callback,
            std::string animationName)
    {
        if (!animationName.empty()) {
            auto it = std::find_if(animations.begin(), animations.end(),
                [animationName](const SpriteAnimation x) {
                    return x->animationName == animationName;
                });
            if (it != animations.end())
                (*it)->addEndAnimCallBack(callback);
            else
                throw debug::ExceptionLogger("Cannot find animation with name: " + animationName);
        }
    }

    void SpriteAnimatorImpl::clearAnimationCallbacks(std::string name)
    {
        if (!name.empty())
            std::find_if(animations.begin(), animations.end(), [name](const SpriteAnimation x){
                return x->animationName == name;
            }).operator*()->clear();
        else for (auto &a : animations)
            a->clear();
    }

    void SpriteAnimatorImpl::setAnimationFrameTime(std::string name,
                                                     float frameTime)
    {
        auto a = std::find_if(animations.begin(), animations.end(), [name](const SpriteAnimation x){
            return x->animationName == name;
        }).operator*();
        a->frameTime = frameTime;
        if (name == currentAnimation)
            _timer.delay = frameTime;
    }

    float SpriteAnimatorImpl::getAnimationFrameTime(std::string name)
    {
        auto a = std::find_if(animations.begin(), animations.end(), [name](const SpriteAnimation x){
            return x->animationName == name;
        }).operator*();
        return a->frameTime;
    }

    void SpriteAnimatorImpl::build()
    {
        _setProperty("currentAnimation", currentAnimation);
        _setProperty("targetGraphics", targetGraphics);
        _setProperty("animations", animations);
    }

    void SpriteAnimatorImpl::saveAll()
    {
        saveProperty("currentAnimation", currentAnimation);
        saveProperty("targetGraphics", targetGraphics);
        saveProperty("animations", animations);
    }

}