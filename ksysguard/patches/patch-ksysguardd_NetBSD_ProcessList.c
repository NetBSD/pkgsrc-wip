$NetBSD: patch-ksysguard_ksysguardd_NetBSD_ProcessList.c,v 1.1 2013/01/17 16:05:53 joerg Exp $

No more sys/user.h on netbsd.

--- ksysguardd/NetBSD/ProcessList.c.orig	2018-03-27 11:15:15.000000000 +0000
+++ ksysguardd/NetBSD/ProcessList.c
@@ -34,7 +34,7 @@
 #include <sys/sysctl.h>
 #include <sys/time.h>
 #include <sys/types.h>
-#include <sys/user.h>
+#include <sys/resource.h>
 #include <unistd.h>
 #include <signal.h>
 
