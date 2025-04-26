target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
file(GLOB PROJECT_HEADERS "inc/*.h")
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")

target_sources(${CMAKE_PROJECT_NAME} PUBLIC
        "main.cpp"
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Qml)