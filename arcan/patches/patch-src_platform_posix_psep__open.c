$NetBSD$

Handle NetBSD like OpenBSD
XXX might be the reason this doesn't run!

--- src/platform/posix/psep_open.c.orig	2018-12-10 23:33:36.000000000 +0000
+++ src/platform/posix/psep_open.c
@@ -126,7 +126,7 @@ struct whitelist whitelist[] = {
  * is needed for backlight controls as backlight resolves here */
 	{"/sys/devices/", -1, MODE_PREFIX},
 	{"/dev/tty", -1, MODE_PREFIX | MODE_TTY},
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 	{"/dev/wsmouse", -1, MODE_DEFAULT},
 	{"/dev/wsmouse0", -1, MODE_DEFAULT},
 	{"/dev/wsmouse1", -1, MODE_DEFAULT},
