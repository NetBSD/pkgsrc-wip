$NetBSD$

https://github.com/gvansickle/ucg/issues/97

--- src/MemDiags.cpp.orig	2016-03-31 00:05:28.000000000 +0000
+++ src/MemDiags.cpp
@@ -28,5 +28,7 @@ MemDiags::MemDiags()
 
 void MemDiags::PrintStats() const
 {
+#ifndef __NetBSD__
 	malloc_stats();
+#endif
 }
