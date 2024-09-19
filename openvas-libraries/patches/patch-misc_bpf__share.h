$NetBSD$

Add NetBSD support.

--- misc/bpf_share.h.orig	2015-08-03 10:14:29.000000000 +0000
+++ misc/bpf_share.h
@@ -27,6 +27,7 @@
 #define OPENVAS_BPF_SHARE_H
 
 #include <sys/types.h>
+#include <time.h>
 
 int bpf_open_live (char *, char *);
 u_char *bpf_next (int, int *);
