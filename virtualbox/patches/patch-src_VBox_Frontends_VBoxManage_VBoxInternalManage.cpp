$NetBSD$

--- src/VBox/Frontends/VBoxManage/VBoxInternalManage.cpp.orig	2016-03-04 19:28:59.000000000 +0000
+++ src/VBox/Frontends/VBoxManage/VBoxInternalManage.cpp
@@ -51,7 +51,7 @@
 # include <windows.h>
 # include <winioctl.h>
 #elif defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) \
-    || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+    || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <errno.h>
 # include <sys/ioctl.h>
 # include <sys/types.h>
@@ -73,9 +73,9 @@
 # include <sys/dkio.h>
 # include <sys/vtoc.h>
 #endif /* RT_OS_SOLARIS */
-#ifdef RT_OS_FREEBSD
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/disk.h>
-#endif /* RT_OS_FREEBSD */
+#endif /* RT_OS_FREEBSD || RT_OS_NETBSD */
 
 using namespace com;
 
@@ -1192,12 +1192,12 @@ static RTEXITCODE CmdCreateRawVMDK(int a
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
@@ -1437,7 +1437,7 @@ static RTEXITCODE CmdCreateRawVMDK(int a
         RTMsgError("Failed to get file informtation for raw disk '%s': %Rrc",
                    rawdisk.c_str(), vrc);
     }
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     struct stat DevStat;
     if (!fstat(RTFileToNative(hRawFile), &DevStat))
     {
@@ -1657,13 +1657,13 @@ static RTEXITCODE CmdCreateRawVMDK(int a
 
                 if (fRelative)
                 {
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
                     /* Refer to the correct partition and use offset 0. */
                     char *psz;
                     RTStrAPrintf(&psz,
 #if defined(RT_OS_LINUX)
                                  "%s%u",
-#elif defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
                                  "%ss%u",
 #endif
                                  rawdisk.c_str(),
@@ -2562,4 +2562,3 @@ RTEXITCODE handleInternalCommands(Handle
     /* default: */
     return errorSyntax(USAGE_ALL, "Invalid command '%s'", a->argv[0]);
 }
-
