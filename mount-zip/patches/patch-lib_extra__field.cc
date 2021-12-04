$NetBSD$

Header does not exist on NetBSD.
https://github.com/google/mount-zip/pull/1

--- lib/extra_field.cc.orig	2021-11-28 04:14:07.000000000 +0000
+++ lib/extra_field.cc
@@ -18,7 +18,9 @@
 #include "extra_field.h"
 
 #include <sys/stat.h>
+#ifdef __Linux__
 #include <sys/sysmacros.h>
+#endif
 
 #include <cassert>
 #include <cstring>
