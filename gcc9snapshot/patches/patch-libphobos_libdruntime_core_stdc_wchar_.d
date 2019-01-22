$NetBSD$

--- libphobos/libdruntime/core/stdc/wchar_.d.orig	2018-10-28 19:51:47.000000000 +0000
+++ libphobos/libdruntime/core/stdc/wchar_.d
@@ -43,6 +43,15 @@ version (CRuntime_Glibc)
         ___value __value;
     }
 }
+else version (NetBSD)
+{
+    union __mbstate_t
+    {
+        int64_t   __mbstateL;
+        char[128] __mbstate8;
+    }
+    alias mbstate_t = __mbstate_t;
+}
 else version (OpenBSD)
 {
     union __mbstate_t
