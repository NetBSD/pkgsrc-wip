$NetBSD$

NetBSD fixes.

--- folly/experimental/EnvUtil.cpp.orig	2023-11-22 17:54:59.165151934 +0000
+++ folly/experimental/EnvUtil.cpp
@@ -22,6 +22,10 @@
 #include <folly/portability/Stdlib.h>
 #include <folly/portability/Unistd.h>
 
+#ifdef __NetBSD__
+extern char **environ;
+#endif
+
 using namespace folly;
 using namespace folly::experimental;
 
