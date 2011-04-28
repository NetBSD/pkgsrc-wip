$NetBSD: patch-chrome_renderer_render__thread.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/render_thread.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/render_thread.cc
@@ -984,7 +984,7 @@ void RenderThread::EnsureWebKitInitializ
 }
 
 void RenderThread::IdleHandler() {
-#if (defined(OS_WIN) || defined(OS_LINUX)) && defined(USE_TCMALLOC)
+#if !defined(OS_MACOSX) && defined(USE_TCMALLOC)
   MallocExtension::instance()->ReleaseFreeMemory();
 #endif
 
@@ -1060,7 +1060,7 @@ void RenderThread::OnPurgeMemory() {
   while (!v8::V8::IdleNotification()) {
   }
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && defined(USE_TCMALLOC)
+#if !defined(OS_MACOSX) && defined(USE_TCMALLOC)
   // Tell tcmalloc to release any free pages it's still holding.
   MallocExtension::instance()->ReleaseFreeMemory();
 #endif
