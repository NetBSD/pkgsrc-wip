$NetBSD: patch-native__client_build_common.gypi,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- native_client/build/common.gypi.orig	2011-04-13 08:13:11.000000000 +0000
+++ native_client/build/common.gypi
@@ -78,12 +78,12 @@
       # Compute the architecture that we're building for. Default to the
       # architecture that we're building on.
       'conditions': [
-        [ 'OS=="linux" and nacl_standalone==0', {
+        [ '(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and nacl_standalone==0', {
           # This handles the Linux platforms we generally deal with. Anything
           # else gets passed through, which probably won't work very well; such
           # hosts should pass an explicit target_arch to gyp.
           'target_arch%':
-            '<!(uname -m | sed -e "s/i.86/ia32/;s/x86_64/x64/;s/arm.*/arm/")'
+            '<!(uname -m | sed -e "s/i.86/ia32/;s/x86_64/x64/;s/amd64/x64/;s/arm.*/arm/")'
         }, {  # OS!="linux"
           'target_arch%': 'ia32',
         }],
@@ -375,7 +375,7 @@
     },
   },
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
       'target_defaults': {
         # Enable -Werror by default, but put it in a variable so it can
         # be disabled in ~/.gyp/include.gypi on the valgrind builders.
@@ -458,6 +458,7 @@
           'NACL_OSX=0',
           'NACL_WINDOWS=0',
           '_BSD_SOURCE=1',
+          '_NETBSD_SOURCE=1',
           '_POSIX_C_SOURCE=199506',
           '_XOPEN_SOURCE=600',
           '_GNU_SOURCE=1',
