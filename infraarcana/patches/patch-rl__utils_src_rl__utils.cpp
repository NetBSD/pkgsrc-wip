$NetBSD$

Fix includes (for accumulator).

--- rl_utils/src/rl_utils.cpp.orig	2016-04-30 08:38:48.000000000 +0000
+++ rl_utils/src/rl_utils.cpp
@@ -4,6 +4,7 @@
 #include <vector>
 #include <cassert>
 #include <sstream>
+#include <numeric>
 
 #include "mersenne_twister.hpp"
 
