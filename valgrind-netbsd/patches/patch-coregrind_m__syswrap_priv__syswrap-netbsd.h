$NetBSD$

--- coregrind/m_syswrap/priv_syswrap-netbsd.h.orig	2019-03-29 12:02:52.642924072 +0000
+++ coregrind/m_syswrap/priv_syswrap-netbsd.h
@@ -0,0 +1,281 @@
+
+/*--------------------------------------------------------------------*/
+/*--- netbsd-specific syscalls stuff.          priv_syswrap-netbsd.h ---*/
+/*--------------------------------------------------------------------*/
+
+/*
+   This file is part of Valgrind, a dynamic binary instrumentation
+   framework.
+
+   Copyright (C) 2000-2008 Nicholas Nethercote
+      njn@valgrind.org
+
+   This program is free software; you can redistribute it and/or
+   modify it under the terms of the GNU General Public License as
+   published by the Free Software Foundation; either version 2 of the
+   License, or (at your option) any later version.
+
+   This program is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+   General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software
+   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
+   02111-1307, USA.
+
+   The GNU General Public License is contained in the file COPYING.
+*/
+
+#ifndef __PRIV_SYSWRAP_NETBSD_H
+#define __PRIV_SYSWRAP_NETBSD_H
+
+/* requires #include "priv_types_n_macros.h" */
+
+// Clone-related functions
+extern Word ML_(start_thread_NORETURN) ( void* arg );
+extern Addr ML_(allocstack)            ( ThreadId tid );
+extern void ML_(call_on_new_stack_0_1) ( Addr stack, Addr retaddr,
+			                 void (*f)(Word), Word arg1 );
+extern SysRes ML_(do_fork) ( ThreadId tid );
+extern SysRes ML_(do_vfork) ( ThreadId tid );
+extern SysRes ML_(do_rfork) ( ThreadId tid, Int flags );
+
+#if 0
+DECL_TEMPLATE(netbsd, sys_syscall);
+DECL_TEMPLATE(netbsd, sys_exit);
+DECL_TEMPLATE(netbsd, sys_getfsstat4);
+DECL_TEMPLATE(netbsd, sys_getfsstat);
+DECL_TEMPLATE(netbsd, sys_mount);
+DECL_TEMPLATE(netbsd, sys_unmount);
+DECL_TEMPLATE(netbsd, sys_ptrace);
+DECL_TEMPLATE(netbsd, sys_recvmsg);
+DECL_TEMPLATE(netbsd, sys_sendmsg);
+DECL_TEMPLATE(netbsd, sys_recvfrom);
+DECL_TEMPLATE(netbsd, sys_accept);
+DECL_TEMPLATE(netbsd, sys_getpeername);
+DECL_TEMPLATE(netbsd, sys_getsockname);
+DECL_TEMPLATE(netbsd, sys_chflags);
+DECL_TEMPLATE(netbsd, sys_fchflags);
+DECL_TEMPLATE(netbsd, sys_pipe);
+DECL_TEMPLATE(netbsd, sys_pipe2);
+DECL_TEMPLATE(netbsd, sys_ktrace);
+DECL_TEMPLATE(netbsd, sys_getlogin);
+DECL_TEMPLATE(netbsd, sys_setlogin);
+DECL_TEMPLATE(netbsd, sys_reboot);
+DECL_TEMPLATE(netbsd, sys_revoke);
+DECL_TEMPLATE(netbsd, sys_sbrk);
+DECL_TEMPLATE(netbsd, sys_sstk);
+DECL_TEMPLATE(netbsd, sys_swapon);
+DECL_TEMPLATE(netbsd, sys_getdtablesize);
+DECL_TEMPLATE(netbsd, sys_socket);
+DECL_TEMPLATE(netbsd, sys_connect);
+DECL_TEMPLATE(netbsd, sys_bind);
+DECL_TEMPLATE(netbsd, sys_setsockopt);
+DECL_TEMPLATE(netbsd, sys_listen);
+DECL_TEMPLATE(netbsd, sys_getsockopt);
+DECL_TEMPLATE(netbsd, sys_mkfifo);
+DECL_TEMPLATE(netbsd, sys_sendto);
+DECL_TEMPLATE(netbsd, sys_shutdown);
+DECL_TEMPLATE(netbsd, sys_socketpair);
+DECL_TEMPLATE(netbsd, sys_adjtime);
+DECL_TEMPLATE(netbsd, sys_quotactl);
+DECL_TEMPLATE(netbsd, sys_nfssvc);
+DECL_TEMPLATE(netbsd, sys_getfh);
+DECL_TEMPLATE(netbsd, sys_getdomainname);
+DECL_TEMPLATE(netbsd, sys_setdomainname);
+DECL_TEMPLATE(netbsd, sys_uname);
+DECL_TEMPLATE(netbsd, sys_sysarch);
+DECL_TEMPLATE(netbsd, sys_rtprio);
+DECL_TEMPLATE(netbsd, sys_semsys);
+DECL_TEMPLATE(netbsd, sys_msgsys);
+DECL_TEMPLATE(netbsd, sys_shmsys);
+DECL_TEMPLATE(netbsd, sys_pread);
+DECL_TEMPLATE(netbsd, sys_pwrite);
+DECL_TEMPLATE(netbsd, sys_ntp_adjtime);
+DECL_TEMPLATE(netbsd, sys_setegid);
+DECL_TEMPLATE(netbsd, sys_seteuid);
+DECL_TEMPLATE(netbsd, sys_stat);
+DECL_TEMPLATE(netbsd, sys_fstat);
+DECL_TEMPLATE(netbsd, sys_lstat);
+DECL_TEMPLATE(netbsd, sys_pathconf);
+DECL_TEMPLATE(netbsd, sys_fpathconf);
+DECL_TEMPLATE(netbsd, sys_getdirentries);
+DECL_TEMPLATE(netbsd, sys_mmap);
+DECL_TEMPLATE(netbsd, sys___syscall);
+DECL_TEMPLATE(netbsd, sys_lseek);
+DECL_TEMPLATE(netbsd, sys_truncate);
+DECL_TEMPLATE(netbsd, sys_ftruncate);
+DECL_TEMPLATE(netbsd, sys___sysctl);
+DECL_TEMPLATE(netbsd, sys_undelete);
+DECL_TEMPLATE(netbsd, sys_futimes);
+DECL_TEMPLATE(netbsd, sys_nfs_fhopen);
+DECL_TEMPLATE(netbsd, sys___semctl7);
+DECL_TEMPLATE(netbsd, sys___semctl);
+DECL_TEMPLATE(netbsd, sys_semget);
+DECL_TEMPLATE(netbsd, sys_semop);
+DECL_TEMPLATE(netbsd, sys_msgctl);
+DECL_TEMPLATE(netbsd, sys_msgget);
+DECL_TEMPLATE(netbsd, sys_msgsnd);
+DECL_TEMPLATE(netbsd, sys_msgrcv);
+DECL_TEMPLATE(netbsd, sys_shmat);
+DECL_TEMPLATE(netbsd, sys_shmctl);
+DECL_TEMPLATE(netbsd, sys_shmctl7);
+DECL_TEMPLATE(netbsd, sys_shmdt);
+DECL_TEMPLATE(netbsd, sys_shmget);
+DECL_TEMPLATE(netbsd, sys_clock_gettime);
+DECL_TEMPLATE(netbsd, sys_clock_settime);
+DECL_TEMPLATE(netbsd, sys_clock_getres);
+DECL_TEMPLATE(netbsd, sys_minherit);
+DECL_TEMPLATE(netbsd, sys_rfork);
+DECL_TEMPLATE(netbsd, sys_issetugid);
+DECL_TEMPLATE(netbsd, sys_lchmod);
+DECL_TEMPLATE(netbsd, sys_lutimes);
+DECL_TEMPLATE(netbsd, sys_netbsd_msync);
+DECL_TEMPLATE(netbsd, sys_nstat);
+DECL_TEMPLATE(netbsd, sys_nfstat);
+DECL_TEMPLATE(netbsd, sys_nlstat);
+DECL_TEMPLATE(netbsd, sys_fhstatfs);
+DECL_TEMPLATE(netbsd, sys_fhopen);
+DECL_TEMPLATE(netbsd, sys_fhstat);
+DECL_TEMPLATE(netbsd, sys_modnext);
+DECL_TEMPLATE(netbsd, sys_modstat);
+DECL_TEMPLATE(netbsd, sys_modfnext);
+DECL_TEMPLATE(netbsd, sys_modfind);
+DECL_TEMPLATE(netbsd, sys_kldload);
+DECL_TEMPLATE(netbsd, sys_kldunload);
+DECL_TEMPLATE(netbsd, sys_kldfind);
+DECL_TEMPLATE(netbsd, sys_kldnext);
+DECL_TEMPLATE(netbsd, sys_kldstat);
+DECL_TEMPLATE(netbsd, sys_kldfirstmod);
+DECL_TEMPLATE(netbsd, sys_setresuid);
+DECL_TEMPLATE(netbsd, sys_setresgid);
+DECL_TEMPLATE(netbsd, sys_aio_return);
+DECL_TEMPLATE(netbsd, sys_aio_suspend);
+DECL_TEMPLATE(netbsd, sys_aio_cancel);
+DECL_TEMPLATE(netbsd, sys_aio_error);
+DECL_TEMPLATE(netbsd, sys_aio_read);
+DECL_TEMPLATE(netbsd, sys_aio_write);
+DECL_TEMPLATE(netbsd, sys_lio_listio);
+DECL_TEMPLATE(netbsd, sys_yield);
+DECL_TEMPLATE(netbsd, sys_thr_sleep);
+DECL_TEMPLATE(netbsd, sys_thr_wakeup);
+DECL_TEMPLATE(netbsd, sys_munlockall);
+DECL_TEMPLATE(netbsd, sys___getcwd);
+DECL_TEMPLATE(netbsd, sys_sched_setparam);
+DECL_TEMPLATE(netbsd, sys_sched_getparam);
+DECL_TEMPLATE(netbsd, sys_sched_setscheduler);
+DECL_TEMPLATE(netbsd, sys_sched_getscheduler);
+DECL_TEMPLATE(netbsd, sys_sched_yield);
+DECL_TEMPLATE(netbsd, sys_sched_get_priority_max);
+DECL_TEMPLATE(netbsd, sys_sched_get_priority_min);
+DECL_TEMPLATE(netbsd, sys_sched_rr_get_interval);
+DECL_TEMPLATE(netbsd, sys_utrace);
+DECL_TEMPLATE(netbsd, sys_kldsym);
+DECL_TEMPLATE(netbsd, sys_jail);
+DECL_TEMPLATE(netbsd, sys_sigprocmask);
+DECL_TEMPLATE(netbsd, sys_sigsuspend);
+DECL_TEMPLATE(netbsd, sys_sigaction);
+DECL_TEMPLATE(netbsd, sys_sigpending);
+DECL_TEMPLATE(netbsd, sys_sigreturn);
+DECL_TEMPLATE(netbsd, sys_fake_sigreturn);
+DECL_TEMPLATE(netbsd, sys_sigtimedwait);
+DECL_TEMPLATE(netbsd, sys_sigwaitinfo);
+DECL_TEMPLATE(netbsd, sys_getcontext);
+DECL_TEMPLATE(netbsd, sys_setcontext);
+DECL_TEMPLATE(netbsd, sys_swapcontext);
+DECL_TEMPLATE(netbsd, sys___acl_get_file);
+DECL_TEMPLATE(netbsd, sys___acl_set_file);
+DECL_TEMPLATE(netbsd, sys___acl_get_fd);
+DECL_TEMPLATE(netbsd, sys___acl_set_fd);
+DECL_TEMPLATE(netbsd, sys___acl_delete_file);
+DECL_TEMPLATE(netbsd, sys___acl_delete_fd);
+DECL_TEMPLATE(netbsd, sys___acl_aclcheck_file);
+DECL_TEMPLATE(netbsd, sys___acl_aclcheck_fd);
+DECL_TEMPLATE(netbsd, sys___acl_get_link);
+DECL_TEMPLATE(netbsd, sys___acl_set_link);
+DECL_TEMPLATE(netbsd, sys___acl_delete_link);
+DECL_TEMPLATE(netbsd, sys___acl_aclcheck_link);
+DECL_TEMPLATE(netbsd, sys_extattrctl);
+DECL_TEMPLATE(netbsd, sys_extattr_set_file);
+DECL_TEMPLATE(netbsd, sys_extattr_get_file);
+DECL_TEMPLATE(netbsd, sys_extattr_delete_file);
+DECL_TEMPLATE(netbsd, sys_aio_waitcomplete);
+DECL_TEMPLATE(netbsd, sys_getresuid);
+DECL_TEMPLATE(netbsd, sys_getresgid);
+DECL_TEMPLATE(netbsd, sys_kqueue);
+DECL_TEMPLATE(netbsd, sys_kevent);
+DECL_TEMPLATE(netbsd, sys_sendfile);
+DECL_TEMPLATE(netbsd, sys_statfs6);
+DECL_TEMPLATE(netbsd, sys_fstatfs6);
+DECL_TEMPLATE(netbsd, sys_fhstatfs6);
+DECL_TEMPLATE(netbsd, sys_thr_exit);
+DECL_TEMPLATE(netbsd, sys_thr_self);
+DECL_TEMPLATE(netbsd, sys_thr_set_name);
+DECL_TEMPLATE(netbsd, sys_rtprio_thread);
+DECL_TEMPLATE(netbsd, sys_fork);
+DECL_TEMPLATE(netbsd, sys_vfork);
+DECL_TEMPLATE(netbsd, sys_modfind);
+DECL_TEMPLATE(netbsd, sys_modstat);
+DECL_TEMPLATE(netbsd, sys_lkmnosys0);
+DECL_TEMPLATE(netbsd, sys_lkmnosys1);
+DECL_TEMPLATE(netbsd, sys_lkmnosys2);
+DECL_TEMPLATE(netbsd, sys_lkmnosys3);
+DECL_TEMPLATE(netbsd, sys_lkmnosys4);
+DECL_TEMPLATE(netbsd, sys_lkmnosys5);
+DECL_TEMPLATE(netbsd, sys_lkmnosys6);
+DECL_TEMPLATE(netbsd, sys_lkmnosys7);
+DECL_TEMPLATE(netbsd, sys_lkmnosys8);
+DECL_TEMPLATE(netbsd, sys_sigaction4);
+DECL_TEMPLATE(netbsd, sys_mmap7);
+DECL_TEMPLATE(netbsd, sys_lseek7);
+DECL_TEMPLATE(netbsd, sys_truncate7);
+DECL_TEMPLATE(netbsd, sys_ftruncate7);
+DECL_TEMPLATE(netbsd, sys_pread7);
+DECL_TEMPLATE(netbsd, sys_pwrite7);
+DECL_TEMPLATE(netbsd, sys__umtx_op);
+DECL_TEMPLATE(netbsd, sys__umtx_lock);
+DECL_TEMPLATE(netbsd, sys__umtx_unlock);
+DECL_TEMPLATE(netbsd, sys_thr_kill2);
+DECL_TEMPLATE(netbsd, sys_thr_wake);
+DECL_TEMPLATE(netbsd, sys_shm_open);
+DECL_TEMPLATE(netbsd, sys_shm_unlink);
+DECL_TEMPLATE(netbsd, sys_eaccess);
+DECL_TEMPLATE(netbsd, sys_cpuset);
+DECL_TEMPLATE(netbsd, sys_cpuset_setid);
+DECL_TEMPLATE(netbsd, sys_cpuset_getid);
+DECL_TEMPLATE(netbsd, sys_cpuset_getaffinity);
+DECL_TEMPLATE(netbsd, sys_cpuset_setaffinity);
+DECL_TEMPLATE(netbsd, sys_faccessat);
+DECL_TEMPLATE(netbsd, sys_fchmodat);
+DECL_TEMPLATE(netbsd, sys_fchownat);
+DECL_TEMPLATE(netbsd, sys_fexecve);
+DECL_TEMPLATE(netbsd, sys_fstatat);
+DECL_TEMPLATE(netbsd, sys_futimesat);
+DECL_TEMPLATE(netbsd, sys_linkat);
+DECL_TEMPLATE(netbsd, sys_mkdirat);
+DECL_TEMPLATE(netbsd, sys_mkfifoat);
+DECL_TEMPLATE(netbsd, sys_mknodat);
+DECL_TEMPLATE(netbsd, sys_openat);
+DECL_TEMPLATE(netbsd, sys_readlinkat);
+DECL_TEMPLATE(netbsd, sys_renameat);
+DECL_TEMPLATE(netbsd, sys_symlinkat);
+DECL_TEMPLATE(netbsd, sys_unlinkat);
+DECL_TEMPLATE(netbsd, sys_posix_openpt);
+DECL_TEMPLATE(netbsd, sys_kenv);
+DECL_TEMPLATE(netbsd, sys_uuidgen);
+DECL_TEMPLATE(netbsd, sys_thr_new);
+DECL_TEMPLATE(netbsd, sys_thr_kill);
+DECL_TEMPLATE(netbsd, sys_thr_kill2);
+DECL_TEMPLATE(netbsd, sys_fcntl);
+DECL_TEMPLATE(netbsd, sys_ioctl);
+DECL_TEMPLATE(netbsd, sys_mq_open);
+DECL_TEMPLATE(netbsd, sys_mq_unlink);
+#endif
+
+#endif   // __PRIV_SYSWRAP_NETBSD_H
+
+/*--------------------------------------------------------------------*/
+/*--- end                                                          ---*/
+/*--------------------------------------------------------------------*/
