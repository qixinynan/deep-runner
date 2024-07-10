set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

find_package(SDL2 REQUIRED)
find_package(spdlog REQUIRED)

add_library(Nan SHARED "nan/nan.cpp" "nan/log.h" "nan/nan.h" "nan/nanapp.cpp" "nan/nanapp.h")

target_include_directories(Nan
    PUBLIC ${SDL2_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${spdlog_INCLUDE_DIR}
)

target_link_libraries(Nan PUBLIC spdlog::spdlog  ${SDL2_LIBRARIES})
