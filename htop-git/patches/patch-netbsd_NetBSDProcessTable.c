$NetBSD$

Fix build due to upstream changes.

https://github.com/htop-dev/htop/pull/1360

--- netbsd/NetBSDProcessTable.c.orig	2023-12-29 15:52:13.000000000 +0000
+++ netbsd/NetBSDProcessTable.c
@@ -151,7 +151,7 @@ static double getpcpu(const NetBSDMachin
 }
 
 static void NetBSDProcessTable_scanProcs(NetBSDProcessTable* this) {
-   const Machine* host = this->super.host;
+   const Machine* host = this->super.super.host;
    const NetBSDMachine* nhost = (const NetBSDMachine*) host;
    const Settings* settings = host->settings;
    bool hideKernelThreads = settings->hideKernelThreads;
@@ -182,7 +182,7 @@ static void NetBSDProcessTable_scanProcs
          ProcessTable_add(&this->super, proc);
 
          proc->tty_nr = kproc->p_tdev;
-         const char* name = ((dev_t)kproc->p_tdev != KERN_PROC_TTY_NODEV) ? devname(kproc->p_tdev, S_IFCHR) : NULL;
+         const char* name = devname(kproc->p_tdev, S_IFCHR);
          if (!name) {
             free(proc->tty_name);
             proc->tty_name = NULL;
