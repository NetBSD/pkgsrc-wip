$NetBSD$

--- gdb/i386-bsd-nat.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/i386-bsd-nat.h
@@ -20,6 +20,8 @@
 #ifndef I386_BSD_NAT_H
 #define I386_BSD_NAT_H
 
+#include "x86-bsd-nat.h"
+
 /* Helper functions.  See definitions.  */
 extern void i386bsd_fetch_inferior_registers (struct regcache *regcache,
 					      int regnum);
