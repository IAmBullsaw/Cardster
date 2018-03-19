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
	Window(unsigned screen_width, unsigned screen_height, unsigned screen_fps);
	~Window();
	unsigned get_width() const;
	unsigned get_height() const;
	SDL_Renderer* get_renderer() const;
	unsigned get_ticks_per_frame() const;
	void start_frame();
	void end_frame();

private:
	const unsigned screen_width;
	const unsigned screen_height;
	const unsigned screen_fps;
	const unsigned ticks_per_frame;

	unsigned current_time;
	unsigned last_time;

	SDL_Window* window;
	SDL_Renderer* renderer;

};




#endif /* WINDOW_H */
