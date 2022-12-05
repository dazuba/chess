add_library(backend STATIC)

target_sources(backend
    PRIVATE
        impl/board.cpp
        impl/coordinate.cpp
        impl/pieces.cpp
)

target_include_directories(backend
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/impl
)
