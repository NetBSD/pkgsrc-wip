--- report.c.orig	2014-05-29 12:31:51.000000000 +0300
+++ report.c	2014-05-29 14:23:56.000000000 +0300
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
+  if (enable_ipinfo && reportwide)
+    len_tmp += ii_getwidth() - 1;
   snprintf( fmt, sizeof(fmt), "HOST: %%-%ds", len_tmp);
 #else
   snprintf( fmt, sizeof(fmt), "HOST: %%-%ds", len_hosts);
@@ -146,7 +139,7 @@
     snprint_addr(name, sizeof(name), addr);
 
 #ifdef IPINFO
-    if (is_printii()) {
+    if (enable_ipinfo) {
       snprintf(fmt, sizeof(fmt), " %%2d. %%s%%-%ds", len_hosts);
       snprintf(buf, sizeof(buf), fmt, at+1, fmt_ipinfo(addr), name);
     } else {
@@ -192,7 +185,7 @@
       if (!found) {
   
 #ifdef IPINFO
-        if (is_printii()) {
+        if (enable_ipinfo) {
           if (mpls->labels && z == 1 && enablempls)
             print_mpls(mpls);
           snprint_addr(name, sizeof(name), addr2);
@@ -228,7 +221,7 @@
 
     /* No multipath */
 #ifdef IPINFO
-    if (is_printii()) {
+    if (enable_ipinfo) {
       if (mpls->labels && z == 1 && enablempls)
         print_mpls(mpls);
     } else {
@@ -340,12 +333,10 @@
 
     int last = net_last(at);
 #ifdef IPINFO
-    if(!ipinfo_no) {
-      char* fmtinfo = fmt_ipinfo(addr);
-      if (fmtinfo != NULL) fmtinfo = trim(fmtinfo);
+    if(enable_ipinfo)
       printf("MTR.%s;%lld;%s;%s;%d;%s;%s;%d", MTR_VERSION, (long long)now, "OK", Hostname,
-             at+1, name, fmtinfo, last);
-    } else
+             at+1, name, trim(fmt_ipinfo(addr)), last);
+    else
 #endif
       printf("MTR.%s;%lld;%s;%s;%d;%s;%d", MTR_VERSION, (long long)now, "OK", Hostname,
              at+1, name, last);
