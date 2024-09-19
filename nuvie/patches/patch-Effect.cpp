$NetBSD$

"Fixes for C++11 support" from upstream.

--- Effect.cpp.orig	2014-02-22 12:05:53.000000000 +0000
+++ Effect.cpp
@@ -1082,7 +1082,7 @@ void FadeEffect::init_pixelated_fade()
             {
                 // put surface on transparent background (not checked)
                 fillret = SDL_FillRect(overlay, NULL, uint32(TRANSPARENT_COLOR));
-                SDL_Rect overlay_rect = { fade_x, fade_y, 0, 0 };
+                SDL_Rect overlay_rect = { (Sint16)fade_x, (Sint16)fade_y, 0, 0 };
                 fillret = SDL_BlitSurface(fade_from, NULL,
                                           overlay, &overlay_rect);
             }
@@ -1234,8 +1234,8 @@ bool FadeEffect::pixelated_fade_core(uin
             SDL_FillRect(overlay, NULL, (uint32)fade_to);
         else // Note: assert(fade_from) if(fade_to < 0)
         {
-            SDL_Rect fade_from_rect = { 0, 0, fade_from->w, fade_from->h };
-            SDL_Rect overlay_rect = { fade_x, fade_y, fade_from->w, fade_from->h };
+            SDL_Rect fade_from_rect = { 0, 0, (Uint16)fade_from->w, (Uint16)fade_from->h };
+            SDL_Rect overlay_rect = { (Sint16)fade_x, (Sint16)fade_y, (Uint16)fade_from->w, (Uint16)fade_from->h };
             SDL_BlitSurface(fade_from, &fade_from_rect, overlay, &overlay_rect);
         }
         return(true);
