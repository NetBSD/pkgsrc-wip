$NetBSD$

Support getsockopt(LOCAL_PEEREID) call.
The emulation using getpeereid() is completely broken.

--- compat/getpeercred.c.orig	2011-10-12 22:55:25.000000000 +0200
+++ compat/getpeercred.c	2013-12-06 12:02:46.000000000 +0100
@@ -75,6 +75,17 @@
   if (gid!=NULL) *gid=cred.cr_gid;
   if (pid!=NULL) *pid=(pid_t)-1;
   return 0;
+#elif defined(LOCAL_PEEREID)
+  socklen_t l;
+  struct unpcbid pcbid;
+  l=(socklen_t)sizeof(struct unpcbid);
+  if (getsockopt(sock,0,LOCAL_PEEREID,&pcbid,&l) < 0)
+    return -1; /* errno already set */
+  /* return the data */
+  if (uid!=NULL) *uid=pcbid.unp_euid;
+  if (gid!=NULL) *gid=pcbid.unp_egid;
+  if (pid!=NULL) *pid=pcbid.unp_pid;
+  return 0;
 #elif defined(HAVE_GETPEERUCRED)
   ucred_t *cred=NULL;
   if (getpeerucred(sock,&cred))
@@ -90,12 +101,10 @@
   uid_t tuid;
   gid_t tgid;
   if (uid==NULL) uid=&tuid;
-  if (gid==NULL) gid=&tguid;
+  if (gid==NULL) gid=&tgid;
   if (getpeereid(sock,uid,gid))
     return -1;
   /* return the data */
-  if (uid!=NULL) *uid=cred.uid;
-  if (gid!=NULL) *gid=cred.gid;
   if (pid!=NULL) *pid=-1; /* we return a -1 pid because we have no usable pid */
   return 0;
 #else
