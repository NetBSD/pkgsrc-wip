$NetBSD: patch-cpp_src_fuse_fuse__operations.cpp,v 1.1.1.1 2011/11/08 01:42:14 tnn2 Exp $

--- cpp/src/fuse/fuse_operations.cpp.orig	2011-11-03 10:51:07.000000000 +0000
+++ cpp/src/fuse/fuse_operations.cpp
@@ -332,6 +332,8 @@ void *xtreemfs_fuse_init(struct fuse_con
     Logging::log->getLog(LEVEL_DEBUG)  << "xtreemfs_fuse_init " << endl;
   }
 
+  if (conn) {
+
   // http://sourceforge.net/apps/mediawiki/fuse/index.php?title=Fuse_file_info
   // TODO(mberlin): Check for valid parameters.
   conn->async_read = 5;
@@ -347,6 +349,8 @@ void *xtreemfs_fuse_init(struct fuse_con
       | FUSE_CAP_ATOMIC_O_TRUNC | FUSE_CAP_POSIX_LOCKS;
 #endif
 
+  }
+
   struct fuse_context* context = fuse_get_context();
   return context->private_data;
 }
