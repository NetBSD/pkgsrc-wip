--- select.c.orig	2014-04-20 21:28:39.000000000 +0300
+++ select.c	2014-04-22 20:44:05.000000000 +0300
@@ -239,17 +239,27 @@
 	}
 	break;
 #ifdef IPINFO
-      case ActionII:
-	if (ipinfo_no >= 0) {
-	  ipinfo_no++;
-          if (ipinfo_no > ipinfo_max)
-            ipinfo_no = 0;
-	}
-	break;
-      case ActionAS:
-	if (ipinfo_no >= 0)
-          ipinfo_no = ipinfo_no?0:ipinfo_max;
-	break;
+	case ActionII:
+		if (ipinfo_no >= 0) {
+			int i;
+			for (i = 0; (i <= II_ITEM_MAX) && (ipinfo_nos[i] >= 0); i++) {
+				ipinfo_nos[i]++;
+				if (ipinfo_nos[i] > ipinfo_max)
+					ipinfo_nos[i] = 0;
+			}
+		} else {
+			ii_parse("");	// origin: origin.asn.cymru.com
+			asn_open();
+		}
+		break;
+	case ActionAS:
+		if (ipinfo_no >= 0)
+			ipinfo_no = ipinfo_no?0:ipinfo_max;
+		else {
+			ii_parse("2");	// origin: asn.routeviews.org
+			asn_open();
+		}
+		break;
 #endif
 
       case ActionScrollDown:
