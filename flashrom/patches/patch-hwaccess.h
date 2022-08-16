$NetBSD$

Fix header file location

--- hwaccess.h.orig	2022-08-16 09:06:26.181267581 +0000
+++ hwaccess.h
@@ -30,11 +30,7 @@
  */
 #define index shadow_workaround_index
 
-#if !defined (__NetBSD__)
 #include <pci/pci.h>
-#else
-#include <pciutils/pci.h>
-#endif
 
 #undef index
 #endif /* NEED_PCI == 1 */
