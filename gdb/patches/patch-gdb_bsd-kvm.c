$NetBSD: patch-gdb_bsd-kvm.c,v 1.2 2013/06/02 13:14:55 makoto Exp $

(1) (unknown yet)
(2) +#include <sys/signal.h> part:
NetBSD/i386 5.2 has following problem without sys/signal.h
from bsd-kvm.c:36:
/usr/include/sys/signalvar.h:56: error: field 'sd_sigact' has incomplete type
/usr/include/sys/signalvar.h:59: error: 'NSIG' undeclared here (not in a function)
gmake[2]: *** [bsd-kvm.o] Error 1

--- ./work/gdb-7.5.1/gdb/bsd-kvm.c.orig	2012-01-04 17:16:59.000000000 +0900
+++ gdb/bsd-kvm.c	2013-06-02 20:59:26.000000000 +0900
@@ -29,7 +29,12 @@
 
 #include "gdb_assert.h"
 #include <fcntl.h>
+#include <stddef.h>
 #include <kvm.h>
+#define _KMEMUSER 1
+#include <sys/signal.h>
+#include <lwp.h>
+#include <sys/lwp.h>
 #ifdef HAVE_NLIST_H
 #include <nlist.h>
 #endif
@@ -37,6 +42,7 @@
 #include "readline/readline.h"
 #include <sys/param.h>
 #include <sys/proc.h>
+#include <sys/types.h>
 #include <sys/user.h>
 
 #include "bsd-kvm.h"
