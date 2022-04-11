$NetBSD$

Missing #include for C++20 support.
--- extern/Pomme/src/PommeDebug.cpp.orig	2022-04-11 12:42:52.834341110 -0700
+++ extern/Pomme/src/PommeDebug.cpp	2022-04-11 12:42:39.586446895 -0700
@@ -1,6 +1,7 @@
 #include "PommeDebug.h"
 
 #include <SDL.h>
+#include <algorithm>
 #include <sstream>
 #include <iostream>
 
