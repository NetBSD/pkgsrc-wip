$NetBSD$

--- src/Method.cxx.orig	2007-03-15 17:59:30.000000000 +0000
+++ src/Method.cxx
@@ -515,6 +515,8 @@ long Cint::G__MethodInfo::FilePosition()
       return((long)ifunc->pentry[index]->pos.__pos);
 #elif defined(G__NONSCALARFPOS_QNX)      
       return((long)ifunc->pentry[index]->pos._Off);
+#elif defined(__NetBSD__)
+      return((long)ifunc->pentry[index]->pos._pos);
 #else
       return((long)ifunc->pentry[index]->pos);
 #endif
