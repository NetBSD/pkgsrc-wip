$NetBSD: patch-etc_cnid_dbd_comm.c,v 1.1 2011/07/28 16:08:01 hfath Exp $

--- etc/cnid_dbd/comm.c.orig	2011-07-22 04:30:42.000000000 +0000
+++ etc/cnid_dbd/comm.c
@@ -9,6 +9,7 @@
 #include "config.h"
 #endif
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #ifndef _XOPEN_SOURCE
 # define _XOPEN_SOURCE 600
 #endif
@@ -18,6 +19,7 @@
 #ifndef _GNU_SOURCE
 # define _GNU_SOURCE
 #endif
+#endif
 
 #include <stdio.h>
 #include <stdlib.h>
