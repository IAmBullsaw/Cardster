#include "window.h"
#include <iostream>

using namespace std;

/**
 * \param SCREEN_WIDTH_IN Screen width.
 * \param SCREEN_HEIGHT_IN Screen height.
 * \param SCREEN_FPS Desired frames per second.
 */
Window::Window(int SCREEN_WIDTH_IN, int SCREEN_HEIGHT_IN, int SCREEN_FPS) :
		SCREEN_WIDTH { SCREEN_WIDTH_IN }, SCREEN_HEIGHT { SCREEN_HEIGHT_IN }, SCREEN_FPS {
				SCREEN_FPS }, TICKS_PER_FRAME { 1000 / SCREEN_FPS }, last_time {
				0 } {

	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO /*|SDL_INIT_AUDIO*/) != 0) {
		cerr << "Error initializing SDL" << endl;
		exit(1);
	}

	// create the window
	window = SDL_CreateWindow("SokobanII",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, 0);

	// make the scaled rendering look smoother
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");

	// render at a virtual resolution then stretch to actual resolution
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
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

int Window::get_width() const {
	return SCREEN_WIDTH;
}

int Window::get_height() const {
	return SCREEN_HEIGHT;
}

SDL_Renderer* Window::get_renderer() const {
	return renderer;
}

int Window::get_ticks_per_frame() const {
	return TICKS_PER_FRAME;
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

	if ((current_time - last_time) < TICKS_PER_FRAME) {
		SDL_Delay(TICKS_PER_FRAME - (current_time - last_time));
	}

	last_time = current_time;
}
