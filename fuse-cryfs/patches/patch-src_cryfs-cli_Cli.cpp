$NetBSD$

Awful hack to workaround the need to register_t type

--- src/cryfs-cli/Cli.cpp.orig	2017-02-11 12:34:50.000000000 +0000
+++ src/cryfs-cli/Cli.cpp
@@ -1,3 +1,7 @@
+#ifdef __NetBSD__ /* XXX awful hack */
+#define _KMEMUSER 1
+#endif
+
 #include "Cli.h"
 
 #include <blockstore/implementations/ondisk/OnDiskBlockStore.h>
