$NetBSD$

--- linux/LinuxProcess.c.orig	2016-02-02 15:30:44.000000000 +0000
+++ linux/LinuxProcess.c
@@ -14,6 +14,7 @@ in the source distribution for its full 
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
+#include <sys/resource.h>
 #include <sys/syscall.h>
 
 /*{
@@ -268,13 +269,21 @@ io_priority = (cpu_nice + 20) / 5. -- Fr
 #define LinuxProcess_effectiveIOPriority(p_) (IOPriority_class(p_->ioPriority) == IOPRIO_CLASS_NONE ? IOPriority_tuple(IOPRIO_CLASS_BE, (p_->super.nice + 20) / 5) : p_->ioPriority)
 
 IOPriority LinuxProcess_updateIOPriority(LinuxProcess* this) {
+#if defined(__NetBSD__)
+   IOPriority ioprio = getpriority(this->super.pid, IOPRIO_WHO_PROCESS);
+#else
    IOPriority ioprio = syscall(SYS_ioprio_get, IOPRIO_WHO_PROCESS, this->super.pid);
+#endif
    this->ioPriority = ioprio;
    return ioprio;
 }
 
 bool LinuxProcess_setIOPriority(LinuxProcess* this, IOPriority ioprio) {
+#if defined(__NetBSD__)
+   setpriority(this->super.pid, IOPRIO_WHO_PROCESS, ioprio);
+#else
    syscall(SYS_ioprio_set, IOPRIO_WHO_PROCESS, this->super.pid, ioprio);
+#endif
    return (LinuxProcess_updateIOPriority(this) == ioprio);
 }
 
