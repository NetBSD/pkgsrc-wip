$NetBSD$

Add header file for std::byte.

--- source/network/StunClient.cpp.orig	2021-07-27 21:57:02.000000000 +0000
+++ source/network/StunClient.cpp
@@ -28,6 +28,7 @@
 #include "lib/external_libraries/enet.h"
 
 #include <chrono>
+#include <cstddef>
 #include <vector>
 #include <thread>
 
