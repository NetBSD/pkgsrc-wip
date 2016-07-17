$NetBSD$

--- build/filename_rules.gypi.orig	2016-06-24 01:02:09.000000000 +0000
+++ build/filename_rules.gypi
@@ -29,7 +29,7 @@
     # In case a file is not needed, it is going to be excluded later on.
     # TODO(evan): the above is not correct; we shouldn't build _linux
     # files on non-linux.
-    ['OS!="linux" and OS!="openbsd" and OS!="freebsd" or >(nacl_untrusted_build)==1', {
+    ['OS!="linux" and OS!="openbsd" and OS!="freebsd" and OS!="netbsd" or >(nacl_untrusted_build)==1', {
       'sources/': [
         ['exclude', '_linux(_unittest|_test)?\\.(h|cc)$'],
         ['exclude', '(^|/)linux/'],
@@ -89,7 +89,7 @@
                     ['exclude', '_ashwin\\.(h|cc)$']
       ]
     }],
-    ['<(use_aura)==0 or OS!="linux" or >(nacl_untrusted_build)==1', {
+    ['<(use_aura)==0 or (OS!="linux" and OS!="openbsd" and OS!="freebsd" and OS!="netbsd") or >(nacl_untrusted_build)==1', {
       'sources/': [ ['exclude', '_auralinux\\.(h|cc)$'] ]
     }],
     ['<(use_ozone)==0 or >(nacl_untrusted_build)==1', {
