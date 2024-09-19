$NetBSD$

--- gold/output.cc.orig	2017-10-29 22:52:18.000000000 +0000
+++ gold/output.cc
@@ -129,7 +129,8 @@ gold_fallocate(int o, off_t offset, off_
 {
 #ifdef HAVE_POSIX_FALLOCATE
   if (parameters->options().posix_fallocate())
-    return ::posix_fallocate(o, offset, len);
+    if (::posix_fallocate(o, offset, len) == 0)
+      return 0;
 #endif // defined(HAVE_POSIX_FALLOCATE)
 #ifdef HAVE_FALLOCATE
   if (::fallocate(o, 0, offset, len) == 0)
