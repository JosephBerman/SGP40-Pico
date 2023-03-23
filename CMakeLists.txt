file(GLOB FILES *.cpp *.h)

add_library(sgp STATIC
        ${FILES}
        )

target_link_libraries(sgp pico_stdlib hardware_i2c)

# Link with the pico stdlib


target_include_directories(dht PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        )

