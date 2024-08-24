$NetBSD$

Part of fix to ("BIND relinquishes privileges too early")

https://gitlab.isc.org/isc-projects/bind9/-/issues/4793
pulled from
https://gitlab.isc.org/isc-projects/bind9/-/merge_requests/9123

Also fix to (compat setresuid() is mis-implemented)
and follow-up fixes to get rid of setresuid() usage:

https://gitlab.isc.org/isc-projects/bind9/-/issues/4862
pulled from
https://gitlab.isc.org/isc-projects/bind9/-/merge_requests/9363

--- bin/named/os.c.orig	2024-07-08 13:09:16.774268226 +0000
+++ bin/named/os.c
@@ -249,115 +249,6 @@ linux_keepcaps(void) {
 
 #endif /* HAVE_LIBCAP */
 
-/*
- * First define compatibility shims if {set,get}res{uid,gid} are not available
- */
-
-#if !HAVE_GETRESGID
-static int
-getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid) {
-	*rgid = -1;
-	*egid = getegid();
-	*sgid = -1;
-
-	return (0);
-}
-#endif /* !HAVE_GETRESGID */
-
-#if !HAVE_SETRESGID
-static int
-setresgid(gid_t rgid, gid_t egid, gid_t sgid) {
-	REQUIRE(rgid == (gid_t)-1);
-	REQUIRE(sgid == (gid_t)-1);
-
-#if HAVE_SETREGID
-	return (setregid(rgid, egid));
-#else  /* HAVE_SETREGID */
-	return (setegid(egid));
-#endif /* HAVE_SETREGID */
-}
-#endif /* !HAVE_SETRESGID */
-
-#if !HAVE_GETRESUID
-static int
-getresuid(uid_t *ruid, uid_t *euid, uid_t *suid) {
-	*ruid = -1;
-	*euid = geteuid();
-	*suid = -1;
-
-	return (0);
-}
-#endif /* !HAVE_GETRESUID */
-
-#if !HAVE_SETRESUID
-static int
-setresuid(uid_t ruid, uid_t euid, uid_t suid) {
-	REQUIRE(ruid == (uid_t)-1);
-	REQUIRE(suid == (uid_t)-1);
-
-#if HAVE_SETREGID
-	return (setregid(ruid, euid));
-#else  /* HAVE_SETREGID */
-	return (setegid(euid));
-#endif /* HAVE_SETREGID */
-}
-#endif /* !HAVE_SETRESUID */
-
-static int
-set_effective_gid(gid_t gid) {
-	gid_t oldgid;
-
-	if (getresgid(&(gid_t){ 0 }, &oldgid, &(gid_t){ 0 }) == -1) {
-		return (-1);
-	}
-
-	if (oldgid == gid) {
-		return (0);
-	}
-
-	if (setresgid(-1, gid, -1) == -1) {
-		return (-1);
-	}
-
-	if (getresgid(&(gid_t){ 0 }, &oldgid, &(gid_t){ 0 }) == -1) {
-		return (-1);
-	}
-
-	if (oldgid != gid) {
-		return (-1);
-	}
-
-	return (0);
-}
-
-static int
-set_effective_uid(uid_t uid) {
-	uid_t olduid;
-
-	if (getresuid(&(uid_t){ 0 }, &olduid, &(uid_t){ 0 }) == -1) {
-		return (-1);
-	}
-
-	if (olduid == uid) {
-		return (0);
-	}
-
-	if (setresuid(-1, uid, -1) == -1) {
-		return (-1);
-	}
-
-	if (getresuid(&(uid_t){ 0 }, &olduid, &(uid_t){ 0 }) == -1) {
-		return (-1);
-	}
-
-	if (olduid != uid) {
-		return (-1);
-	}
-
-	/* Success */
-	return (0);
-}
-
 static void
 setperms(uid_t uid, gid_t gid) {
 	char strbuf[ISC_STRERRORSIZE];
@@ -366,13 +257,13 @@ setperms(uid_t uid, gid_t gid) {
 	 * Drop the gid privilege first, because in some cases the gid privilege
 	 * cannot be dropped after the uid privilege has been dropped.
 	 */
-	if (set_effective_gid(gid) == -1) {
+	if (setegid(gid) == -1) {
 		strerror_r(errno, strbuf, sizeof(strbuf));
 		named_main_earlywarning("unable to set effective gid to %d: %s",
 					gid, strbuf);
 	}
 
-	if (set_effective_uid(uid) == -1) {
+	if (seteuid(uid) == -1) {
 		strerror_r(errno, strbuf, sizeof(strbuf));
 		named_main_earlywarning("unable to set effective uid to %d: %s",
 					uid, strbuf);
@@ -578,12 +469,12 @@ named_os_changeuser(void) {
 
 	done_setuid = true;
 
-	if (setgid(runas_pw->pw_gid) < 0) {
+	if (setgid(runas_pw->pw_gid) == -1) {
 		strerror_r(errno, strbuf, sizeof(strbuf));
 		named_main_earlyfatal("setgid(): %s", strbuf);
 	}
 
-	if (setuid(runas_pw->pw_uid) < 0) {
+	if (setuid(runas_pw->pw_uid) == -1) {
 		strerror_r(errno, strbuf, sizeof(strbuf));
 		named_main_earlyfatal("setuid(): %s", strbuf);
 	}
@@ -603,8 +494,22 @@ named_os_changeuser(void) {
 #endif /* HAVE_LIBCAP */
 }
 
+void
+named_os_tempuser(uid_t uid) {
+	char strbuf[ISC_STRERRORSIZE];
+
+	if (done_setuid) {
+		return;
+	}
+
+	if (getuid() == 0 && seteuid(uid) < 0) {
+		strerror_r(errno, strbuf, sizeof(strbuf));
+		named_main_earlyfatal("setuid(): %s", strbuf);
+	}
+}
+
 uid_t
-ns_os_uid(void) {
+named_os_uid(void) {
 	if (runas_pw == NULL) {
 		return (0);
 	}
