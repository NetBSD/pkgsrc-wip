$NetBSD$

# Fix build

--- src/core/device-support.cpp.orig	2024-10-04 12:23:39 UTC
+++ src/core/device-support.cpp
@@ -27,6 +27,7 @@
 //----------------------------------------------------------------------------
 
 #include <regex>
+#include <cstring>
 #include "idevice.hpp"
 #include "icomputer.hpp"
 #include "cartridge.hpp"
