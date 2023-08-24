$NetBSD: patch-widget_gtk_DMABufSurface.cpp,v 1.1 2023/02/10 10:04:54 pho Exp $

No eventfd on NetBSD 9 and older, fix build

--- widget/gtk/DMABufSurface.cpp.orig	2021-04-08 21:20:12.000000000 +0000
+++ widget/gtk/DMABufSurface.cpp
@@ -18,7 +18,9 @@
 #include <sys/time.h>
 #include <dlfcn.h>
 #include <sys/mman.h>
+#ifndef __NetBSD__
 #include <sys/eventfd.h>
+#endif
 #include <poll.h>
 #include <sys/ioctl.h>
 
@@ -147,6 +149,7 @@ void DMABufSurface::GlobalRefAdd() {
 }
 
 void DMABufSurface::GlobalRefCountCreate() {
+#ifndef __NetBSD__
   LOGDMABUFREF(("DMABufSurface::GlobalRefCountCreate UID %d", mUID));
   MOZ_DIAGNOSTIC_ASSERT(!mGlobalRefCountFd);
   // Create global ref count initialized to 0,
@@ -159,6 +162,7 @@ void DMABufSurface::GlobalRefCountCreate
     mGlobalRefCountFd = 0;
     return;
   }
+#endif
 }
 
 void DMABufSurface::GlobalRefCountImport(int aFd) {
