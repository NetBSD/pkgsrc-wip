$NetBSD$

--- source/Host/netbsd/HostThreadNetBSD.cpp.orig	2016-05-01 10:39:36.000000000 +0000
+++ source/Host/netbsd/HostThreadNetBSD.cpp
@@ -18,6 +18,7 @@
 #include <string.h>
 #include <sys/sysctl.h>
 #include <sys/user.h>
+#include <lwp.h>
 
 // C++ includes
 #include <string>
@@ -36,7 +37,8 @@ HostThreadNetBSD::HostThreadNetBSD(lldb:
 void
 HostThreadNetBSD::SetName(lldb::thread_t thread, llvm::StringRef &name)
 {
-    ::pthread_setname_np(thread, "%s", const_cast<char*>(name.data()));
+    ::pthread_setname_np(thread, "%s", static_cast<void*>(const_cast<char*>(name.data())));
+    //::_lwp_setname(thread, name.data());
 }
 
 void
@@ -44,6 +46,7 @@ HostThreadNetBSD::GetName(lldb::thread_t
 {
     char buf[PTHREAD_MAX_NAMELEN_NP];
     ::pthread_getname_np(thread, buf, PTHREAD_MAX_NAMELEN_NP);
+    //_lwp_getname(thread, buf, PTHREAD_MAX_NAMELEN_NP);
 
     name.clear();
     name.append(buf, buf + strlen(buf));
