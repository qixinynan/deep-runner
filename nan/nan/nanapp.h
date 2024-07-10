#pragma once

#include <SDL.h>

const int kNanAppFPS = 60;
class NanApp {
public:
	~NanApp();
	int CreateWindow(const char *title, int width, int height);
	int Run();
	int DestroyWindow();
private:
	SDL_Window *window_ = nullptr;
	const char *window_title_ = "Nan Application";
	int window_width_ = 800;
	int window_height_ = 640;
	bool running_ = false;
	SDL_Event event_;
};