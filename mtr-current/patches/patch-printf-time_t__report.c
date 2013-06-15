$NetBSD: patch-printf-time_t__report.c,v 1.1 2013/06/15 16:00:13 yvs4sf Exp $

netbsd/i386 issue: printf() time_t
https://bugs.launchpad.net/mtr/+bug/1180403

--- report.c.orig	2013-05-15 13:24:32.000000000 +0300
+++ report.c	2013-05-15 14:36:29.000000000 +0300
@@ -340,15 +340,16 @@
     snprint_addr(name, sizeof(name), addr);
 
     int last = net_last(at);
+#ifndef NO_IPINFO
     if(!ipinfo_no) {
       char* fmtinfo = fmt_ipinfo(addr);
       if (fmtinfo != NULL) fmtinfo = trim(fmtinfo);
-      printf("MTR.%s;%lu;%s;%s;%d;%s;%s;%d", MTR_VERSION, now, "OK", Hostname,
+      printf("MTR.%s;%lld;%s;%s;%d;%s;%s;%d", MTR_VERSION, (long long)now, "OK", Hostname,
              at+1, name, fmtinfo, last);
-    } else {
-      printf("MTR.%s;%lu;%s;%s;%d;%s;%d", MTR_VERSION, now, "OK", Hostname,
+    } else
+#endif
+      printf("MTR.%s;%lld;%s;%s;%d;%s;%d", MTR_VERSION, (long long)now, "OK", Hostname,
              at+1, name, last);
-    }
 
     for( i=0; i<MAXFLD; i++ ) {
       j = fld_index[fld_active[j]];
