$NetBSD$

--- include/VBox/types.h.orig	2018-12-18 12:51:31.000000000 +0000
+++ include/VBox/types.h
@@ -29,6 +29,10 @@
 #include <VBox/cdefs.h>
 #include <iprt/types.h>
 
+#if defined(RT_OS_NETBSD)
+/* PVM is defined by 'sys/param.h' */
+#undef PVM
+#endif
 
 /** @defgroup grp_types     VBox Basic Types
  * @{
