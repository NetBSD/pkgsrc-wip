$NetBSD$

--- lib/safestack/safestack.cc.orig	2017-07-04 05:53:20.000000000 +0000
+++ lib/safestack/safestack.cc
@@ -21,7 +21,9 @@
 #include <unistd.h>
 #include <sys/resource.h>
 #include <sys/types.h>
+#if !defined(__NetBSD__)
 #include <sys/user.h>
+#endif
 
 #include "interception/interception.h"
 #include "sanitizer_common/sanitizer_common.h"
