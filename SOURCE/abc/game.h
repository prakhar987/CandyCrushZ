#include <bits/stdc++.h>
#include <SDL.h>        // SDL2
#include <SDL_ttf.h>    // Extension for TEXT Rendering
#include <SDL_mixer.h>  // Extension for Sound Playing

#include "grid.h"       // To Use the Grid Class
using namespace std;

class Game{
public:
    int game_main();
    Game(int,int);
private:
    //Screen dimension constants
    int SCREEN_WIDTH ;
    int SCREEN_HEIGHT;
    SDL_Window* gWindow;            //The window we'll be rendering to
    SDL_Surface* gScreenSurface;    //The surface contained by the window
    SDL_Surface* gCurrentSurface;   //Current displayed image

    TTF_Font* font=NULL ;           // Font
    SDL_Surface* textSurface=NULL;  // Text
    Mix_Chunk *gMusic = NULL;       // Music

    map<int,SDL_Surface*>shapes;    // Contains the 5 Shapes
    SDL_Surface* point_shape=NULL;  // Contains Celebration Image
    int point;
    int moves;

    enum {
    GRID_TYPE_DIAMOND,
    GRID_TYPE_DODE,
    GRID_TYPE_HEXAGON,
    GRID_TYPE_SQUARE,
    GRID_TYPE_TRIANGLE
    };

    bool init();                            //Starts up SDL and creates window
    SDL_Surface* loadSurface(string path);  //Loads individual image (Helper)
    bool loadMedia();                       //Loads media
    void animate_point(vector<int>&, Grid); // Display Celebration when get point
    void animate_grid(Grid);                // Draw the Grid
    void ready_text(string,int);                // Update Currently Held Text
    void close();                           //Frees media and shuts down SDL
};
