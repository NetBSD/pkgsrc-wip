$NetBSD$

--- egg/egg-unix-credentials.c.orig	2014-09-23 07:45:13.000000000 +0000
+++ egg/egg-unix-credentials.c
@@ -56,14 +56,8 @@ egg_unix_credentials_read (int sock, pid
 	char buf;
 	int ret;
 	
-#if defined(HAVE_CMSGCRED) || defined(LOCAL_CREDS)
-	/* Prefer CMSGCRED over LOCAL_CREDS because the former provides the
-	 * remote PID. */
 #if defined(HAVE_CMSGCRED)
 	struct cmsgcred *cred;
-#else /* defined(LOCAL_CREDS) */
-	struct sockcred *cred;
-#endif
 	union {
 		struct cmsghdr hdr;
 		char cred[CMSG_SPACE (sizeof *cred)];
@@ -84,7 +78,7 @@ egg_unix_credentials_read (int sock, pid
 	msg.msg_iov = &iov;
 	msg.msg_iovlen = 1;
 	
-#if defined(HAVE_CMSGCRED) || defined(LOCAL_CREDS)
+#if defined(HAVE_CMSGCRED)
 	memset (&cmsg, 0, sizeof (cmsg));
 	msg.msg_control = (caddr_t) &cmsg;
 	msg.msg_controllen = CMSG_SPACE(sizeof *cred);
@@ -108,7 +102,7 @@ egg_unix_credentials_read (int sock, pid
 		return -1;
 	}
 
-#if defined(HAVE_CMSGCRED) || defined(LOCAL_CREDS)
+#if defined(HAVE_CMSGCRED)
 	if (cmsg.hdr.cmsg_len < CMSG_LEN (sizeof *cred) ||
 	    cmsg.hdr.cmsg_type != SCM_CREDS) {
 		fprintf (stderr, "message from recvmsg() was not SCM_CREDS\n");
@@ -138,11 +132,6 @@ egg_unix_credentials_read (int sock, pid
 		cred = (struct cmsgcred *) CMSG_DATA (&cmsg.hdr);
 		*pid = cred->cmcred_pid;
 		*uid = cred->cmcred_euid;
-#elif defined(LOCAL_CREDS)
-		cred = (struct sockcred *) CMSG_DATA (&cmsg.hdr);
-		*pid = 0;
-		*uid = cred->sc_euid;
-		set_local_creds(sock, 0);
 #elif defined(HAVE_GETPEEREID) /* OpenBSD */
 		uid_t euid;
 		gid_t egid;
@@ -179,7 +168,7 @@ egg_unix_credentials_write (int socket)
 {
 	char buf;
 	int bytes_written;
-#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+#if defined(HAVE_CMSGCRED) && defined(__FreeBSD__)
 	union {
 		struct cmsghdr hdr;
 		char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
@@ -190,7 +179,7 @@ egg_unix_credentials_write (int socket)
 
 	buf = 0;
 
-#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+#if defined(HAVE_CMSGCRED) && defined(__FreeBSD__)
 	iov.iov_base = &buf;
 	iov.iov_len = 1;
 
@@ -208,7 +197,7 @@ egg_unix_credentials_write (int socket)
 
 again:
 
-#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+#if defined(HAVE_CMSGCRED) && defined(__FreeBSD__)
 	bytes_written = sendmsg (socket, &msg, 0);
 #else
 	bytes_written = write (socket, &buf, 1);
@@ -227,13 +216,6 @@ int
 egg_unix_credentials_setup (int sock)
 {
 	int retval = 0;
-#if defined(LOCAL_CREDS) && !defined(HAVE_CMSGCRED)
-	int val = 1;
-	if (setsockopt (sock, 0, LOCAL_CREDS, &val, sizeof (val)) < 0) {
-		fprintf (stderr, "unable to set LOCAL_CREDS socket option on fd %d\n", fd);
-		retval = -1;
-	}
-#endif
 	return retval;
 }
 
