add_library(frontend STATIC)

target_sources(frontend
    PRIVATE
        impl/boarditem.cpp
        impl/mainwidget.cpp
        impl/pieceitem.cpp
        impl/scene.cpp
        impl/validmoveitem.cpp
        include/boarditem.h
        include/mainwidget.h
        include/pieceitem.h
        include/scene.h
        include/validmoveitem.h
)

target_include_directories(frontend
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/impl
)

target_link_libraries(frontend PRIVATE backend Qt6::Core Qt6::Gui Qt6::SvgWidgets Qt6::Widgets)
