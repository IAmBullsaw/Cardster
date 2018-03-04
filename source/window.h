#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window {
public:
	Window(int SCREEN_WIDTH, int SCREEN_HEIGHT, int SCREEN_FPS);
	~Window();
	int get_width() const;
	int get_height() const;
	SDL_Renderer* get_renderer() const;
	int get_ticks_per_frame() const;
	void start_frame();
	void end_frame();

private:
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT;
	const int SCREEN_FPS;
	const int TICKS_PER_FRAME;

	Uint32 current_time;
	Uint32 last_time;

	SDL_Window* window;
	SDL_Renderer* renderer;

};




#endif /* WINDOW_H */
