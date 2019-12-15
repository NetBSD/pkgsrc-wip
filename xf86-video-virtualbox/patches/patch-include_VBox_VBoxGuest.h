$NetBSD$

--- include/VBox/VBoxGuest.h.orig	2019-10-10 18:25:38.000000000 +0000
+++ include/VBox/VBoxGuest.h
@@ -980,7 +980,7 @@ RT_C_DECLS_END
 #endif
 
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 
 /* Private IOCtls between user space and the kernel video driver.  DRM private
  * IOCtls always have the type 'd' and a number between 0x40 and 0x99 (0x9F?) */
