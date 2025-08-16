$NetBSD$

* Fix (sayonara-player#460):
src/Gui/Plugins/Engine/GUI_LevelPainter.cpp:188:52:
error: no matching function for call to
'max(__gnu_cxx::__alloc_traits<std::allocator, unsigned int>::value_type, int)'

--- src/Gui/Plugins/Engine/GUI_LevelPainter.cpp.orig	2025-08-16 13:23:23.336606912 +0200
+++ src/Gui/Plugins/Engine/GUI_LevelPainter.cpp
@@ -185,7 +185,7 @@ void GUI_LevelPainter::paint()
 
 			else
 			{
-				m->steps[c][r] = std::max(m->steps[c][r] - 1, 0);
+				m->steps[c][r] = std::max(static_cast<int>(m->steps[c][r]) - 1, 0);
 			}
 
 			if(m->steps[c][r] == 0)
