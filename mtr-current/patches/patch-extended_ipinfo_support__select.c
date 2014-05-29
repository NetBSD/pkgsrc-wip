--- select.c.orig	2014-05-29 12:31:51.000000000 +0300
+++ select.c	2014-05-14 11:15:04.000000000 +0300
@@ -239,19 +239,13 @@
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
+		ii_action(0);
+		break;
+	case ActionAS:
+		ii_action(1);
+		break;
 #endif
-
       case ActionScrollDown:
         display_offset += 5;
 	break;
