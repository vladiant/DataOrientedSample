cmake_minimum_required(VERSION 3.10)

project(DataDesignV4 LANGUAGES CXX)

# Sample App
add_executable(
    ${PROJECT_NAME}
    ComponentAIDummy.h
    ComponentCollisionDummy.h
    ComponentPhysicsDummy.h
    ComponentsManager.h
    GameObject.h
    main.cpp
    main.h
    Object.h
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)




