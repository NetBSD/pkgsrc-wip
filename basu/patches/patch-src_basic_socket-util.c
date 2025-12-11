$NetBSD$

--- src/basic/socket-util.c.orig	2022-12-16 10:13:02.000000000 +0000
+++ src/basic/socket-util.c
@@ -63,8 +63,13 @@ int getpeercred(int fd, struct ucred *uc
                 return -EIO;
 
         /* Check if the data is actually useful and not suppressed due to namespacing issues */
+#ifdef __NetBSD__
+        if (!pid_is_valid(u.unp_pid))
+                return -ENODATA;
+#else
         if (!pid_is_valid(u.pid))
                 return -ENODATA;
+#endif
 
         /* Note that we don't check UID/GID here, as namespace translation works differently there: instead of
          * receiving in "invalid" user/group we get the overflow UID/GID. */
@@ -75,7 +80,7 @@ int getpeercred(int fd, struct ucred *uc
 }
 
 int getpeersec(int fd, char **ret) {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
         return -EOPNOTSUPP;
 #else
         _cleanup_free_ char *s = NULL;
