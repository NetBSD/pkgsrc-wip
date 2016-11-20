$NetBSD$
Missing BSD detection causes undefined USER_AGENT_OS, adapted from OpenBSDs port

--- daemon/http-tx-mgr.c.orig	2016-10-24 00:42:15.434281419 +0000
+++ daemon/http-tx-mgr.c	2016-10-24 00:42:53.206206478 +0000
@@ -60,6 +60,10 @@
 #define USER_AGENT_OS "Linux"
 #endif
 
+#if defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__ || defined __DragonFly__
+#define USER_AGENT_OS "BSD"
+#endif
+
 struct _Connection {
     CURL *curl;
     gint64 ctime;               /* Used to clean up unused connection. */
