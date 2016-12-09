$NetBSD$

The emulation using getpeereid() is completely broken, fix it.

--- compat/getpeercred.c.orig	2016-06-09 06:30:23.000000000 +0000
+++ compat/getpeercred.c
@@ -101,14 +101,10 @@ int getpeercred(int sock, uid_t *uid, gi
   if (uid == NULL)
     uid = &tuid;
   if (gid == NULL)
-    gid = &tguid;
+    gid = &tgid;
   if (getpeereid(sock, uid, gid))
     return -1;
   /* return the data */
-  if (uid != NULL)
-    *uid = cred.uid;
-  if (gid != NULL)
-    *gid = cred.gid;
   if (pid != NULL)
     *pid = -1; /* we return a -1 pid because we have no usable pid */
   return 0;
