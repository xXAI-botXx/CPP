#include <SDL3/SDL.h>
#include <iostream>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL konnte nicht initialisiert werden: " << SDL_GetError() << std::endl;
        return -1;
    } else {
    std::cout << "SDL erfolgreich gestartet!" << std::endl;
    SDL_Quit();
    return 0;
    }
}


