$NetBSD$

Allow overriding CFLAGS. We need -D_NETBSD_SOURCE for mkostemp.

--- config.mk.orig	2019-07-11 05:37:37.000000000 +0000
+++ config.mk
@@ -1,7 +1,7 @@
 # wld: config.mk
 
 CC                  = gcc
-CFLAGS              = -pipe
+CFLAGS              ?= -pipe
 
 ENABLE_DEBUG        = 1
 ENABLE_STATIC       = 1
