$NetBSD$

"Fixes for C++11 support" from upstream.

--- screen/Screen.cpp.orig	2014-02-15 06:41:33.000000000 +0000
+++ screen/Screen.cpp
@@ -1867,7 +1867,7 @@ unsigned char *Screen::copy_area32(SDL_R
 // (NULL area = entire screen)
 unsigned char *Screen::copy_area(SDL_Rect *area, unsigned char *buf)
 {
-    SDL_Rect screen_area = { 0, 0, surface->w, surface->h };
+    SDL_Rect screen_area = { 0, 0, (uint16)surface->w, (uint16)surface->h };
     if(!area)
         area = &screen_area;
 
@@ -1883,7 +1883,7 @@ unsigned char *Screen::copy_area(SDL_Rec
 void Screen::restore_area(unsigned char *pixels, SDL_Rect *area,
                           unsigned char *target, SDL_Rect *target_area, bool free_src)
 {
-    SDL_Rect screen_area = { 0, 0, surface->w, surface->h };
+    SDL_Rect screen_area = { 0, 0, (Uint16)surface->w, (Uint16)surface->h };
     if(!area)
         area = &screen_area;
 
