$NetBSD: patch-extended_ipinfo_support__select.c,v 1.2 2013/07/06 16:28:37 yvs4sf Exp $

extended ipinfo support (select.c part)
https://bugs.launchpad.net/mtr/+bug/701514

diff -ruN select.c.orig select.c
--- select.c.orig	2013-07-06 08:38:48.000000000 +0300
+++ select.c	2013-07-06 19:00:05.000000000 +0300
@@ -211,14 +211,24 @@
 #ifdef IPINFO
       case ActionII:
 	if (ipinfo_no >= 0) {
-	  ipinfo_no++;
-          if (ipinfo_no > ipinfo_max)
-            ipinfo_no = 0;
+	  int i;
+	  for (i = 0; (i <= II_ITEM_MAX) && (ipinfo_nos[i] >= 0); i++) {
+	    ipinfo_nos[i]++;
+	    if (ipinfo_nos[i] > ipinfo_max)
+	      ipinfo_nos[i] = 0;
+	  }
+	} else { // ipinfo init
+	  parse_iiarg("0");
+	  asn_open();
 	}
 	break;
       case ActionAS:
 	if (ipinfo_no >= 0)
           ipinfo_no = ipinfo_no?0:ipinfo_max;
+	else { // AS lookup, origin - routeviews.org
+	  parse_iiarg("-1,0");
+	  asn_open();
+	}
 	break;
 #endif
 
