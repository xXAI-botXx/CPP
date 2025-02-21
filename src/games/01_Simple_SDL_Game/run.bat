:: Deactivate showing every single command
@echo off

:: Go to target path
cd /d D:\Informatik\Projekte\CPP\src\games\01_Simple_SDL_Game

:: Reset/create 'build' folder
if exist build rd /s /q build
mkdir build
cd build

:: Import external libs 
copy D:\CPPlibs\SDL\bin\SDL3.dll .

:: Create Makefile and compile C++ files
cmake -G "MinGW Makefiles" ..
mingw32-make

:: Start your Programm
start Simple_SDL_Game.exe

:: Go back to project folder
cd ..


