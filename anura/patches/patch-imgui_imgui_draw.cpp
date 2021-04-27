$NetBSD$

NetBSD's alloca(3) can be found in stdlib.h.
--- imgui/imgui_draw.cpp.orig	2021-04-26 19:27:27.434449487 -0700
+++ imgui/imgui_draw.cpp	2021-04-26 19:28:18.554672461 -0700
@@ -21,7 +21,7 @@
 #if !defined(alloca)
 #ifdef _WIN32
 #include <malloc.h>     // alloca
-#elif (defined(__FreeBSD__) || defined(FreeBSD_kernel) || defined(__DragonFly__)) && !defined(__GLIBC__)
+#elif (defined(__FreeBSD__) || defined(FreeBSD_kernel) || defined(__DragonFly__) || defined(__NetBSD__)) && !defined(__GLIBC__)
 #include <stdlib.h>     // alloca. FreeBSD uses stdlib.h unless GLIBC
 #else
 #include <alloca.h>     // alloca
