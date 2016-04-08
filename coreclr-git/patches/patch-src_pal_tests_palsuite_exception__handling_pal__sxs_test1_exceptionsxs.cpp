$NetBSD$

--- src/pal/tests/palsuite/exception_handling/pal_sxs/test1/exceptionsxs.cpp.orig	2016-04-08 23:29:23.909574749 +0000
+++ src/pal/tests/palsuite/exception_handling/pal_sxs/test1/exceptionsxs.cpp
@@ -31,7 +31,7 @@ extern "C" int InitializeDllTest2();
 extern "C" int DllTest1();
 extern "C" int DllTest2();
 
-#if !defined(__FreeBSD__) && !defined(__NetBSD__)
+#if !defined(__FreeBSD__)
 
 bool bSignal = false;
 bool bCatch = false;
@@ -73,7 +73,7 @@ void sigsegv_handler(int code, siginfo_t
 
 int main(int argc, char *argv[])
 {
-#if !defined(__FreeBSD__) && !defined(__NetBSD__)
+#if !defined(__FreeBSD__)
     struct sigaction newAction;
     struct sigaction oldAction;
     newAction.sa_flags = SA_SIGINFO | SA_RESTART;
