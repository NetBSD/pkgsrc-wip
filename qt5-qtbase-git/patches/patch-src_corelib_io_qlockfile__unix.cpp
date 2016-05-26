$NetBSD$

--- src/corelib/io/qlockfile_unix.cpp.orig	2016-05-20 00:28:32.000000000 +0000
+++ src/corelib/io/qlockfile_unix.cpp
@@ -59,14 +59,12 @@
 #   include <unistd.h>
 #   include <cstdio>
 #elif defined(Q_OS_BSD4) && !defined(Q_OS_IOS)
+# if !defined(Q_OS_NETBSD)
 #   include <sys/user.h>
-# if defined(__GLIBC__) && defined(__FreeBSD_kernel__)
+# endif
 #   include <sys/cdefs.h>
 #   include <sys/param.h>
 #   include <sys/sysctl.h>
-# else
-#   include <libutil.h>
-# endif
 #endif
 
 QT_BEGIN_NAMESPACE
@@ -269,30 +267,45 @@ QString QLockFilePrivate::processNameByP
     buf[len] = 0;
     return QFileInfo(QFile::decodeName(buf)).fileName();
 #elif defined(Q_OS_BSD4) && !defined(Q_OS_IOS)
-# if defined(__GLIBC__) && defined(__FreeBSD_kernel__)
-    int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, pid };
+# if defined(Q_OS_NETBSD)
+    struct kinfo_proc2 kp, *proc = &kp;
+    int mib[6] = { CTL_KERN, KERN_PROC2, KERN_PROC_PID, (int)pid, sizeof(struct kinfo_proc2), 1 };
     size_t len = 0;
-    if (sysctl(mib, 4, NULL, &len, NULL, 0) < 0)
+    if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0)
+        return QString();
+# elif defined(Q_OS_OPENBSD)
+    struct kinfo_proc kp, *proc = &kp;
+    int mib[6] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, (int)pid, sizeof(struct kinfo_proc), 1 };
+    size_t len = 0;
+    if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0)
         return QString();
-    kinfo_proc *proc = static_cast<kinfo_proc *>(malloc(len));
 # else
-    kinfo_proc *proc = kinfo_getproc(pid);
+    struct kinfo_proc kp, *proc = &kp;
+    int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, (int)pid };
+    size_t len = 0;
+    if (sysctl(mib, 4, NULL, &len, NULL, 0) < 0)
+        return QString();
 # endif
+
     if (!proc)
         return QString();
-# if defined(__GLIBC__) && defined(__FreeBSD_kernel__)
-    if (sysctl(mib, 4, proc, &len, NULL, 0) < 0) {
-        free(proc);
+
+# if defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD)
+    if (sysctl(mib, 6, proc, &len, NULL, 0) < 0)
         return QString();
-    }
-    if (proc->ki_pid != pid) {
-        free(proc);
+    if (proc->p_pid != pid)
+        return QString();
+    QString name = QFile::decodeName(proc->p_comm);
+    return name;
+# else
+    if (sysctl(mib, 4, proc, &len, NULL, 0) < 0)
+        return QString();
+    if (proc->ki_pid != pid)
         return QString();
-    }
-# endif
     QString name = QFile::decodeName(proc->ki_comm);
-    free(proc);
     return name;
+# endif
+
 #else
     Q_UNUSED(pid);
     return QString();
