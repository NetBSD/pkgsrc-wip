$NetBSD$

Use amixer only on Linux

--- config.def.h.orig	2020-02-21 16:08:47.000000000 +0000
+++ config.def.h
@@ -8,9 +8,15 @@ const char* term[]    = {"st",          
 const char* scrot[]   = {"scr",            0};
 const char* briup[]   = {"bri", "10", "+", 0};
 const char* bridown[] = {"bri", "10", "-", 0};
+#if defined(__Linux__)
 const char* voldown[] = {"amixer", "sset", "Master", "5%-",         0};
 const char* volup[]   = {"amixer", "sset", "Master", "5%+",         0};
 const char* volmute[] = {"amixer", "sset", "Master", "toggle",      0};
+#elif (__NetBSD__)
+const char* volup[] = {"mixerctl", "-w", "outputs.master+=5" };
+const char* voldown[] = {"mixerctl", "-w", "outputs.master-=5" };
+const char* volmute[] = {"mixerctl", "-w", "outputs.master=0" };
+#endif
 const char* colors[]  = {"bud", "/home/goldie/Pictures/Wallpapers", 0};
 
 static struct key keys[] = {
