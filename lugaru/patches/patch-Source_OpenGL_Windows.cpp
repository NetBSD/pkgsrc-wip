$NetBSD$
--- ./Source/OpenGL_Windows.cpp.orig	2017-02-26 14:58:52.433154283 -0800
+++ ./Source/OpenGL_Windows.cpp	2017-02-26 14:59:06.089987208 -0800
@@ -112,6 +112,7 @@
 #include <math.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #include <fstream>
 #include <iostream>
 #include "gamegl.h"
