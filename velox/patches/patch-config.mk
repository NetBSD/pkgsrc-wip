$NetBSD$

--- config.mk.orig	2019-06-15 23:36:40.000000000 +0000
+++ config.mk
@@ -1,7 +1,7 @@
 # velox: config.mk
 
 CC              = gcc
-CFLAGS          = -pipe
+CFLAGS          ?= -pipe
 
 ENABLE_DEBUG    = 1
 
