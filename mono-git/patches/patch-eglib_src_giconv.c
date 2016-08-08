$NetBSD$

--- eglib/src/giconv.c.orig	2016-05-07 13:14:32.000000000 +0000
+++ eglib/src/giconv.c
@@ -199,8 +199,11 @@ g_iconv (GIConv cd, gchar **inbytes, gsi
 		} else {
 			outleftptr = NULL;
 		}
-		
+#if defined(__NetBSD__)
+		return iconv (cd->cd, (const gchar **)inbytes, inleftptr, outbytes, outleftptr);
+#else
 		return iconv (cd->cd, inbytes, inleftptr, outbytes, outleftptr);
+#endif
 	}
 #endif
 	
