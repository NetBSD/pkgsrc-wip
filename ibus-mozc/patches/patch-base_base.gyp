$NetBSD: patch-base_base.gyp,v 1.1 2013/01/14 06:21:30 ryo-on Exp $

* Set openssl flags.

--- base/base.gyp.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/base.gyp
@@ -262,20 +262,20 @@
         }],
         ['OS=="linux" and target_platform!="Android"', {
           'cflags': [
-            '<!@(<(pkg_config_command) --cflags-only-other openssl)',
+            '@OPENSSL_CFLAGS@',
           ],
           'defines': [
             'HAVE_OPENSSL=1',
           ],
           'include_dirs': [
-            '<!@(<(pkg_config_command) --cflags-only-I openssl)',
+            '@OPENSSL_INC@',
           ],
           'link_settings': {
             'ldflags': [
-              '<!@(<(pkg_config_command) --libs-only-L openssl)',
+              '@OPENSSL_LDFLAGS@',
             ],
             'libraries': [
-              '<!@(<(pkg_config_command) --libs-only-l openssl)',
+              '@OPENSSL_LIBS@',
             ],
           },
         }],
