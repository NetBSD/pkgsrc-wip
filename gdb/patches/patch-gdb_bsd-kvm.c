$NetBSD: patch-gdb_bsd-kvm.c,v 1.1 2013/04/11 14:28:35 keckhardt Exp $

--- gdb/bsd-kvm.c.orig	2012-01-04 08:16:59.000000000 +0000
+++ gdb/bsd-kvm.c
@@ -29,7 +29,11 @@
 
 #include "gdb_assert.h"
 #include <fcntl.h>
+#include <stddef.h>
 #include <kvm.h>
+#define _KMEMUSER 1
+#include <lwp.h>
+#include <sys/lwp.h>
 #ifdef HAVE_NLIST_H
 #include <nlist.h>
 #endif
@@ -37,6 +41,7 @@
 #include "readline/readline.h"
 #include <sys/param.h>
 #include <sys/proc.h>
+#include <sys/types.h>
 #include <sys/user.h>
 
 #include "bsd-kvm.h"
