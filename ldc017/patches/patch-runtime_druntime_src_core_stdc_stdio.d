$NetBSD$

--- runtime/druntime/src/core/stdc/stdio.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/stdc/stdio.d
@@ -29,6 +29,10 @@ private
   {
     import core.sys.posix.sys.types;
   }
+  version (NetBSD)
+  {
+    import core.sys.posix.sys.types;
+  }
 }
 
 extern (C):
@@ -209,6 +213,37 @@ else version ( DragonFlyBSD )
         long        _mbstateL;
     }
 }
+else version ( NetBSD )
+{
+    enum
+    {
+        ///
+        BUFSIZ       = 1024,
+        ///
+        EOF          = -1,
+        ///
+        FOPEN_MAX    = 20,
+        ///
+        FILENAME_MAX = 1024,
+        ///
+        TMP_MAX      = 308915776,
+        ///
+        L_tmpnam     = 1024
+    }
+
+    struct __sbuf
+    {
+        ubyte *_base;
+        int _size;
+    }
+
+    union __mbstate_t // <sys/_types.h>
+    {
+        char[128]   _mbstate8;
+        long        _mbstateL;
+    }
+}
+
 else version (Solaris)
 {
     enum
