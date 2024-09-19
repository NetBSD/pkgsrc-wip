$NetBSD$

- Fix NetBSD support.

--- src/netbsd.h.orig	2020-07-27 12:01:52.000000000 +0000
+++ src/netbsd.h
@@ -15,11 +15,13 @@
 #include <sys/envsys.h>
 #include <sys/sched.h>
 #include <sys/socket.h>
+#include <sys/statvfs.h>
 #include <sys/swap.h>
 #include <sys/sysctl.h>
 #include <sys/time.h>
 #include <sys/types.h>
-#include <sys/user.h>
+
+#include <prop/proplib.h>
 
 #include <net/if.h>
 
