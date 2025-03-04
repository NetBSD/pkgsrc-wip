$NetBSD$

* Add support to NetBSD and FreeBSD

--- node_modules/kerberos/binding.gyp.orig	2025-02-24 07:29:25.935536457 +0000
+++ node_modules/kerberos/binding.gyp
@@ -54,7 +54,7 @@
             ]
           }
         }],
-        ['OS=="mac" or OS=="linux"', {
+        ['OS=="mac" or OS=="linux" or OS=="freebsd" or OS=="netbsd"', {
           'sources': [
             'src/unix/base64.cc',
             'src/unix/kerberos_gss.cc',
