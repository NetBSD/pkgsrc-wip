$NetBSD: patch-Source_JavaScriptCore_tools_CodeProfiling.cpp,v 1.1 2015/02/23 16:11:06 leot1990 Exp $

* Add NetBSD support

--- src/qt/qtwebkit/Source/JavaScriptCore/tools/CodeProfiling.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/JavaScriptCore/tools/CodeProfiling.cpp
@@ -33,7 +33,7 @@
 #include <signal.h>
 #endif
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(NETBSD)
 #include <sys/time.h>
 #endif
 
@@ -48,7 +48,7 @@ WTF::MetaAllocatorTracker* CodeProfiling
 #pragma clang diagnostic ignored "-Wmissing-noreturn"
 #endif
 
-#if (PLATFORM(MAC) && CPU(X86_64)) || (OS(LINUX) && CPU(X86) && !OS(ANDROID))
+#if (PLATFORM(MAC) && CPU(X86_64)) || ((OS(LINUX) || OS(NETBSD)) && CPU(X86) && !OS(ANDROID))
 // Helper function to start & stop the timer.
 // Presently we're using the wall-clock timer, since this seems to give the best results.
 static void setProfileTimer(unsigned usec)
@@ -73,7 +73,7 @@ static void profilingTimer(int, siginfo_
     CodeProfiling::sample(reinterpret_cast<void*>(context->__ss.__rip),
                           reinterpret_cast<void**>(context->__ss.__rbp));
 }
-#elif OS(LINUX) && CPU(X86) && !OS(ANDROID)
+#elif (OS(LINUX) || OS(NETBSD)) && CPU(X86) && !OS(ANDROID)
 static void profilingTimer(int, siginfo_t*, void* uap)
 {
     mcontext_t context = static_cast<ucontext_t*>(uap)->uc_mcontext;
@@ -143,7 +143,7 @@ void CodeProfiling::begin(const SourceCo
     if (alreadyProfiling)
         return;
 
-#if (PLATFORM(MAC) && CPU(X86_64)) || (OS(LINUX) && CPU(X86) && !OS(ANDROID))
+#if (PLATFORM(MAC) && CPU(X86_64)) || ((OS(LINUX) || OS(NETBSD)) && CPU(X86) && !OS(ANDROID))
     // Regsiter a signal handler & itimer.
     struct sigaction action;
     action.sa_sigaction = reinterpret_cast<void (*)(int, siginfo_t *, void *)>(profilingTimer);
