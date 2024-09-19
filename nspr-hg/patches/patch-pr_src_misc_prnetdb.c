$NetBSD: patch-pr_src_misc_prnetdb.c,v 1.2 2014/09/28 14:33:59 thomasklausner Exp $

chunk 1: improve NetBSD support.
chunk 2: add Dragonfly support.
chunk 3: add Dragonfly support.
chunk 4: improve NetBSD support.
chunk 5: improve NetBSD support.

--- pr/src/misc/prnetdb.c.orig	2014-09-28 14:07:42.000000000 +0000
+++ pr/src/misc/prnetdb.c
@@ -73,7 +73,7 @@ PRLock *_pr_dnsLock = NULL;
         || defined(AIX4_3_PLUS) || (defined(AIX) && defined(_THREAD_SAFE)) \
 	|| (defined(HPUX10_10) && defined(_REENTRANT)) \
         || (defined(HPUX10_20) && defined(_REENTRANT)) \
-        || defined(OPENBSD)
+        || defined(OPENBSD) || defined(NETBSD)
 #define _PR_HAVE_GETPROTO_R
 #define _PR_HAVE_GETPROTO_R_INT
 #endif
@@ -83,6 +83,11 @@ PRLock *_pr_dnsLock = NULL;
 #define _PR_HAVE_5_ARG_GETPROTO_R
 #endif
 
+#if __DragonFly_version >= 200202
+#define _PR_HAVE_GETPROTO_R
+#define _PR_HAVE_5_ARG_GETPROTO_R
+#endif
+
 /* BeOS has glibc but not the glibc-style getprotobyxxx_r functions. */
 #if (defined(__GLIBC__) && __GLIBC__ >= 2 && !defined(XP_BEOS))
 #define _PR_HAVE_GETPROTO_R
@@ -300,7 +305,7 @@ _pr_QueryNetIfs(void)
 }
 
 #elif (defined(DARWIN) && defined(HAVE_GETIFADDRS)) || defined(FREEBSD) \
-    || defined(NETBSD) || defined(OPENBSD)
+    || defined(NETBSD) || defined(OPENBSD) || defined(DRAGONFLY)
 
 /*
  * Use the BSD getifaddrs function.
@@ -2044,6 +2049,11 @@ PR_IMPLEMENT(PRAddrInfo *) PR_GetAddrInf
          */
         hints.ai_socktype = SOCK_STREAM;
 
+/* NetBSD >= 2.99.9 has a thread-safe resolver */
+#if defined(__NetBSD_Version__) && __NetBSD_Version__ < 299000900
+        LOCK_DNS();
+#endif
+
         rv = GETADDRINFO(hostname, NULL, &hints, &res);
 #ifdef AI_ADDRCONFIG
         if (rv == EAI_BADFLAGS && (hints.ai_flags & AI_ADDRCONFIG)) {
@@ -2051,6 +2061,11 @@ PR_IMPLEMENT(PRAddrInfo *) PR_GetAddrInf
             rv = GETADDRINFO(hostname, NULL, &hints, &res);
         }
 #endif
+
+#if defined(__NetBSD_Version__) && __NetBSD_Version__ < 299000900
+        UNLOCK_DNS();
+#endif
+
         if (rv == 0)
             return (PRAddrInfo *) res;
 
