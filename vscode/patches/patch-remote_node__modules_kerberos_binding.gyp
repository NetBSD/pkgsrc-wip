$NetBSD$

* Add support to NetBSD and FreeBSD

--- remote/node_modules/kerberos/binding.gyp.orig	2025-03-01 08:55:16.000000000 +0000
+++ remote/node_modules/kerberos/binding.gyp
@@ -54,7 +54,7 @@
             ]
           }
         }],
-        ['OS=="mac" or OS=="linux"', {
+        ['OS=="mac" or OS=="linux" or OS=="freebsd" or OS=="netbsd"', {
           'sources': [
             'src/unix/base64.cc',
             'src/unix/kerberos_gss.cc',
