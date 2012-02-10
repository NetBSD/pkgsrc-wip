$NetBSD: patch-src_daemon.c,v 1.1 2012/02/10 14:13:36 bartoszkuzma Exp $

--- src/daemon.c.orig	2010-06-16 14:12:42.000000000 +0000
+++ src/daemon.c
@@ -265,7 +265,8 @@ void debug_privileges(char *msg)
 {
 	uid_t r=-1, e=-1, s=-1;
 
-	getresuid(&r, &e, &s);
+	r = getuid();
+	e = geteuid();
 	log_action(LOG_DEBUG, "%s: real=%d, effective=%d, saved=%d", msg, r, e, s);
 }
 
@@ -273,7 +274,7 @@ void debug_privileges(char *msg)
 int drop_privileges()
 {
 	int _err;
-	uid_t r, e, s;
+	uid_t r, e, s = -1;
 
 //	debug_privileges("drop_privileges().pre");
 	if (daemon_uid == -1 && getuid() == 0) {
@@ -287,14 +288,16 @@ int drop_privileges()
 	/* become root temporarily just to gain permissions to change real&effective uid */
 	if (seteuid(0) == -1) {
 		_err = errno;
-		getresuid(&r, &e, &s);
+		r = getuid();
+		e = geteuid();
 		log_action(LOG_CRIT, "%s.seteuid(%d; real=%d, effective=%d, saved=%d): %s", __FUNCTION__, 0, r, e, s, strerror(_err));
 		return -1;
 	}
 
 	if (setuid(daemon_uid) == -1) {
 		_err = errno;
-		getresuid(&r, &e, &s);
+		r = getuid();
+		e = geteuid();
 		log_action(LOG_CRIT, "%s.setuid(%d; real=%d, effective=%d, saved=%d): %s", __FUNCTION__, 0, r, e, s, strerror(_err));
 		return -1;
 	}
@@ -306,14 +309,15 @@ int drop_privileges()
 int elevate_privileges()
 {
 	int _err;
-	uid_t r, e, s;
+	uid_t r, e, s = -1;
 
 	if (daemon_uid == -1)
 		return 0;
 
 	if (seteuid(0) < 0) {
 		_err = errno;
-		getresuid(&r, &e, &s);
+		r = getuid();
+		e = geteuid();
 		log_action(LOG_CRIT, "%s.seteuid(%d; real=%d, effective=%d, saved=%d): %s", __FUNCTION__, 0, r, e, s, strerror(_err));
 		return -1;
 	}
@@ -323,14 +327,15 @@ int elevate_privileges()
 int lower_privileges()
 {
 	int _err;
-	uid_t r, e, s;
+	uid_t r, e, s = -1;
 
 	if (daemon_uid == -1)
 		return 0;
 
 	if (seteuid(daemon_uid) < 0) {
 		_err = errno;
-		getresuid(&r, &e, &s);
+		r = getuid();
+		e = geteuid();
 		log_action(LOG_CRIT, "%s.seteuid(%d; real=%d, effective=%d, saved=%d): %s", __FUNCTION__, daemon_uid, r, e, s, strerror(_err));
 		return -1;
 	}
