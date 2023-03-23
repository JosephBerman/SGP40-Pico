file(GLOB FILES *.c *.cpp *.h)
file(GLOB ALGO gas-index-algorithm/sensirion_gas_index_algorithm/*.c gas-index-algorithm/sensirion_gas_index_algorithm/*.h)
message(${FILES})

add_library(sgp STATIC
        ${FILES}
        ${ALGO}
        )


target_link_libraries(sgp pico_stdlib hardware_i2c)

# Link with the pico stdlib

message( ${CMAKE_CURRENT_LIST_DIR})

target_include_directories(sgp PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        gas-index-algorithm/sensirion_gas_index_algorithm
        )



