$NetBSD$

More than just linux has memcpy in <cstring>...

--- lib-src/header-substitutes/allegro.h.orig	2020-06-19 15:16:47.000000000 +0000
+++ lib-src/header-substitutes/allegro.h
@@ -10,13 +10,9 @@
 #include "../portsmf/allegro.h"
 #pragma warning( pop )
 
-#elif defined(__linux__)
-
-#include <cstring> // Allegro include fails if this header isn't included due to no memcpy
-#include "../portsmf/allegro.h"
-
 #else //_MSC_VER
 
+#include <cstring> // Allegro include fails if this header isn't included due to no memcpy
 #include "../portsmf/allegro.h"
 
 #endif //_MSC_VER
