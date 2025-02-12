$NetBSD$

Fix SDL backend.

--- src/screen_sdl.cpp.orig	2025-01-04 21:38:58.000000000 +0000
+++ src/screen_sdl.cpp
@@ -70,7 +70,7 @@ void screenInit_sys(const Settings* sett
 
     {
     char buf[MOD_NAME_LIMIT];
-    SDL_WM_SetCaption(settings->gameTitle(buf), NULL);
+    SDL_WM_SetCaption(xu4.config->gameTitle(buf), NULL);
     }
 
     SDL_SetGamma(settings->gamma / 100.0f, settings->gamma / 100.0f, settings->gamma / 100.0f);
