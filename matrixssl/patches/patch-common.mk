$NetBSD$

Let pkgsrc tell us where macOS system headers are.

--- common.mk.orig	2017-06-28 06:34:11.000000000 +0000
+++ common.mk
@@ -309,7 +309,7 @@ endif
 # OS X Target
 ifneq (,$(findstring -apple,$(CCARCH)))
  OSDEP:=POSIX
- CFLAGS+=-isystem -I/usr/include
+ #CFLAGS+=-isystem -I/usr/include
 endif
 
 # Bare Metal / RTOS Target
