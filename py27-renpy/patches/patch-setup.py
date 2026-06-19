$NetBSD$

* libpng in pkgsrc is libpng16.

--- setup.py.orig	2026-06-19 02:22:31.731038418 +0000
+++ setup.py
@@ -79,7 +79,7 @@ library("SDL2")
 include("pygame_sdl2/pygame_sdl2.h", directory="python{}.{}".format(sys.version_info.major, sys.version_info.minor))
 
 library("SDL2")
-library("png")
+library("png16")
 library("avformat")
 library("avcodec")
 library("avutil")
@@ -99,7 +99,7 @@ else:
     png = 'png16'
 else:
     sdl = [ 'SDL2' ]
-    png = 'png'
+    png = 'png16'
 
 
 if has_fribidi and (not android) and (not ios):
