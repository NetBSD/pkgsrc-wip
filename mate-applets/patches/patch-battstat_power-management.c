$NetBSD: patch-battstat_power-management.c,v 1.1 2015/01/01 08:27:02 obache Exp $

* NetBSD support

--- battstat/power-management.c.orig	2014-04-19 21:25:24.000000000 +0000
+++ battstat/power-management.c
@@ -250,7 +250,11 @@ apm_readinfo (BatteryStatus *status)
   /* Code for OpenBSD by Joe Ammond <jra@twinight.org>. Using the same
      procedure as for FreeBSD.
   */
+#if defined(__NetBSD__)
+  struct apm_power_info apminfo;
+#else /* __OpenBSD__ */
   struct apm_info apminfo;
+#endif
   int fd;
 
 #if defined(__NetBSD__)
