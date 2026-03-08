$NetBSD$

src/she/sdl2/she.cpp: In member function 'void she::SDL2EventQueue::refresh()':
.buildlink/include/X11/X.h:115:30: error: expected unqualified-id before numeric constant
  115 | #define None                 0L /* universal null resource or null atom */
      |                              ^~

https://github.com/LibreSprite/LibreSprite/issues/542

--- src/she/sdl2/she.cpp.orig	2026-03-08 09:46:40.980210698 +0000
+++ src/she/sdl2/she.cpp
@@ -39,6 +39,8 @@
 #include <chrono>
 #include <thread>
 
+#undef None
+
 float penPressure = 0;
 
 namespace ui {
