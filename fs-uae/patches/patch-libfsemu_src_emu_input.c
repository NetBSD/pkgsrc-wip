$NetBSD: patch-libfsemu_src_emu_input.c,v 1.1 2013/10/25 22:02:17 rhialto Exp $

Add support for NetBSD.

--- libfsemu/src/emu/input.c.orig	2013-06-25 19:21:16.000000000 +0000
+++ libfsemu/src/emu/input.c
@@ -480,6 +480,8 @@ static char *joystick_long_config_name(c
     const char *platform = "linux";
 #elif defined(FREEBSD)
     const char *platform = "freebsd";
+#elif defined(NETBSD)
+    const char *platform = "netbsd";
 #elif defined(OPENBSD)
     const char *platform = "openbsd";
 #else
