$NetBSD$

--- src/VBox/GuestHost/OpenGL/include/chromium.h.orig	2016-03-04 19:29:19.000000000 +0000
+++ src/VBox/GuestHost/OpenGL/include/chromium.h
@@ -67,7 +67,7 @@
 
 #ifdef DARWIN
 # include <stddef.h>
-#elif !defined(FreeBSD)
+#elif !defined(FreeBSD) && !defined(__NetBSD__)
 #  include <malloc.h>  /* to get ptrdiff_t used below */
 #endif
 
