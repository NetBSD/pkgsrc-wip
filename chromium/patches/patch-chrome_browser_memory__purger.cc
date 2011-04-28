$NetBSD: patch-chrome_browser_memory__purger.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/memory_purger.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/browser/memory_purger.cc
@@ -135,7 +135,7 @@ void MemoryPurger::PurgeBrowser() {
   // * Purge AppCache memory.  Not yet implemented sufficiently.
   // * Browser-side DatabaseTracker.  Not implemented sufficiently.
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && defined(USE_TCMALLOC)
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_TCMALLOC)
   // Tell tcmalloc to release any free pages it's still holding.
   //
   // TODO(pkasting): A lot of the above calls kick off actions on other threads.
