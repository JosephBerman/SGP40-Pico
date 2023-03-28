file(GLOB FILES *.c *.cpp *.h)
file(GLOB ALGO gas-index-algorithm/*.c gas-index-algorithm/*.h)
message(${FILES})

add_library(sgp STATIC
        ${FILES}
        ${ALGO}
        )


target_link_libraries(sgp pico_stdlib hardware_i2c)

# Link with the pico stdlib

message( ${CMAKE_CURRENT_LIST_DIR}/gas-index-algorithms)

target_include_directories(sgp PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/gas-index-algorithms
        )



