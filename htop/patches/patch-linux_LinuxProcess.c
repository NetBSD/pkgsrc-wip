$NetBSD$

--- linux/LinuxProcess.c.orig	2016-02-02 15:30:44.000000000 +0000
+++ linux/LinuxProcess.c
@@ -268,13 +268,20 @@ io_priority = (cpu_nice + 20) / 5. -- Fr
 #define LinuxProcess_effectiveIOPriority(p_) (IOPriority_class(p_->ioPriority) == IOPRIO_CLASS_NONE ? IOPriority_tuple(IOPRIO_CLASS_BE, (p_->super.nice + 20) / 5) : p_->ioPriority)
 
 IOPriority LinuxProcess_updateIOPriority(LinuxProcess* this) {
-   IOPriority ioprio = syscall(SYS_ioprio_get, IOPRIO_WHO_PROCESS, this->super.pid);
+   IOPriority ioprio = 0;
+// Other OSes masquerading as Linux (NetBSD?) don't have this syscall 
+#ifdef SYS_ioprio_get
+   ioprio = syscall(SYS_ioprio_get, IOPRIO_WHO_PROCESS, this->super.pid);
+#endif
    this->ioPriority = ioprio;
    return ioprio;
 }
 
 bool LinuxProcess_setIOPriority(LinuxProcess* this, IOPriority ioprio) {
+// Other OSes masquerading as Linux (NetBSD?) don't have this syscall
+#ifdef SYS_ioprio_get
    syscall(SYS_ioprio_set, IOPRIO_WHO_PROCESS, this->super.pid, ioprio);
+#endif
    return (LinuxProcess_updateIOPriority(this) == ioprio);
 }
 
