$NetBSD$

Support NetBSD.

--- gtk2_ardour/ardour_ui.cc.orig	2017-09-15 20:56:22.000000000 +0000
+++ gtk2_ardour/ardour_ui.cc
@@ -1336,7 +1336,7 @@ ARDOUR_UI::check_memory_locking ()
 						  "You can view the memory limit with 'ulimit -l', "
 						  "and it is normally controlled by %2"),
 						PROGRAM_NAME,
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 						X_("/etc/login.conf")
 #else
 						X_(" /etc/security/limits.conf")
