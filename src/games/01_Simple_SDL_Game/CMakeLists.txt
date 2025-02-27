cmake_minimum_required(VERSION 3.10)
# = ADJUST ME =
project(Simple_SDL_Game)

include_directories(_core _game_entities _helper _output _data)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
# = ADJUST ME =
set(SOURCES Main.cpp 
			_core/Game.cpp 
			_game_entities/Entity.cpp _game_entities/Player.cpp _game_entities/Ball.cpp _game_entities/Wall.cpp 
			_helper/Math.cpp
			_output/AudioHandler.cpp
			_output/GraphicsHandler.cpp _output/SDL_Handler.cpp
			_data/Rectangle.cpp)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include External Libs -> = ADJUST ME =
# Include SDL (Custom Path)
set(SDL3_DIR "D:/CPPlibs/SDL")
include_directories(${SDL3_DIR}/include)
link_directories(${SDL3_DIR}/lib)
target_link_libraries(${PROJECT_NAME} "${SDL3_DIR}/lib/libSDL3.dll.a")



