$NetBSD: patch-extended_ipinfo_support__report.c,v 1.2 2013/07/06 16:28:37 yvs4sf Exp $

extended ipinfo support (report.c part)
https://bugs.launchpad.net/mtr/+bug/701514

diff -ruN report.c.orig report.c
--- report.c.orig	2013-07-06 08:38:48.000000000 +0300
+++ report.c	2013-07-06 18:51:33.000000000 +0300
@@ -112,15 +112,8 @@
   
 #ifdef IPINFO
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
+  if ((ipinfo_no >= 0) && reportwide)
+    len_tmp += get_iiwidth() -1;
   snprintf( fmt, sizeof(fmt), "HOST: %%-%ds", len_tmp);
 #else
   snprintf( fmt, sizeof(fmt), "HOST: %%-%ds", len_hosts);
