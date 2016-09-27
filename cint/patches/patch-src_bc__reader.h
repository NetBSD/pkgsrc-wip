$NetBSD$

Add NetBSD support.

--- src/bc_reader.h.orig	2007-03-15 17:59:30.000000000 +0000
+++ src/bc_reader.h
@@ -66,6 +66,8 @@ class G__fstream {
   #else
      m_pos.__pos = pos; // this is for rest linux distribution
   #endif
+#elif defined(__NetBSD__)
+  m_pos._pos = pos;
 #else
   m_pos = pos;
 #endif
