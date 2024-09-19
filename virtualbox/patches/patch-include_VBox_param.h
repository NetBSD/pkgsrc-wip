$NetBSD$

--- include/VBox/param.h.orig	2016-03-04 19:22:57.000000000 +0000
+++ include/VBox/param.h
@@ -45,7 +45,7 @@
  * @remarks This must match GMMR0Init; currently we only support page fusion on
  *          all 64-bit hosts except Mac OS X */
 #if (   HC_ARCH_BITS == 64          /* ASM-NOINC */ \
-     && (defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_WINDOWS)) ) /* ASM-NOINC */ \
+     && (defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_WINDOWS) || defined(RT_OS_NETBSD)) ) /* ASM-NOINC */ \
  || defined(DOXYGEN_RUNNING)        /* ASM-NOINC */
 # define VBOX_WITH_PAGE_SHARING     /* ASM-NOINC */
 #endif                              /* ASM-NOINC */
@@ -172,4 +172,3 @@
 /** @} */
 
 #endif
-
