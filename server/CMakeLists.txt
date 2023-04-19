add_library(server STATIC)

target_sources(server
    PRIVATE
        impl/handler.cpp
)

target_include_directories(server
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/impl
)

target_link_libraries(server PRIVATE backend Drogon::Drogon)
