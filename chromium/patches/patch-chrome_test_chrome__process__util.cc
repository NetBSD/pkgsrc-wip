$NetBSD: patch-chrome_test_chrome__process__util.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/test/chrome_process_util.cc.orig	2011-04-13 08:01:56.000000000 +0000
+++ chrome/test/chrome_process_util.cc
@@ -61,7 +61,7 @@ ChromeProcessList GetRunningChromeProces
     result.push_back(process_entry->pid());
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux we might be running with a zygote process for the renderers.
   // Because of that we sweep the list of processes again and pick those which
   // are children of one of the processes that we've already seen.
@@ -72,9 +72,9 @@ ChromeProcessList GetRunningChromeProces
     while (const base::ProcessEntry* process_entry = it.NextProcessEntry())
       result.push_back(process_entry->pid());
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_POSIX)
   // On Mac OS X we run the subprocesses with a different bundle, and
   // on Linux via /proc/self/exe, so they end up with a different
   // name.  We must collect them in a second pass.
