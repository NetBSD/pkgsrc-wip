$NetBSD$

automatically determine for what system to compile

--- def/defines.h
+++ def/defines.h
@@ -27,9 +27,19 @@ Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 #define DEFINES_H
 
 // OS constants
+#if defined(_WIN32)
 #define APP_WIN						true
 #define APP_MAC						false
 #define APP_X11						false
+#elif defined(__APPLE__)
+#define APP_WIN						false
+#define APP_MAC						true
+#define APP_X11						false
+#else
+#define APP_WIN						false
+#define APP_MAC						false
+#define APP_X11						true
+#endif
 #define APP_PORTABLE				false //at least one of the 3 OS must be true too!
 
 // Languages
