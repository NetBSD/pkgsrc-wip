$NetBSD$

pkgsrc calls it pciutils

--- Modules/pci/kpci.cpp.orig	2020-05-05 14:39:33.000000000 +0000
+++ Modules/pci/kpci.cpp
@@ -13,7 +13,7 @@
 
 //extern "C" is needed to proper linking with libpci
 extern "C" {
-#include <pci/pci.h>
+#include <pciutils/pci.h>
 }
 #include <unistd.h>
 #include <sys/types.h> //getuid
