$NetBSD$

Implement for NetBSD.

Upstream approved newer patch by Ralf Nolden support as well (it adds FreeBSD and OpenBSD):
https://codereview.qt-project.org/#/c/162259/5/src/lib/corelib/tools/processutils.cpp

--- src/shared/qbs/src/lib/corelib/tools/processutils.cpp.orig	2016-06-02 14:28:45.000000000 +0000
+++ src/shared/qbs/src/lib/corelib/tools/processutils.cpp
@@ -40,10 +40,14 @@
 #   include "fileinfo.h"
 #   include <unistd.h>
 #   include <cstdio>
-#elif defined(Q_OS_BSD4)
+#elif defined(Q_OS_BSD4) && !defined(Q_OS_NETBSD)
 #   include <libutil.h>
 #   include <sys/types.h>
 #   include <sys/user.h>
+#elif defined(Q_OS_NETBSD)
+#   include <sys/cdefs.h>
+#   include <sys/param.h>
+#   include <sys/sysctl.h>
 #else
 #   error Missing implementation of processNameByPid for this platform.
 #endif
@@ -81,13 +85,24 @@ QString processNameByPid(qint64 pid)
     sprintf(exePath, "/proc/%lld/exe", pid);
     readlink(exePath, buf, sizeof(buf));
     return FileInfo::fileName(QString::fromUtf8(buf));
-#elif defined(Q_OS_BSD4)
+#elif defined(Q_OS_BSD4) && !defined(Q_OS_NETBSD)
     kinfo_proc *proc = kinfo_getproc(pid);
     if (!proc)
         return QString();
     QString name = QString::fromUtf8(proc->ki_comm);
     free(proc);
     return name;
+#elif defined(Q_OS_NETBSD)
+    struct kinfo_proc2 kp;
+    int mib[6] = { CTL_KERN, KERN_PROC2, KERN_PROC_PID, (int)pid, sizeof(struct kinfo_proc2), 1 };
+    size_t len = sizeof(kp);
+    u_int mib_len = sizeof(mib)/sizeof(u_int);
+    if (sysctl(mib, mib_len, &kp, &len, NULL, 0) < 0)
+        return QString();
+    if (kp.p_pid != pid)
+        return QString();
+    QString name = QString::fromUtf8(kp.p_comm);
+    return name;
 #else
     return QString();
 #endif
