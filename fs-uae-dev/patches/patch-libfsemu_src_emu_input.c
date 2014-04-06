$NetBSD: patch-libfsemu_src_emu_input.c,v 1.2 2014/04/06 13:33:55 rhialto Exp $

Add support for NetBSD.

--- libfsemu/src/emu/input.c.orig	2014-03-25 19:40:58.000000000 +0000
+++ libfsemu/src/emu/input.c
@@ -510,6 +510,8 @@ static char *joystick_long_config_name(c
     const char *platform = "linux";
 #elif defined(FREEBSD)
     const char *platform = "freebsd";
+#elif defined(NETBSD)
+    const char *platform = "netbsd";
 #elif defined(OPENBSD)
     const char *platform = "openbsd";
 #else
