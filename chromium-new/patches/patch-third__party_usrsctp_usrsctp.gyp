$NetBSD$

--- third_party/usrsctp/usrsctp.gyp.orig	2016-06-24 01:02:50.000000000 +0000
+++ third_party/usrsctp/usrsctp.gyp
@@ -111,6 +111,14 @@
           'cflags!': [ '-Werror', '-Wall' ],
           'cflags': [ '-w' ],
         }],
+        ['OS=="freebsd"', {
+          'defines': [
+            'HAVE_SCONN_LEN',
+            '__Userspace_os_FreeBSD',
+          ],
+          'cflags!': [ '-Werror', '-Wall' ],
+          'cflags': [ '-U__FreeBSD__', '-w' ],
+        }],
         ['OS=="mac" or OS=="ios"', {
           'defines': [
             'HAVE_SA_LEN',
