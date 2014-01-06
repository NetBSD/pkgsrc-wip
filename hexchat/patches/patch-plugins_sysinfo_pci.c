$NetBSD: patch-plugins_sysinfo_pci.c,v 1.1 2014/01/06 23:05:18 othyro Exp $

Fix header location for pkgsrc.

--- plugins/sysinfo/pci.c.orig	2013-09-11 22:18:19.000000000 +0000
+++ plugins/sysinfo/pci.c
@@ -24,7 +24,7 @@
 #include <string.h>
 #include <ctype.h>
 #include <unistd.h>
-#include <pci/pci.h>
+#include <pciutils/pci.h>
 #include "xsys.h"
 
 static struct pci_filter filter;       /* Device filter */
