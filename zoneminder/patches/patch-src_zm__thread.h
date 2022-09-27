$NetBSD: patch-src_zm__thread.h,v 1.4 2015/04/10 02:58:49 dsainty Exp $

Fix build with Clang.

pthread_t is opaque, and under NetBSD is a pointer.  It's being abused here,
but the value is only used for logging, and casting pthread_self() is more
portable than syscall(SYS_gettid).

\todo Fix correctly upstream.

--- src/zm_thread.h.orig	2018-12-08 14:22:36.000000000 +0000
+++ src/zm_thread.h
@@ -22,19 +22,20 @@
 
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
 #include <sys/thr.h>
 #endif
+#ifdef __NetBSD__
+#include <lwp.h>
+#endif
 
 class ThreadException : public Exception {
 private:
-#ifndef SOLARIS
+#ifndef USE_PTHREAD
   pid_t pid() {
     pid_t tid; 
 #ifdef __FreeBSD__ 
@@ -44,6 +45,8 @@ private:
 #else 
   #ifdef __FreeBSD_kernel__
     if ( (syscall(SYS_thr_self, &tid)) < 0 ) // Thread/Process id
+  #elif defined(__NetBSD__)
+    tid = _lwp_self();
   # else
     tid=syscall(SYS_gettid); 
   #endif
@@ -54,7 +57,7 @@ private:
   pthread_t pid() { return( pthread_self() ); }
 #endif
 public:
-  explicit ThreadException( const std::string &message ) : Exception( stringtf("(%d) ", (long int)pid())+message ) {
+  explicit ThreadException( const std::string &message ) : Exception( stringtf("(%jd) ", (intmax_t)pid())+message ) {
   }
 };
 
@@ -209,7 +212,7 @@ protected:
 
   Mutex mThreadMutex;
   Condition mThreadCondition;
-#ifndef SOLARIS
+#ifndef USE_PTHREAD
   pid_t mPid;
 #else
   pthread_t mPid;
@@ -222,7 +225,7 @@ protected:
   Thread();
   virtual ~Thread();
 
-#ifndef SOLARIS
+#ifndef USE_PTHREAD
   pid_t id() const {
     pid_t tid; 
 #ifdef __FreeBSD__ 
@@ -233,6 +236,8 @@ protected:
   #ifdef __FreeBSD_kernel__
     if ( (syscall(SYS_thr_self, &tid)) < 0 ) // Thread/Process id
 
+  #elif defined(__NetBSD__)
+    tid = _lwp_self();
   #else
     tid=syscall(SYS_gettid); 
   #endif
@@ -257,7 +262,7 @@ public:
   void join();
   void kill( int signal );
   bool isThread() {
-    return( mPid > -1 && pthread_equal( pthread_self(), mThread ) );
+    return( /* mPid > -1 && */ pthread_equal( pthread_self(), mThread ) );
   }
   bool isStarted() const { return mStarted; }
   bool isRunning() const { return mRunning; }
