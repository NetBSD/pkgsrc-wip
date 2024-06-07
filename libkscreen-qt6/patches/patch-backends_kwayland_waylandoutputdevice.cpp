$NetBSD$

Explicitly include cmath, for compilers that are more exacting, e.g., GCC 7.5.

--- backends/kwayland/waylandoutputdevice.cpp.orig	2024-06-07 09:11:36.618228713 +0000
+++ backends/kwayland/waylandoutputdevice.cpp
@@ -16,6 +16,7 @@
 
 #include <wayland-server-protocol.h>
 
+#include <cmath>
 #include <utility>
 
 using namespace KScreen;
