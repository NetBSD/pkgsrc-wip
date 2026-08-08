$NetBSD$

--- ext/pty/pty.c.orig	2008-04-15 03:35:55.000000000 +0000
+++ ext/pty/pty.c
@@ -369,7 +369,7 @@ get_device_once(master, slave, SlaveName, fail)
 	}
 	close(i);
     }
-    if (!fail) rb_raise(rb_eRuntimeError, "can't get Master/Slave device");
+    if (fail) rb_raise(rb_eRuntimeError, "can't get Master/Slave device");
     return -1;
 #else
     char **p;
