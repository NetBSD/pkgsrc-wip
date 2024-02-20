$NetBSD$

--- lib/misc/server.cc.orig	2024-02-20 01:36:50.043359706 +0000
+++ lib/misc/server.cc
@@ -17,6 +17,7 @@
 #include <config.h>
 #include "server.h"
 #include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
 #include "un.h"
 #include "debug.h"
