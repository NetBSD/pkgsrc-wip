$NetBSD$

--- src/dev/cpp/utils.cpp.orig	2016-02-27 19:59:48.000000000 +0000
+++ src/dev/cpp/utils.cpp
@@ -45,6 +45,8 @@
 # include <sys/thr.h>
 # elif defined(__APPLE__)
 # include <pthread.h>
+# elif defined(__NetBSD__)
+# include <lwp.h>
 # endif
 
 # ifdef __TITLE__
@@ -69,6 +71,8 @@ namespace dsn {
             return static_cast<int>(lwpid);
 # elif defined(__APPLE__)
             return static_cast<int>(pthread_mach_thread_np(pthread_self()));
+# elif defined(__NetBSD__)
+            return static_cast<int>(_lwp_self());
 # else
 # error not implemented yet
 # endif 
@@ -506,8 +510,3 @@ namespace  dsn 
         return true;
     }
 } // end namespace dsn
-
-
-
-
-
