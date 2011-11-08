$NetBSD: patch-cpp_src_fuse_mount.xtreemfs.cpp,v 1.1.1.1 2011/11/08 01:42:14 tnn2 Exp $

--- cpp/src/fuse/mount.xtreemfs.cpp.orig	2011-11-03 10:51:07.000000000 +0000
+++ cpp/src/fuse/mount.xtreemfs.cpp
@@ -254,8 +254,12 @@ int main(int argc, char **argv) {
   }
 
   // Run fuse.
+#if defined(__NetBSD__)
+  fuse_loop(fuse_);
+#else
   fuse_set_signal_handlers(fuse_get_session(fuse_));
   fuse_loop_mt(fuse_);
+#endif
   // Cleanup
   fuse_teardown(fuse_, mount_point);
   for (int i = 0; i < fuse_opts.size(); i++) {
