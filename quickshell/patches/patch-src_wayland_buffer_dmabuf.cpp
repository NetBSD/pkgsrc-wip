$NetBSD$

* Include sysmacros.h only on linux

--- src/wayland/buffer/dmabuf.cpp.orig	2026-08-21 02:28:55.000000000 +0000
+++ src/wayland/buffer/dmabuf.cpp
@@ -37,7 +37,9 @@
 #include <qwaylandclientextension.h>
 #include <sys/mman.h>
 #include <sys/stat.h>
+#if defined(__linux__)
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 #include <vulkan/vulkan_core.h>
