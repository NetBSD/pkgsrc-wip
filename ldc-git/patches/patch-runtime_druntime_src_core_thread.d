$NetBSD$

--- runtime/druntime/src/core/thread.d.orig	2016-02-04 22:58:14.000000000 +0000
+++ runtime/druntime/src/core/thread.d
@@ -3195,6 +3195,7 @@ extern (C)
 nothrow:
     version (CRuntime_Glibc) int pthread_getattr_np(pthread_t thread, pthread_attr_t* attr);
     version (FreeBSD) int pthread_attr_get_np(pthread_t thread, pthread_attr_t* attr);
+    version (NetBSD) int pthread_getattr_np(pthread_t thread, pthread_attr_t* attr);
     version (Solaris) int thr_stksegment(stack_t* stk);
     version (CRuntime_Bionic) int pthread_getattr_np(pthread_t thid, pthread_attr_t* attr);
 }
@@ -3322,6 +3323,16 @@ private void* getStackBottom() nothrow
         pthread_attr_destroy(&attr);
         return addr + size;
     }
+    else version (NetBSD)
+    {
+        pthread_attr_t attr;
+        void* addr; size_t size;
+
+        pthread_getattr_np(pthread_self(), &attr);
+        pthread_attr_getstack(&attr, &addr, &size);
+        pthread_attr_destroy(&attr);
+        return addr + size;
+    }
     else version (Solaris)
     {
         stack_t stk;
