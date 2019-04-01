$NetBSD$

--- coregrind/m_syswrap/syswrap-generic.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_syswrap/syswrap-generic.c
@@ -30,7 +30,7 @@
    The GNU General Public License is contained in the file COPYING.
 */
 
-#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 #include "pub_core_basics.h"
 #include "pub_core_vki.h"
@@ -67,6 +67,9 @@
 
 #include "config.h"
 
+#ifndef __NR_ipc
+#define __NR_ipc -1
+#endif
 
 void ML_(guess_and_register_stack) (Addr sp, ThreadState* tst)
 {
@@ -270,7 +273,7 @@ ML_(notify_core_and_tool_of_mprotect) ( 
 
 
 
-#if HAVE_MREMAP
+#if HAVE_MREMAP && 0
 /* Expand (or shrink) an existing mapping, potentially moving it at
    the same time (controlled by the MREMAP_MAYMOVE flag).  Nightmare.
 */
@@ -926,7 +929,7 @@ void VG_(init_preopened_fds)(void)
   out:
    VG_(close)(sr_Res(f));
 
-#elif defined(VGO_darwin)
+#elif defined(VGO_darwin) || defined(VGO_netbsd)
    init_preopened_fds_without_proc_self_fd();
 
 #elif defined(VGO_solaris)
@@ -1131,6 +1134,11 @@ void pre_mem_read_sockaddr ( ThreadId ti
    VG_(sprintf) ( outmsg, description, "sa_family" );
    PRE_MEM_READ( outmsg, (Addr) &sa->sa_family, sizeof(vki_sa_family_t));
 
+#if defined(VGO_netbsd)
+   VG_(sprintf) ( outmsg, description, ".sa_len" );
+   PRE_MEM_READ( outmsg, (Addr) &sa->sa_len, sizeof(char));
+#endif
+
    /* Don't do any extra checking if we cannot determine the sa_family. */
    if (! ML_(safe_to_deref) (&sa->sa_family, sizeof(vki_sa_family_t)))
       return;
@@ -1818,6 +1826,9 @@ UInt get_sem_count( Int semid )
 
    return buf.sem_nsems;
 
+#  elif defined(VGO_netbsd)
+   return 0;
+
 #  else
    struct vki_semid_ds buf;
    arg.buf = &buf;
@@ -1844,8 +1855,10 @@ ML_(generic_PRE_sys_semctl) ( ThreadId t
    case VKI_SEM_INFO:
    case VKI_IPC_INFO|VKI_IPC_64:
    case VKI_SEM_INFO|VKI_IPC_64:
+#if !defined(VGO_netbsd)
       PRE_MEM_WRITE( "semctl(IPC_INFO, arg.buf)",
                      (Addr)arg.buf, sizeof(struct vki_seminfo) );
+#endif
       break;
 #endif
 
@@ -1923,7 +1936,9 @@ ML_(generic_POST_sys_semctl) ( ThreadId 
    case VKI_SEM_INFO:
    case VKI_IPC_INFO|VKI_IPC_64:
    case VKI_SEM_INFO|VKI_IPC_64:
+#if !defined(VGO_netbsd)
       POST_MEM_WRITE( (Addr)arg.buf, sizeof(struct vki_seminfo) );
+#endif
       break;
 #endif
 
@@ -2641,7 +2656,7 @@ PRE(sys_madvise)
                  unsigned long, start, vki_size_t, length, int, advice);
 }
 
-#if HAVE_MREMAP
+#if HAVE_MREMAP && 0
 PRE(sys_mremap)
 {
    // Nb: this is different to the glibc version described in the man pages,
@@ -2735,6 +2750,7 @@ PRE(sys_sync)
    PRE_REG_READ0(long, "sync");
 }
 
+#if 0
 PRE(sys_fstatfs)
 {
    FUSE_COMPATIBLE_MAY_BLOCK();
@@ -2762,6 +2778,8 @@ POST(sys_fstatfs64)
 {
    POST_MEM_WRITE( ARG3, ARG2 );
 }
+#endif
+
 
 PRE(sys_getsid)
 {
@@ -3339,7 +3357,7 @@ PRE(sys_fork)
 
    if (!SUCCESS) return;
 
-#if defined(VGO_linux)
+#if defined(VGO_linux) || defined(VGO_netbsd)
    // RES is 0 for child, non-0 (the child's PID) for parent.
    is_child = ( RES == 0 ? True : False );
    child_pid = ( is_child ? -1 : RES );
@@ -4429,6 +4447,7 @@ POST(sys_newstat)
    POST_MEM_WRITE( ARG2, sizeof(struct vki_stat) );
 }
 
+#if 0
 PRE(sys_statfs)
 {
    FUSE_COMPATIBLE_MAY_BLOCK();
@@ -4456,6 +4475,7 @@ POST(sys_statfs64)
 {
    POST_MEM_WRITE( ARG3, ARG2 );
 }
+#endif
 
 PRE(sys_symlink)
 {
@@ -4514,6 +4534,7 @@ PRE(sys_unlink)
    PRE_MEM_RASCIIZ( "unlink(pathname)", ARG1 );
 }
 
+#if 0
 PRE(sys_newuname)
 {
    PRINT("sys_newuname ( %#" FMT_REGWORD "x )", ARG1);
@@ -4527,6 +4548,7 @@ POST(sys_newuname)
       POST_MEM_WRITE( ARG1, sizeof(struct vki_new_utsname) );
    }
 }
+#endif
 
 PRE(sys_waitpid)
 {
