project(LedDotMatrix_Tests)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
include_directories(${LEDDotMatrix_SOURCE_DIR}/inc)

add_executable(Google_Tests_run Workspace/WorkspaceTests.cpp ../src/Workspace.cpp FrameBuilder/FrameBuilderTests.cpp FrameBuilder/WorkspaceStub.h ../src/FrameBuilder.cpp ../src/FrameBuilderSpiConverter.cpp FrameBuilderSpiConverter/FrameBuilderSpiConverterTests.cpp FrameBuilderSpiConverter/FrameBuilderStub.h SpiController/SpiControllerTests.cpp SpiController/SpiTransmitterMock.h SpiController/SpiConvertibleStub.h ../src/SpiController.cpp ../src/NullPointerException.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main gmock)