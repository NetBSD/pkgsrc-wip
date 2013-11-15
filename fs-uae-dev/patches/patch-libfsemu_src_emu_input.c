$NetBSD: patch-libfsemu_src_emu_input.c,v 1.1 2013/11/15 12:26:23 rhialto Exp $

Add support for NetBSD.

--- libfsemu/src/emu/input.c.orig	2013-10-23 17:57:59.000000000 +0000
+++ libfsemu/src/emu/input.c
@@ -509,6 +509,8 @@ static char *joystick_long_config_name(c
     const char *platform = "linux";
 #elif defined(FREEBSD)
     const char *platform = "freebsd";
+#elif defined(NETBSD)
+    const char *platform = "netbsd";
 #elif defined(OPENBSD)
     const char *platform = "openbsd";
 #else
