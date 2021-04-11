set(target ${PROJECT_TESTS})

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest) #${PROJECT_LIBRARY})

# REPORT
message( STATUS "")
message( STATUS "General configuration for ${target}")
message( STATUS "OK")
message( STATUS "")
