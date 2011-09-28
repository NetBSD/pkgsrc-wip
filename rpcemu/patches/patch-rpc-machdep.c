$NetBSD: patch-rpc-machdep.c,v 1.1.1.1 2011/09/28 14:55:43 ryo-on Exp $

* Change base directory.

--- rpc-machdep.c.orig	2010-09-19 19:25:37.000000000 +0000
+++ rpc-machdep.c
@@ -28,7 +28,8 @@ rpcemu_get_datadir(void)
 		*p = '\0';
 	}
 
-	return datadir;
+//	return datadir;
+	return "@RPCEMUBASE@";
 }
 
 /**
