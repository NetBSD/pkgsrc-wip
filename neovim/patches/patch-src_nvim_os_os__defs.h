$NetBSD$

--- src/nvim/os/os_defs.h.orig	2021-11-30 17:20:42.000000000 +0000
+++ src/nvim/os/os_defs.h
@@ -13,6 +13,10 @@
 # include "nvim/os/unix_defs.h"
 #endif
 
+#if !defined(NAME_MAX) && defined(_XOPEN_NAME_MAX)
+#define NAME_MAX _XOPEN_NAME_MAX
+#endif
+
 #define BASENAMELEN (NAME_MAX - 5)
 
 // Use the system path length if it makes sense.
