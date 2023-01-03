#include "PluginCore.hpp"
#include "ComponentFactory.hpp"
#include "SerializableObjectFactory.hpp"
#include "polymorph/engine/api/plugin/Symbols.hpp"
#include "ADrawable2dComponent.hpp"
#include "polymorph/engine/debug/exception/core/MissingReferenceException.hpp"

namespace polymorph::engine::api
{
    PluginCore::PluginCore(config::XmlNode &data, Engine &game,
                           std::string PluginsPath)
            : APlugin(data, game, PluginsPath)
    {

    }
    void PluginCore::preUpdateInternalSystems(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::updateInternalSystems(std::shared_ptr<Scene> &scene)
    {
        auto entities = scene->getAll();

        for (auto &entity: entities)
        {
            try {
                if (!!entity->transform->parent())
                    continue;
                _drawEntity(entity);
            } catch (debug::MissingReferenceException &e) {
                e.what();
            }
        }
    }

    void PluginCore::postUpdateInternalSystems(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::startScripts(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::endScripts(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::createConfig(std::vector<std::shared_ptr<APluginConfig>> &configs)
    {
    }

    std::unique_ptr<AComponentFactory> PluginCore::createComponentFactory()
    {
        return std::unique_ptr<AComponentFactory>(new ComponentFactory());
    }

    std::unique_ptr<ASerializableObjectFactory> PluginCore::createSerializableObjectFactory()
    {
        return std::unique_ptr<ASerializableObjectFactory>(new SerializableObjectFactory());
    }

    void PluginCore::_drawEntity(GameObject &entity)
    {
        if (!entity->isActive())
            return;
        auto drawable = entity->getComponent<render2D::ADrawable2dComponent>();
        if (!!drawable && drawable->enabled)
            drawable->draw();

        for (auto &child: **entity->transform)
            _drawEntity(child->gameObject);
    }
}

EXPORT_MODULE polymorph::engine::api::APlugin *createPlugin(polymorph::engine::config::XmlNode &data,
                                                            polymorph::engine::Engine &game, std::string PluginsPath)
{
    return new polymorph::engine::api::PluginCore(data, game, std::move(PluginsPath));
}