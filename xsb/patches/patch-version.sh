$NetBSD$

Seems a typo to prefix #! with s

https://sourceforge.net/p/xsb/patches/9/

--- version.sh.orig	2022-05-12 21:57:20.000000000 +0000
+++ version.sh
@@ -1,3 +1,3 @@
-s#! /bin/sh
+#! /bin/sh
 
 # Do not touch xsb_patch_date! It should be updated by SVN (does not currently)
