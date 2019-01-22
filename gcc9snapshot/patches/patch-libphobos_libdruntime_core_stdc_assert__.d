$NetBSD$

--- libphobos/libdruntime/core/stdc/assert_.d.orig	2018-10-28 19:51:47.000000000 +0000
+++ libphobos/libdruntime/core/stdc/assert_.d
@@ -53,6 +53,13 @@ else version (FreeBSD)
      */
     void __assert(const(char)* exp, const(char)* file, uint line);
 }
+else version (NetBSD)
+{
+    /***
+     * Assert failure function in the NetBSD C library.
+     */
+    void __assert(const(char)* file, int line, const(char)* exp);
+}
 else version (DragonFlyBSD)
 {
     /***
