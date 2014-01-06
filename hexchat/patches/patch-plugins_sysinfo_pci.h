$NetBSD: patch-plugins_sysinfo_pci.h,v 1.1 2014/01/06 23:05:18 othyro Exp $

Fix header location for pkgsrc.

--- plugins/sysinfo/pci.h.orig	2013-09-11 22:18:19.000000000 +0000
+++ plugins/sysinfo/pci.h
@@ -21,7 +21,7 @@
 #ifndef _PCI_H_
 #define _PCI_H_
 
-#include <pci/pci.h>
+#include <pciutils/pci.h>
 void pci_find_fullname(char *fullname, char *vendor, char *device);
 int  pci_find_by_class(u16 *class, char *vendor, char *device);
 
