add_library(lib STATIC)

target_sources(lib
    PRIVATE
        impl/board.cpp
        impl/coordinate.cpp
        impl/game.cpp
        impl/pieces.cpp
)

target_include_directories(lib
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/impl
)
