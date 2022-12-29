if(NOT TARGET render-modules)
    include(FetchContent)

    FetchContent_Declare(
            render-modules
            GIT_REPOSITORY https://github.com/PolymorphEngine/render-modules.git
            GIT_TAG dev
    )

    FetchContent_MakeAvailable(render-modules)
    get_target_property(render-modules-icls render-modules INTERFACE_INCLUDE_DIRECTORIES)
endif()