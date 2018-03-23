#include "../src/window.hpp"
#include <gtest/gtest.h>

struct WindowState {
  int screen_width;
  int screen_height;
  int screen_fps;
  bool success;
};

struct WindowTest : testing::Test {
  Window* window;
  WindowTest () {
    window = new Window(100,100,100);
  }
  virtual ~WindowTest () {
    delete window;
  }
};

TEST_F(WindowTest, ConstructorZero) {
  EXPECT_EQ(1, window->get_width());
  EXPECT_EQ(1, window->get_height());
}
