$NetBSD$

* NetBSD's sysctl is different than in other BSD's,
* use upower backend

--- src/modules/battery/e_mod_upower.c.orig	2020-07-26 16:39:12.087314600 +0000
+++ src/modules/battery/e_mod_upower.c
@@ -1,7 +1,7 @@
 #include "e.h"
 #include "e_mod_main.h"
 
-#if !(defined(HAVE_EEZE) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__))
+#if !(defined(HAVE_EEZE) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__))
 
 # define BUS "org.freedesktop.UPower"
 # define PATH "/org/freedesktop/UPower"
