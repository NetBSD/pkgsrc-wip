$NetBSD$

--- Tests/LibJS/test262-runner.cpp.orig	2025-05-05 13:40:56.000000000 +0000
+++ Tests/LibJS/test262-runner.cpp
@@ -27,7 +27,7 @@
 #include <signal.h>
 #include <unistd.h>
 
-#if !defined(AK_OS_MACOS) && !defined(AK_OS_EMSCRIPTEN) && !defined(AK_OS_GNU_HURD)
+#if !defined(AK_OS_MACOS) && !defined(AK_OS_EMSCRIPTEN) && !defined(AK_OS_GNU_HURD) && !defined(AK_OS_NETBSD)
 // Only used to disable core dumps
 #    include <sys/prctl.h>
 #endif
@@ -592,7 +592,7 @@ int main(int argc, char** argv)
 #ifdef AK_OS_GNU_HURD
     if (disable_core_dumping)
         setenv("CRASHSERVER", "/servers/crash-kill", true);
-#elif !defined(AK_OS_MACOS) && !defined(AK_OS_EMSCRIPTEN)
+#elif defined(PR_SET_DUMPABLE)
     if (disable_core_dumping && prctl(PR_SET_DUMPABLE, 0, 0, 0) < 0) {
         perror("prctl(PR_SET_DUMPABLE)");
         return exit_wrong_arguments;
