$NetBSD$

* add NetBSD support
* add Solaris support

--- libcaf_core/src/detail/set_thread_name.cpp.orig	2021-07-16 09:33:16.000000000 +0000
+++ libcaf_core/src/detail/set_thread_name.cpp
@@ -34,6 +34,10 @@ void set_thread_name(const char* name) {
   prctl(PR_SET_NAME, name, 0, 0, 0);
 #  elif defined(CAF_BSD)
   pthread_set_name_np(pthread_self(), name);
+#  elif defined(CAF_NETBSD)
+  pthread_setname_np(pthread_self(), name , NULL); 
+#  elif defined(CAF_SOLARIS)
+  pthread_setname_np(pthread_self(), name); 
 #  endif // defined(...)
 #endif   // CAF_WINDOWS
 }
