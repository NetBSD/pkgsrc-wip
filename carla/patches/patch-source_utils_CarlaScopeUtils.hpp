$NetBSD$

NetBSD does not have uselocale.

--- source/utils/CarlaScopeUtils.hpp.orig	2020-09-26 14:38:36.000000000 +0000
+++ source/utils/CarlaScopeUtils.hpp
@@ -25,7 +25,7 @@
 #include <algorithm>
 #include <clocale>
 
-#if ! (defined(CARLA_OS_HAIKU) || defined(CARLA_OS_MAC) || defined(CARLA_OS_WIN))
+#if ! (defined(CARLA_OS_HAIKU) || defined(CARLA_OS_MAC) || defined(CARLA_OS_WIN) || defined(__NetBSD__))
 # define CARLA_USE_NEWLOCALE
 #endif
 
