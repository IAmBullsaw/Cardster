#include "window.h"
#include <iostream>

using namespace std;

/**
 * \param screen_width_in Screen width.
 * \param screen_height_in Screen height.
 * \param screen_fps Desired frames per second.
 */
Window::Window(unsigned screen_width, unsigned screen_height, unsigned screen_fps) :
		screen_width{screen_width}, screen_height{screen_height},
    screen_fps{screen_fps}, ticks_per_frame{1000/screen_fps},
    last_time{0}
{

	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO /*|SDL_INIT_AUDIO*/) != 0) {
		cerr << "Error initializing SDL" << endl;
		exit(1);
	}

	// create the window
	window = SDL_CreateWindow("Cardster",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width,
			screen_height, SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, 0);

	// make the scaled rendering look smoother
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");

	// render at a virtual resolution then stretch to actual resolution
	SDL_RenderSetLogicalSize(renderer, screen_width, screen_height);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_GL_SetSwapInterval(-1);
	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

}

/**
 * \brief Takes care of window and renderer pointer, and quits SDL.
 */
Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

unsigned Window::get_width() const {
	return screen_width;
}

unsigned Window::get_height() const {
	return screen_height;
}

SDL_Renderer* Window::get_renderer() const {
	return renderer;
}

unsigned Window::get_ticks_per_frame() const {
	return ticks_per_frame;
}

/**
 * \brief Sets current time with SDL_GetTicks at start of frame.
 */
void Window::start_frame() {
	current_time = SDL_GetTicks();
}

/**
 * \brief Compares start time of this and last frame to calculate what delay is
 * needed for desired fps.
 */
void Window::end_frame() {
	SDL_RenderPresent(renderer);

	if ((current_time - last_time) < ticks_per_frame) {
		SDL_Delay(ticks_per_frame - (current_time - last_time));
	}

	last_time = current_time;
}
