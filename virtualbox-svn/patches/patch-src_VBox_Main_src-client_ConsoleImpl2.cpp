$NetBSD$

--- src/VBox/Main/src-client/ConsoleImpl2.cpp.orig	2016-07-10 20:39:31.000000000 +0000
+++ src/VBox/Main/src-client/ConsoleImpl2.cpp
@@ -103,7 +103,7 @@
 #  include <linux/types.h>
 #  include <linux/if.h>
 #  include <linux/wireless.h>
-# elif defined(RT_OS_FREEBSD)
+# elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 #  include <unistd.h>
 #  include <sys/types.h>
 #  include <sys/ioctl.h>
@@ -4862,7 +4862,7 @@ int Console::i_configNetwork(const char 
 
             case NetworkAttachmentType_Bridged:
             {
-#if (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)) && !defined(VBOX_WITH_NETFLT)
+#if (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)) && !defined(VBOX_WITH_NETFLT)
                 hrc = i_attachToTapInterface(aNetworkAdapter);
                 if (FAILED(hrc))
                 {
@@ -5057,8 +5057,8 @@ int Console::i_configNetwork(const char 
                 const char *pszTrunk = szTrunkName;
                 /* we're not releasing the INetCfg stuff here since we use it later to figure out whether it is wireless */
 
-# elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
-#  if defined(RT_OS_FREEBSD)
+# elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
+#  if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
                 /*
                  * If we bridge to a tap interface open it the `old' direct way.
                  * This works and performs better than bridging a physical
@@ -5168,7 +5168,7 @@ int Console::i_configNetwork(const char 
                 }
                 else
                     Log(("Failed to open wireless socket\n"));
-# elif defined(RT_OS_FREEBSD)
+# elif defined(RT_OS_FREEBSD)  || defined(RT_OS_NETBSD)
                 int iSock = socket(AF_INET, SOCK_DGRAM, 0);
                 if (iSock >= 0)
                 {
@@ -5286,7 +5286,7 @@ int Console::i_configNetwork(const char 
             /* NOTHING TO DO HERE */
 #elif defined(RT_OS_LINUX)
 /// @todo aleksey: is there anything to be done here?
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 /** @todo FreeBSD: Check out this later (HIF networking). */
 #else
 # error "Port me"
