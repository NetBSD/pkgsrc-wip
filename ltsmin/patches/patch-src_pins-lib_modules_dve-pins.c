$NetBSD$

Some macros from sys/wait.h are used, #include is needed.

Upstream: https://github.com/utwente-fmt/ltsmin/issues/203

--- src/pins-lib/modules/dve-pins.c.orig	2018-07-03 19:28:10.000000000 +0000
+++ src/pins-lib/modules/dve-pins.c
@@ -6,6 +6,7 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 #include <unistd.h>
 
 #include <dm/dm.h>
