$NetBSD: patch-include_VBox_VBoxGuest.h,v 1.1 2015/09/15 20:56:04 tnn2 Exp $

--- include/VBox/VBoxGuest.h.orig	2015-09-08 07:03:01.000000000 +0000
+++ include/VBox/VBoxGuest.h
@@ -527,7 +527,7 @@ typedef VBOXGUESTOS2IDCCONNECT *PVBOXGUE
 
 #endif /* RT_OS_OS2 */
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 
 /* Private IOCtls between user space and the kernel video driver.  DRM private
  * IOCtls always have the type 'd' and a number between 0x40 and 0x99 (0x9F?) */
