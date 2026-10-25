$NetBSD$

* Add support to NetBSD and FreeBSD

--- remote/node_modules/kerberos/binding.gyp.orig	2026-10-24 14:37:41.000000000 +0000
+++ remote/node_modules/kerberos/binding.gyp
@@ -54,14 +54,14 @@
             ]
           }
         }],
-        ['OS=="mac" or OS=="linux"', {
+        ['OS=="mac" or OS=="linux" or OS=="freebsd" or OS=="netbsd"', {
           'sources': [
             'src/unix/base64.cc',
             'src/unix/kerberos_gss.cc',
             'src/unix/kerberos_unix.cc'
           ]
         }],
-        ['(OS=="mac" or OS=="linux") and (kerberos_use_rtld!="true")', {
+        ['(OS=="mac" or OS=="linux" or OS=="freebsd" or OS=="netbsd") and (kerberos_use_rtld!="true")', {
           'link_settings': {
             'libraries': [
               '-lkrb5',
@@ -78,7 +78,7 @@
             }]
           ]
         }],
-        ['(OS=="mac" or OS=="linux") and (kerberos_use_rtld=="true")', {
+        ['(OS=="mac" or OS=="linux" or OS=="freebsd" or OS=="netbsd") and (kerberos_use_rtld=="true")', {
           'defines': ['KERBEROS_USE_RTLD=1'],
           'link_settings': {
             'libraries': [
@@ -86,6 +86,16 @@
             ]
           },
         }],
+        ['OS=="freebsd" or OS=="netbsd"', {
+          'include_dirs+': [
+            '<!(pkg-config krb5 --cflags-only-I | sed -E "s/(-I *|-isystem *)//g")',
+          ],
+          'link_settings': {
+            'library_dirs': [
+              '<!(pkg-config krb5 --libs-only-L | sed -e "s/-L//g")',
+            ]
+          },
+        }],
         ['OS=="win"',  {
           'sources': [
             'src/win32/kerberos_sspi.cc',
