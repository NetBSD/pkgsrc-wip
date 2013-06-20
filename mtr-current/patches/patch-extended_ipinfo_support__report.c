$NetBSD: patch-extended_ipinfo_support__report.c,v 1.1 2013/06/20 07:25:59 yvs4sf Exp $

extended ipinfo support (report.c part)
https://bugs.launchpad.net/mtr/+bug/701514

diff -ruN report.c.orig report.c
--- report.c.orig	2013-05-15 12:11:37.000000000 +0300
+++ report.c	2013-05-15 14:54:53.000000000 +0300
@@ -114,15 +114,8 @@
   
 #ifndef NO_IPINFO
   int len_tmp = len_hosts;
-  if (ipinfo_no >= 0) {
-    ipinfo_no %= iiwidth_len;
-    if (reportwide) {
-      len_hosts++;    // space
-      len_tmp   += get_iiwidth();
-      if (!ipinfo_no)
-        len_tmp += 2; // align header: AS
-    }
-  }
+  if ((ipinfo_nos[0] >= 0) && reportwide)
+    len_tmp += get_iiwidth() -1;
   snprintf( fmt, sizeof(fmt), "HOST: %%-%ds", len_tmp);
 #else
   snprintf( fmt, sizeof(fmt), "HOST: %%-%ds", len_hosts);
