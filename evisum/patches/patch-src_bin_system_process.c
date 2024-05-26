$NetBSD$

More work needed here by writing OS specific code to list processes

--- src/bin/system/process.c.orig	2024-05-21 03:11:50.326493848 +0000
+++ src/bin/system/process.c
@@ -5,15 +5,17 @@
 #include "ui/gettext.h"
 #define _(STR) gettext(STR)

-#if defined(__MacOS__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+#if defined(__MacOS__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__NetBSD__)
 # include <sys/types.h>
 # include <sys/sysctl.h>
+#if !defined(__NetBSD__)
 # include <sys/user.h>
+#endif
 # include <sys/proc.h>
 # include <libgen.h>
 #endif

-#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__NetBSD__)
 # include <libgen.h>
 # include <unistd.h>
 # include <fcntl.h>
@@ -82,13 +84,23 @@ _states_init(void)
    _states['Z']     = _("zombie");
 #else
    _states[SIDL]    = _("idle");
+#if !defined(__NetBSD__)
    _states[SRUN]    = _("running");
    _states[SSLEEP]  = _("sleeping");
+#else
+   _states[LSRUN]    = _("running");
+   _states[LSSLEEP]  = _("sleeping");
+#endif
    _states[SSTOP]   = _("stopped");
 #if !defined(__MacOS__)
 #if !defined(__OpenBSD__)
+#if !defined(__NetBSD__)
    _states[SWAIT]   = _("wait");
    _states[SLOCK]   = _("lock");
+#else
+   _states[PWAIT]   = _("wait");
+   _states[PLOCK]   = _("lock");
+#endif
    _states[SZOMB]   = _("zombie");
 #endif
 #if defined(__OpenBSD__)
