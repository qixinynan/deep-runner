#include "nanapp.h"
#include "log.h"

NanApp::~NanApp() {
	DestroyWindow();
}

int NanApp::CreateWindow(const char *title, int width, int height) {
    window_title_ = title;
    window_width_ = width;
    window_height_ = height;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        LOG_ERROR("Could not initialize SDL, Eror: {}", SDL_GetError());
        return -1;
    }
    window_ = SDL_CreateWindow(window_title_, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width_, window_height_, SDL_WINDOW_SHOWN);
    if (window_ == nullptr) {
        LOG_ERROR("The window could not be created, Error: {}", SDL_GetError());
        return -1;
    }
    return 0;
}

int NanApp::Run() {
    running_ = true;
    const int framedelay = 1000 / kNanAppFPS;

    Uint32 framestart;
    int frametime;

    while (running_) {
        framestart = SDL_GetTicks();

        while (SDL_PollEvent(&event_)) {
            if (event_.type == SDL_QUIT) {
                running_ = false;
				LOG_INFO("The windows has been closed");
            }
        }
        
        // Ensure the game running loop running at tatget FPS
        frametime = SDL_GetTicks() - framestart;
        if (framedelay > frametime) {
            SDL_Delay(framedelay - frametime);
            LOG_INFO("Delay {}ms", framedelay - frametime);
        }
    }
	DestroyWindow();
    return 0;
}

int NanApp::DestroyWindow() {
    SDL_DestroyWindow(window_);
    SDL_Quit();
    return 0;
}
