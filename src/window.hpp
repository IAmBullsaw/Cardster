#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
/*!
 *
 * \brief Window is a container for each new window.
 *
 */
class Window {
public:
	Window(int screen_width, int screen_height, int screen_fps);
	~Window();
	int get_width() const;
	int get_height() const;
	SDL_Renderer* get_renderer() const;
	int get_ticks_per_frame() const;
	void start_frame();
	void end_frame();

private:
	const int screen_width;
	const int screen_height;
	const int screen_fps;
	const int ticks_per_frame;

	int current_time;
	int last_time;

	SDL_Window* window;
	SDL_Renderer* renderer;

};

#endif /* WINDOW_H */
