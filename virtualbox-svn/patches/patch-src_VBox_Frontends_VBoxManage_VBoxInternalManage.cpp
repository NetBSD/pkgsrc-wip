$NetBSD$

--- src/VBox/Frontends/VBoxManage/VBoxInternalManage.cpp.orig	2016-07-10 20:58:44.000000000 +0000
+++ src/VBox/Frontends/VBoxManage/VBoxInternalManage.cpp
@@ -52,7 +52,7 @@
 # include <windows.h>
 # include <winioctl.h>
 #elif defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) \
-    || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+    || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <errno.h>
 # include <sys/ioctl.h>
 # include <sys/types.h>
@@ -74,9 +74,9 @@
 # include <sys/dkio.h>
 # include <sys/vtoc.h>
 #endif /* RT_OS_SOLARIS */
-#ifdef RT_OS_FREEBSD
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/disk.h>
-#endif /* RT_OS_FREEBSD */
+#endif /* RT_OS_FREEBSD || RT_OS_NETBSD */
 
 using namespace com;
 
@@ -1193,12 +1193,12 @@ static RTEXITCODE CmdCreateRawVMDK(int a
             i++;
             pszPartitions = argv[i];
         }
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_WINDOWS)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_WINDOWS) || defined(RT_OS_NETBSD)
         else if (strcmp(argv[i], "-relative") == 0)
         {
             fRelative = true;
         }
-#endif /* RT_OS_LINUX || RT_OS_FREEBSD */
+#endif /* RT_OS_LINUX || RT_OS_FREEBSD || RT_OS_NETBSD */
         else
             return errorSyntax(USAGE_CREATERAWVMDK, "Invalid parameter '%s'", argv[i]);
     }
@@ -1438,7 +1438,7 @@ static RTEXITCODE CmdCreateRawVMDK(int a
         RTMsgError("Failed to get file informtation for raw disk '%s': %Rrc",
                    rawdisk.c_str(), vrc);
     }
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     struct stat DevStat;
     if (!fstat(RTFileToNative(hRawFile), &DevStat))
     {
@@ -2580,4 +2580,3 @@ RTEXITCODE handleInternalCommands(Handle
     /* default: */
     return errorSyntax(USAGE_ALL, "Invalid command '%s'", a->argv[0]);
 }
-
