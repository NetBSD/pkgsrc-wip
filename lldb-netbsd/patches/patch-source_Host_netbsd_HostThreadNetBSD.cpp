$NetBSD$

--- source/Host/netbsd/HostThreadNetBSD.cpp.orig	2016-12-17 10:30:35.000000000 +0000
+++ source/Host/netbsd/HostThreadNetBSD.cpp
@@ -29,15 +29,7 @@ HostThreadNetBSD::HostThreadNetBSD() {}
 HostThreadNetBSD::HostThreadNetBSD(lldb::thread_t thread)
     : HostThreadPosix(thread) {}
 
-void HostThreadNetBSD::SetName(lldb::thread_t thread, llvm::StringRef &name) {
-  ::pthread_setname_np(thread, "%s", const_cast<char *>(name.data()));
-}
-
-void HostThreadNetBSD::GetName(lldb::thread_t thread,
+void HostThreadNetBSD::GetName(lldb::tid_t thread,
                                llvm::SmallVectorImpl<char> &name) {
-  char buf[PTHREAD_MAX_NAMELEN_NP];
-  ::pthread_getname_np(thread, buf, PTHREAD_MAX_NAMELEN_NP);
-
   name.clear();
-  name.append(buf, buf + strlen(buf));
 }
