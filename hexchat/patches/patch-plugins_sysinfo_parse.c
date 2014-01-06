$NetBSD: patch-plugins_sysinfo_parse.c,v 1.1 2014/01/06 23:05:18 othyro Exp $

Fix header location for pkgsrc.

--- plugins/sysinfo/parse.c.orig	2013-09-11 22:18:19.000000000 +0000
+++ plugins/sysinfo/parse.c
@@ -28,7 +28,7 @@
 #include <time.h>
 #include <dirent.h>
 #include <sys/types.h>
-#include <pci/header.h>
+#include <pciutils/header.h>
 
 #include "pci.h"
 #include "match.h"
