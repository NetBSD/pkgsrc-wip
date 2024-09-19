$NetBSD$

--- coregrind/m_scheduler/scheduler.c.orig	2018-09-30 04:41:00.000000000 +0000
+++ coregrind/m_scheduler/scheduler.c
@@ -500,7 +500,7 @@ void VG_(vg_yield)(void)
    /* 
       Tell the kernel we're yielding.
     */
-#  if defined(VGO_linux) || defined(VGO_darwin)
+#  if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    VG_(do_syscall0)(__NR_sched_yield);
 #  elif defined(VGO_solaris)
    VG_(do_syscall0)(__NR_yield);
@@ -539,7 +539,7 @@ static void os_state_clear(ThreadState *
    tst->os_state.lwpid       = 0;
    tst->os_state.threadgroup = 0;
    tst->os_state.stk_id = NULL_STK_ID;
-#  if defined(VGO_linux)
+#  if defined(VGO_linux) || defined(VGO_netbsd)
    /* no other fields to clear */
 #  elif defined(VGO_darwin)
    tst->os_state.post_mach_trap_fn = NULL;
