$NetBSD$

"Fixes for C++11 support" from upstream.

--- MapWindow.cpp.orig	2014-02-22 12:05:53.000000000 +0000
+++ MapWindow.cpp
@@ -2730,7 +2730,7 @@ SDL_Surface *MapWindow::get_sdl_surface(
 {
  SDL_Surface *new_surface = NULL;
  unsigned char *screen_area;
- SDL_Rect copy_area = { area.x + x, area.y + y, w, h };
+ SDL_Rect copy_area = { (Sint16)(area.x + x), (Sint16)(area.y + y), w, h };
 
  GUI::get_gui()->Display();
  screen_area = screen->copy_area(&copy_area);
