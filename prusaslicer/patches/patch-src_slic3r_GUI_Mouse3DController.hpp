$NetBSD$

pkgsrc hidapi.h is one level deeper than builtin.

--- src/slic3r/GUI/Mouse3DController.hpp.orig	2021-01-11 13:01:51.000000000 +0000
+++ src/slic3r/GUI/Mouse3DController.hpp
@@ -6,7 +6,7 @@
 
 #include "libslic3r/Point.hpp"
 
-#include "hidapi.h"
+#include "hidapi/hidapi.h"
 
 #include <queue>
 #include <atomic>
