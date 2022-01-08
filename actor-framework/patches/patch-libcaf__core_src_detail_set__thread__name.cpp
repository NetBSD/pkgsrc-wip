$NetBSD$

* NetBSD does not have pthread_np.h, since this package requires c++17 use _has_include
  so that pthread_np.h is only included on platforms that have it

* add NetBSD support
* add Solaris support

--- libcaf_core/src/detail/set_thread_name.cpp.orig	2021-07-16 09:33:16.000000000 +0000
+++ libcaf_core/src/detail/set_thread_name.cpp
@@ -12,7 +12,7 @@
 
 #if defined(CAF_LINUX)
 #  include <sys/prctl.h>
-#elif defined(CAF_BSD)
+#elif __has_include(<pthread_np.h>)
 #  include <pthread_np.h>
 #endif // defined(...)
 
@@ -32,6 +32,10 @@ void set_thread_name(const char* name) {
   pthread_setname_np(name);
 #  elif defined(CAF_LINUX)
   prctl(PR_SET_NAME, name, 0, 0, 0);
+#  elif defined(CAF_NETBSD)
+  pthread_setname_np(pthread_self(), name , NULL); 
+#  elif defined(CAF_SOLARIS)
+  pthread_setname_np(pthread_self(), name); 
 #  elif defined(CAF_BSD)
   pthread_set_name_np(pthread_self(), name);
 #  endif // defined(...)
