cmake_minimum_required(VERSION 3.10)

project(DataDesignV5 LANGUAGES CXX)

# Sample App
add_executable(
    ${PROJECT_NAME}
    ComponentAIDummy.h
    ComponentAIDummy.cpp
    ComponentCollisionDummy.h
    ComponentCollisionDummy.cpp
    Component.h
    ComponentPhysicsDummy.h
    ComponentPhysicsDummy.cpp
    ComponentsManager.h
    ComponentsManager.cpp
    GameObject.h
    GameObject.cpp
    main.cpp
    Object.h
    Object.cpp
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)




