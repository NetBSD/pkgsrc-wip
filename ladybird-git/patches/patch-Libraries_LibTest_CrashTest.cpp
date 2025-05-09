$NetBSD$

--- Libraries/LibTest/CrashTest.cpp.orig	2025-05-09 08:07:32.093318354 +0000
+++ Libraries/LibTest/CrashTest.cpp
@@ -12,7 +12,7 @@
 #include <sys/wait.h>
 #include <unistd.h>
 
-#if !defined(AK_OS_MACOS) && !defined(AK_OS_EMSCRIPTEN) && !defined(AK_OS_GNU_HURD)
+#if !defined(AK_OS_MACOS) && !defined(AK_OS_EMSCRIPTEN) && !defined(AK_OS_GNU_HURD) && !defined(AK_OS_NETBSD)
 #    include <sys/prctl.h>
 #endif
 
@@ -41,7 +41,7 @@ bool Crash::run(RunType run_type)
 #if defined(AK_OS_GNU_HURD)
             // When we crash, just kill the program, don't dump core.
             setenv("CRASHSERVER", "/servers/crash-kill", true);
-#elif !defined(AK_OS_MACOS) && !defined(AK_OS_EMSCRIPTEN)
+#elif defined(PR_SET_DUMPABLE)
             if (prctl(PR_SET_DUMPABLE, 0, 0, 0) < 0)
                 perror("prctl(PR_SET_DUMPABLE)");
 #endif
