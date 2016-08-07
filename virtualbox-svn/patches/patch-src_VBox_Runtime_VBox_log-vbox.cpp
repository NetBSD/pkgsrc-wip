$NetBSD$

--- src/VBox/Runtime/VBox/log-vbox.cpp.orig	2016-08-05 16:53:56.000000000 +0000
+++ src/VBox/Runtime/VBox/log-vbox.cpp
@@ -131,10 +131,12 @@
 #  include <iprt/win/windows.h>
 # elif defined(RT_OS_LINUX)
 #  include <unistd.h>
-# elif defined(RT_OS_FREEBSD)
+# elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 #  include <sys/param.h>
 #  include <sys/sysctl.h>
-#  include <sys/user.h>
+#  if defined(RT_OS_FREEBSD)
+#    include <sys/user.h>
+#  endif
 #  include <stdlib.h>
 #  include <unistd.h>
 # elif defined(RT_OS_HAIKU)
@@ -647,13 +649,20 @@ RTDECL(PRTLOGGER) RTLogDefaultInit(void)
             RTLogLoggerEx(pLogger, 0, ~0U, "Commandline: %.64s\n", info.args);
         }
 
-#  elif defined(RT_OS_FREEBSD)
+#  elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         /* Retrieve the required length first */
         int aiName[4];
+#  if defined(RT_OS_FREEBSD)
         aiName[0] = CTL_KERN;
         aiName[1] = KERN_PROC;
         aiName[2] = KERN_PROC_ARGS;     /* Introduced in FreeBSD 4.0 */
         aiName[3] = getpid();
+#  elif defined(RT_OS_NETBSD)
+        aiName[0] = CTL_KERN;
+        aiName[1] = KERN_PROC_ARGS;
+        aiName[2] = getpid();
+        aiName[3] = KERN_PROC_ARGV;
+#  endif
         size_t cchArgs = 0;
         int rcBSD = sysctl(aiName, RT_ELEMENTS(aiName), NULL, &cchArgs, NULL, 0);
         if (cchArgs > 0)
