$NetBSD$

--- src/VBox/Additions/common/VBoxService/VBoxServiceVMInfo.cpp.orig	2016-03-04 19:23:11.000000000 +0000
+++ src/VBox/Additions/common/VBoxService/VBoxServiceVMInfo.cpp
@@ -71,7 +71,7 @@
 # include <net/if.h>
 # include <pwd.h> /* getpwuid */
 # include <unistd.h>
-# if !defined(RT_OS_OS2) && !defined(RT_OS_FREEBSD) && !defined(RT_OS_HAIKU)
+# if !defined(RT_OS_OS2) && !defined(RT_OS_FREEBSD) && !defined(RT_OS_HAIKU) 
 #  include <utmpx.h> /* @todo FreeBSD 9 should have this. */
 # endif
 # ifdef RT_OS_OS2
@@ -81,7 +81,7 @@
 #  include <sys/sockio.h>
 #  include <net/if_arp.h>
 # endif
-# if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+# if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 #  include <ifaddrs.h> /* getifaddrs, freeifaddrs */
 #  include <net/if_dl.h> /* LLADDR */
 #  include <netdb.h> /* getnameinfo */
@@ -568,6 +568,10 @@ static int vgsvcVMInfoWriteUsers(void)
      *                 block below (?). */
     rc = VERR_NOT_IMPLEMENTED;
 
+#elif defined(RT_OS_NETBSD)
+    /** @todo NetBSD: */
+    rc = VERR_NOT_IMPLEMENTED;
+
 #elif defined(RT_OS_HAIKU)
     /** @todo Haiku: Port logged on user info retrieval. */
     rc = VERR_NOT_IMPLEMENTED;
@@ -874,7 +878,7 @@ static int vgsvcVMInfoWriteUsers(void)
     RTMemFree(papszUsers);
 
     endutxent(); /* Close utmpx file. */
-#endif /* !RT_OS_WINDOWS && !RT_OS_FREEBSD && !RT_OS_HAIKU && !RT_OS_OS2 */
+#endif /* !RT_OS_WINDOWS && !RT_OS_FREEBSD && !RT_OS_HAIKU && !RT_OS_OS2 && !RT_OS_NETBSD */
 
     Assert(RT_FAILURE(rc) || cUsersInList == 0 || (pszUserList && *pszUserList));
 
@@ -1090,7 +1094,7 @@ static int vgsvcVMInfoWriteNetwork(void)
     /** @todo Haiku: implement network info. retreival */
     return VERR_NOT_IMPLEMENTED;
 
-#elif defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     struct ifaddrs *pIfHead = NULL;
 
     /* Get all available interfaces */
@@ -1162,7 +1166,7 @@ static int vgsvcVMInfoWriteNetwork(void)
     /* Free allocated resources. */
     freeifaddrs(pIfHead);
 
-#else /* !RT_OS_WINDOWS && !RT_OS_FREEBSD */
+#else /* !RT_OS_WINDOWS && !RT_OS_FREEBSD && !RT_OS_NETBSD */
     /*
      * Use SIOCGIFCONF to get a list of interface/protocol configurations.
      *
@@ -1685,4 +1689,3 @@ VBOXSERVICE g_VMInfo =
     vbsvcVMInfoStop,
     vbsvcVMInfoTerm
 };
-
