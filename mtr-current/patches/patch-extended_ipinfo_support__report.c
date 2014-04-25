--- report.c.orig	2014-01-29 08:21:13.000000000 +0200
+++ report.c	2014-04-25 11:11:04.000000000 +0300
@@ -113,15 +113,8 @@
   
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
