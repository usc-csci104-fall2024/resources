file(COPY inputs DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/student_outputs)

add_makefile_problem(
    NAME floorplan
    EXECUTABLE_NAME floorplan
    TEST_SOURCE
        floorplan_tests.cpp)
