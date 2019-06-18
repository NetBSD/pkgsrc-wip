$NetBSD: patch-src_zm__thread.h,v 1.4 2015/04/10 02:58:49 dsainty Exp $

Fix build with Clang.

pthread_t is opaque, and under NetBSD is a pointer.  It's being abused here,
but the value is only used for logging, and casting pthread_self() is more
portable than syscall(SYS_gettid).

--- src/zm_thread.h.orig	2016-02-03 18:40:30.000000000 +0000
+++ src/zm_thread.h
@@ -22,10 +22,8 @@
 
 #include <unistd.h>
 #include <pthread.h>
+#include <stdint.h>
 #include <unistd.h>
-#ifdef HAVE_SYS_SYSCALL_H
-#include <sys/syscall.h>
-#endif // HAVE_SYS_SYSCALL_H
 #include "zm_exception.h"
 #include "zm_utils.h"
 #ifdef __FreeBSD__
@@ -35,7 +33,7 @@
 class ThreadException : public Exception
 {
 private:
-#ifndef SOLARIS
+#if !defined(SOLARIS) && !defined(__NetBSD__)
 pid_t pid() {
     pid_t tid; 
 #ifdef __FreeBSD__ 
@@ -55,7 +53,8 @@ pid_t pid() {
 pthread_t pid() { return( pthread_self() ); }
 #endif
 public:
-    ThreadException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)pid() ) ) {
+ /* The type of pid() varies by OS */
+ ThreadException( const std::string &message ) : Exception( stringtf( ("(%jd) "+message).c_str, (intmax_t)pid() ) ) {
     }
 };
 
