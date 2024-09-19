$NetBSD$

alloca.h inclusion is made conditional uniformly, such as in
vset-lib/vset_listdd.c

Upstream: https://github.com/utwente-fmt/ltsmin/issues/203

--- src/pins2lts-sym/pins2lts-sym.c.orig	2018-07-03 19:28:10.000000000 +0000
+++ src/pins2lts-sym/pins2lts-sym.c
@@ -1,7 +1,9 @@
 #include <hre/config.h>
 
 #include <float.h>
+#ifdef __APPLE__
 #include <alloca.h>
+#endif
 #include <assert.h>
 #include <dirent.h>
 #include <limits.h>
