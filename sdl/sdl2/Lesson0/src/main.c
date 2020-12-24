
#include <SDL.h>

/*
 * Lesson 0: Test to make sure SDL is setup properly
 */
int main(int, char**){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        return 1;
    }
    SDL_Quit();
    return 0;
}