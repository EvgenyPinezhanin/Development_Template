set(target ${PROJECT_LIBRARY})

file(GLOB hdrs "*.h*" "${PROJECT_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

add_library(${target} STATIC ${srcs} ${hdrs})
target_link_libraries(${target} ${LIBRARY_DEPS})

# REPORT
message( STATUS "")
message( STATUS "General configuration for ${target}")
message( STATUS "OK")
message( STATUS "")
