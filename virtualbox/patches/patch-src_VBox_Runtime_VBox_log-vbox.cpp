$NetBSD$

--- src/VBox/Runtime/VBox/log-vbox.cpp.orig	2016-03-04 19:29:47.000000000 +0000
+++ src/VBox/Runtime/VBox/log-vbox.cpp
@@ -137,6 +137,11 @@
 #  include <sys/user.h>
 #  include <stdlib.h>
 #  include <unistd.h>
+# elif defined(RT_OS_NETBSD)
+#  include <sys/param.h>
+#  include <sys/sysctl.h>
+#  include <stdlib.h>
+#  include <unistd.h>
 # elif defined(RT_OS_HAIKU)
 #  include <OS.h>
 # elif defined(RT_OS_SOLARIS)
@@ -422,6 +427,40 @@ RTDECL(PRTLOGGER) RTLogDefaultInit(void)
             }
         }
 
+#  elif defined(RT_OS_NETBSD)
+        /* Retrieve the required length first */
+        int aiName[4];
+        aiName[0] = CTL_KERN;
+        aiName[1] = KERN_PROC_ARGS;
+        aiName[2] = getpid();
+        aiName[3] = KERN_PROC_ARGV;
+        size_t cchArgs = 0;
+        int rcBSD = sysctl(aiName, RT_ELEMENTS(aiName), NULL, &cchArgs, NULL, 0);
+        if (cchArgs > 0)
+        {
+            char *pszArgFileBuf = (char *)RTMemAllocZ(cchArgs + 1 /* Safety */);
+            if (pszArgFileBuf)
+            {
+                /* Retrieve the argument list */
+                rcBSD = sysctl(aiName, RT_ELEMENTS(aiName), pszArgFileBuf, &cchArgs, NULL, 0);
+                if (!rcBSD)
+                {
+                    unsigned    iArg = 0;
+                    size_t      off = 0;
+                    while (off < cchArgs)
+                    {
+                        size_t cchArg = strlen(&pszArgFileBuf[off]);
+                        RTLogLoggerEx(pLogger, 0, ~0U, "Arg[%u]: %s\n", iArg, &pszArgFileBuf[off]);
+
+                        /* advance */
+                        off += cchArg + 1;
+                        iArg++;
+                    }
+                }
+                RTMemFree(pszArgFileBuf);
+            }
+        }
+
 #  elif defined(RT_OS_OS2) || defined(RT_OS_DARWIN)
         /* commandline? */
 #  else
