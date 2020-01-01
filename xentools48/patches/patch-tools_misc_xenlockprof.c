$NetBSD$

char bufer too small

--- tools/misc/xenlockprof.c.orig	2020-01-01 19:43:06.189653207 +0900
+++ tools/misc/xenlockprof.c	2020-01-01 19:37:55.053480360 +0900
@@ -24,7 +24,7 @@
     uint32_t           i, j, n;
     uint64_t           time;
     double             l, b, sl, sb;
-    char               name[60];
+    char               name[128];
     DECLARE_HYPERCALL_BUFFER(xc_lockprof_data_t, data);
 
     if ( (argc > 2) || ((argc == 2) && (strcmp(argv[1], "-r") != 0)) )
