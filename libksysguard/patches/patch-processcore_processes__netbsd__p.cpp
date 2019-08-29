$NetBSD: patch-libs_ksysguard_processcore_processes__netbsd__p.cpp,v 1.1 2013/01/17 16:05:53 joerg Exp $

No more sys/user.h in netbsd.

--- processcore/processes_netbsd_p.cpp.orig	2019-07-30 10:27:02.000000000 +0000
+++ processcore/processes_netbsd_p.cpp
@@ -29,7 +29,7 @@
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#include <sys/user.h>
+#include <sys/resource.h>
 #include <sys/stat.h>
 #include <signal.h>
 #include <unistd.h>
@@ -102,7 +102,7 @@ void ProcessesLocal::Private::readProcSt
     process->setEgid(p->p_gid);
     process->setTracerpid(-1);
 
-    process->setName(QString(p->p_comm ? p->p_comm : "????"));
+    process->setName(QString::fromUtf8(p->p_comm ? p->p_comm : "????"));
 }
 
 void ProcessesLocal::Private::readProcStat(struct kinfo_proc2 *p, Process *ps)
@@ -167,11 +167,11 @@ bool ProcessesLocal::Private::readProcCm
     if ((argv = kvm_getargv2(kd, p, 256)) == NULL)
         return false;
 
-    QString command = QString("");
+    QString command = QString::fromUtf8("");
 
     while (*argv) {
-        command += *argv;
-	command += " ";
+        command += QString::fromUtf8(*argv);
+	command += QString::fromUtf8(" ");
 	argv++;
     }
     process->setCommand(command.trimmed());
