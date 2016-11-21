$NetBSD$

Fix includes (for iota).

--- src/room.cpp.orig	2016-07-02 15:42:10.000000000 +0000
+++ src/room.cpp
@@ -2,6 +2,7 @@
 
 #include <algorithm>
 #include <climits>
+#include <numeric>
 
 #include "init.hpp"
 #include "map.hpp"
