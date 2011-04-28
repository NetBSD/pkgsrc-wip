$NetBSD: patch-chrome_browser_renderer__host_backing__store__x.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/renderer_host/backing_store_x.cc.orig	2011-04-13 08:01:43.000000000 +0000
+++ chrome/browser/renderer_host/backing_store_x.cc
@@ -10,7 +10,7 @@
 #include <sys/ipc.h>
 #include <sys/shm.h>
 
-#if defined(OS_OPENBSD) || defined(OS_FREEBSD)
+#if defined(OS_BSD)
 #include <sys/endian.h>
 #endif
 
@@ -70,7 +70,7 @@ BackingStoreX::BackingStoreX(RenderWidge
       visual_(visual),
       visual_depth_(depth),
       root_window_(ui::GetX11RootWindow()) {
-#if defined(OS_OPENBSD) || defined(OS_FREEBSD)
+#if defined(OS_BSD)
   COMPILE_ASSERT(_BYTE_ORDER == _LITTLE_ENDIAN, assumes_little_endian);
 #else
   COMPILE_ASSERT(__BYTE_ORDER == __LITTLE_ENDIAN, assumes_little_endian);
