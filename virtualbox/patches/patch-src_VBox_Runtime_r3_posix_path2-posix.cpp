$NetBSD$

--- src/VBox/Runtime/r3/posix/path2-posix.cpp.orig	2016-03-04 19:30:03.000000000 +0000
+++ src/VBox/Runtime/r3/posix/path2-posix.cpp
@@ -189,6 +189,7 @@ RTR3DECL(int) RTPathSetTimesEx(const cha
                 }
 #if (defined(RT_OS_DARWIN) && MAC_OS_X_VERSION_MIN_REQUIRED >= 1050) \
  || defined(RT_OS_FREEBSD) \
+ || defined(RT_OS_NETBSD) \
  || defined(RT_OS_LINUX) \
  || defined(RT_OS_OS2) /** @todo who really has lutimes? */
                 else
@@ -287,4 +288,3 @@ RTR3DECL(int) RTPathSetOwnerEx(const cha
              pszPath, pszPath, uid, gid, rc));
     return rc;
 }
-
