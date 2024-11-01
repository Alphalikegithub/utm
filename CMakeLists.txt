# CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(CoordinateConversion)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加源文件
set(SOURCES_FINAL1
    1utm_to_geo.cpp
    datum.cpp
    utm.cpp
)

set(SOURCES_FINAL2
    2geo_to_utm.cpp
    datum.cpp
    utm.cpp
)

# 生成可执行文件 final1 和 final2
add_executable(final1 ${SOURCES_FINAL1})
add_executable(final2 ${SOURCES_FINAL2})

# 添加自动执行的目标
add_custom_target(run_final1
    COMMAND final1
    DEPENDS final1
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running final1..."
)

add_custom_target(run_final2
    COMMAND final2
    DEPENDS final2
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running final2..."
)

# 使 run_final1 和 run_final2 成为默认目标
add_custom_target(run_all DEPENDS run_final1 run_final2)
