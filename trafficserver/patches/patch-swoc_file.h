$NetBSD$

- climits required for build on NetBSD.

diff --git lib/swoc/include/swoc/swoc_file.h lib/swoc/include/swoc/swoc_file.h
index 7e9423969b..9c163662d7 100644
--- lib/swoc/include/swoc/swoc_file.h
+++ lib/swoc/include/swoc/swoc_file.h
@@ -7,6 +7,10 @@
 
 #pragma once
 
+#if !defined(PATH_MAX)
+#include <climits>
+#endif
+
 #include <unistd.h>
 #include <sys/stat.h>
 
