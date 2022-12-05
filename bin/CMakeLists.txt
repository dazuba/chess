add_executable(chess)

target_sources(chess
    PRIVATE
        main.cpp
)

target_link_libraries(chess PRIVATE lib)
