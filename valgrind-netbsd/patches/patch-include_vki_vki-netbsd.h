$NetBSD$

--- include/vki/vki-netbsd.h.orig	2019-03-31 21:41:11.006389280 +0000
+++ include/vki/vki-netbsd.h
@@ -0,0 +1,3297 @@
+
+/*--------------------------------------------------------------------*/
+/*--- NetBSD-specific kernel interface.               vki-netbsd.h ---*/
+/*--------------------------------------------------------------------*/
+
+/*
+   This file is part of Valgrind, a dynamic binary instrumentation
+   framework.
+
+   Copyright (C) 2011-2017 Petr Pavlu
+      setup@dagobah.cz
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
+/* Copyright 2013-2017, Ivo Raisr <ivosh@ivosh.net> */
+
+/* Copyright 2013, OmniTI Computer Consulting, Inc. All rights reserved. */
+
+/* The purpose of this file is described in vki-linux.h.
+
+   To avoid any copyright issues, vki-netbsd.h follows the same approach as
+   vki-darwin.h (not copying anything from kernel header files but instead
+   just including them).
+ */
+
+#ifndef __VKI_NETBSD_H
+#define __VKI_NETBSD_H
+
+//----------------------------------------------------------------------
+// Arch-specific POSIX types
+//----------------------------------------------------------------------
+
+#if defined(VGA_amd64)                                                                                                                                     
+#  include "vki-machine-types-amd64-netbsd.h"
+#else
+#  error Unknown platform
+#endif
+
+//----------------------------------------------------------------------
+// sys/ansi.h
+//----------------------------------------------------------------------
+
+typedef char *                  vki___caddr_t;
+typedef vki_uint32_t            vki___gid_t;
+typedef vki_uint32_t            vki___in_addr_t;
+typedef vki_uint16_t            vki___in_port_t;
+typedef vki_uint32_t            vki___mode_t;
+typedef vki_int64_t             vki___off_t;
+typedef vki_int32_t             vki___pid_t;
+typedef vki_uint8_t             vki___sa_family_t;
+typedef unsigned int            vki___socklen_t;
+typedef vki_uint32_t            vki___uid_t;
+typedef vki_uint64_t            vki___fsblkcnt_t;
+typedef vki_uint64_t            vki___fsfilcnt_t;
+
+struct vki___tag_wctrans_t;
+typedef struct vki___tag_wctrans_t *vki___wctrans_t;
+
+struct vki___tag_wctype_t;
+typedef struct vki___tag_wctype_t *vki___wctype_t;
+
+typedef union {
+        vki_int64_t __mbstateL; /* for alignment */
+        char __mbstate8[128];
+} vki___mbstate_t;
+
+typedef vki_uint64_t            vki___fsfilcnt_t;
+
+//----------------------------------------------------------------------
+// sys/param.h
+//----------------------------------------------------------------------
+
+#define VKI_BSD     199506          /* System version (year & month). */
+#define VKI_BSD4_3  1
+#define VKI_BSD4_4  1
+
+#define VKI_MAXCOMLEN       16              /* max command name remembered */
+#define VKI_MAXINTERP       VKI_PATH_MAX        /* max interpreter file name length */
+/* DEPRECATED: use LOGIN_NAME_MAX instead. */
+#define VKI_MAXLOGNAME      (VKI_LOGIN_NAME_MAX - 1) /* max login name length */
+#define VKI_NCARGS          VKI_ARG_MAX         /* max bytes for an exec function */
+#define VKI_NGROUPS         VKI_NGROUPS_MAX     /* max number groups */
+#define VKI_NOGROUP         65535           /* marker for empty group set member */
+#define VKI_MAXHOSTNAMELEN  256             /* max hostname size */
+
+#ifndef VKI_NOFILE
+#define VKI_NOFILE          VKI_OPEN_MAX        /* max open files per process */
+#endif
+
+#define VKI_ALIGNBYTES      VKI___ALIGNBYTES
+
+//----------------------------------------------------------------------
+// sys/types.h
+//----------------------------------------------------------------------
+
+typedef vki_uint8_t             vki_u_int8_t;
+typedef vki_uint16_t            vki_u_int16_t;
+typedef vki_uint32_t            vki_u_int32_t;                                                                                                               
+typedef vki_uint64_t            vki_u_int64_t;
+
+typedef unsigned char           vki_u_char;
+typedef unsigned short          vki_u_short;
+typedef unsigned int            vki_u_int;
+typedef unsigned long           vki_u_long;
+
+typedef unsigned char           vki_unchar;
+typedef unsigned short          vki_ushort;
+typedef unsigned int            vki_uint;
+typedef unsigned long           vki_ulong;
+
+typedef vki_uint64_t            vki_u_quad_t;
+typedef vki_int64_t             vki_quad_t;
+typedef vki_quad_t *            vki_qaddr_t;
+
+typedef vki_int64_t             vki_longlong_t;
+typedef vki_uint64_t            vki_u_longlong_t;
+
+typedef vki_int64_t             vki_blkcnt_t;
+typedef vki_int32_t             vki_blksize_t;
+
+typedef vki___fsblkcnt_t        vki_fsblkcnt_t;
+typedef vki___fsfilcnt_t        vki_fsfilcnt_t;
+typedef vki___caddr_t           vki_caddr_t;
+typedef vki_int64_t             vki_daddr_t;
+
+typedef vki_uint64_t            vki_dev_t;
+typedef vki_uint32_t            vki_fixpt_t;
+typedef vki___gid_t             vki_gid_t;
+
+typedef vki_uint32_t            vki_id_t;
+typedef vki_uint64_t            vki_ino_t;
+typedef long                    vki_key_t;
+
+typedef vki___mode_t            vki_mode_t;
+
+typedef vki_uint32_t            vki_nlink_t;
+
+typedef vki___off_t             vki_off_t;
+typedef vki___pid_t             vki_pid_t;
+typedef vki_int32_t             vki_lwpid_t;
+typedef vki_uint64_t            vki_rlim_t;
+typedef vki_int32_t             vki_segsz_t;
+typedef vki_int32_t             vki_swblk_t;
+
+typedef vki___uid_t             vki_uid_t;
+
+typedef int                     vki_mqd_t;
+
+typedef unsigned long           vki_cpuid_t;
+
+typedef int                     vki_psetid_t;
+
+typedef volatile vki___cpu_simple_lock_nv_t vki___cpu_simple_lock_t;
+
+typedef int                     vki_boolean_t;
+
+union vki___semun {
+        int             val;            /* value for SETVAL */
+        struct vki_semid_ds *buf;           /* buffer for IPC_STAT & IPC_SET */
+        unsigned short  *array;         /* array for GETALL & SETALL */
+};
+
+#define vki_semun vki___semun // linux compat
+
+typedef vki_int32_t             vki___devmajor_t;
+typedef vki_int32_t             vki___devminor_t;
+
+typedef vki___devmajor_t        vki_devmajor_t;
+typedef vki___devminor_t        vki_devminor_t;
+
+typedef vki_bsd_clock_t         vki_clock_t;
+typedef vki_bsd_ptrdiff_t       vki_ptrdiff_t;
+typedef vki_bsd_size_t          vki_size_t;
+typedef vki_bsd_ssize_t         vki_ssize_t;
+typedef vki_bsd_time_t          vki_time_t;
+typedef vki_bsd_clockid_t       vki_clockid_t;
+typedef vki_bsd_timer_t         vki_timer_t;
+typedef vki_bsd_suseconds_t     vki_suseconds_t;
+typedef vki_bsd_useconds_t      vki_useconds_t;
+
+typedef struct vki_kauth_cred * vki_kauth_cred_t;
+
+typedef int                     vki_pri_t;
+
+//----------------------------------------------------------------------
+// sys/cdefs.h
+//----------------------------------------------------------------------
+
+#define VKI___CAST(__dt, __st)      ((__dt)(__st))
+#define VKI___CASTV(__dt, __st)     VKI___CAST(__dt, VKI___CAST(void *, __st))
+#define VKI___CASTCV(__dt, __st)    VKI___CAST(__dt, VKI___CAST(const void *, __st))
+
+//----------------------------------------------------------------------
+// Now the rest of the arch-specific stuff
+//----------------------------------------------------------------------
+
+#if defined(VGA_amd64)
+#  include "vki-amd64-netbsd.h"
+#else
+#  error Unknown platform
+#endif
+
+//----------------------------------------------------------------------
+// sys/syslimits.h
+//----------------------------------------------------------------------
+
+#define VKI_ARG_MAX             (256 * 1024)
+#define VKI_CHILD_MAX           160
+#define VKI_GID_MAX             2147483647U
+#define VKI_LINK_MAX            32767
+#define VKI_MAX_CANON           255
+#define VKI_MAX_INPUT           255
+#define VKI_NAME_MAX            511
+#define VKI_NGROUPS_MAX         16
+#define VKI_UID_MAX             2147483647U
+#define VKI_OPEN_MAX            128
+#define VKI_PATH_MAX            1024
+#define VKI_PIPE_BUF            512
+#define VKI_BC_BASE_MAX         VKI_INT_MAX
+#define VKI_BC_DIM_MAX          65535
+#define VKI_BC_SCALE_MAX        VKI_INT_MAX
+#define VKI_BC_STRING_MAX       VKI_INT_MAX
+#define VKI_COLL_WEIGHTS_MAX    2
+#define VKI_EXPR_NEST_MAX       32
+#define VKI_LINE_MAX            2048
+#define VKI_RE_DUP_MAX          255
+#define VKI_LOGIN_NAME_MAX      17
+#define VKI_IOV_MAX             1024
+#define VKI_NZERO               20
+
+//----------------------------------------------------------------------
+// sys/timespec.h
+//----------------------------------------------------------------------
+
+struct vki_timespec {
+        vki_time_t  tv_sec;         /* seconds */
+        long    tv_nsec;        /* and nanoseconds */
+};
+
+//----------------------------------------------------------------------
+// sys/time.h
+//----------------------------------------------------------------------
+
+struct vki_timeval {
+        vki_time_t          tv_sec;         /* seconds */
+        vki_suseconds_t     tv_usec;        /* and microseconds */
+};
+
+struct vki_timezone {
+        int     tz_minuteswest; /* minutes west of Greenwich */
+        int     tz_dsttime;     /* type of dst correction */
+};
+
+struct vki_bintime {
+        vki_time_t  sec;
+        vki_uint64_t frac;
+};
+
+struct  vki_itimerval {
+        struct  vki_timeval it_interval;    /* timer interval */
+        struct  vki_timeval it_value;       /* current value */
+};
+
+struct  vki_itimerspec {
+        struct  vki_timespec it_interval;
+        struct  vki_timespec it_value;
+};
+
+
+//----------------------------------------------------------------------
+// From sys/resource.h
+//----------------------------------------------------------------------
+
+#define VKI_PRIO_MIN        -20
+#define VKI_PRIO_MAX        20
+
+#define VKI_PRIO_PROCESS    0
+#define VKI_PRIO_PGRP       1
+#define VKI_PRIO_USER       2
+
+#define VKI_RUSAGE_SELF     0
+#define VKI_RUSAGE_CHILDREN -1
+
+struct  vki_rusage {
+        struct vki_timeval ru_utime;    /* user time used */
+        struct vki_timeval ru_stime;    /* system time used */
+        long    ru_maxrss;              /* maximum resident set size */                                                                                      
+#define ru_first        ru_ixrss
+        long    ru_ixrss;               /* integral shared memory size */
+        long    ru_idrss;               /* integral unshared data size */
+        long    ru_isrss;               /* integral unshared stack size */
+        long    ru_minflt;              /* page reclaims */                                                                                                  
+        long    ru_majflt;              /* page faults */                                                                                                    
+        long    ru_nswap;               /* swaps */
+        long    ru_inblock;             /* block input operations */
+        long    ru_oublock;             /* block output operations */
+        long    ru_msgsnd;              /* messages sent */
+        long    ru_msgrcv;              /* messages received */
+        long    ru_nsignals;            /* signals received */
+        long    ru_nvcsw;               /* voluntary context switches */
+        long    ru_nivcsw;              /* involuntary " */
+#define ru_last         ru_nivcsw
+};
+
+struct vki_wrusage {
+        struct vki_rusage   wru_self;
+        struct vki_rusage   wru_children;
+};
+
+#define VKI_RLIMIT_CPU      0               /* cpu time in milliseconds */
+#define VKI_RLIMIT_FSIZE    1               /* maximum file size */
+#define VKI_RLIMIT_DATA     2               /* data size */
+#define VKI_RLIMIT_STACK    3               /* stack size */
+#define VKI_RLIMIT_CORE     4               /* core file size */
+#define VKI_RLIMIT_RSS      5               /* resident set size */
+#define VKI_RLIMIT_MEMLOCK  6               /* locked-in-memory address space */
+#define VKI_RLIMIT_NPROC    7               /* number of processes */
+#define VKI_RLIMIT_NOFILE   8               /* number of open files */
+#define VKI_RLIMIT_SBSIZE   9               /* maximum size of all socket buffers */
+#define VKI_RLIMIT_AS       10              /* virtual process size (inclusive of mmap) */
+#define VKI_RLIMIT_VMEM     VKI_RLIMIT_AS       /* common alias */
+#define VKI_RLIMIT_NTHR     11              /* number of threads */
+
+#define VKI_RLIM_NLIMITS    12              /* number of resource limits */
+
+#define VKI_RLIM_INFINITY   (~((vki_u_quad_t)1 << 63))  /* no limit */
+#define VKI_RLIM_SAVED_MAX  VKI_RLIM_INFINITY   /* unrepresentable hard limit */
+#define VKI_RLIM_SAVED_CUR  VKI_RLIM_INFINITY   /* unrepresentable soft limit */
+
+struct vki_rlimit {
+        vki_rlim_t  rlim_cur;               /* current (soft) limit */
+        vki_rlim_t  rlim_max;               /* maximum value for rlim_cur */
+};
+
+struct vki_loadavg {
+        vki_fixpt_t ldavg[3];
+        long    fscale;
+};
+
+//----------------------------------------------------------------------
+// From sys/sigtypes.h
+//----------------------------------------------------------------------
+
+typedef struct {
+        vki_uint32_t sig/*__bits*/[4 /* _VKI_NSIG_WORDS */];
+} vki_sigset_t;
+
+typedef struct vki_sigaltstack {
+        void *ss_sp;
+        vki_size_t ss_size;
+        int ss_flags;
+} vki_stack_t;
+
+//----------------------------------------------------------------------
+// From sys/sigtypes.h
+//----------------------------------------------------------------------
+
+typedef union vki_sigval {
+        int sival_int;
+        void *sival_ptr;
+} vki_sigval_t;
+
+struct vki__ksiginfo {
+        int     _signo;
+        int     _code;
+        int     _errno;
+#ifdef _LP64
+        /* In _LP64 the union starts on an 8-byte boundary. */
+        int     _pad;
+#endif
+        union {
+                struct {
+                        vki_pid_t   _pid;  
+                        vki_uid_t   _uid;  
+                        vki_sigval_t        _value;
+                } _rt;
+                
+                struct {
+                        vki_pid_t   _pid;  
+                        vki_uid_t   _uid;
+                        int     _status;
+                        vki_clock_t _utime;
+                        vki_clock_t _stime;
+                } _child;
+
+                struct {
+                        void   *_addr;  
+                        int     _trap; 
+                        int     _trap2;
+                        int     _trap3;
+                } _fault;
+
+                struct {                                                                                                                                     
+                        long    _band;
+                        int     _fd;
+                } _poll;                                                                                                                                     
+        } _reason;
+};
+
+typedef union vki_siginfo {
+        char    si_pad[128];    /* Total size; for future expansion */   
+        struct vki__ksiginfo _info;
+} vki_siginfo_t;
+
+#define si_signo        _info._signo
+#define si_code         _info._code
+#define si_errno        _info._errno
+
+#define si_value        _info._reason._rt._value   
+#define si_pid          _info._reason._child._pid
+#define si_uid          _info._reason._child._uid   
+#define si_status       _info._reason._child._status
+#define si_utime        _info._reason._child._utime                                                                                                          
+#define si_stime        _info._reason._child._stime
+
+#define si_addr         _info._reason._fault._addr
+#define si_trap         _info._reason._fault._trap
+#define si_trap2        _info._reason._fault._trap2
+#define si_trap3        _info._reason._fault._trap3
+
+#define si_band         _info._reason._poll._band
+#define si_fd           _info._reason._poll._fd 
+
+#define VKI_ILL_ILLOPC      1       /* Illegal opcode                       */
+#define VKI_ILL_ILLOPN      2       /* Illegal operand                      */
+#define VKI_ILL_ILLADR      3       /* Illegal addressing mode              */
+#define VKI_ILL_ILLTRP      4       /* Illegal trap                         */
+#define VKI_ILL_PRVOPC      5       /* Privileged opcode                    */
+#define VKI_ILL_PRVREG      6       /* Privileged register                  */
+#define VKI_ILL_COPROC      7       /* Coprocessor error                    */
+#define VKI_ILL_BADSTK      8       /* Internal stack error                 */
+
+#define VKI_FPE_INTDIV      1       /* Integer divide by zero               */
+#define VKI_FPE_INTOVF      2       /* Integer overflow                     */
+#define VKI_FPE_FLTDIV      3       /* Floating point divide by zero        */
+#define VKI_FPE_FLTOVF      4       /* Floating point overflow              */
+#define VKI_FPE_FLTUND      5       /* Floating point underflow             */
+#define VKI_FPE_FLTRES      6       /* Floating point inexact result        */
+#define VKI_FPE_FLTINV      7       /* Invalid Floating point operation     */
+#define VKI_FPE_FLTSUB      8       /* Subscript out of range               */
+
+#define VKI_SEGV_MAPERR     1       /* Address not mapped to object         */
+#define VKI_SEGV_ACCERR     2       /* Invalid permissions for mapped object*/
+
+#define VKI_BUS_ADRALN      1       /* Invalid address alignment            */
+#define VKI_BUS_ADRERR      2       /* Non-existent physical address        */
+#define VKI_BUS_OBJERR      3       /* Object specific hardware error       */
+
+#define VKI_TRAP_BRKPT      1       /* Process breakpoint                   */
+#define VKI_TRAP_TRACE      2       /* Process trace trap                   */
+#define VKI_TRAP_EXEC       3       /* Process exec trap                    */
+#define VKI_TRAP_CHLD       4       /* Process child trap                   */                                                                                   
+#define VKI_TRAP_LWP        5       /* Process lwp trap                     */
+#define VKI_TRAP_DBREG      6       /* Process hardware debug register trap */
+#define VKI_TRAP_SCE        7       /* Process syscall entry trap           */
+#define VKI_TRAP_SCX        8       /* Process syscall exit trap            */
+
+#define VKI_CLD_EXITED      1       /* Child has exited                     */
+#define VKI_CLD_KILLED      2       /* Child has terminated abnormally but  */
+                                /* did not create a core file           */                                                                                   
+#define VKI_CLD_DUMPED      3       /* Child has terminated abnormally and  */
+                                /* created a core file                  */
+#define VKI_CLD_TRAPPED     4       /* Traced child has trapped             */
+#define VKI_CLD_STOPPED     5       /* Child has stopped                    */
+#define VKI_CLD_CONTINUED   6       /* Stopped child has continued          */
+
+#define VKI_POLL_IN         1       /* Data input available                 */
+#define VKI_POLL_OUT        2       /* Output buffers available             */                                                                                   
+#define VKI_POLL_MSG        3       /* Input message available              */
+#define VKI_POLL_ERR        4       /* I/O Error                            */
+#define VKI_POLL_PRI        5       /* High priority input available        */
+#define VKI_POLL_HUP        6       /* Device disconnected                  */
+
+#define VKI_SI_USER         0       /* Sent by kill(2)                      */
+#define VKI_SI_QUEUE        -1      /* Sent by the sigqueue(2)              */                                                                                   
+#define VKI_SI_TIMER        -2      /* Generated by expiration of a timer   */
+                                /* set by timer_settime(2)              */
+#define VKI_SI_ASYNCIO      -3      /* Generated by completion of an        */
+                                /* asynchronous I/O signal              */
+#define VKI_SI_MESGQ        -4      /* Generated by arrival of a message on */
+                                /* an empty message queue               */
+
+#define VKI_SI_LWP          -5      /* Generated by _lwp_kill(2)            */
+#define VKI_SI_NOINFO       32767   /* No signal specific info available    */
+
+//----------------------------------------------------------------------
+// From poll.h
+//----------------------------------------------------------------------
+
+typedef unsigned int    vki_nfds_t;
+
+struct vki_pollfd {
+        int     fd;             /* file descriptor */
+        short   events;         /* events to look for */
+        short   revents;        /* events returned */
+};
+
+#define VKI_POLLIN          0x0001
+#define VKI_POLLPRI         0x0002
+#define VKI_POLLOUT         0x0004
+#define VKI_POLLRDNORM      0x0040
+#define VKI_POLLWRNORM      POLLOUT
+#define VKI_POLLRDBAND      0x0080
+#define VKI_POLLWRBAND      0x0100
+
+#define VKI_POLLERR         0x0008
+#define VKI_POLLHUP         0x0010
+#define VKI_POLLNVAL        0x0020
+
+#define VKI_INFTIM          -1
+
+//----------------------------------------------------------------------
+// From sys/uio.h
+//----------------------------------------------------------------------
+
+struct vki_iovec {
+        void    *iov_base;      /* Base address. */
+        vki_size_t   iov_len;       /* Length. */
+};
+
+enum    vki_uio_rw { VKI_UIO_READ, VKI_UIO_WRITE };
+
+enum vki_uio_seg {
+        VKI_UIO_USERSPACE,          /* from user data space */
+        VKI_UIO_SYSSPACE            /* from system space */
+};
+
+#define VKI_UIO_MAXIOV      1024            /* max 1K of iov's */
+
+//----------------------------------------------------------------------
+// From sys/socket.h
+//----------------------------------------------------------------------
+
+typedef vki___sa_family_t   vki_sa_family_t;
+
+typedef vki___socklen_t     vki_socklen_t;
+
+#define VKI_SOCK_STREAM     1               /* stream socket */
+#define VKI_SOCK_DGRAM      2               /* datagram socket */
+#define VKI_SOCK_RAW        3               /* raw-protocol interface */
+#define VKI_SOCK_RDM        4               /* reliably-delivered message */
+#define VKI_SOCK_SEQPACKET  5               /* sequenced packet stream */
+#define VKI_SOCK_CONN_DGRAM 6               /* connection-orientated datagram */
+#define VKI_SOCK_DCCP       VKI_SOCK_CONN_DGRAM
+
+#define VKI_SOCK_CLOEXEC    0x10000000      /* set close on exec on socket */
+#define VKI_SOCK_NONBLOCK   0x20000000      /* set non blocking i/o socket */
+#define VKI_SOCK_NOSIGPIPE  0x40000000      /* don't send sigpipe */
+#define VKI_SOCK_FLAGS_MASK 0xf0000000      /* flags mask */
+#define VKI_SO_DEBUG        0x0001          /* turn on debugging info recording */
+#define VKI_SO_ACCEPTCONN   0x0002          /* socket has had listen() */
+#define VKI_SO_REUSEADDR    0x0004          /* allow local address reuse */
+#define VKI_SO_KEEPALIVE    0x0008          /* keep connections alive */
+#define VKI_SO_DONTROUTE    0x0010          /* just use interface addresses */
+#define VKI_SO_BROADCAST    0x0020          /* permit sending of broadcast msgs */                                                                               
+#define VKI_SO_USELOOPBACK  0x0040          /* bypass hardware when possible */
+#define VKI_SO_LINGER       0x0080          /* linger on close if data present */
+#define VKI_SO_OOBINLINE    0x0100          /* leave received OOB data in line */
+#define VKI_SO_REUSEPORT    0x0200          /* allow local address & port reuse */
+/*      SO_OTIMESTAMP   0x0400          */
+#define VKI_SO_NOSIGPIPE    0x0800          /* no SIGPIPE from EPIPE */
+#define VKI_SO_ACCEPTFILTER 0x1000          /* there is an accept filter */
+#define VKI_SO_TIMESTAMP    0x2000          /* timestamp received dgram traffic */
+#define VKI_SO_RERROR       0x4000          /* Keep track of receive errors */                                                                                   
+
+#define VKI_SO_SNDBUF       0x1001          /* send buffer size */
+#define VKI_SO_RCVBUF       0x1002          /* receive buffer size */
+#define VKI_SO_SNDLOWAT     0x1003          /* send low-water mark */
+#define VKI_SO_RCVLOWAT     0x1004          /* receive low-water mark */
+/* SO_OSNDTIMEO         0x1005 */
+/* SO_ORCVTIMEO         0x1006 */
+#define VKI_SO_ERROR        0x1007          /* get error status and clear */                                                                                     
+#define VKI_SO_TYPE         0x1008          /* get socket type */
+#define VKI_SO_OVERFLOWED   0x1009          /* datagrams: return packets dropped */
+
+#define VKI_SO_NOHEADER     0x100a          /* user supplies no header to kernel;
+                                         * kernel removes header and supplies
+                                         * payload
+                                         */
+#define VKI_SO_SNDTIMEO     0x100b          /* send timeout */
+
+#define VKI_SO_RCVTIMEO     0x100c          /* receive timeout */
+/*
+ * Structure used for manipulating linger option.
+ */
+
+struct  vki_linger {
+        int     l_onoff;                /* option on/off */
+        int     l_linger;               /* linger time in seconds */
+};
+
+struct  vki_accept_filter_arg {
+        char    af_name[16];
+        char    af_arg[256-16];
+};
+
+#define VKI_SOL_SOCKET      0xffff          /* options for socket level */
+
+/*
+ * Address families.
+ */
+#define VKI_AF_UNSPEC       0               /* unspecified */
+#define VKI_AF_LOCAL        1               /* local to host */
+#define VKI_AF_UNIX         VKI_AF_LOCAL        /* backward compatibility */
+#define VKI_AF_INET         2               /* internetwork: UDP, TCP, etc. */
+#define VKI_AF_IMPLINK      3               /* arpanet imp addresses */
+#define VKI_AF_PUP          4               /* pup protocols: e.g. BSP */
+#define VKI_AF_CHAOS        5               /* mit CHAOS protocols */
+#define VKI_AF_NS           6               /* XEROX NS protocols */
+#define VKI_AF_ISO          7               /* ISO protocols */
+#define VKI_AF_OSI          VKI_AF_ISO
+#define VKI_AF_ECMA         8               /* european computer manufacturers */
+#define VKI_AF_DATAKIT      9               /* datakit protocols */
+#define VKI_AF_CCITT        10              /* CCITT protocols, X.25 etc */
+
+#define VKI_AF_SNA          11              /* IBM SNA */                                                                                                        
+#define VKI_AF_DECnet       12              /* DECnet */
+#define VKI_AF_DLI          13              /* DEC Direct data link interface */
+#define VKI_AF_LAT          14              /* LAT */
+#define VKI_AF_HYLINK       15              /* NSC Hyperchannel */
+#define VKI_AF_APPLETALK    16              /* Apple Talk */
+#define VKI_AF_OROUTE       17              /* Internal Routing Protocol */
+#define VKI_AF_LINK         18              /* Link layer interface */
+#define VKI_pseudo_AF_XTP   19              /* eXpress Transfer Protocol (no AF) */                                                                              
+#define VKI_AF_COIP         20              /* connection-oriented IP, aka ST II */
+#define VKI_AF_CNT          21              /* Computer Network Technology */
+#define VKI_pseudo_AF_RTIP  22              /* Help Identify RTIP packets */
+#define VKI_AF_IPX          23              /* Novell Internet Protocol */
+#define VKI_AF_INET6        24              /* IP version 6 */
+#define VKI_pseudo_AF_PIP   25              /* Help Identify PIP packets */
+#define VKI_AF_ISDN         26              /* Integrated Services Digital Network*/
+#define VKI_AF_E164         VKI_AF_ISDN         /* CCITT E.164 recommendation */
+#define VKI_AF_NATM         27              /* native ATM access */
+#define VKI_AF_ARP          28              /* (rev.) addr. res. prot. (RFC 826) */
+#define VKI_pseudo_AF_KEY   29              /* Internal key management protocol  */
+#define VKI_pseudo_AF_HDRCMPLT 30           /* Used by BPF to not rewrite hdrs                                                                                   
+                                           in interface output routine */
+
+//#define VKI_AF_BLUETOOTH    31              /* Bluetooth: HCI, SCO, L2CAP, RFCOMM */
+
+#define VKI_AF_IEEE80211    32              /* IEEE80211 */
+#define VKI_AF_MPLS         33              /* MultiProtocol Label Switching */
+#define VKI_AF_ROUTE        34              /* Internal Routing Protocol */
+#define VKI_AF_CAN          35
+#define VKI_AF_ETHER        36
+#define VKI_AF_MAX          37
+
+struct vki_sockaddr {
+        vki_uint8_t       sa_len;         /* total length */
+        vki_sa_family_t     sa_family;      /* address family */
+        char            sa_data[14];    /* actually longer; address value */
+};
+
+#define VKI__SS_MAXSIZE     128
+#define VKI__SS_ALIGNSIZE   (sizeof(vki_int64_t))
+#define VKI__SS_PAD1SIZE    (VKI__SS_ALIGNSIZE - 2)
+#define VKI__SS_PAD2SIZE    (VKI__SS_MAXSIZE - 2 - \
+                                VKI__SS_PAD1SIZE - VKI__SS_ALIGNSIZE)
+
+struct vki_sockaddr_storage {
+        vki_uint8_t       ss_len;         /* address length */
+        vki_sa_family_t     ss_family;      /* address family */
+        char            __ss_pad1[VKI__SS_PAD1SIZE];
+        vki_int64_t     __ss_align;/* force desired structure storage alignment */                                                                             
+        char            __ss_pad2[VKI__SS_PAD2SIZE];
+};
+
+#define vki_sstosa(__ss)    ((struct vki_sockaddr *)(__ss))
+#define vki_sstocsa(__ss)   ((const struct vki_sockaddr *)(__ss))
+
+#define VKI_PF_UNSPEC       VKI_AF_UNSPEC
+#define VKI_PF_LOCAL        VKI_AF_LOCAL  
+#define VKI_PF_UNIX         VKI_PF_LOCAL        /* backward compatibility */
+#define VKI_PF_INET         VKI_AF_INET
+#define VKI_PF_IMPLINK      VKI_AF_IMPLINK
+#define VKI_PF_PUP          VKI_AF_PUP
+#define VKI_PF_CHAOS        VKI_AF_CHAOS                                                                                                                             
+#define VKI_PF_NS           VKI_AF_NS
+#define VKI_PF_ISO          VKI_AF_ISO
+#define VKI_PF_OSI          VKI_AF_ISO
+#define VKI_PF_ECMA         VKI_AF_ECMA
+#define VKI_PF_DATAKIT      VKI_AF_DATAKIT
+#define VKI_PF_CCITT        VKI_AF_CCITT
+#define VKI_PF_SNA          VKI_AF_SNA
+#define VKI_PF_DECnet       VKI_AF_DECnet
+#define VKI_PF_CHAOS        VKI_AF_CHAOS                                                                                                                             
+#define VKI_PF_NS           VKI_AF_NS
+#define VKI_PF_ISO          VKI_AF_ISO
+#define VKI_PF_OSI          VKI_AF_ISO
+#define VKI_PF_ECMA         VKI_AF_ECMA
+#define VKI_PF_DATAKIT      VKI_AF_DATAKIT
+#define VKI_PF_CCITT        VKI_AF_CCITT
+#define VKI_PF_SNA          VKI_AF_SNA
+#define VKI_PF_DECnet       VKI_AF_DECnet
+#define VKI_PF_DLI          VKI_AF_DLI                                                                                                                               
+#define VKI_PF_LAT          VKI_AF_LAT
+#define VKI_PF_HYLINK       VKI_AF_HYLINK
+#define VKI_PF_APPLETALK    VKI_AF_APPLETALK
+#define VKI_PF_OROUTE       VKI_AF_OROUTE
+#define VKI_PF_LINK         VKI_AF_LINK
+
+#define VKI_PF_XTP          VKI_pseudo_AF_XTP   /* really just proto family, no AF */
+
+#define VKI_PF_COIP         VKI_AF_COIP                                                                                                                              
+#define VKI_PF_CNT          VKI_AF_CNT
+#define VKI_PF_INET6        VKI_AF_INET6
+#define VKI_PF_IPX          VKI_AF_IPX          /* same format as AF_NS */
+
+#define VKI_PF_RTIP         VKI_pseudo_AF_RTIP  /* same format as AF_INET */
+#define VKI_PF_PIP          VKI_pseudo_AF_PIP
+
+#define VKI_PF_ISDN         VKI_AF_ISDN         /* same as E164 */
+#define VKI_PF_E164         VKI_AF_E164                                                                                                                              
+#define VKI_PF_NATM         VKI_AF_NATM
+#define VKI_PF_ARP          VKI_AF_ARP
+
+#define VKI_PF_KEY          VKI_pseudo_AF_KEY   /* like PF_ROUTE, only for key mgmt */
+
+#define VKI_PF_BLUETOOTH    VKI_AF_BLUETOOTH
+#define VKI_PF_MPLS         VKI_AF_MPLS
+#define VKI_PF_ROUTE        VKI_AF_ROUTE
+#define VKI_PF_CAN          VKI_AF_CAN                                                                                                                               
+#define VKI_PF_ETHER        VKI_AF_ETHER
+
+#define VKI_PF_MAX          VKI_AF_MAX
+
+struct vki_sockcred {
+        vki_pid_t   sc_pid;                 /* process id */
+        vki_uid_t   sc_uid;                 /* real user id */
+        vki_uid_t   sc_euid;                /* effective user id */
+        vki_gid_t   sc_gid;                 /* real group id */
+        vki_gid_t   sc_egid;                /* effective group id */
+        int     sc_ngroups;             /* number of supplemental groups */
+        vki_gid_t   sc_groups[1];           /* variable length */
+};
+
+#define VKI_SOCKCREDSIZE(ngrps) \
+        (/*CONSTCOND*/sizeof(struct vki_sockcred) + (sizeof(vki_gid_t) * \
+            ((ngrps) ? ((ngrps) - 1) : 0)))
+
+struct vki_kinfo_pcb {
+        vki_uint64_t      ki_pcbaddr;     /* PTR: pcb addr */
+        vki_uint64_t      ki_ppcbaddr;    /* PTR: ppcb addr */
+        vki_uint64_t      ki_sockaddr;    /* PTR: socket addr */
+
+        vki_uint32_t      ki_family;      /* INT: protocol family */
+        vki_uint32_t      ki_type;        /* INT: socket type */
+        vki_uint32_t      ki_protocol;    /* INT: protocol */
+        vki_uint32_t      ki_pflags;      /* INT: generic protocol flags */
+
+        vki_uint32_t      ki_sostate;     /* INT: socket state */
+        vki_uint32_t      ki_prstate;     /* INT: protocol state */
+        vki_int32_t       ki_tstate;      /* INT: tcp state */
+        vki_uint32_t      ki_tflags;      /* INT: tcp flags */
+
+        vki_uint64_t      ki_rcvq;        /* U_LONG: receive queue len */
+        vki_uint64_t      ki_sndq;        /* U_LONG: send queue len */
+
+        union {
+                struct vki_sockaddr _kis_src; /* STRUCT: local address */
+                char _kis_pad[256 + 8];         /* pad to max addr length */
+        } ki_s;
+        union {
+                struct vki_sockaddr _kid_dst; /* STRUCT: remote address */
+                char _kid_pad[256 + 8];         /* pad to max addr length */
+        } ki_d;
+
+        vki_uint64_t      ki_inode;       /* INO_T: fake inode number */                                                                                       
+        vki_uint64_t      ki_vnode;       /* PTR: if associated with file */
+        vki_uint64_t      ki_conn;        /* PTR: control block of peer */
+        vki_uint64_t      ki_refs;        /* PTR: referencing socket */
+        vki_uint64_t      ki_nextref;     /* PTR: link in refs list */
+};
+
+#define ki_src ki_s._kis_src
+#define ki_dst ki_d._kid_dst
+#define ki_spad ki_s._kis_pad
+#define ki_dpad ki_d._kid_pad
+
+#define VKI_PCB_SLOP                20
+#define VKI_PCB_ALL                 0
+
+#define VKI_NET_RT_DUMP             1       /* dump; may limit to a.f. */
+#define VKI_NET_RT_FLAGS            2       /* by flags, e.g. RESOLVING */
+#define VKI_NET_RT_OOOIFLIST        3       /* old NET_RT_IFLIST (pre 1.5) */
+#define VKI_NET_RT_OOIFLIST         4       /* old NET_RT_IFLIST (pre-64bit time) */
+#define VKI_NET_RT_OIFLIST          5       /* old NET_RT_IFLIST (pre 8.0) */
+#define VKI_NET_RT_IFLIST           6       /* survey interface list */
+
+#ifndef VKI_SOMAXCONN
+#define VKI_SOMAXCONN       128
+#endif
+
+struct vki_msghdr {
+        void            *msg_name;      /* optional address */
+        vki_socklen_t       msg_namelen;    /* size of address */
+        struct vki_iovec    *msg_iov;       /* scatter/gather array */
+        int             msg_iovlen;     /* # elements in msg_iov */
+        void            *msg_control;   /* ancillary data, see below */
+        vki_socklen_t       msg_controllen; /* ancillary data buffer len */
+        int             msg_flags;      /* flags on received message */
+};
+
+#define VKI_MSG_OOB         0x0001          /* process out-of-band data */
+#define VKI_MSG_PEEK        0x0002          /* peek at incoming message */                                                                                       
+#define VKI_MSG_DONTROUTE   0x0004          /* send without using routing tables */
+#define VKI_MSG_EOR         0x0008          /* data completes record */
+#define VKI_MSG_TRUNC       0x0010          /* data discarded before delivery */
+#define VKI_MSG_CTRUNC      0x0020          /* control data lost before delivery */
+#define VKI_MSG_WAITALL     0x0040          /* wait for full request or error */
+#define VKI_MSG_DONTWAIT    0x0080          /* this message should be nonblocking */
+#define VKI_MSG_BCAST       0x0100          /* this message was rcvd using link-level brdcst */
+#define VKI_MSG_MCAST       0x0200          /* this message was rcvd using link-level mcast */
+#define VKI_MSG_NOSIGNAL    0x0400          /* do not generate SIGPIPE on EOF */                                                                                 
+
+#define VKI_MSG_CMSG_CLOEXEC 0x0800         /* close on exec receiving fd */
+#define VKI_MSG_NBIO        0x1000          /* use non-blocking I/O */
+#define VKI_MSG_WAITFORONE  0x2000          /* recvmmsg() wait for one message */
+#define VKI_MSG_NOTIFICATION 0x4000         /* SCTP notification */
+
+struct vki_mmsghdr {
+        struct vki_msghdr msg_hdr;
+        unsigned int msg_len;
+};
+
+#define VKI_MSG_USERFLAGS   0x0ffffff
+#define VKI_MSG_NAMEMBUF    0x1000000       /* msg_name is an mbuf */
+#define VKI_MSG_CONTROLMBUF 0x2000000       /* msg_control is an mbuf */
+#define VKI_MSG_IOVUSRSPACE 0x4000000       /* msg_iov is in user space */                                                                                       
+#define VKI_MSG_LENUSRSPACE 0x8000000       /* address length is in user space */
+
+struct vki_cmsghdr {
+        vki_socklen_t       cmsg_len;       /* data byte count, including hdr */
+        int             cmsg_level;     /* originating protocol */
+        int             cmsg_type;      /* protocol-specific type */
+/* followed by  u_char  cmsg_data[]; */
+};
+
+#define VKI___CMSG_ALIGN(n) (((n) + VKI___ALIGNBYTES) & ~VKI___ALIGNBYTES)
+
+#define VKI_CMSG_ALIGN(n) VKI___CMSG_ALIGN(n)
+
+#define VKI___CMSG_ASIZE    VKI___CMSG_ALIGN(sizeof(struct vki_cmsghdr))
+#define VKI___CMSG_MSGNEXT(cmsg) \
+    (VKI___CASTV(char *, cmsg) + VKI___CMSG_ALIGN((cmsg)->cmsg_len))
+#define VKI___CMSG_MSGEND(mhdr) \
+    (VKI___CASTV(char *, (mhdr)->msg_control) + (mhdr)->msg_controllen)
+
+/* given pointer to struct cmsghdr, return pointer to data */
+#define VKI_CMSG_DATA(cmsg) (VKI___CASTV(vki_u_char *, cmsg) + VKI___CMSG_ASIZE)
+#define VKI_CCMSG_DATA(cmsg) (VKI___CASTCV(const vki_u_char *, cmsg) + VKI___CMSG_ASIZE)
+
+#define VKI_CMSG_NXTHDR(mhdr, cmsg) \
+    VKI___CASTV(struct vki_cmsghdr *,  \
+        VKI___CMSG_MSGNEXT(cmsg) + VKI___CMSG_ASIZE > VKI___CMSG_MSGEND(mhdr) ? 0 : \
+        VKI___CMSG_MSGNEXT(cmsg))
+
+#define VKI_CMSG_FIRSTHDR(mhdr) \
+    VKI___CASTV(struct vki_cmsghdr *, \
+        (mhdr)->msg_controllen < sizeof(struct vki_cmsghdr) ? 0 : \
+        (mhdr)->msg_control)
+
+#define VKI_CMSG_SPACE(l)   (VKI___CMSG_ASIZE + VKI___CMSG_ALIGN(l))
+#define VKI_CMSG_LEN(l)     (VKI___CMSG_ASIZE + (l))
+
+
+/* "Socket"-level control message types: */
+#define VKI_SCM_RIGHTS      0x01            /* access rights (array of int) */
+
+#define VKI_SCM_TIMESTAMP   0x08            /* timestamp (struct timeval) */
+#define VKI_SCM_CREDS       0x10            /* credentials (struct sockcred) */
+
+#define VKI_SHUT_RD         0               /* Disallow further receives. */
+#define VKI_SHUT_WR         1               /* Disallow further sends. */                                                                                        
+#define VKI_SHUT_RDWR       2               /* Disallow further sends/receives. */
+
+//----------------------------------------------------------------------
+// From sys/signal.h
+//----------------------------------------------------------------------
+
+#define VKI__NSIG           64
+#define VKI_NSIG VKI__NSIG
+#define _VKI_NSIG VKI_NSIG // linux compat
+#define _VKI_NSIG_BPW   32 // linux compat?
+#define _VKI_NSIG_WORDS 4 // linux compat?
+
+#define VKI_SIGHUP          1       /* hangup */   
+#define VKI_SIGINT          2       /* interrupt */
+#define VKI_SIGQUIT         3       /* quit */
+#define VKI_SIGILL          4       /* illegal instruction (not reset when caught) */
+#define VKI_SIGTRAP         5       /* trace trap (not reset when caught) */
+#define VKI_SIGABRT         6       /* abort() */                                                                                                                
+#define VKI_SIGIOT          VKI_SIGABRT /* compatibility */
+#define VKI_SIGEMT          7       /* EMT instruction */
+#define VKI_SIGFPE          8       /* floating point exception */
+#define VKI_SIGKILL         9       /* kill (cannot be caught or ignored) */
+#define VKI_SIGBUS          10      /* bus error */
+#define VKI_SIGSEGV         11      /* segmentation violation */
+#define VKI_SIGSYS          12      /* bad argument to system call */
+#define VKI_SIGPIPE         13      /* write on a pipe with no one to read it */
+#define VKI_SIGALRM         14      /* alarm clock */                                                                                                            
+#define VKI_SIGTERM         15      /* software termination signal from kill */
+#define VKI_SIGURG          16      /* urgent condition on IO channel */
+#define VKI_SIGSTOP         17      /* sendable stop signal not from tty */
+#define VKI_SIGTSTP         18      /* stop signal from tty */
+#define VKI_SIGCONT         19      /* continue a stopped process */
+#define VKI_SIGCHLD         20      /* to parent on child stop or exit */
+#define VKI_SIGTTIN         21      /* to readers pgrp upon background tty read */
+#define VKI_SIGTTOU         22      /* like TTIN for output if (tp->t_local&LTOSTOP) */
+#define VKI_SIGIO           23      /* input/output possible signal */                                                                                           
+#define VKI_SIGXCPU         24      /* exceeded CPU time limit */
+#define VKI_SIGXFSZ         25      /* exceeded file size limit */
+#define VKI_SIGVTALRM       26      /* virtual time alarm */
+#define VKI_SIGPROF         27      /* profiling time alarm */
+#define VKI_SIGWINCH        28      /* window size changes */
+#define VKI_SIGINFO         29      /* information request */
+#define VKI_SIGUSR1         30      /* user defined signal 1 */
+#define VKI_SIGUSR2         31      /* user defined signal 2 */
+#define VKI_SIGPWR          32      /* power fail/restart (not reset when caught) */                                                                             
+#define VKI_SIGRTMIN        33
+#define VKI_SIGRTMAX        63
+
+#define VKI_SIG_DFL         ((void (*)(int))  0)
+#define VKI_SIG_IGN         ((void (*)(int))  1)
+#define VKI_SIG_ERR         ((void (*)(int)) -1)
+#define VKI_SIG_HOLD        ((void (*)(int))  3)
+
+struct  vki_sigaction {
+        union {
+                void (*_sa_handler)(int);
+                void (*_sa_sigaction)(int, vki_siginfo_t *, void *);
+        } _sa_u;        /* signal handler */
+        vki_sigset_t sa_mask;               /* signal mask to apply */  
+        int     sa_flags;               /* see signal options below */
+};
+
+typedef  struct vki_sigaction  vki_sigaction_toK_t; // compat with linux
+typedef  struct vki_sigaction  vki_sigaction_fromK_t; // compat with linux
+
+#define vki_sa_handler _sa_u._sa_handler
+#define ksa_handler    vki_sa_handler
+
+#define VKI_SA_RESTORER 0 /* linux compat, not supported */
+
+#define VKI_SA_ONSTACK      0x0001  /* take signal on signal stack */
+#define VKI_SA_RESTART      0x0002  /* restart system call on signal return */
+#define VKI_SA_RESETHAND    0x0004  /* reset to SIG_DFL when taking signal */
+#define VKI_SA_NODEFER      0x0010  /* don't mask the signal we're delivering */
+
+#define VKI_SA_ONESHOT VKI_SA_RESETHAND /* linux compat */
+#define VKI_SA_NOMASK VKI_SA_NODEFER /* linux compat */
+
+#define VKI_SA_NOCLDSTOP    0x0008  /* do not generate SIGCHLD on child stop */
+#define VKI_SA_NOCLDWAIT    0x0020  /* do not generate zombies on unwaited child */
+
+#define VKI_SA_SIGINFO      0x0040  /* take sa_sigaction handler */
+
+#define VKI_SA_NOKERNINFO   0x0080  /* siginfo does not print kernel info on tty */
+
+#define VKI_SIG_BLOCK       1       /* block specified signal set */
+#define VKI_SIG_UNBLOCK     2       /* unblock specified signal set */
+#define VKI_SIG_SETMASK     3       /* set specified signal set */
+
+#define VKI_SS_INIT 
+
+#define VKI_SS_ONSTACK      0x0001  /* take signals on alternate stack */
+#define VKI_SS_DISABLE      0x0004  /* disable taking signals on alternate stack */
+
+#define VKI_MINSIGSTKSZ     8192                    /* minimum allowable stack */
+#define VKI_SIGSTKSZ        (VKI_MINSIGSTKSZ + 32768)   /* recommended stack size */
+
+struct  vki_sigstack {
+        void    *ss_sp;                 /* signal stack pointer */
+        int     ss_onstack;             /* current status */
+};
+
+#define VKI_BADSIG          VKI_SIG_ERR
+
+struct  vki_sigevent {
+        int     sigev_notify;                                                                                                                                
+        int     sigev_signo;
+        union vki_sigval    sigev_value;
+        void    (*sigev_notify_function)(union vki_sigval);
+        void /* pthread_attr_t */       *sigev_notify_attributes;
+};
+
+#define VKI_SIGEV_NONE      0  
+#define VKI_SIGEV_SIGNAL    1
+#define VKI_SIGEV_THREAD    2
+
+#define VKI_SIGEV_SA        3
+
+//----------------------------------------------------------------------
+// From sys/ucontext.h
+//----------------------------------------------------------------------
+
+typedef struct vki___ucontext       vki_ucontext_t;
+
+struct vki___ucontext {
+        unsigned int    uc_flags;       /* properties */
+        vki_ucontext_t *    uc_link;        /* context to resume */
+        vki_sigset_t        uc_sigmask;     /* signals blocked in this context */ 
+        vki_stack_t         uc_stack;       /* the stack used by this context */ 
+        vki_mcontext_t      uc_mcontext;    /* machine state */
+#if defined(VKI__UC_MACHINE_PAD)
+        long            __uc_pad[VKI__UC_MACHINE_PAD];
+#endif
+};
+
+#define vki_ucontext vki___ucontext // compat with linux
+
+//----------------------------------------------------------------------
+// From sys/stat.h
+//----------------------------------------------------------------------
+
+struct vki_stat {
+        vki_dev_t     st_dev;               /* inode's device */
+        vki_mode_t    st_mode;              /* inode protection mode */
+        vki_ino_t     st_ino;               /* inode's number */
+        vki_nlink_t   st_nlink;             /* number of hard links */
+        vki_uid_t     st_uid;               /* user ID of the file's owner */
+        vki_gid_t     st_gid;               /* group ID of the file's group */
+        vki_dev_t     st_rdev;              /* device type */
+        struct    vki_timespec st_atim;     /* time of last access */
+        struct    vki_timespec st_mtim;     /* time of last data modification */
+        struct    vki_timespec st_ctim;     /* time of last file status change */
+        struct    vki_timespec st_birthtim; /* time of creation */
+        vki_off_t     st_size;              /* file size, in bytes */
+        vki_blkcnt_t  st_blocks;            /* blocks allocated for file */
+        vki_blksize_t st_blksize;           /* optimal blocksize for I/O */
+        vki_uint32_t  st_flags;             /* user defined flags for file */
+        vki_uint32_t  st_gen;               /* file generation number */
+        vki_uint32_t  st_spare[2];
+};
+
+#define st_atime                st_atim.tv_sec
+#define st_mtime                st_mtim.tv_sec
+#define st_ctime                st_ctim.tv_sec
+#define st_birthtime            st_birthtim.tv_sec
+
+#define st_atimespec            st_atim
+#define st_atimensec            st_atim.tv_nsec
+#define st_atime_nsec st_atimensec // linux compat
+#define st_mtimespec            st_mtim
+#define st_mtimensec            st_mtim.tv_nsec
+#define st_mtime_nsec st_mtimensec // linux compat
+#define st_ctimespec            st_ctim
+#define st_ctimensec            st_ctim.tv_nsec
+#define st_ctime_nsec st_ctimensec // linux compat
+#define st_birthtimespec        st_birthtim
+#define st_birthtimensec        st_birthtimespec.tv_nsec
+#define st_birthtime_nsec st_birthtimensec // linux compat
+
+#define VKI_S_ISUID 0004000                 /* set user id on execution */
+#define VKI_S_ISGID 0002000                 /* set group id on execution */
+
+#define VKI_S_ISTXT 0001000                 /* sticky bit */
+
+#define VKI_S_IRWXU 0000700                 /* RWX mask for owner */
+#define VKI_S_IRUSR 0000400                 /* R for owner */                                                                                                    
+#define VKI_S_IWUSR 0000200                 /* W for owner */
+#define VKI_S_IXUSR 0000100                 /* X for owner */
+
+#define VKI_S_IREAD         VKI_S_IRUSR
+#define VKI_S_IWRITE        VKI_S_IWUSR
+#define VKI_S_IEXEC         VKI_S_IXUSR
+#define VKI_S_IRWXG 0000070                 /* RWX mask for group */
+#define VKI_S_IRGRP 0000040                 /* R for group */
+#define VKI_S_IWGRP 0000020                 /* W for group */
+#define VKI_S_IXGRP 0000010                 /* X for group */
+
+#define VKI_S_IRWXO 0000007                 /* RWX mask for other */
+#define VKI_S_IROTH 0000004                 /* R for other */
+#define VKI_S_IWOTH 0000002                 /* W for other */
+#define VKI_S_IXOTH 0000001                 /* X for other */                                                                                                    
+
+#define VKI__S_IFMT   0170000               /* type of file mask */
+#define VKI__S_IFIFO  0010000               /* named pipe (fifo) */
+#define VKI__S_IFCHR  0020000               /* character special */
+#define VKI__S_IFDIR  0040000               /* directory */
+#define VKI__S_IFBLK  0060000               /* block special */
+#define VKI__S_IFREG  0100000               /* regular */
+#define VKI__S_IFLNK  0120000               /* symbolic link */
+#define VKI__S_ISVTX  0001000               /* save swapped text even after use */                                                                               
+#define VKI__S_IFSOCK 0140000               /* socket */
+#define VKI__S_IFWHT  0160000               /* whiteout */
+
+#define VKI__S_ARCH1  0200000               /* Archive state 1, ls -l shows 'a' */
+#define VKI__S_ARCH2  0400000               /* Archive state 2, ls -l shows 'A' */
+
+#define VKI_S_IFMT   VKI__S_IFMT
+#define VKI_S_IFIFO  VKI__S_IFIFO
+#define VKI_S_IFCHR  VKI__S_IFCHR                                                                                                                                    
+#define VKI_S_IFDIR  VKI__S_IFDIR
+#define VKI_S_IFBLK  VKI__S_IFBLK
+#define VKI_S_IFREG  VKI__S_IFREG
+#define VKI_S_IFLNK  VKI__S_IFLNK
+#define VKI_S_ISVTX  VKI__S_ISVTX
+
+#define VKI_S_IFSOCK VKI__S_IFSOCK
+
+#define VKI_S_IFWHT  VKI__S_IFWHT
+
+#define VKI_S_ARCH1 VKI__S_ARCH1 
+#define VKI_S_ARCH2 VKI__S_ARCH2 
+
+#define VKI_S_ISDIR(m)      (((m) & VKI__S_IFMT) == VKI__S_IFDIR)   /* directory */
+#define VKI_S_ISCHR(m)      (((m) & VKI__S_IFMT) == VKI__S_IFCHR)   /* char special */
+#define VKI_S_ISBLK(m)      (((m) & VKI__S_IFMT) == VKI__S_IFBLK)   /* block special */
+#define VKI_S_ISREG(m)      (((m) & VKI__S_IFMT) == VKI__S_IFREG)   /* regular file */
+#define VKI_S_ISFIFO(m)     (((m) & VKI__S_IFMT) == VKI__S_IFIFO)   /* fifo */
+
+#define VKI_S_ISLNK(m)      (((m) & VKI__S_IFMT) == VKI__S_IFLNK)   /* symbolic link */
+
+#define VKI_S_ISSOCK(m)     (((m) & VKI__S_IFMT) == VKI__S_IFSOCK)  /* socket */
+
+#define VKI_S_ISWHT(m)      (((m) & VKI__S_IFMT) == VKI__S_IFWHT)   /* whiteout */
+
+#define VKI_ACCESSPERMS     (VKI_S_IRWXU|VKI_S_IRWXG|VKI_S_IRWXO)       /* 0777 */
+                                                        /* 7777 */                                                                                           
+#define VKI_ALLPERMS        (VKI_S_ISUID|VKI_S_ISGID|VKI_S_ISTXT|VKI_S_IRWXU|VKI_S_IRWXG|VKI_S_IRWXO)
+                                                        /* 0666 */
+#define VKI_DEFFILEMODE     (VKI_S_IRUSR|VKI_S_IWUSR|VKI_S_IRGRP|VKI_S_IWGRP|VKI_S_IROTH|VKI_S_IWOTH)
+
+#define VKI_S_BLKSIZE       512             /* block size used in the stat struct */
+
+#define VKI_UF_SETTABLE     0x0000ffff      /* mask of owner changeable flags */
+#define VKI_UF_NODUMP       0x00000001      /* do not dump file */
+#define VKI_UF_IMMUTABLE    0x00000002      /* file may not be changed */
+#define VKI_UF_APPEND       0x00000004      /* writes to file may only append */
+#define VKI_UF_OPAQUE       0x00000008      /* directory is opaque wrt. union */
+
+#define VKI_SF_SETTABLE     0xffff0000      /* mask of superuser changeable flags */
+#define VKI_SF_ARCHIVED     0x00010000      /* file is archived */
+#define VKI_SF_IMMUTABLE    0x00020000      /* file may not be changed */
+#define VKI_SF_APPEND       0x00040000      /* writes to file may only append */
+/*      VKI_SF_NOUNLINK     0x00100000         [NOT IMPLEMENTED] */
+#define VKI_SF_SNAPSHOT     0x00200000      /* snapshot inode */
+#define VKI_SF_LOG          0x00400000      /* WAPBL log file inode */                                                                                           
+#define VKI_SF_SNAPINVAL    0x00800000      /* snapshot is invalid */
+
+#define VKI_UTIME_NOW       ((1 << 30) - 1)
+#define VKI_UTIME_OMIT      ((1 << 30) - 2)
+
+//----------------------------------------------------------------------
+// From sys/fntl.h
+//----------------------------------------------------------------------
+
+#define VKI_O_RDONLY        0x00000000      /* open for reading only */
+#define VKI_O_WRONLY        0x00000001      /* open for writing only */
+#define VKI_O_RDWR          0x00000002      /* open for reading and writing */
+#define VKI_O_ACCMODE       0x00000003      /* mask for above modes */
+
+#define VKI_FREAD           0x00000001
+#define VKI_FWRITE          0x00000002
+
+#define VKI_O_NONBLOCK      0x00000004      /* no delay */
+#define VKI_O_APPEND        0x00000008      /* set append mode */
+
+#define VKI_O_SHLOCK        0x00000010      /* open with shared file lock */
+#define VKI_O_EXLOCK        0x00000020      /* open with exclusive file lock */
+#define VKI_O_ASYNC         0x00000040      /* signal pgrp when data ready */
+
+#define VKI_O_SYNC          0x00000080      /* synchronous writes */
+
+#define VKI_O_NOFOLLOW      0x00000100      /* don't follow symlinks on the last */
+
+#define VKI_O_CREAT         0x00000200      /* create if nonexistent */
+#define VKI_O_TRUNC         0x00000400      /* truncate to zero length */
+#define VKI_O_EXCL          0x00000800      /* error if already exists */
+
+#define VKI_O_NOCTTY        0x00008000      /* don't assign controlling terminal */
+
+#define VKI_O_DSYNC         0x00010000      /* write: I/O data completion */
+#define VKI_O_RSYNC         0x00020000      /* read: I/O completion as for write */
+
+#define VKI_O_ALT_IO        0x00040000      /* use alternate i/o semantics */
+#define VKI_O_DIRECT        0x00080000      /* direct I/O hint */
+
+#define VKI_O_DIRECTORY     0x00200000      /* fail if not a directory */
+#define VKI_O_CLOEXEC       0x00400000      /* set close on exec */
+
+#define VKI_O_SEARCH        0x00800000      /* skip search permission checks */
+
+#define VKI_O_NOSIGPIPE     0x01000000      /* don't deliver sigpipe */
+#define VKI_O_REGULAR       0x02000000      /* fail if not a regular file */
+
+#define VKI_FAPPEND         VKI_O_APPEND        /* kernel/compat */
+#define VKI_FASYNC          VKI_O_ASYNC         /* kernel/compat */
+#define VKI_O_FSYNC         VKI_O_SYNC          /* compat */
+#define VKI_FNDELAY         VKI_O_NONBLOCK      /* compat */
+#define VKI_O_NDELAY        VKI_O_NONBLOCK      /* compat */
+
+#define VKI_F_DUPFD         0               /* duplicate file descriptor */
+#define VKI_F_GETFD         1               /* get file descriptor flags */
+#define VKI_F_SETFD         2               /* set file descriptor flags */
+#define VKI_F_GETFL         3               /* get file status flags */                                                                                          
+#define VKI_F_SETFL         4               /* set file status flags */
+
+#define VKI_F_GETOWN        5               /* get SIGIO/SIGURG proc/pgrp */
+#define VKI_F_SETOWN        6               /* set SIGIO/SIGURG proc/pgrp */
+
+#define VKI_F_GETLK         7               /* get record locking information */
+#define VKI_F_SETLK         8               /* set record locking information */
+#define VKI_F_SETLKW        9               /* F_SETLK; wait if blocked */ 
+
+#define VKI_F_CLOSEM        10              /* close all fds >= to the one given */
+#define VKI_F_MAXFD         11              /* return the max open fd */
+#define VKI_F_DUPFD_CLOEXEC 12              /* close on exec duplicated fd */
+#define VKI_F_GETNOSIGPIPE  13              /* get SIGPIPE disposition */
+#define VKI_F_SETNOSIGPIPE  14              /* set SIGPIPE disposition */
+
+#define VKI_FD_CLOEXEC      1               /* close-on-exec flag */
+
+#define VKI_F_RDLCK         1               /* shared or read lock */
+#define VKI_F_UNLCK         2               /* unlock */
+#define VKI_F_WRLCK         3               /* exclusive or write lock */
+
+#define VKI_F_PARAM_MASK    0xfff
+#define VKI_F_PARAM_LEN(x)  (((x) >> 16) & VKI_F_PARAM_MASK)
+#define VKI_F_PARAM_MAX     4095
+#define VKI_F_FSCTL         (int)0x80000000 /* This fcntl goes to the fs */                                                                                      
+#define VKI_F_FSVOID        (int)0x40000000 /* no parameters */
+#define VKI_F_FSOUT         (int)0x20000000 /* copy out parameter */
+#define VKI_F_FSIN          (int)0x10000000 /* copy in parameter */
+#define VKI_F_FSINOUT       (VKI_F_FSIN | VKI_F_FSOUT)
+#define VKI_F_FSDIRMASK     (int)0x70000000 /* mask for IN/OUT/VOID */
+#define VKI_F_FSPRIV        (int)0x00008000 /* command is fs-specific */
+
+#define VKI__FCN(inout, num, len) \
+                (VKI_F_FSCTL | inout | ((len & VKI_F_PARAM_MASK) << 16) | (num))
+#define VKI__FCNO(c)        VKI__FCN(F_FSVOID,  (c), 0)
+#define VKI__FCNR(c, t)     VKI__FCN(F_FSIN,    (c), (int)sizeof(t))
+#define VKI__FCNW(c, t)     VKI__FCN(F_FSOUT,   (c), (int)sizeof(t))
+#define VKI__FCNRW(c, t)    VKI__FCN(F_FSINOUT, (c), (int)sizeof(t))
+
+#define VKI__FCN_FSPRIV(inout, fs, num, len) \
+        (VKI_F_FSCTL | VKI_F_FSPRIV | inout | ((len & VKI_F_PARAM_MASK) << 16) |    \
+         (fs) << 8 | (num))
+#define VKI__FCNO_FSPRIV(f, c)      VKI__FCN_FSPRIV(F_FSVOID,  (f), (c), 0)
+#define VKI__FCNR_FSPRIV(f, c, t)   VKI__FCN_FSPRIV(F_FSIN,    (f), (c), (int)sizeof(t))
+#define VKI__FCNW_FSPRIV(f, c, t)   VKI__FCN_FSPRIV(F_FSOUT,   (f), (c), (int)sizeof(t))                                                                             
+#define VKI__FCNRW_FSPRIV(f, c, t)  VKI__FCN_FSPRIV(F_FSINOUT, (f), (c), (int)sizeof(t))
+
+struct vki_flock {                                                                                                                                               
+        vki_off_t   l_start;        /* starting offset */
+        vki_off_t   l_len;          /* len = 0 means until end of file */
+        vki_pid_t   l_pid;          /* lock owner */
+        short   l_type;         /* lock type: read/write, etc. */
+        short   l_whence;       /* type of l_start */
+};
+
+#define VKI_LOCK_SH         0x01            /* shared file lock */
+#define VKI_LOCK_EX         0x02            /* exclusive file lock */
+#define VKI_LOCK_NB         0x04            /* don't block when locking */
+#define VKI_LOCK_UN         0x08            /* unlock file */
+
+/* Always ensure that these are consistent with <stdio.h> and <unistd.h>! */
+#ifndef VKI_SEEK_SET
+#define VKI_SEEK_SET        0       /* set file offset to offset */
+#endif
+
+#ifndef VKI_SEEK_CUR
+#define VKI_SEEK_CUR        1       /* set file offset to current plus offset */
+#endif
+
+#ifndef VKI_SEEK_END
+#define VKI_SEEK_END        2       /* set file offset to EOF plus offset */
+#endif
+
+#define VKI_POSIX_FADV_NORMAL       0       /* default advice / no advice */
+#define VKI_POSIX_FADV_RANDOM       1       /* random access */
+#define VKI_POSIX_FADV_SEQUENTIAL   2       /* sequential access(lower to higher) */
+#define VKI_POSIX_FADV_WILLNEED     3       /* be needed in near future */
+#define VKI_POSIX_FADV_DONTNEED     4       /* not be needed in near future */                                                                                   
+#define VKI_POSIX_FADV_NOREUSE      5       /* be accessed once */
+
+#define VKI_AT_FDCWD                -100    /* Use cwd for relative link target */                                                                               
+#define VKI_AT_EACCESS              0x100   /* Use euig/egid for access checks */
+#define VKI_AT_SYMLINK_NOFOLLOW     0x200   /* Do not follow symlinks */
+#define VKI_AT_SYMLINK_FOLLOW       0x400   /* Follow symlinks */
+#define VKI_AT_REMOVEDIR            0x800   /* Remove directory only */
+
+//----------------------------------------------------------------------
+// From sys/errno.h
+//----------------------------------------------------------------------
+
+#define VKI_EPERM		1		/* Operation not permitted */
+#define VKI_ENOENT		2		/* No such file or directory */
+#define VKI_ESRCH		3		/* No such process */
+#define VKI_EINTR		4		/* Interrupted system call */
+#define VKI_EIO		5		/* Input/output error */
+#define VKI_ENXIO		6		/* Device not configured */
+#define VKI_E2BIG		7		/* Argument list too long */
+#define VKI_ENOEXEC		8		/* Exec format error */
+#define VKI_EBADF		9		/* Bad file descriptor */
+#define VKI_ECHILD		10		/* No child processes */
+#define VKI_EDEADLK		11		/* Resource deadlock avoided */
+#define VKI_ENOMEM		12		/* Cannot allocate memory */
+#define VKI_EACCES		13		/* Permission denied */
+#define VKI_EFAULT		14		/* Bad address */
+#define VKI_ENOTBLK		15		/* Block device required */
+#define VKI_EBUSY		16		/* Device busy */
+#define VKI_EEXIST		17		/* File exists */
+#define VKI_EXDEV		18		/* Cross-device link */
+#define VKI_ENODEV		19		/* Operation not supported by device */
+#define VKI_ENOTDIR		20		/* Not a directory */
+#define VKI_EISDIR		21		/* Is a directory */
+#define VKI_EINVAL		22		/* Invalid argument */
+#define VKI_ENFILE		23		/* Too many open files in system */
+#define VKI_EMFILE		24		/* Too many open files */
+#define VKI_ENOTTY		25		/* Inappropriate ioctl for device */
+#define VKI_ETXTBSY		26		/* Text file busy */
+#define VKI_EFBIG		27		/* File too large */
+#define VKI_ENOSPC		28		/* No space left on device */
+#define VKI_ESPIPE		29		/* Illegal seek */
+#define VKI_EROFS		30		/* Read-only file system */
+#define VKI_EMLINK		31		/* Too many links */
+#define VKI_EPIPE		32		/* Broken pipe */
+#define VKI_EDOM		33		/* Numerical argument out of domain */
+#define VKI_ERANGE		34		/* Result too large or too small */
+#define VKI_EAGAIN		35		/* Resource temporarily unavailable */
+#define VKI_EWOULDBLOCK	EAGAIN		/* Operation would block */
+#define VKI_EINPROGRESS	36		/* Operation now in progress */
+#define VKI_EALREADY	37		/* Operation already in progress */
+#define VKI_ENOTSOCK	38		/* Socket operation on non-socket */
+#define VKI_EDESTADDRREQ	39		/* Destination address required */
+#define VKI_EMSGSIZE	40		/* Message too long */
+#define VKI_EPROTOTYPE	41		/* Protocol wrong type for socket */
+#define VKI_ENOPROTOOPT	42		/* Protocol option not available */
+#define VKI_EPROTONOSUPPORT	43		/* Protocol not supported */
+#define VKI_ESOCKTNOSUPPORT	44		/* Socket type not supported */
+#define VKI_EOPNOTSUPP	45		/* Operation not supported */
+#define VKI_EPFNOSUPPORT	46		/* Protocol family not supported */
+#define VKI_EAFNOSUPPORT	47		/* Address family not supported by protocol family */
+#define VKI_EADDRINUSE	48		/* Address already in use */
+#define VKI_EADDRNOTAVAIL	49		/* Can't assign requested address */
+#define VKI_ENETDOWN	50		/* Network is down */
+#define VKI_ENETUNREACH	51		/* Network is unreachable */
+#define VKI_ENETRESET	52		/* Network dropped connection on reset */
+#define VKI_ECONNABORTED	53		/* Software caused connection abort */
+#define VKI_ECONNRESET	54		/* Connection reset by peer */
+#define VKI_ENOBUFS		55		/* No buffer space available */
+#define VKI_EISCONN		56		/* Socket is already connected */
+#define VKI_ENOTCONN	57		/* Socket is not connected */
+#define VKI_ESHUTDOWN	58		/* Can't send after socket shutdown */
+#define VKI_ETOOMANYREFS	59		/* Too many references: can't splice */
+#define VKI_ETIMEDOUT	60		/* Operation timed out */
+#define VKI_ECONNREFUSED	61		/* Connection refused */
+#define VKI_ELOOP		62		/* Too many levels of symbolic links */
+#define VKI_ENAMETOOLONG	63		/* File name too long */
+#define VKI_EHOSTDOWN	64		/* Host is down */
+#define VKI_EHOSTUNREACH	65		/* No route to host */
+#define VKI_ENOTEMPTY	66		/* Directory not empty */
+#define VKI_EPROCLIM	67		/* Too many processes */
+#define VKI_EUSERS		68		/* Too many users */
+#define VKI_EDQUOT		69		/* Disc quota exceeded */
+#define VKI_ESTALE		70		/* Stale NFS file handle */
+#define VKI_EREMOTE		71		/* Too many levels of remote in path */
+#define VKI_EBADRPC		72		/* RPC struct is bad */
+#define VKI_ERPCMISMATCH	73		/* RPC version wrong */
+#define VKI_EPROGUNAVAIL	74		/* RPC prog. not avail */
+#define VKI_EPROGMISMATCH	75		/* Program version wrong */
+#define VKI_EPROCUNAVAIL	76		/* Bad procedure for program */
+#define VKI_ENOLCK		77		/* No locks available */
+#define VKI_ENOSYS		78		/* Function not implemented */
+#define VKI_EFTYPE		79		/* Inappropriate file type or format */
+#define VKI_EAUTH		80		/* Authentication error */
+#define VKI_ENEEDAUTH	81		/* Need authenticator */
+#define VKI_EIDRM		82		/* Identifier removed */
+#define VKI_ENOMSG		83		/* No message of desired type */
+#define VKI_EOVERFLOW	84		/* Value too large to be stored in data type */
+#define VKI_EILSEQ		85		/* Illegal byte sequence */
+#define VKI_ENOTSUP		86		/* Not supported */
+#define VKI_ECANCELED	87		/* Operation canceled */
+#define VKI_EBADMSG		88		/* Bad or Corrupt message */
+#define VKI_ENODATA		89		/* No message available */
+#define VKI_ENOSR		90		/* No STREAM resources */
+#define VKI_ENOSTR		91		/* Not a STREAM */
+#define VKI_ETIME		92		/* STREAM ioctl timeout */
+#define VKI_ENOATTR		93		/* Attribute not found */
+#define VKI_EMULTIHOP	94		/* Multihop attempted */ 
+#define VKI_ENOLINK		95		/* Link has been severed */
+#define VKI_EPROTO		96		/* Protocol error */
+#define VKI_ELAST		96		/* Must equal largest errno */
+#define VKI_EJUSTRETURN	-2		/* don't modify regs, just return */
+#define VKI_ERESTART	-3		/* restart syscall */
+#define VKI_EPASSTHROUGH	-4		/* ioctl not handled by this layer */
+#define VKI_EDUPFD		-5		/* Dup given fd */
+#define VKI_EMOVEFD		-6		/* Move given fd */
+
+//----------------------------------------------------------------------
+// From unistd.h
+//----------------------------------------------------------------------
+
+#define VKI__POSIX_JOB_CONTROL      1
+
+#define VKI__POSIX_VERSION                  200112L
+#define VKI__POSIX2_VERSION                 200112L
+
+#define VKI__POSIX_SPAWN                    200809L
+
+#undef  VKI__POSIX_ADVISORY_INFO
+                                        /* asynchronous I/O is available */
+#define VKI__POSIX_ASYNCHRONOUS_IO          200112L
+                                        /* barriers */
+#define VKI__POSIX_BARRIERS                 200112L
+                                        /* chown requires correct privileges */
+#define VKI__POSIX_CHOWN_RESTRICTED         1
+                                        /* clock selection */
+#define VKI__POSIX_CLOCK_SELECTION          -1
+                                        /* cputime clock */
+#define VKI__POSIX_CPUTIME                  200112L
+                                        /* CPU type */
+#undef  VKI__POSIX_CPUTYPE
+                                        /* file synchronization is available */
+#define VKI__POSIX_FSYNC                    1
+
+                                        /* support IPv6 */                                                                                                   
+#define VKI__POSIX_IPV6                     0
+                                        /* job control is available */
+#define VKI__POSIX_JOB_CONTROL              1
+                                        /* memory mapped files */
+#define VKI__POSIX_MAPPED_FILES             1
+                                        /* memory locking whole address space */
+#define VKI__POSIX_MEMLOCK                  1
+                                        /* memory locking address ranges */
+#define VKI__POSIX_MEMLOCK_RANGE            1                                                                                                                    
+                                        /* memory access protections */
+#define VKI__POSIX_MEMORY_PROTECTION        1
+                                        /* message passing is available */
+#define VKI__POSIX_MESSAGE_PASSING          200112L
+                                        /* monotonic clock */
+#define VKI__POSIX_MONOTONIC_CLOCK          200112L
+                                        /* too-long path comp generate errors */
+#define VKI__POSIX_NO_TRUNC                 1
+
+
+                                        /* prioritized I/O */                                                                                                
+#define VKI__POSIX_PRIORITIZED_IO           -1
+                                        /* priority scheduling */
+#define VKI__POSIX_PRIORITY_SCHEDULING      200112L
+                                        /* raw sockets */
+#define VKI__POSIX_RAW_SOCKETS              200112L
+                                        /* read/write locks */
+#define VKI__POSIX_READER_WRITER_LOCKS      200112L
+                                        /* realtime signals */
+#undef  VKI__POSIX_REALTIME_SIGNALS                                                                                                                              
+                                        /* regular expressions */
+#define VKI__POSIX_REGEXP                   1
+                                        /* semaphores */
+#define VKI__POSIX_SEMAPHORES               0
+                                        /* shared memory objects */
+#define VKI__POSIX_SHARED_MEMORY_OBJECTS    0
+                                        /* shell */
+#define VKI__POSIX_SHELL                    1
+
+
+                                        /* spin locks */                                                                                                     
+#define VKI__POSIX_SPIN_LOCKS               200112L
+                                        /* sporadic server */
+#undef  VKI__POSIX_SPORADIC_SERVER
+                                        /* synchronized I/O is available */
+#define VKI__POSIX_SYNCHRONIZED_IO          1
+                                        /* threads */
+#define VKI__POSIX_THREADS                  200112L
+                                        /* pthread_attr for stack size */
+#define VKI__POSIX_THREAD_ATTR_STACKSIZE    200112L                                                                                                              
+                                        /* pthread_attr for stack address */
+#define VKI__POSIX_THREAD_ATTR_STACKADDR    200112L
+                                        /* thread cputime clock */
+#define VKI__POSIX_THREAD_CPUTIME           200112L
+                                        /* _r functions */
+#define VKI__POSIX_THREAD_PRIO_PROTECT      200112L
+                                        /* PTHREAD_PRIO_PROTECT */
+#define VKI__POSIX_THREAD_SAFE_FUNCTIONS    200112L
+
+                                        /* timeouts */                                                                                                       
+#undef  VKI__POSIX_TIMEOUTS
+                                        /* timers */
+#define VKI__POSIX_TIMERS                   200112L
+                                        /* typed memory objects */
+#undef  VKI__POSIX_TYPED_MEMORY_OBJECTS
+                                        /* may disable terminal spec chars */
+#define VKI__POSIX_VDISABLE                 ((unsigned char)'\377')
+
+                                        /* C binding */                                                                                                      
+#define VKI__POSIX2_C_BIND                  200112L
+
+                                        /* XPG4.2 shared memory */
+#define VKI__XOPEN_SHM                      0
+
+/* access function */
+#define VKI_F_OK            0       /* test for existence of file */
+#define VKI_X_OK            0x01    /* test for execute or search permission */
+#define VKI_W_OK            0x02    /* test for write permission */                                                                                              
+#define VKI_R_OK            0x04    /* test for read permission */
+
+/* whence values for lseek(2) */
+#define VKI_SEEK_SET        0       /* set file offset to offset */
+#define VKI_SEEK_CUR        1       /* set file offset to current plus offset */
+#define VKI_SEEK_END        2       /* set file offset to EOF plus offset */
+
+#define VKI_L_SET           VKI_SEEK_SET
+#define VKI_L_INCR          VKI_SEEK_CUR
+#define VKI_L_XTND          VKI_SEEK_END
+
+#define VKI_FDATASYNC       0x0010  /* sync data and minimal metadata */
+#define VKI_FFILESYNC       0x0020  /* sync data and metadata */
+#define VKI_FDISKSYNC       0x0040  /* flush disk caches after sync */
+
+#define VKI__PC_LINK_MAX             1
+#define VKI__PC_MAX_CANON            2
+#define VKI__PC_MAX_INPUT            3
+#define VKI__PC_NAME_MAX             4
+#define VKI__PC_PATH_MAX             5
+#define VKI__PC_PIPE_BUF             6
+#define VKI__PC_CHOWN_RESTRICTED     7
+#define VKI__PC_NO_TRUNC             8                                                                                                                           
+#define VKI__PC_VDISABLE             9
+#define VKI__PC_SYNC_IO             10
+#define VKI__PC_FILESIZEBITS        11
+#define VKI__PC_SYMLINK_MAX         12
+#define VKI__PC_2_SYMLINKS          13
+#define VKI__PC_ACL_EXTENDED        14
+
+#define VKI__PC_MIN_HOLE_SIZE       15 
+
+#define VKI__SC_ARG_MAX              1
+#define VKI__SC_CHILD_MAX            2
+#define VKI__O_SC_CLK_TCK            3 /* Old version, always 100 */
+#define VKI__SC_NGROUPS_MAX          4
+#define VKI__SC_OPEN_MAX             5
+#define VKI__SC_JOB_CONTROL          6
+#define VKI__SC_SAVED_IDS            7
+#define VKI__SC_VERSION              8
+#define VKI__SC_BC_BASE_MAX          9
+#define VKI__SC_BC_DIM_MAX          10
+#define VKI__SC_BC_SCALE_MAX        11
+#define VKI__SC_BC_STRING_MAX       12
+#define VKI__SC_COLL_WEIGHTS_MAX    13
+#define VKI__SC_EXPR_NEST_MAX       14
+#define VKI__SC_LINE_MAX            15
+#define VKI__SC_RE_DUP_MAX          16
+#define VKI__SC_2_VERSION           17
+#define VKI__SC_2_C_BIND            18
+#define VKI__SC_2_C_DEV             19                                                                                                                           
+#define VKI__SC_2_CHAR_TERM         20
+#define VKI__SC_2_FORT_DEV          21
+#define VKI__SC_2_FORT_RUN          22
+#define VKI__SC_2_LOCALEDEF         23
+#define VKI__SC_2_SW_DEV            24
+#define VKI__SC_2_UPE               25
+#define VKI__SC_STREAM_MAX          26
+#define VKI__SC_TZNAME_MAX          27
+#define VKI__SC_PAGESIZE            28                                                                                                                           
+#define VKI__SC_PAGE_SIZE           VKI__SC_PAGESIZE    /* 1170 compatibility */
+#define VKI__SC_FSYNC               29
+#define VKI__SC_XOPEN_SHM           30
+#define VKI__SC_SYNCHRONIZED_IO     31
+#define VKI__SC_IOV_MAX             32
+#define VKI__SC_MAPPED_FILES        33
+#define VKI__SC_MEMLOCK             34
+#define VKI__SC_MEMLOCK_RANGE       35
+#define VKI__SC_MEMORY_PROTECTION   36                                                                                                                           
+#define VKI__SC_LOGIN_NAME_MAX      37
+#define VKI__SC_MONOTONIC_CLOCK     38
+#define VKI__SC_CLK_TCK             39 /* New, variable version */
+#define VKI__SC_ATEXIT_MAX          40
+#define VKI__SC_THREADS             41
+#define VKI__SC_SEMAPHORES          42
+#define VKI__SC_BARRIERS            43
+#define VKI__SC_TIMERS              44
+#define VKI__SC_SPIN_LOCKS          45                                                                                                                           
+#define VKI__SC_READER_WRITER_LOCKS 46
+#define VKI__SC_GETGR_R_SIZE_MAX    47
+#define VKI__SC_GETPW_R_SIZE_MAX    48
+#define VKI__SC_CLOCK_SELECTION     49
+#define VKI__SC_ASYNCHRONOUS_IO     50
+#define VKI__SC_AIO_LISTIO_MAX      51
+#define VKI__SC_AIO_MAX             52
+#define VKI__SC_MESSAGE_PASSING     53
+#define VKI__SC_MQ_OPEN_MAX         54                                                                                                                           
+#define VKI__SC_MQ_PRIO_MAX         55
+#define VKI__SC_PRIORITY_SCHEDULING 56
+#define VKI__SC_THREAD_DESTRUCTOR_ITERATIONS 57
+#define VKI__SC_THREAD_KEYS_MAX             58
+#define VKI__SC_THREAD_STACK_MIN            59
+#define VKI__SC_THREAD_THREADS_MAX          60
+#define VKI__SC_THREAD_ATTR_STACKADDR       61
+#define VKI__SC_THREAD_ATTR_STACKSIZE       62
+#define VKI__SC_THREAD_PRIORITY_SCHEDULING  63                                                                                                                   
+#define VKI__SC_THREAD_PRIO_INHERIT         64
+#define VKI__SC_THREAD_PRIO_PROTECT         65
+#define VKI__SC_THREAD_PROCESS_SHARED       66
+#define VKI__SC_THREAD_SAFE_FUNCTIONS       67
+#define VKI__SC_TTY_NAME_MAX                68
+#define VKI__SC_HOST_NAME_MAX               69
+#define VKI__SC_PASS_MAX                    70
+#define VKI__SC_REGEXP                      71
+#define VKI__SC_SHELL                       72                                                                                                                   
+#define VKI__SC_SYMLOOP_MAX                 73
+
+/* Actually, they are not supported or implemented yet */
+#define VKI__SC_V6_ILP32_OFF32              74
+#define VKI__SC_V6_ILP32_OFFBIG             75
+#define VKI__SC_V6_LP64_OFF64               76
+#define VKI__SC_V6_LPBIG_OFFBIG             77
+#define VKI__SC_2_PBS                       80
+#define VKI__SC_2_PBS_ACCOUNTING            81                                                                                                                   
+#define VKI__SC_2_PBS_CHECKPOINT            82
+#define VKI__SC_2_PBS_LOCATE                83
+#define VKI__SC_2_PBS_MESSAGE               84
+#define VKI__SC_2_PBS_TRACK                 85
+
+/* These are implemented */
+#define VKI__SC_SPAWN                       86
+#define VKI__SC_SHARED_MEMORY_OBJECTS       87
+#define VKI__SC_TIMER_MAX                   88
+#define VKI__SC_SEM_NSEMS_MAX               89
+#define VKI__SC_CPUTIME                     90
+#define VKI__SC_THREAD_CPUTIME              91
+#define VKI__SC_DELAYTIMER_MAX              92
+#define VKI__SC_SIGQUEUE_MAX                93
+#define VKI__SC_REALTIME_SIGNALS            94
+
+/* Extensions found in Solaris and Linux. */                                                                                                                 
+#define VKI__SC_PHYS_PAGES          121
+
+/* Commonly provided sysconf() extensions */
+#define VKI__SC_NPROCESSORS_CONF    1001
+#define VKI__SC_NPROCESSORS_ONLN    1002
+/* Native variables */
+#define VKI__SC_SCHED_RT_TS         2001
+#define VKI__CS_PATH                 1
+
+//----------------------------------------------------------------------
+// From netinet/in.h
+//----------------------------------------------------------------------
+
+typedef vki___in_addr_t     vki_in_addr_t;
+typedef vki___in_port_t     vki_in_port_t;
+typedef vki___sa_family_t   vki_sa_family_t;
+
+#define VKI_IPPROTO_IP              0               /* dummy for IP */
+#define VKI_IPPROTO_HOPOPTS         0               /* IP6 hop-by-hop options */
+#define VKI_IPPROTO_ICMP            1               /* control message protocol */
+#define VKI_IPPROTO_IGMP            2               /* group mgmt protocol */
+#define VKI_IPPROTO_GGP             3               /* gateway^2 (deprecated) */
+#define VKI_IPPROTO_IPV4            4               /* IP header */
+#define VKI_IPPROTO_IPIP            4               /* IP inside IP */
+#define VKI_IPPROTO_TCP             6               /* tcp */
+#define VKI_IPPROTO_EGP             8               /* exterior gateway protocol */
+#define VKI_IPPROTO_PUP             12              /* pup */
+#define VKI_IPPROTO_UDP             17              /* user datagram protocol */
+#define VKI_IPPROTO_IDP             22              /* xns idp */
+#define VKI_IPPROTO_TP              29              /* tp-4 w/ class negotiation */
+#define VKI_IPPROTO_DCCP            33              /* DCCP */
+#define VKI_IPPROTO_IPV6            41              /* IP6 header */
+#define VKI_IPPROTO_ROUTING         43              /* IP6 routing header */
+#define VKI_IPPROTO_FRAGMENT        44              /* IP6 fragmentation header */
+#define VKI_IPPROTO_RSVP            46              /* resource reservation */
+#define VKI_IPPROTO_GRE             47              /* GRE encaps RFC 1701 */                                                                                    
+#define VKI_IPPROTO_ESP             50              /* encap. security payload */
+#define VKI_IPPROTO_AH              51              /* authentication header */
+#define VKI_IPPROTO_MOBILE          55              /* IP Mobility RFC 2004 */
+#define VKI_IPPROTO_IPV6_ICMP       58              /* IPv6 ICMP */
+#define VKI_IPPROTO_ICMPV6          58              /* ICMP6 */
+#define VKI_IPPROTO_NONE            59              /* IP6 no next header */
+#define VKI_IPPROTO_DSTOPTS         60              /* IP6 destination option */
+#define VKI_IPPROTO_EON             80              /* ISO cnlp */
+#define VKI_IPPROTO_ETHERIP         97              /* Ethernet-in-IP */                                                                                         
+#define VKI_IPPROTO_ENCAP           98              /* encapsulation header */
+#define VKI_IPPROTO_PIM             103             /* Protocol indep. multicast */
+#define VKI_IPPROTO_IPCOMP          108             /* IP Payload Comp. Protocol */
+#define VKI_IPPROTO_VRRP            112             /* VRRP RFC 2338 */
+#define VKI_IPPROTO_CARP            112             /* Common Address Resolution Protocol */
+#define VKI_IPPROTO_L2TP            115             /* L2TPv3 */
+#define VKI_IPPROTO_SCTP            132             /* SCTP */
+#define VKI_IPPROTO_PFSYNC      240     /* PFSYNC */
+#define VKI_IPPROTO_RAW             255             /* raw IP packet */                                                                                          
+#define VKI_IPPROTO_MAX             256
+
+/* last return value of *_input(), meaning "all job for this pkt is done".  */
+#define VKI_IPPROTO_DONE            257
+
+/* sysctl placeholder for (FAST_)IPSEC */
+#define VKI_CTL_IPPROTO_IPSEC       258
+
+#define VKI_IPPORT_RESERVED         1024
+#define VKI_IPPORT_ANONMIN          49152
+#define VKI_IPPORT_ANONMAX          65535
+#define VKI_IPPORT_RESERVEDMIN      600
+#define VKI_IPPORT_RESERVEDMAX      (VKI_IPPORT_RESERVED-1)
+
+struct vki_in_addr {
+        vki_in_addr_t s_addr;
+} __attribute__((__packed__));
+
+#define VKI___IPADDR(x)     ((vki_uint32_t)(x))
+
+#define VKI_IN_CLASSA(i)            (((vki_uint32_t)(i) & VKI___IPADDR(0x80000000)) == \
+                                 VKI___IPADDR(0x00000000))
+#define VKI_IN_CLASSA_NET           VKI___IPADDR(0xff000000)
+#define VKI_IN_CLASSA_NSHIFT        24                                                                                                                           
+#define VKI_IN_CLASSA_HOST          VKI___IPADDR(0x00ffffff)
+#define VKI_IN_CLASSA_MAX           128
+
+#define VKI_IN_CLASSB(i)            (((vki_uint32_t)(i) & VKI___IPADDR(0xc0000000)) == \
+                                 VKI___IPADDR(0x80000000))
+#define VKI_IN_CLASSB_NET           VKI___IPADDR(0xffff0000)
+#define VKI_IN_CLASSB_NSHIFT        16
+#define VKI_IN_CLASSB_HOST          VKI___IPADDR(0x0000ffff)
+
+#define VKI_IN_CLASSB_MAX           65536                                                                                                                        
+
+#define VKI_IN_CLASSC(i)            (((vki_uint32_t)(i) & VKI___IPADDR(0xe0000000)) == \
+                                 VKI___IPADDR(0xc0000000))
+#define VKI_IN_CLASSC_NET           VKI___IPADDR(0xffffff00)
+#define VKI_IN_CLASSC_NSHIFT        8
+#define VKI_IN_CLASSC_HOST          VKI___IPADDR(0x000000ff)
+
+#define VKI_IN_CLASSD(i)            (((vki_uint32_t)(i) & VKI___IPADDR(0xf0000000)) == \
+                                 VKI___IPADDR(0xe0000000))                                                                                                       
+/* These ones aren't really net and host fields, but routing needn't know. */
+#define VKI_IN_CLASSD_NET           VKI___IPADDR(0xf0000000)
+#define VKI_IN_CLASSD_NSHIFT        28
+#define VKI_IN_CLASSD_HOST          VKI___IPADDR(0x0fffffff)
+#define VKI_IN_MULTICAST(i)         VKI_IN_CLASSD(i)
+
+#define VKI_IN_EXPERIMENTAL(i)      (((vki_uint32_t)(i) & VKI___IPADDR(0xf0000000)) == \
+                                 VKI___IPADDR(0xf0000000))
+
+#define VKI_IN_BADCLASS(i)          (((vki_uint32_t)(i) & VKI___IPADDR(0xf0000000)) == \
+                                 VKI___IPADDR(0xf0000000))
+
+#define VKI_IN_LINKLOCAL(i) (((vki_uint32_t)(i) & VKI___IPADDR(0xffff0000)) == \
+                         VKI___IPADDR(0xa9fe0000))
+
+#define VKI_IN_PRIVATE(i)   ((((vki_uint32_t)(i) & VKI___IPADDR(0xff000000)) ==     \
+                          VKI___IPADDR(0x0a000000)) ||                      \
+                         (((vki_uint32_t)(i) & VKI___IPADDR(0xfff00000)) ==     \
+                          VKI___IPADDR(0xac100000)) ||                      \
+                         (((vki_uint32_t)(i) & VKI___IPADDR(0xffff0000)) ==     \
+                          VKI___IPADDR(0xc0a80000)))
+
+#define VKI_IN_LOCAL_GROUP(i)       (((vki_uint32_t)(i) & VKI___IPADDR(0xffffff00)) == \
+                                 VKI___IPADDR(0xe0000000))
+
+#define VKI_IN_ANY_LOCAL(i)         (VKI_IN_LINKLOCAL(i) || VKI_IN_LOCAL_GROUP(i))
+
+#define VKI_INADDR_ANY              VKI___IPADDR(0x00000000)                                                                                                         
+#define VKI_INADDR_LOOPBACK         VKI___IPADDR(0x7f000001)
+#define VKI_INADDR_BROADCAST        VKI___IPADDR(0xffffffff)    /* must be masked */
+#define VKI_INADDR_NONE             VKI___IPADDR(0xffffffff)    /* -1 return */
+
+#define VKI_INADDR_UNSPEC_GROUP     VKI___IPADDR(0xe0000000)    /* 224.0.0.0 */
+#define VKI_INADDR_ALLHOSTS_GROUP   VKI___IPADDR(0xe0000001)    /* 224.0.0.1 */
+#define VKI_INADDR_ALLRTRS_GROUP    VKI___IPADDR(0xe0000002)    /* 224.0.0.2 */
+#define VKI_INADDR_CARP_GROUP       VKI___IPADDR(0xe0000012)    /* 224.0.0.18 */
+#define VKI_INADDR_MAX_LOCAL_GROUP  VKI___IPADDR(0xe00000ff)    /* 224.0.0.255 */                                                                                    
+
+#define VKI_IN_LOOPBACKNET          127                     /* official! */
+
+struct vki_sockaddr_in {
+        vki_uint8_t         sin_len;
+        vki_sa_family_t     sin_family;
+        vki_in_port_t       sin_port;
+        struct vki_in_addr  sin_addr;
+        vki_int8_t        sin_zero[8];
+};
+
+#define VKI_INET_ADDRSTRLEN                 16
+
+struct vki_ip_opts {
+        struct vki_in_addr  ip_dst;         /* first hop, 0 w/o src rt */
+        vki_int8_t        ip_opts[40];    /* actually variable in size */
+};
+
+#define VKI_IP_OPTIONS              1    /* buf/ip_opts; set/get IP options */
+#define VKI_IP_HDRINCL              2    /* int; header is included with data */
+#define VKI_IP_TOS                  3    /* int; IP type of service and preced. */
+#define VKI_IP_TTL                  4    /* int; IP time to live */
+#define VKI_IP_RECVOPTS             5    /* bool; receive all IP opts w/dgram */
+#define VKI_IP_RECVRETOPTS          6    /* bool; receive IP opts for response */
+#define VKI_IP_RECVDSTADDR          7    /* bool; receive IP dst addr w/dgram */
+#define VKI_IP_RETOPTS              8    /* ip_opts; set/get IP options */
+#define VKI_IP_MULTICAST_IF         9    /* in_addr; set/get IP multicast i/f  */                                                                                
+#define VKI_IP_MULTICAST_TTL        10   /* u_char; set/get IP multicast ttl */
+#define VKI_IP_MULTICAST_LOOP       11   /* u_char; set/get IP multicast loopback */
+/* The add and drop membership option numbers need to match with the v6 ones */
+#define VKI_IP_ADD_MEMBERSHIP       12   /* ip_mreq; add an IP group membership */
+#define VKI_IP_DROP_MEMBERSHIP      13   /* ip_mreq; drop an IP group membership */
+#define VKI_IP_PORTALGO             18   /* int; port selection algo (rfc6056) */
+#define VKI_IP_PORTRANGE            19   /* int; range to use for ephemeral port */
+#define VKI_IP_RECVIF               20   /* bool; receive reception if w/dgram */
+
+#define VKI_IP_ERRORMTU             21   /* int; get MTU of last xmit = EMSGSIZE */                                                                              
+#define VKI_IP_IPSEC_POLICY         22   /* struct; get/set security policy */
+#define VKI_IP_RECVTTL              23   /* bool; receive IP TTL w/dgram */
+#define VKI_IP_MINTTL               24   /* minimum TTL for packet or drop */
+#define VKI_IP_PKTINFO              25   /* struct; set default src if/addr */
+#define VKI_IP_RECVPKTINFO          26   /* int; receive dst if/addr w/dgram */
+
+#define VKI_IP_SENDSRCADDR VKI_IP_RECVDSTADDR /* FreeBSD compatibility */
+
+/*                                                                                                                                                           
+ * Information sent in the control message of a datagram socket for
+ * IP_PKTINFO and IP_RECVPKTINFO.
+ */
+struct vki_in_pktinfo {
+        struct vki_in_addr  ipi_addr;       /* src/dst address */
+        unsigned int ipi_ifindex;       /* interface index */
+};
+
+#define ipi_spec_dst ipi_addr   /* Solaris/Linux compatibility */                                                                                            
+
+/*
+ * Defaults and limits for options
+ */
+#define VKI_IP_DEFAULT_MULTICAST_TTL  1     /* normally limit m'casts to 1 hop  */
+#define VKI_IP_DEFAULT_MULTICAST_LOOP 1     /* normally hear sends if a member  */
+#define VKI_IP_MAX_MEMBERSHIPS      20      /* per socket; must fit in one mbuf */
+
+/*                                                                                                                                                           
+ * Argument structure for IP_ADD_MEMBERSHIP and IP_DROP_MEMBERSHIP.
+ */
+struct vki_ip_mreq {
+        struct  vki_in_addr imr_multiaddr;  /* IP multicast address of group */
+        struct  vki_in_addr imr_interface;  /* local IP address of interface */
+};
+
+#define VKI_IP_PORTRANGE_DEFAULT    0       /* default range */
+#define VKI_IP_PORTRANGE_HIGH       1       /* same as DEFAULT (FreeBSD compat) */
+#define VKI_IP_PORTRANGE_LOW        2       /* use privileged range */
+
+#define VKI_IPCTL_FORWARDING        1       /* act as router */                                                                                                  
+#define VKI_IPCTL_SENDREDIRECTS     2       /* may send redirects when forwarding */
+#define VKI_IPCTL_DEFTTL            3       /* default TTL */
+/* IPCTL_DEFMTU=4, never implemented */
+#define VKI_IPCTL_FORWSRCRT         5       /* forward source-routed packets */
+#define VKI_IPCTL_DIRECTEDBCAST     6       /* default broadcast behavior */
+#define VKI_IPCTL_ALLOWSRCRT        7       /* allow/drop all source-routed pkts */
+#define VKI_IPCTL_SUBNETSARELOCAL   8       /* treat subnets as local addresses */
+#define VKI_IPCTL_MTUDISC           9       /* allow path MTU discovery */
+
+#define VKI_IPCTL_ANONPORTMIN      10       /* minimum ephemeral port */                                                                                         
+#define VKI_IPCTL_ANONPORTMAX      11       /* maximum ephemeral port */
+#define VKI_IPCTL_MTUDISCTIMEOUT   12       /* allow path MTU discovery */
+#define VKI_IPCTL_MAXFLOWS         13       /* maximum ip flows allowed */
+#define VKI_IPCTL_HOSTZEROBROADCAST 14      /* is host zero a broadcast addr? */
+#define VKI_IPCTL_GIF_TTL          15       /* default TTL for gif encap packet */
+#define VKI_IPCTL_LOWPORTMIN       16       /* minimum reserved port */
+#define VKI_IPCTL_LOWPORTMAX       17       /* maximum reserved port */
+#define VKI_IPCTL_MAXFRAGPACKETS   18       /* max packets reassembly queue */
+
+#define VKI_IPCTL_GRE_TTL          19       /* default TTL for gre encap packet */                                                                               
+#define VKI_IPCTL_CHECKINTERFACE   20       /* drop pkts in from 'wrong' iface */
+#define VKI_IPCTL_IFQ              21       /* IP packet input queue */
+#define VKI_IPCTL_RANDOMID         22       /* use random IP ids (if configured) */
+#define VKI_IPCTL_LOOPBACKCKSUM    23       /* do IP checksum on loopback */
+#define VKI_IPCTL_STATS             24      /* IP statistics */
+#define VKI_IPCTL_DAD_COUNT        25       /* DAD packets to send */
+
+//----------------------------------------------------------------------
+// From netinet/mman.h
+//----------------------------------------------------------------------
+
+#define VKI_PROT_NONE       0x00    /* no permissions */
+#define VKI_PROT_READ       0x01    /* pages can be read */
+#define VKI_PROT_WRITE      0x02    /* pages can be written */
+#define VKI_PROT_EXEC       0x04    /* pages can be executed */
+
+#define VKI_PROT_MPROTECT(x)                ((x) << 3)
+#define VKI_PROT_MPROTECT_EXTRACT(x)        (((x) >> 3) & 0x7)
+
+#define VKI_MAP_SHARED      0x0001  /* share changes */
+#define VKI_MAP_PRIVATE     0x0002  /* changes are private */
+        /* old MAP_COPY 0x0004     "copy" region at mmap time */
+
+#define VKI_MAP_REMAPDUP     0x0004 /* mremap only: duplicate the mapping */
+#define VKI_MAP_FIXED        0x0010 /* map addr must be exactly as requested */
+#define VKI_MAP_RENAME       0x0020 /* Sun: rename private pages to file */
+#define VKI_MAP_NORESERVE    0x0040 /* Sun: don't reserve needed swap area */
+#define VKI_MAP_INHERIT      0x0080 /* region is retained after exec */
+#define VKI_MAP_HASSEMAPHORE 0x0200 /* region may contain semaphores */
+#define VKI_MAP_TRYFIXED     0x0400 /* attempt hint address, even within break */                                                                                
+#define VKI_MAP_WIRED        0x0800 /* mlock() mapping when it is established */
+
+#define VKI_MAP_FILE        0x0000  /* map from file (default) */
+#define VKI_MAP_ANONYMOUS   0x1000  /* allocated from memory, swap space */
+#define VKI_MAP_ANON        VKI_MAP_ANONYMOUS
+#define VKI_MAP_STACK       0x2000  /* allocated from memory, swap space (stack) */  
+
+#define VKI_MAP_ALIGNED(n)  ((int)((unsigned int)(n) << VKI_MAP_ALIGNMENT_SHIFT))
+#define VKI_MAP_ALIGNMENT_SHIFT     24
+#define VKI_MAP_ALIGNMENT_MASK      VKI_MAP_ALIGNED(0xff)
+#define VKI_MAP_ALIGNMENT_64KB      VKI_MAP_ALIGNED(16) /* 2^16 */                                                                                                   
+#define VKI_MAP_ALIGNMENT_16MB      VKI_MAP_ALIGNED(24) /* 2^24 */
+#define VKI_MAP_ALIGNMENT_4GB       VKI_MAP_ALIGNED(32) /* 2^32 */
+#define VKI_MAP_ALIGNMENT_1TB       VKI_MAP_ALIGNED(40) /* 2^40 */
+#define VKI_MAP_ALIGNMENT_256TB     VKI_MAP_ALIGNED(48) /* 2^48 */
+#define VKI_MAP_ALIGNMENT_64PB      VKI_MAP_ALIGNED(56) /* 2^56 */
+
+#define VKI_MAP_FAILED      ((void *) -1)   /* mmap() failed */
+
+/*
+ * Flags to msync
+ */   
+#define VKI_MS_ASYNC        0x01    /* perform asynchronous writes */
+#define VKI_MS_INVALIDATE   0x02    /* invalidate cached data */
+#define VKI_MS_SYNC         0x04    /* perform synchronous writes */
+
+#define VKI_MCL_CURRENT     0x01    /* lock all pages currently mapped */
+#define VKI_MCL_FUTURE      0x02    /* lock all pages mapped in the future */
+
+#define VKI_POSIX_MADV_NORMAL       0       /* No further special treatment */
+#define VKI_POSIX_MADV_RANDOM       1       /* Expect random page references */                                                                                  
+#define VKI_POSIX_MADV_SEQUENTIAL   2       /* Expect sequential page references */
+#define VKI_POSIX_MADV_WILLNEED     3       /* Will need these pages */
+#define VKI_POSIX_MADV_DONTNEED     4       /* Don't need these pages */
+
+#define VKI_MADV_NORMAL             VKI_POSIX_MADV_NORMAL
+#define VKI_MADV_RANDOM             VKI_POSIX_MADV_RANDOM
+#define VKI_MADV_SEQUENTIAL         VKI_POSIX_MADV_SEQUENTIAL
+#define VKI_MADV_WILLNEED           VKI_POSIX_MADV_WILLNEED
+#define VKI_MADV_DONTNEED           VKI_POSIX_MADV_DONTNEED
+#define VKI_MADV_SPACEAVAIL         5       /* Insure that resources are reserved */
+#define VKI_MADV_FREE               6       /* Pages are empty, free them */
+
+#define VKI_MAP_INHERIT_SHARE       0       /* share with child */
+#define VKI_MAP_INHERIT_COPY        1       /* copy into child */
+#define VKI_MAP_INHERIT_NONE        2       /* absent from child */
+#define VKI_MAP_INHERIT_DONATE_COPY 3       /* copy and delete -- not
+                                           implemented in UVM */
+#define VKI_MAP_INHERIT_ZERO        4       /* zero in child */
+#define VKI_MAP_INHERIT_DEFAULT     VKI_MAP_INHERIT_COPY  
+
+//----------------------------------------------------------------------
+// From netinet/tcp.h
+//----------------------------------------------------------------------
+
+typedef vki_uint32_t vki_tcp_seq;
+
+struct vki_tcphdr {
+        vki_uint16_t th_sport;              /* source port */
+        vki_uint16_t th_dport;              /* destination port */
+        vki_tcp_seq   th_seq;               /* sequence number */
+        vki_tcp_seq   th_ack;               /* acknowledgement number */
+#if __x86_64__ /* Little endian */
+        /*LINTED non-portable bitfields*/
+        vki_uint8_t  th_x2:4,               /* (unused) */
+                  th_off:4;             /* data offset */
+#elif 0 /* Big endian */
+        /*LINTED non-portable bitfields*/
+        uint8_t  th_off:4,              /* data offset */                                                                                                    
+                  th_x2:4;              /* (unused) */
+#else
+#error unknown endian
+#endif
+        vki_uint8_t  th_flags;
+#define VKI_TH_FIN    0x01
+#define VKI_TH_SYN    0x02
+#define VKI_TH_RST    0x04
+#define VKI_TH_PUSH   0x08
+#define VKI_TH_ACK    0x10
+#define VKI_TH_URG    0x20
+#define VKI_TH_ECE    0x40
+#define VKI_TH_CWR    0x80
+        vki_uint16_t th_win;                        /* window */
+        vki_uint16_t th_sum;                        /* checksum */
+        vki_uint16_t th_urp;                        /* urgent pointer */
+} __attribute__((__packed__));
+
+#define VKI_TCPOPT_EOL              0
+#define VKI_TCPOLEN_EOL                  1                                                                                                                    
+#define VKI_TCPOPT_PAD              0
+#define VKI_TCPOLEN_PAD                  1
+#define VKI_TCPOPT_NOP              1
+#define VKI_TCPOLEN_NOP                  1
+#define VKI_TCPOPT_MAXSEG           2
+#define VKI_TCPOLEN_MAXSEG               4
+#define VKI_TCPOPT_WINDOW           3
+#define VKI_TCPOLEN_WINDOW               3
+#define VKI_TCPOPT_SACK_PERMITTED   4               /* Experimental */                                                                                           
+#define VKI_TCPOLEN_SACK_PERMITTED       2
+#define VKI_TCPOPT_SACK             5               /* Experimental */
+#define VKI_TCPOPT_TIMESTAMP        8
+#define VKI_TCPOLEN_TIMESTAMP            10
+#define VKI_TCPOLEN_TSTAMP_APPA          (VKI_TCPOLEN_TIMESTAMP+2) /* appendix A */
+
+#define VKI_TCPOPT_TSTAMP_HDR       \
+    (VKI_TCPOPT_NOP<<24|VKI_TCPOPT_NOP<<16|VKI_TCPOPT_TIMESTAMP<<8|VKI_TCPOLEN_TIMESTAMP)
+                                                                                                                                                             
+#define VKI_TCPOPT_SIGNATURE        19              /* Keyed MD5: RFC 2385 */
+#define VKI_TCPOLEN_SIGNATURE            18
+#define VKI_TCPOLEN_SIGLEN               (VKI_TCPOLEN_SIGNATURE+2) /* padding */
+
+#define VKI_MAX_TCPOPTLEN   40      /* max # bytes that go in options */
+
+#define VKI_TCP_MSS         536
+
+#define VKI_TCP_MINMSS      216
+
+#define VKI_TCP_MAXWIN      65535   /* largest value for (unscaled) window */
+  
+#define VKI_TCP_MAX_WINSHIFT        14      /* maximum window shift */
+ 
+#define VKI_TCP_MAXBURST    4       /* maximum segments in a burst */
+
+/*
+ * User-settable options (used with setsockopt).
+ */
+#define VKI_TCP_NODELAY     1       /* don't delay send to coalesce packets */
+
+#define VKI_TCP_MAXSEG      2       /* set maximum segment size */
+#define VKI_TCP_KEEPIDLE    3
+
+#define VKI_TCP_KEEPINTVL   5
+#define VKI_TCP_KEEPCNT     6
+#define VKI_TCP_KEEPINIT    7
+
+#define VKI_TCP_INFO        9       /* retrieve tcp_info structure */
+#define VKI_TCP_MD5SIG      0x10    /* use MD5 digests (RFC2385) */
+#define VKI_TCP_CONGCTL     0x20    /* selected congestion control */
+
+#define VKI_TCPI_OPT_TIMESTAMPS     0x01
+#define VKI_TCPI_OPT_SACK           0x02
+#define VKI_TCPI_OPT_WSCALE         0x04                                                                                                                         
+#define VKI_TCPI_OPT_ECN            0x08
+#define VKI_TCPI_OPT_TOE            0x10
+
+struct vki_tcp_info {
+        vki_uint8_t         tcpi_state; /* TCP FSM state. */
+        vki_uint8_t         __tcpi_ca_state;
+        vki_uint8_t         __tcpi_retransmits;
+        vki_uint8_t         __tcpi_probes;
+        vki_uint8_t         __tcpi_backoff;
+        vki_uint8_t         tcpi_options;          /* Options enabled on conn. */
+        /*LINTED: non-portable bitfield*/
+        vki_uint8_t         tcpi_snd_wscale:4,      /* RFC1323 send shift value. */
+        /*LINTED: non-portable bitfield*/
+                        tcpi_rcv_wscale:4; /* RFC1323 recv shift value. */
+
+        vki_uint32_t        tcpi_rto;               /* Retransmission timeout (usec). */
+        vki_uint32_t        __tcpi_ato;
+        vki_uint32_t        tcpi_snd_mss;           /* Max segment size for send. */
+        vki_uint32_t        tcpi_rcv_mss;           /* Max segment size for receive. */
+
+        vki_uint32_t        __tcpi_unacked;
+        vki_uint32_t        __tcpi_sacked;                                                                                                                       
+        vki_uint32_t        __tcpi_lost;
+        vki_uint32_t        __tcpi_retrans;
+        vki_uint32_t        __tcpi_fackets;
+
+        /* Times; measurements in usecs. */
+        vki_uint32_t        __tcpi_last_data_sent;
+        vki_uint32_t        __tcpi_last_ack_sent;   /* Also unimpl. on Linux? */
+        vki_uint32_t        tcpi_last_data_recv;    /* Time since last recv data. */
+        vki_uint32_t        __tcpi_last_ack_recv;                                                                                                                
+
+        /* Metrics; variable units. */
+        vki_uint32_t        __tcpi_pmtu;
+        vki_uint32_t        __tcpi_rcv_ssthresh;
+        vki_uint32_t        tcpi_rtt;               /* Smoothed RTT in usecs. */
+        vki_uint32_t        tcpi_rttvar;            /* RTT variance in usecs. */
+        vki_uint32_t        tcpi_snd_ssthresh;      /* Slow start threshold. */
+        vki_uint32_t        tcpi_snd_cwnd;          /* Send congestion window. */
+        vki_uint32_t        __tcpi_advmss;                                                                                                                       
+        vki_uint32_t        __tcpi_reordering;
+
+        vki_uint32_t        __tcpi_rcv_rtt;
+        vki_uint32_t        tcpi_rcv_space;         /* Advertised recv window. */
+
+        /* FreeBSD/NetBSD extensions to tcp_info. */
+        vki_uint32_t        tcpi_snd_wnd;           /* Advertised send window. */
+        vki_uint32_t        tcpi_snd_bwnd;          /* No longer used. */
+        vki_uint32_t        tcpi_snd_nxt;           /* Next egress seqno */                                                                                      
+        vki_uint32_t        tcpi_rcv_nxt;           /* Next ingress seqno */
+        vki_uint32_t        tcpi_toe_tid;           /* HWTID for TOE endpoints */
+        vki_uint32_t        tcpi_snd_rexmitpack;    /* Retransmitted packets */
+        vki_uint32_t        tcpi_rcv_ooopack;       /* Out-of-order packets */
+        vki_uint32_t        tcpi_snd_zerowin;       /* Zero-sized windows sent */
+
+        /* Padding to grow without breaking ABI. */
+        vki_uint32_t        __tcpi_pad[26];         /* Padding. */
+}; 
+
+//----------------------------------------------------------------------
+// From sys/exec_elf.h
+//----------------------------------------------------------------------
+
+#define VKI_AT_NULL         0       /* Marks end of array */
+#define VKI_AT_IGNORE       1       /* No meaning, a_un is undefined */
+#define VKI_AT_EXECFD       2       /* Open file descriptor of object file */
+#define VKI_AT_PHDR         3       /* &phdr[0] */
+#define VKI_AT_PHENT        4       /* sizeof(phdr[0]) */
+#define VKI_AT_PHNUM        5       /* # phdr entries */
+#define VKI_AT_PAGESZ       6       /* PAGESIZE */
+#define VKI_AT_BASE         7       /* Interpreter base addr */
+#define VKI_AT_FLAGS        8       /* Processor flags */
+#define VKI_AT_ENTRY        9       /* Entry address of executable */
+#define VKI_AT_DCACHEBSIZE  10      /* Data cache block size */
+#define VKI_AT_ICACHEBSIZE  11      /* Instruction cache block size */
+#define VKI_AT_UCACHEBSIZE  12      /* Unified cache block size */
+#define VKI_AT_STACKBASE    13      /* Base address of the main thread */
+
+#define VKI_AT_MIPS_NOTELF  10      /* XXX a_val != 0 -> MIPS XCOFF executable */                                                                                
+
+#define VKI_AT_EUID         2000    /* euid (solaris compatible numbers) */
+#define VKI_AT_RUID         2001    /* ruid (solaris compatible numbers) */
+#define VKI_AT_EGID         2002    /* egid (solaris compatible numbers) */
+#define VKI_AT_RGID         2003    /* rgid (solaris compatible numbers) */
+
+#define VKI_AT_SUN_LDELF    2004    /* dynamic linker's ELF header */
+#define VKI_AT_SUN_LDSHDR   2005    /* dynamic linker's section header */                                                                                        
+#define VKI_AT_SUN_LDNAME   2006    /* dynamic linker's name */
+#define VKI_AT_SUN_LPGSIZE  2007    /* large pagesize */
+
+#define VKI_AT_SUN_PLATFORM 2008    /* sysinfo(SI_PLATFORM) */
+#define VKI_AT_SUN_HWCAP    2009    /* process hardware capabilities */
+#define VKI_AT_SUN_IFLUSH   2010    /* do we need to flush the instruction cache? */
+#define VKI_AT_SUN_CPU      2011    /* CPU name */
+        /* ibcs2 emulation band aid */                                                                                                                       
+#define VKI_AT_SUN_EMUL_ENTRY 2012  /* coff entry point */
+#define VKI_AT_SUN_EMUL_EXECFD 2013 /* coff file descriptor */
+        /* Executable's fully resolved name */
+#define VKI_AT_SUN_EXECNAME 2014
+
+//----------------------------------------------------------------------
+// From sys/un.h
+//----------------------------------------------------------------------
+
+struct  vki_sockaddr_un {
+        vki_uint8_t         sun_len;        /* total sockaddr length */
+        vki_sa_family_t     sun_family;     /* AF_LOCAL */
+        char            sun_path[104];  /* path name (gag) */
+};
+
+#define VKI_LOCAL_OCREDS    0x0001          /* pass credentials to receiver */
+#define VKI_LOCAL_CONNWAIT  0x0002          /* connects block until accepted */
+#define VKI_LOCAL_PEEREID   0x0003          /* get peer identification */
+#define VKI_LOCAL_CREDS     0x0004          /* pass credentials to receiver */
+
+struct vki_unpcbid {
+        vki_pid_t unp_pid;          /* process id */
+        vki_uid_t unp_euid;         /* effective user id */                                                                                                      
+        vki_gid_t unp_egid;         /* effective group id */
+};
+
+#define VKI_SUN_LEN(su) \
+        (sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
+
+//----------------------------------------------------------------------
+// From netinet6/in6.h
+//----------------------------------------------------------------------
+
+#define VKI_IPV6PORT_RESERVED       1024
+#define VKI_IPV6PORT_ANONMIN        49152
+#define VKI_IPV6PORT_ANONMAX        65535                                                                                                                        
+#define VKI_IPV6PORT_RESERVEDMIN    600
+#define VKI_IPV6PORT_RESERVEDMAX    (VKI_IPV6PORT_RESERVED-1)
+
+struct vki_in6_addr {
+        union {
+                vki_uint8_t   __u6_addr8[16];
+                vki_uint16_t  __u6_addr16[8];
+                vki_uint32_t  __u6_addr32[4];
+        } __u6_addr;                    /* 128-bit IP6 address */
+}; 
+
+#define s6_addr   __u6_addr.__u6_addr8
+
+#define VKI_INET6_ADDRSTRLEN        46
+
+#define VKI_SIN6_LEN
+
+struct vki_sockaddr_in6 {
+        vki_uint8_t         sin6_len;       /* length of this struct(socklen_t)*/
+        vki_sa_family_t     sin6_family;    /* AF_INET6 (sa_family_t) */
+        vki_in_port_t       sin6_port;      /* Transport layer port */
+        vki_uint32_t        sin6_flowinfo;  /* IP6 flow information */
+        struct vki_in6_addr sin6_addr;      /* IP6 address */                                                                                                    
+        vki_uint32_t        sin6_scope_id;  /* scope zone index */
+};
+
+#define VKI_IN6ADDR_ANY_INIT \
+        {{{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
+            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }}}
+#define VKI_IN6ADDR_LOOPBACK_INIT \
+        {{{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
+            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }}}
+#define VKI_IN6ADDR_NODELOCAL_ALLNODES_INIT \
+        {{{ 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
+            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }}}
+#define VKI_IN6ADDR_LINKLOCAL_ALLNODES_INIT \
+        {{{ 0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
+            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }}}
+#define VKI_IN6ADDR_LINKLOCAL_ALLROUTERS_INIT \
+        {{{ 0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
+            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02 }}}
+
+#define VKI___IPV6_ADDR_SCOPE_NODELOCAL     0x01
+#define VKI___IPV6_ADDR_SCOPE_LINKLOCAL     0x02
+#define VKI___IPV6_ADDR_SCOPE_SITELOCAL     0x05
+#define VKI___IPV6_ADDR_SCOPE_ORGLOCAL      0x08    /* just used in this file */
+#define VKI___IPV6_ADDR_SCOPE_GLOBAL        0x0e
+
+#define VKI_IN6_IS_ADDR_MULTICAST(a)        ((a)->s6_addr[0] == 0xff)
+
+#define VKI___IPV6_ADDR_MC_SCOPE(a)         ((a)->s6_addr[1] & 0x0f)
+
+#define VKI_IPV6_SOCKOPT_RESERVED1  3  /* reserved for future use */
+#define VKI_IPV6_UNICAST_HOPS       4  /* int; IP6 hops */
+#define VKI_IPV6_MULTICAST_IF       9  /* u_int; set/get IP6 multicast i/f  */
+#define VKI_IPV6_MULTICAST_HOPS     10 /* int; set/get IP6 multicast hops */
+#define VKI_IPV6_MULTICAST_LOOP     11 /* u_int; set/get IP6 multicast loopback */
+/* The join and leave membership option numbers need to match with the v4 ones */
+#define VKI_IPV6_JOIN_GROUP         12 /* ip6_mreq; join a group membership */
+#define VKI_IPV6_LEAVE_GROUP        13 /* ip6_mreq; leave a group membership */                                                                                  
+#define VKI_IPV6_PORTRANGE          14 /* int; range to choose for unspec port */
+
+#define VKI_IPV6_PORTALGO           17 /* int; port selection algo (rfc6056) */
+#define VKI_ICMP6_FILTER            18 /* icmp6_filter; icmp6 filter */
+
+#define VKI_IPV6_CHECKSUM           26 /* int; checksum offset for raw socket */
+#define VKI_IPV6_V6ONLY             27 /* bool; make AF_INET6 sockets v6 only */
+                                                                                                                                                             
+#define VKI_IPV6_IPSEC_POLICY       28 /* struct; get/set security policy */
+#define VKI_IPV6_FAITH              29 /* bool; accept FAITH'ed connections */
+
+/* new socket options introduced in RFC3542 */
+#define VKI_IPV6_RTHDRDSTOPTS       35 /* ip6_dest; send dst option before rthdr */
+
+#define VKI_IPV6_RECVPKTINFO        36 /* bool; recv if, dst addr */
+#define VKI_IPV6_RECVHOPLIMIT       37 /* bool; recv hop limit */
+
+#define VKI_IPV6_RECVRTHDR          38 /* bool; recv routing header */                                                                                           
+#define VKI_IPV6_RECVHOPOPTS        39 /* bool; recv hop-by-hop option */
+#define VKI_IPV6_RECVDSTOPTS        40 /* bool; recv dst option after rthdr */
+
+#define VKI_IPV6_USE_MIN_MTU        42 /* bool; send packets at the minimum MTU */
+#define VKI_IPV6_RECVPATHMTU        43 /* bool; notify an according MTU */
+#define VKI_IPV6_PATHMTU            44 /* mtuinfo; get the current path MTU (sopt),
+                                      4 bytes int; MTU notification (cmsg) */                                                                                
+
+/* more new socket options introduced in RFC3542 */
+#define VKI_IPV6_PKTINFO            46 /* in6_pktinfo; send if, src addr */
+#define VKI_IPV6_HOPLIMIT           47 /* int; send hop limit */
+#define VKI_IPV6_NEXTHOP            48 /* sockaddr; next hop addr */
+#define VKI_IPV6_HOPOPTS            49 /* ip6_hbh; send hop-by-hop option */
+#define VKI_IPV6_DSTOPTS            50 /* ip6_dest; send dst option befor rthdr */
+#define VKI_IPV6_RTHDR              51 /* ip6_rthdr; send routing header */
+
+#define VKI_IPV6_RECVTCLASS         57 /* bool; recv traffic class values */
+
+#define VKI_IPV6_TCLASS             61 /* int; send traffic class value */
+#define VKI_IPV6_DONTFRAG           62 /* bool; disable IPv6 fragmentation */
+#define VKI_IPV6_PREFER_TEMPADDR    63 /* int; prefer temporary address as
+                                    * the sorce address */                                                                                                   
+/* to define VKI_items, should talk with KAME guys first, for *BSD compatibility */
+
+#define VKI_IPV6_RTHDR_LOOSE     0 /* this hop need not be a neighbor. XXX old spec */
+#define VKI_IPV6_RTHDR_STRICT    1 /* this hop must be a neighbor. XXX old spec */
+#define VKI_IPV6_RTHDR_TYPE_0    0 /* IPv6 routing header type 0 */
+
+                                                                            
+#define VKI_IPV6_DEFAULT_MULTICAST_HOPS 1   /* normally limit m'casts to 1 hop  */
+#define VKI_IPV6_DEFAULT_MULTICAST_LOOP 1   /* normally hear sends if a member  */
+
+struct vki_ipv6_mreq {
+        struct vki_in6_addr ipv6mr_multiaddr;
+        unsigned int    ipv6mr_interface;                                                                                                                    
+};
+
+struct vki_in6_pktinfo {
+        struct vki_in6_addr ipi6_addr;      /* src/dst IPv6 address */
+        unsigned int    ipi6_ifindex;   /* send/recv interface index */                                                                                      
+};
+
+/*
+ * Control structure for IPV6_RECVPATHMTU socket option.
+ */
+struct vki_ip6_mtuinfo {
+        struct vki_sockaddr_in6 ip6m_addr;  /* or sockaddr_storage? */
+        vki_uint32_t ip6m_mtu;
+};  
+
+#define VKI_IPV6_PORTRANGE_DEFAULT  0       /* default range */
+#define VKI_IPV6_PORTRANGE_HIGH     1       /* "high" - request firewall bypass */
+#define VKI_IPV6_PORTRANGE_LOW      2       /* "low" - vouchsafe security */
+
+#define VKI_IPV6CTL_FORWARDING      1       /* act as router */
+#define VKI_IPV6CTL_SENDREDIRECTS   2       /* may send redirects when forwarding*/
+#define VKI_IPV6CTL_DEFHLIM         3       /* default Hop-Limit */
+/* IPV6CTL_DEFMTU=4, never implemented */
+#define VKI_IPV6CTL_FORWSRCRT       5       /* forward source-routed dgrams */
+#define VKI_IPV6CTL_STATS           6       /* stats */
+#define VKI_IPV6CTL_MRTSTATS        7       /* multicast forwarding stats */
+#define VKI_IPV6CTL_MRTPROTO        8       /* multicast routing protocol */
+#define VKI_IPV6CTL_MAXFRAGPACKETS  9       /* max packets reassembly queue */                                                                                   
+#define VKI_IPV6CTL_SOURCECHECK     10      /* verify source route and intf */
+#define VKI_IPV6CTL_SOURCECHECK_LOGINT 11   /* minimum logging interval */
+#define VKI_IPV6CTL_ACCEPT_RTADV    12
+#define VKI_IPV6CTL_KEEPFAITH       13
+#define VKI_IPV6CTL_LOG_INTERVAL    14
+#define VKI_IPV6CTL_HDRNESTLIMIT    15
+#define VKI_IPV6CTL_DAD_COUNT       16
+#define VKI_IPV6CTL_AUTO_FLOWLABEL  17
+
+#define VKI_IPV6CTL_DEFMCASTHLIM    18                                                                                                                           
+#define VKI_IPV6CTL_GIF_HLIM        19      /* default HLIM for gif encap packet */
+#define VKI_IPV6CTL_KAME_VERSION    20
+#define VKI_IPV6CTL_USE_DEPRECATED  21      /* use deprecated addr (RFC2462 5.5.4) */
+#define VKI_IPV6CTL_RR_PRUNE        22      /* walk timer for router renumbering */
+/* 23: reserved */
+#define VKI_IPV6CTL_V6ONLY          24
+/* 25 to 27: reserved */
+#define VKI_IPV6CTL_ANONPORTMIN     28      /* minimum ephemeral port */
+#define VKI_IPV6CTL_ANONPORTMAX     29      /* maximum ephemeral port */                                                                                         
+#define VKI_IPV6CTL_LOWPORTMIN      30      /* minimum reserved port */
+#define VKI_IPV6CTL_LOWPORTMAX      31      /* maximum reserved port */
+/* 32 to 34: reserved */
+#define VKI_IPV6CTL_AUTO_LINKLOCAL  35      /* automatic link-local addr assign */
+/* 36 to 37: reserved */
+#define VKI_IPV6CTL_ADDRCTLPOLICY   38      /* get/set address selection policy */
+#define VKI_IPV6CTL_USE_DEFAULTZONE 39      /* use default scope zone */
+
+#define VKI_IPV6CTL_MAXFRAGS        41      /* max fragments */                                                                                                  
+#define VKI_IPV6CTL_IFQ             42      /* IPv6 packet input queue */
+#define VKI_IPV6CTL_RTADV_MAXROUTES 43      /* maximum number of routes */
+                                        /* via router advertisement */
+#define VKI_IPV6CTL_RTADV_NUMROUTES 44      /* current number of routes */
+  /* via router advertisement */
+
+#define VKI_INET6_IS_ADDR_LINKLOCAL         1
+#define VKI_INET6_IS_ADDR_MC_LINKLOCAL      2
+#define VKI_INET6_IS_ADDR_SITELOCAL         4
+
+//----------------------------------------------------------------------
+// From sys/ipc.h
+//----------------------------------------------------------------------
+
+struct vki_ipc_perm {
+        vki_uid_t           uid;    /* user id */
+        vki_gid_t           gid;    /* group id */
+        vki_uid_t           cuid;   /* creator user id */
+        vki_gid_t           cgid;   /* creator group id */
+        vki_mode_t          mode;   /* r/w permission */
+
+        /*
+         * These members are private and used only in the internal
+         * implementation of this interface.
+         */
+        unsigned short  _seq;   /* sequence # (to generate unique
+                                   msg/sem/shm id) */
+        vki_key_t           _key;   /* user specified msg/sem/shm key */
+};
+
+struct vki_ipc_perm_sysctl {
+        vki_uint64_t        _key;
+        vki_uid_t           uid;
+        vki_gid_t           gid;
+        vki_uid_t           cuid;
+        vki_gid_t           cgid;
+        vki_mode_t          mode;
+        vki_int16_t         _seq;
+        vki_int16_t         pad;
+};
+
+#define VKI_IPC_R           000400  /* read permission */
+#define VKI_IPC_W           000200  /* write/alter permission */
+#define VKI_IPC_M           010000  /* permission to change control info */
+
+#define VKI_IPC_CREAT       001000  /* create entry if key does not exist */                                                                                     
+#define VKI_IPC_EXCL        002000  /* fail if key exists */
+#define VKI_IPC_NOWAIT      004000  /* error if request must wait */
+
+#define VKI_IPC_PRIVATE     (vki_key_t)0 /* private key */
+
+#define VKI_IPC_RMID        0       /* remove identifier */
+#define VKI_IPC_SET         1       /* set options */
+#define VKI_IPC_STAT        2       /* get options */
+
+#define VKI_IXSEQ_TO_IPCID(ix,perm) (((perm._seq) << 16) | (ix & 0xffff))
+
+//----------------------------------------------------------------------
+// From sys/sem.h
+//----------------------------------------------------------------------
+
+struct vki___sem {
+        unsigned short  semval;         /* semaphore value */
+        vki_pid_t           sempid;         /* pid of last operation */
+        unsigned short  semncnt;        /* # awaiting semval > cval */
+        unsigned short  semzcnt;        /* # awaiting semval = 0 */
+};
+
+struct vki_semid_ds {
+        struct vki_ipc_perm sem_perm;       /* operation permission structure */
+        unsigned short  sem_nsems;      /* number of semaphores in set */
+        vki_time_t          sem_otime;      /* last semop() time */
+        vki_time_t          sem_ctime;      /* last time changed by semctl() */
+                                                                                                                                                             
+        /*
+         * These members are private and used only in the internal
+         * implementation of this interface.
+         */
+        struct vki___sem    *_sem_base;     /* pointer to first semaphore in set */
+};
+
+struct vki_sembuf {
+        unsigned short  sem_num;        /* semaphore # */
+        short           sem_op;         /* semaphore operation */
+        short           sem_flg;        /* operation flags */
+};
+#define VKI_SEM_UNDO        010000          /* undo changes on process exit */
+
+#define VKI_GETNCNT 3       /* Return the value of semncnt {READ} */
+#define VKI_GETPID  4       /* Return the value of sempid {READ} */
+#define VKI_GETVAL  5       /* Return the value of semval {READ} */
+#define VKI_GETALL  6       /* Return semvals into arg.array {READ} */
+#define VKI_GETZCNT 7       /* Return the value of semzcnt {READ} */
+#define VKI_SETVAL  8       /* Set the value of semval to arg.val {ALTER} */
+#define VKI_SETALL  9       /* Set semvals from arg.array {ALTER} */ 
+
+struct vki_seminfo {
+        vki_int32_t semmap;         /* # of entries in semaphore map */
+        vki_int32_t semmni;         /* # of semaphore identifiers */
+        vki_int32_t semmns;         /* # of semaphores in system */
+        vki_int32_t semmnu;         /* # of undo structures in system */
+        vki_int32_t semmsl;         /* max # of semaphores per id */
+        vki_int32_t semopm;         /* max # of operations per semop call */
+        vki_int32_t semume;         /* max # of undo entries per process */
+        vki_int32_t semusz;         /* size in bytes of undo structure */                                                                                        
+        vki_int32_t semvmx;         /* semaphore maximum value */
+        vki_int32_t semaem;         /* adjust on exit max value */
+};
+
+struct vki_semid_ds_sysctl {
+        struct  vki_ipc_perm_sysctl sem_perm;
+        vki_int16_t sem_nsems;
+        vki_int16_t pad2;                                                                                                                                        
+        vki_int32_t pad3;
+        vki_time_t  sem_otime;
+        vki_time_t  sem_ctime;
+};
+
+struct vki_sem_sysctl_info {
+        struct  vki_seminfo seminfo;
+        struct  vki_semid_ds_sysctl semids[1];
+};
+
+#define VKI_SEM_ALLOC       01000   /* semaphore is allocated */
+
+#define vki_get_semctl_arg(cmd, sembuf, arg) \
+    ((cmd) == VKI_IPC_SET || (cmd) == VKI_IPC_STAT ? (void *)sembuf \
+    : (cmd) == VKI_GETALL || (cmd) == VKI_SETVAL || (cmd) == VKI_SETALL ? (void *)arg \
+    : 0)
+
+//----------------------------------------------------------------------
+// From sys/shm.h
+//----------------------------------------------------------------------
+
+#define VKI_SHM_RDONLY      010000  /* Attach read-only (else read-write) */
+#define VKI_SHM_RND         020000  /* Round attach address to SHMLBA */
+
+#define VKI_SHMLBA          VKI_PAGE_SIZE
+
+typedef unsigned int    vki_shmatt_t;
+
+struct vki_shmid_ds {
+        struct vki_ipc_perm shm_perm;       /* operation permission structure */
+        vki_size_t          shm_segsz;      /* size of segment in bytes */                                                                                       
+        vki_pid_t           shm_lpid;       /* process ID of last shm operation */
+        vki_pid_t           shm_cpid;       /* process ID of creator */
+        vki_shmatt_t        shm_nattch;     /* number of current attaches */
+        vki_time_t          shm_atime;      /* time of last shmat() */
+        vki_time_t          shm_dtime;      /* time of last shmdt() */
+        vki_time_t          shm_ctime;      /* time of last change by shmctl() */
+
+        void            *_shm_internal;
+};
+
+#define VKI_SHM_LOCK        3       /* Lock segment in memory. */
+#define VKI_SHM_UNLOCK      4       /* Unlock a segment locked by SHM_LOCK. */
+
+#define VKI_SHM_R           VKI_IPC_R   /* S_IRUSR, R for owner */
+#define VKI_SHM_W           VKI_IPC_W   /* S_IWUSR, W for owner */
+
+struct vki_shminfo {                                                                                                                                             
+        vki_uint64_t        shmmax; /* max shared memory segment size (bytes) */
+        vki_uint32_t        shmmin; /* min shared memory segment size (bytes) */
+        vki_uint32_t        shmmni; /* max number of shared memory identifiers */
+        vki_uint32_t        shmseg; /* max shared memory segments per process */
+        vki_uint32_t        shmall; /* max amount of shared memory (pages) */
+};
+
+struct vki_shmid_ds_sysctl {                                                                                                                                     
+        struct          vki_ipc_perm_sysctl shm_perm;
+        vki_uint64_t        shm_segsz;
+        vki_pid_t           shm_lpid;
+        vki_pid_t           shm_cpid;
+        vki_time_t          shm_atime;
+        vki_time_t          shm_dtime;
+        vki_time_t          shm_ctime;
+        vki_uint32_t        shm_nattch;
+};                                                                                                                                                           
+
+struct vki_shm_sysctl_info {
+        struct  vki_shminfo shminfo;
+        struct  vki_shmid_ds_sysctl shmids[1];
+};
+
+//----------------------------------------------------------------------
+// From sys/ioccom.h
+//----------------------------------------------------------------------
+
+#define VKI_IOCPARM_MASK    0x1fff          /* parameter length, at most 13 bits */
+#define VKI_IOCPARM_SHIFT   16
+#define VKI_IOCGROUP_SHIFT  8
+#define VKI_IOCPARM_LEN(x)  (((x) >> VKI_IOCPARM_SHIFT) & VKI_IOCPARM_MASK)
+#define VKI_IOCBASECMD(x)   ((x) & ~(VKI_IOCPARM_MASK << VKI_IOCPARM_SHIFT))                                                                                             
+#define VKI_IOCGROUP(x)     (((x) >> VKI_IOCGROUP_SHIFT) & 0xff)
+
+#define VKI_IOCPARM_MAX     VKI_NBPG    /* max size of ioctl args, mult. of NBPG */
+                                /* no parameters */
+#define VKI_IOC_VOID        (unsigned long)0x20000000
+                                /* copy parameters out */
+#define VKI_IOC_OUT         (unsigned long)0x40000000
+                                /* copy parameters in */
+#define VKI_IOC_IN          (unsigned long)0x80000000                                                                                                            
+                                /* copy parameters in and out */
+#define VKI_IOC_INOUT       (VKI_IOC_IN|VKI_IOC_OUT)
+                                /* mask for IN/OUT/VOID */
+#define VKI_IOC_DIRMASK     (unsigned long)0xe0000000
+
+#define VKI__IOC(inout, group, num, len) \
+    ((inout) | (((len) & VKI_IOCPARM_MASK) << VKI_IOCPARM_SHIFT) | \
+    ((group) << VKI_IOCGROUP_SHIFT) | (num))
+#define VKI__IO(g,n)        VKI__IOC(VKI_IOC_VOID,  (g), (n), 0) 
+#define VKI__IOR(g,n,t)     VKI__IOC(VKI_IOC_OUT,   (g), (n), sizeof(t))
+#define VKI__IOW(g,n,t)     VKI__IOC(VKI_IOC_IN,    (g), (n), sizeof(t))
+/* this should be _IORW, but stdio got there first */
+#define VKI__IOWR(g,n,t)    VKI__IOC(VKI_IOC_INOUT, (g), (n), sizeof(t))
+
+// linux-like ioctl flags
+#define _VKI_IOC_DIR(x)         ((x) & VKI_IOC_DIRMASK)
+#define _VKI_IOC_SIZE(x)        VKI_IOCPARM_LEN(x)
+#define _VKI_IOC_NONE           VKI_IOC_VOID  /* GrP fixme correct? */
+#define _VKI_IOC_READ           VKI_IOC_OUT
+#define _VKI_IOC_WRITE          VKI_IOC_IN
+
+//----------------------------------------------------------------------
+// From sys/fd_set.h
+//----------------------------------------------------------------------
+
+typedef vki_uint32_t      vki___fd_mask;
+
+#define VKI___NFDBITS       (32)
+#define VKI___NFDSHIFT      (5)
+#define VKI___NFDMASK       (VKI___NFDBITS - 1)
+
+#ifndef VKI_FD_SETSIZE
+#define VKI_FD_SETSIZE      256
+#endif
+
+#define VKI___NFD_LEN(a)    (((a) + (VKI___NFDBITS - 1)) / VKI___NFDBITS)
+#define VKI___NFD_SIZE      VKI___NFD_LEN(VKI_FD_SETSIZE)
+#define VKI___NFD_BYTES(a)  (VKI___NFD_LEN(a) * sizeof(vki___fd_mask))
+   
+typedef struct vki_fd_set {
+        vki___fd_mask       fds_bits[VKI___NFD_SIZE];
+} vki_fd_set;
+
+#define VKI_FD_SET(n, p)    \
+    ((p)->fds_bits[(unsigned)(n) >> VKI___NFDSHIFT] |= (1U << ((n) & VKI___NFDMASK)))
+#define VKI_FD_CLR(n, p)    \
+    ((p)->fds_bits[(unsigned)(n) >> VKI___NFDSHIFT] &= ~(1U << ((n) & VKI___NFDMASK)))
+#define VKI_FD_ISSET(n, p)  \
+    ((p)->fds_bits[(unsigned)(n) >> VKI___NFDSHIFT] & (1U << ((n) & VKI___NFDMASK)))
+
+#define vki_fd_mask         vki___fd_mask
+#define VKI_NFDBITS         VKI___NFDBITS
+
+//----------------------------------------------------------------------
+// From sys/times.h
+//----------------------------------------------------------------------
+
+struct vki_tms {
+        vki_clock_t tms_utime;      /* User CPU time */
+        vki_clock_t tms_stime;      /* System CPU time */
+        vki_clock_t tms_cutime;     /* User CPU time of terminated child procs */
+        vki_clock_t tms_cstime;     /* System CPU time of terminated child procs */
+};
+
+//----------------------------------------------------------------------
+// From uvm/uvm_param.h
+//----------------------------------------------------------------------
+
+#define VKI_VM_METER        1               /* struct vmmeter */
+#define VKI_VM_LOADAVG      2               /* struct loadavg */
+#define VKI_VM_UVMEXP       3               /* struct uvmexp */
+#define VKI_VM_NKMEMPAGES   4               /* kmem_map pages */
+#define VKI_VM_UVMEXP2      5               /* struct uvmexp_sysctl */
+#define VKI_VM_ANONMIN      6
+#define VKI_VM_EXECMIN      7
+#define VKI_VM_FILEMIN      8
+#define VKI_VM_MAXSLP       9   
+#define VKI_VM_USPACE       10
+#define VKI_VM_ANONMAX      11
+#define VKI_VM_EXECMAX      12
+#define VKI_VM_FILEMAX      13
+#define VKI_VM_MINADDRESS   14
+#define VKI_VM_MAXADDRESS   15
+#define VKI_VM_PROC         16              /* process information */
+#define VKI_VM_GUARD_SIZE   17              /* guard size for main thread */
+#define VKI_VM_THREAD_GUARD_SIZE    18      /* default guard size for new threads */
+
+#define VKI_VM_PROC_MAP     1               /* struct kinfo_vmentry */
+
+typedef unsigned int vki_uvm_flag_t;
+
+typedef int vki_vm_inherit_t;       /* XXX: inheritance codes */                                                                                                 
+typedef vki_off_t vki_voff_t;           /* XXX: offset within a uvm_object */
+typedef vki_voff_t vki_pgoff_t;         /* XXX: number of pages within a uvm object */
+
+//----------------------------------------------------------------------
+// From sys/sysctl.h
+//----------------------------------------------------------------------
+
+#define VKI_CTL_MAXNAME     12      /* largest number of components supported */
+#define VKI_SYSCTL_NAMELEN  32      /* longest name allowed for a node */
+
+#define VKI_CREATE_BASE     (1024)  /* start of dynamic mib allocation */
+#define VKI_SYSCTL_DEFSIZE  8       /* initial size of a child set */
+
+struct vki_ctlname {
+        const char *ctl_name;   /* subsystem name */
+        int     ctl_type;       /* type of name */
+};
+
+#define VKI_CTLTYPE_NODE    1       /* name is a node */                                                                                                         
+#define VKI_CTLTYPE_INT     2       /* name describes an integer */
+#define VKI_CTLTYPE_STRING  3       /* name describes a string */
+#define VKI_CTLTYPE_QUAD    4       /* name describes a 64-bit number */
+#define VKI_CTLTYPE_STRUCT  5       /* name describes a structure */
+#define VKI_CTLTYPE_BOOL    6       /* name describes a bool */
+
+#ifdef _LP64
+#define VKI_CTLTYPE_LONG    VKI_CTLTYPE_QUAD
+#else                                                                                                                                                        
+#define VKI_CTLTYPE_LONG    VKI_CTLTYPE_INT
+#endif
+
+#define VKI_CTLFLAG_READONLY        0x00000000
+
+#define VKI_CTLFLAG_READWRITE       0x00000070
+#define VKI_CTLFLAG_ANYWRITE        0x00000080
+#define VKI_CTLFLAG_PRIVATE         0x00000100
+#define VKI_CTLFLAG_PERMANENT       0x00000200
+#define VKI_CTLFLAG_OWNDATA         0x00000400
+#define VKI_CTLFLAG_IMMEDIATE       0x00000800
+#define VKI_CTLFLAG_HEX             0x00001000
+#define VKI_CTLFLAG_ROOT            0x00002000                                                                                                                   
+#define VKI_CTLFLAG_ANYNUMBER       0x00004000
+#define VKI_CTLFLAG_HIDDEN          0x00008000
+#define VKI_CTLFLAG_ALIAS           0x00010000
+#define VKI_CTLFLAG_MMAP            0x00020000
+#define VKI_CTLFLAG_OWNDESC         0x00040000
+#define VKI_CTLFLAG_UNSIGNED        0x00080000
+
+#define VKI_SYSCTL_VERS_MASK        0xff000000
+#define VKI_SYSCTL_VERS_0           0x00000000
+#define VKI_SYSCTL_VERS_1           0x01000000
+#define VKI_SYSCTL_VERSION          VKI_SYSCTL_VERS_1
+#define VKI_SYSCTL_VERS(f)          ((f) & VKI_SYSCTL_VERS_MASK)
+
+#define VKI_SYSCTL_USERFLAGS        (VKI_CTLFLAG_READWRITE|\
+                                VKI_CTLFLAG_ANYWRITE|\
+                                VKI_CTLFLAG_PRIVATE|\
+                                VKI_CTLFLAG_OWNDATA|\
+                                VKI_CTLFLAG_IMMEDIATE|\
+                                VKI_CTLFLAG_HEX|\
+                                VKI_CTLFLAG_HIDDEN)
+
+#define VKI_SYSCTL_TYPEMASK         0x0000000f
+#define VKI_SYSCTL_TYPE(x)          ((x) & VKI_SYSCTL_TYPEMASK)
+#define VKI_SYSCTL_FLAGMASK         0x00fffff0
+#define VKI_SYSCTL_FLAGS(x)         ((x) & VKI_SYSCTL_FLAGMASK)
+
+#define VKI_CTL_EOL         (-1)            /* end of createv/destroyv list */
+#define VKI_CTL_QUERY       (-2)            /* enumerates children of a node */
+#define VKI_CTL_CREATE      (-3)            /* node create request */
+#define VKI_CTL_CREATESYM   (-4)            /* node create request with symbol */
+#define VKI_CTL_DESTROY     (-5)            /* node destroy request */
+#define VKI_CTL_MMAP        (-6)            /* mmap request */
+#define VKI_CTL_DESCRIBE    (-7)            /* get node descriptions */  
+
+#define VKI_CTL_UNSPEC      0               /* unused */   
+#define VKI_CTL_KERN        1               /* "high kernel": proc, limits */
+#define VKI_CTL_VM          2               /* virtual memory */
+#define VKI_CTL_VFS         3               /* file system, mount type is next */
+#define VKI_CTL_NET         4               /* network, see socket.h */
+#define VKI_CTL_DEBUG       5               /* debugging parameters */
+#define VKI_CTL_HW          6               /* generic CPU/io */
+#define VKI_CTL_MACHDEP     7               /* machine dependent */  
+#define VKI_CTL_USER        8               /* user-level */
+#define VKI_CTL_DDB         9               /* in-kernel debugger */  
+#define VKI_CTL_PROC        10              /* per-proc attr */
+#define VKI_CTL_VENDOR      11              /* vendor-specific data */ 
+#define VKI_CTL_EMUL        12              /* emulation-specific data */
+#define VKI_CTL_SECURITY    13              /* security */
+
+#define VKI_KERN_OSTYPE              1      /* string: system version */
+#define VKI_KERN_OSRELEASE           2      /* string: system release */
+#define VKI_KERN_OSREV               3      /* int: system revision */
+#define VKI_KERN_VERSION             4      /* string: compile time info */
+#define VKI_KERN_MAXVNODES           5      /* int: max vnodes */
+#define VKI_KERN_MAXPROC             6      /* int: max processes */
+#define VKI_KERN_MAXFILES            7      /* int: max open files */
+#define VKI_KERN_ARGMAX              8      /* int: max arguments to exec */                                                                                     
+#define VKI_KERN_SECURELVL           9      /* int: system security level */
+#define VKI_KERN_HOSTNAME           10      /* string: hostname */
+#define VKI_KERN_HOSTID             11      /* int: host identifier */
+#define VKI_KERN_CLOCKRATE          12      /* struct: struct clockinfo */
+#define VKI_KERN_VNODE              13      /* struct: vnode structures */
+#define VKI_KERN_PROC               14      /* struct: process entries */
+#define VKI_KERN_FILE               15      /* struct: file entries */
+#define VKI_KERN_PROF               16      /* node: kernel profiling info */
+#define VKI_KERN_POSIX1             17      /* int: POSIX.1 version */                                                                                           
+#define VKI_KERN_NGROUPS            18      /* int: # of supplemental group ids */
+#define VKI_KERN_JOB_CONTROL        19      /* int: is job control available */
+#define VKI_KERN_SAVED_IDS          20      /* int: saved set-user/group-ID */
+#define VKI_KERN_OBOOTTIME          21      /* struct: time kernel was booted */
+#define VKI_KERN_DOMAINNAME         22      /* string: (YP) domainname */
+#define VKI_KERN_MAXPARTITIONS      23      /* int: number of partitions/disk */
+#define VKI_KERN_RAWPARTITION       24      /* int: raw partition number */
+#define VKI_KERN_NTPTIME            25      /* struct: extended-precision time */
+#define VKI_KERN_TIMEX              26      /* struct: ntp timekeeping state */                                                                                  
+#define VKI_KERN_AUTONICETIME       27      /* int: proc time before autonice */
+#define VKI_KERN_AUTONICEVAL        28      /* int: auto nice value */
+#define VKI_KERN_RTC_OFFSET         29      /* int: offset of rtc from gmt */
+#define VKI_KERN_ROOT_DEVICE        30      /* string: root device */
+#define VKI_KERN_MSGBUFSIZE         31      /* int: max # of chars in msg buffer */
+#define VKI_KERN_FSYNC              32      /* int: file synchronization support */
+#define VKI_KERN_OLDSYSVMSG         33      /* old: SysV message queue support */
+#define VKI_KERN_OLDSYSVSEM         34      /* old: SysV semaphore support */
+#define VKI_KERN_OLDSYSVSHM         35      /* old: SysV shared memory support */                                                                                
+#define VKI_KERN_OLDSHORTCORENAME   36      /* old, unimplemented */
+#define VKI_KERN_SYNCHRONIZED_IO    37      /* int: POSIX synchronized I/O */
+#define VKI_KERN_IOV_MAX            38      /* int: max iovec's for readv(2) etc. */
+#define VKI_KERN_MBUF               39      /* node: mbuf parameters */
+#define VKI_KERN_MAPPED_FILES       40      /* int: POSIX memory mapped files */
+#define VKI_KERN_MEMLOCK            41      /* int: POSIX memory locking */
+#define VKI_KERN_MEMLOCK_RANGE      42      /* int: POSIX memory range locking */
+#define VKI_KERN_MEMORY_PROTECTION  43      /* int: POSIX memory protections */
+#define VKI_KERN_LOGIN_NAME_MAX     44      /* int: max length login name + NUL */                                                                               
+#define VKI_KERN_DEFCORENAME        45      /* old: sort core name format */
+#define VKI_KERN_LOGSIGEXIT         46      /* int: log signaled processes */
+#define VKI_KERN_PROC2              47      /* struct: process entries */
+#define VKI_KERN_PROC_ARGS          48      /* struct: process argv/env */
+#define VKI_KERN_FSCALE             49      /* int: fixpt FSCALE */
+#define VKI_KERN_CCPU               50      /* old: fixpt ccpu */
+#define VKI_KERN_CP_TIME            51      /* struct: CPU time counters */
+#define VKI_KERN_OLDSYSVIPC_INFO    52      /* old: number of valid kern ids */
+#define VKI_KERN_MSGBUF             53      /* kernel message buffer */                                                                                          
+#define VKI_KERN_CONSDEV            54      /* dev_t: console terminal device */
+#define VKI_KERN_MAXPTYS            55      /* int: maximum number of ptys */
+#define VKI_KERN_PIPE               56      /* node: pipe limits */
+#define VKI_KERN_MAXPHYS            57      /* int: kernel value of MAXPHYS */
+#define VKI_KERN_SBMAX              58      /* int: max socket buffer size */
+#define VKI_KERN_TKSTAT             59      /* tty in/out counters */
+#define VKI_KERN_MONOTONIC_CLOCK    60      /* int: POSIX monotonic clock */
+#define VKI_KERN_URND               61      /* int: random integer from urandom */
+#define VKI_KERN_LABELSECTOR        62      /* int: disklabel sector */                                                                                          
+#define VKI_KERN_LABELOFFSET        63      /* int: offset of label within sector */
+#define VKI_KERN_LWP                64      /* struct: lwp entries */
+#define VKI_KERN_FORKFSLEEP         65      /* int: sleep length on failed fork */
+#define VKI_KERN_POSIX_THREADS      66      /* int: POSIX Threads option */
+#define VKI_KERN_POSIX_SEMAPHORES   67      /* int: POSIX Semaphores option */
+#define VKI_KERN_POSIX_BARRIERS     68      /* int: POSIX Barriers option */
+#define VKI_KERN_POSIX_TIMERS       69      /* int: POSIX Timers option */
+#define VKI_KERN_POSIX_SPIN_LOCKS   70      /* int: POSIX Spin Locks option */
+#define VKI_KERN_POSIX_READER_WRITER_LOCKS 71 /* int: POSIX R/W Locks option */                                                                                  
+#define VKI_KERN_DUMP_ON_PANIC      72      /* int: dump on panic */
+#define VKI_KERN_SOMAXKVA           73      /* int: max socket kernel virtual mem */
+#define VKI_KERN_ROOT_PARTITION     74      /* int: root partition */
+#define VKI_KERN_DRIVERS            75      /* struct: driver names and majors #s */
+#define VKI_KERN_BUF                76      /* struct: buffers */
+#define VKI_KERN_FILE2              77      /* struct: file entries */
+#define VKI_KERN_VERIEXEC           78      /* node: verified exec */
+#define VKI_KERN_CP_ID              79      /* struct: cpu id numbers */
+#define VKI_KERN_HARDCLOCK_TICKS    80      /* int: number of hardclock ticks */                                                                                 
+#define VKI_KERN_ARND               81      /* void *buf, size_t siz random */
+#define VKI_KERN_SYSVIPC            82      /* node: SysV IPC parameters */
+#define VKI_KERN_BOOTTIME           83      /* struct: time kernel was booted */
+#define VKI_KERN_EVCNT              84      /* struct: evcnts */
+
+struct vki_clockinfo {                                                                                                                                           
+        int     hz;             /* clock frequency */
+        int     tick;           /* micro-seconds per hz tick */
+        int     tickadj;        /* clock skew rate for adjtime() */
+        int     stathz;         /* statistics clock frequency */
+        int     profhz;         /* profiling clock frequency */
+};
+
+#define VKI_KERN_PROC_ALL            0      /* everything */
+#define VKI_KERN_PROC_PID            1      /* by process id */
+#define VKI_KERN_PROC_PGRP           2      /* by process group id */
+#define VKI_KERN_PROC_SESSION        3      /* by session of pid */
+#define VKI_KERN_PROC_TTY            4      /* by controlling tty */
+#define VKI_KERN_PROC_UID            5      /* by effective uid */
+#define VKI_KERN_PROC_RUID           6      /* by real uid */
+#define VKI_KERN_PROC_GID            7      /* by effective gid */                                                                                               
+#define VKI_KERN_PROC_RGID           8      /* by real gid */
+
+#define VKI_KERN_PROC_TTY_NODEV     VKI_NODEV           /* no controlling tty */
+#define VKI_KERN_PROC_TTY_REVOKE    ((vki_dev_t)-2)     /* revoked tty */
+
+struct vki_ki_pcred {                                                                                                                                            
+        void            *p_pad;
+        vki_uid_t           p_ruid;         /* Real user id */
+        vki_uid_t           p_svuid;        /* Saved effective user id */
+        vki_gid_t           p_rgid;         /* Real group id */
+        vki_gid_t           p_svgid;        /* Saved effective group id */
+        int             p_refcnt;       /* Number of references */
+};
+
+struct vki_ki_ucred {                                                                                                                                            
+        vki_uint32_t        cr_ref;                 /* reference count */
+        vki_uid_t           cr_uid;                 /* effective user id */
+        vki_gid_t           cr_gid;                 /* effective group id */
+        vki_uint32_t        cr_ngroups;             /* number of groups */
+        vki_gid_t           cr_groups[VKI_NGROUPS];     /* groups */
+};
+
+#define VKI_PTRTOUINT64(p) ((vki_uint64_t)(vki_uintptr_t)(p))
+#define VKI_UINT64TOPTR(u) ((void *)(vki_uintptr_t)(u))
+
+#define VKI_KI_NGROUPS      16
+#define VKI_KI_MAXCOMLEN    24      /* extra for 8 byte alignment */
+#define VKI_KI_WMESGLEN     8
+#define VKI_KI_MAXLOGNAME   24      /* extra for 8 byte alignment */
+#define VKI_KI_MAXEMULLEN   16
+#define VKI_KI_LNAMELEN     20      /* extra 4 for alignment */                                                                                                  
+   
+#define VKI_KI_NOCPU        (~(vki_uint64_t)0)
+
+typedef struct {
+        vki_uint32_t        __bits[4];
+} vki_ki_sigset_t;
+
+struct vki_kinfo_proc2 {
+        vki_uint64_t p_forw;                /* PTR: linked run/sleep queue. */                                                                                   
+        vki_uint64_t p_back;
+        vki_uint64_t p_paddr;               /* PTR: address of proc */
+
+        vki_uint64_t p_addr;                /* PTR: Kernel virtual addr of u-area */
+        vki_uint64_t p_fd;                  /* PTR: Ptr to open files structure. */
+        vki_uint64_t p_cwdi;                /* PTR: cdir/rdir/cmask info */
+        vki_uint64_t p_stats;               /* PTR: Accounting/statistics */
+        vki_uint64_t p_limit;               /* PTR: Process limits. */
+        vki_uint64_t p_vmspace;             /* PTR: Address space. */                                                                                            
+        vki_uint64_t p_sigacts;             /* PTR: Signal actions, state */
+        vki_uint64_t p_sess;                /* PTR: session pointer */
+        vki_uint64_t p_tsess;               /* PTR: tty session pointer */
+        vki_uint64_t p_ru;                  /* PTR: Exit information. XXX */
+
+        vki_int32_t p_eflag;                /* LONG: extra kinfo_proc2 flags */
+#define VKI_EPROC_CTTY      0x01    /* controlling tty vnode active */
+#define VKI_EPROC_SLEADER   0x02    /* session leader */
+        vki_int32_t p_exitsig;              /* INT: signal to sent to parent on exit */                                                                          
+        vki_int32_t p_flag;                 /* INT: P_* flags. */
+
+        vki_int32_t p_pid;                  /* PID_T: Process identifier. */
+        vki_int32_t p_ppid;                 /* PID_T: Parent process id */
+        vki_int32_t p_sid;                  /* PID_T: session id */
+        vki_int32_t p__pgid;                /* PID_T: process group id */
+                                        /* XXX: <sys/proc.h> hijacks p_pgid */
+        vki_int32_t p_tpgid;                /* PID_T: tty process group id */
+        vki_uint32_t p_uid;                 /* UID_T: effective user id */
+        vki_uint32_t p_ruid;                /* UID_T: real user id */
+        vki_uint32_t p_gid;                 /* GID_T: effective group id */
+        vki_uint32_t p_rgid;                /* GID_T: real group id */
+
+        vki_uint32_t p_groups[VKI_KI_NGROUPS];  /* GID_T: groups */
+        vki_int16_t p_ngroups;              /* SHORT: number of groups */
+
+        vki_int16_t p_jobc;                 /* SHORT: job control counter */                                                                                     
+        vki_uint32_t p_tdev;                /* XXX: DEV_T: controlling tty dev */
+
+        vki_uint32_t p_estcpu;              /* U_INT: Time averaged value of p_cpticks. */
+        vki_uint32_t p_rtime_sec;           /* STRUCT TIMEVAL: Real time. */
+        vki_uint32_t p_rtime_usec;          /* STRUCT TIMEVAL: Real time. */
+        vki_int32_t p_cpticks;              /* INT: Ticks of CPU time. */
+        vki_uint32_t p_pctcpu;              /* FIXPT_T: %cpu for this process during p_swtime */
+        vki_uint32_t p_swtime;              /* U_INT: Time swapped in or out. */
+        vki_uint32_t p_slptime;             /* U_INT: Time since last blocked. */                                                                                
+        vki_int32_t p_schedflags;           /* INT: PSCHED_* flags */
+
+        vki_uint64_t p_uticks;              /* U_QUAD_T: Statclock hits in user mode. */
+        vki_uint64_t p_sticks;              /* U_QUAD_T: Statclock hits in system mode. */
+        vki_uint64_t p_iticks;              /* U_QUAD_T: Statclock hits processing intr. */
+
+        vki_uint64_t p_tracep;              /* PTR: Trace to vnode or file */
+        vki_int32_t p_traceflag;            /* INT: Kernel trace points. */
+                                                                                                                                                             
+        vki_int32_t p_holdcnt;              /* INT: If non-zero, don't swap. */
+
+        vki_ki_sigset_t p_siglist;          /* SIGSET_T: Signals arrived but not delivered. */
+        vki_ki_sigset_t p_sigmask;          /* SIGSET_T: Current signal mask. */
+        vki_ki_sigset_t p_sigignore;        /* SIGSET_T: Signals being ignored. */
+        vki_ki_sigset_t p_sigcatch;         /* SIGSET_T: Signals being caught by user. */
+
+        vki_int8_t  p_stat;                 /* CHAR: S* process status (from LWP). */
+        vki_uint8_t p_priority;             /* U_CHAR: Process priority. */                                                                                      
+        vki_uint8_t p_usrpri;               /* U_CHAR: User-priority based on p_cpu and p_nice. */
+        vki_uint8_t p_nice;                 /* U_CHAR: Process "nice" value. */
+
+        vki_uint16_t p_xstat;               /* U_SHORT: Exit status for wait; also stop signal. */
+        vki_uint16_t p_acflag;              /* U_SHORT: Accounting flags. */
+
+        char    p_comm[VKI_KI_MAXCOMLEN];
+
+        char    p_wmesg[VKI_KI_WMESGLEN];   /* wchan message */                                                                                                  
+        vki_uint64_t p_wchan;               /* PTR: sleep address. */
+
+        char    p_login[VKI_KI_MAXLOGNAME]; /* setlogin() name */
+
+        vki_int32_t p_vm_rssize;            /* SEGSZ_T: current resident set size in pages */
+        vki_int32_t p_vm_tsize;             /* SEGSZ_T: text size (pages) */
+        vki_int32_t p_vm_dsize;             /* SEGSZ_T: data size (pages) */
+        vki_int32_t p_vm_ssize;             /* SEGSZ_T: stack size (pages) */
+        vki_int64_t p_uvalid;               /* CHAR: following p_u* parameters are valid */
+                                        /* XXX 64 bits for alignment */
+        vki_uint32_t p_ustart_sec;          /* STRUCT TIMEVAL: starting time. */
+        vki_uint32_t p_ustart_usec;         /* STRUCT TIMEVAL: starting time. */
+
+        vki_uint32_t p_uutime_sec;          /* STRUCT TIMEVAL: user time. */
+        vki_uint32_t p_uutime_usec;         /* STRUCT TIMEVAL: user time. */
+        vki_uint32_t p_ustime_sec;          /* STRUCT TIMEVAL: system time. */
+        vki_uint32_t p_ustime_usec;         /* STRUCT TIMEVAL: system time. */                                                                                   
+
+        vki_uint64_t p_uru_maxrss;          /* LONG: max resident set size. */
+        vki_uint64_t p_uru_ixrss;           /* LONG: integral shared memory size. */
+        vki_uint64_t p_uru_idrss;           /* LONG: integral unshared data ". */
+        vki_uint64_t p_uru_isrss;           /* LONG: integral unshared stack ". */
+        vki_uint64_t p_uru_minflt;          /* LONG: page reclaims. */
+        vki_uint64_t p_uru_majflt;          /* LONG: page faults. */
+        vki_uint64_t p_uru_nswap;           /* LONG: swaps. */
+        vki_uint64_t p_uru_inblock;         /* LONG: block input operations. */                                                                                  
+        vki_uint64_t p_uru_oublock;         /* LONG: block output operations. */
+        vki_uint64_t p_uru_msgsnd;          /* LONG: messages sent. */
+        vki_uint64_t p_uru_msgrcv;          /* LONG: messages received. */
+        vki_uint64_t p_uru_nsignals;        /* LONG: signals received. */
+        vki_uint64_t p_uru_nvcsw;           /* LONG: voluntary context switches. */
+        vki_uint64_t p_uru_nivcsw;          /* LONG: involuntary ". */
+
+        vki_uint32_t p_uctime_sec;          /* STRUCT TIMEVAL: child u+s time. */
+        vki_uint32_t p_uctime_usec;         /* STRUCT TIMEVAL: child u+s time. */                                                                                
+        vki_uint64_t p_cpuid;               /* LONG: CPU id */
+        vki_uint64_t p_realflag;            /* INT: P_* flags (not including LWPs). */
+        vki_uint64_t p_nlwps;               /* LONG: Number of LWPs */
+        vki_uint64_t p_nrlwps;              /* LONG: Number of running LWPs */
+        vki_uint64_t p_realstat;            /* LONG: non-LWP process status */
+        vki_uint32_t p_svuid;               /* UID_T: saved user id */
+        vki_uint32_t p_svgid;               /* GID_T: saved group id */
+        char p_ename[VKI_KI_MAXEMULLEN];    /* emulation name */
+        vki_int64_t p_vm_vsize;             /* SEGSZ_T: total map size (pages) */                                                                                
+        vki_int64_t p_vm_msize;             /* SEGSZ_T: stack-adjusted map size (pages) */
+};
+
+#define VKI_P_ADVLOCK               0x00000001
+#define VKI_P_CONTROLT              0x00000002
+#define VKI_L_INMEM                 0x00000004
+#define VKI_P_INMEM              /* 0x00000004 */   L_INMEM
+#define VKI_P_NOCLDSTOP             0x00000008
+#define VKI_P_PPWAIT                0x00000010
+#define VKI_P_PROFIL                0x00000020
+#define VKI_L_SELECT                0x00000040
+#define VKI_P_SELECT             /* 0x00000040 */   L_SELECT                                                                                                     
+#define VKI_L_SINTR                 0x00000080
+#define VKI_P_SINTR              /* 0x00000080 */   L_SINTR
+#define VKI_P_SUGID                 0x00000100
+#define VKI_L_SYSTEM                0x00000200
+#define VKI_P_SYSTEM             /* 0x00000200 */   L_SYSTEM
+#define VKI_L_SA                    0x00000400
+#define VKI_P_SA                 /* 0x00000400 */   L_SA
+#define VKI_P_TRACED                0x00000800
+#define VKI_P_WAITED                0x00001000                                                                                                                   
+#define VKI_P_WEXIT                 0x00002000
+#define VKI_P_EXEC                  0x00004000
+#define VKI_P_OWEUPC                0x00008000
+#define VKI_P_NOCLDWAIT             0x00020000
+#define VKI_P_32                    0x00040000
+#define VKI_P_CLDSIGIGN             0x00080000
+#define VKI_P_SYSTRACE              0x00200000
+#define VKI_P_CHTRACED              0x00400000
+#define VKI_P_STOPFORK              0x00800000                                                                                                                   
+#define VKI_P_STOPEXEC              0x01000000
+#define VKI_P_STOPEXIT              0x02000000
+#define VKI_P_SYSCALL               0x04000000
+
+#define VKI_L_DETACHED              0x00800000
+
+struct vki_kinfo_lwp {
+        vki_uint64_t l_forw;                /* PTR: linked run/sleep queue. */
+        vki_uint64_t l_back;
+        vki_uint64_t l_laddr;               /* PTR: Address of LWP */
+        vki_uint64_t l_addr;                /* PTR: Kernel virtual addr of u-area */
+        vki_int32_t l_lid;                  /* LWPID_T: LWP identifier */                                                                                        
+        vki_int32_t l_flag;                 /* INT: L_* flags. */
+        vki_uint32_t l_swtime;              /* U_INT: Time swapped in or out. */
+        vki_uint32_t l_slptime;             /* U_INT: Time since last blocked. */
+        vki_int32_t l_schedflags;           /* INT: PSCHED_* flags */
+        vki_int32_t l_holdcnt;              /* INT: If non-zero, don't swap. */
+        vki_uint8_t l_priority;             /* U_CHAR: Process priority. */
+        vki_uint8_t l_usrpri;               /* U_CHAR: User-priority based on l_cpu and p_nice. */
+        vki_int8_t  l_stat;                 /* CHAR: S* process status. */
+        vki_int8_t  l_pad1;                 /* fill out to 4-byte boundary */                                                                                    
+        vki_int32_t l_pad2;                 /* .. and then to an 8-byte boundary */
+        char    l_wmesg[VKI_KI_WMESGLEN];   /* wchan message */
+        vki_uint64_t l_wchan;               /* PTR: sleep address. */
+        vki_uint64_t l_cpuid;               /* LONG: CPU id */
+        vki_uint32_t l_rtime_sec;           /* STRUCT TIMEVAL: Real time. */
+        vki_uint32_t l_rtime_usec;          /* STRUCT TIMEVAL: Real time. */
+        vki_uint32_t l_cpticks;             /* INT: ticks during l_swtime */
+        vki_uint32_t l_pctcpu;              /* FIXPT_T: cpu usage for ps */
+        vki_uint32_t l_pid;                 /* PID_T: process identifier */                                                                                      
+        char    l_name[VKI_KI_LNAMELEN];    /* CHAR[]: name, may be empty */
+};
+
+#define VKI_KERN_PROC_ARGV          1       /* argv */
+#define VKI_KERN_PROC_NARGV         2       /* number of strings in above */
+#define VKI_KERN_PROC_ENV           3       /* environ */                                                                                                        
+#define VKI_KERN_PROC_NENV          4       /* number of strings in above */
+#define VKI_KERN_PROC_PATHNAME      5       /* path to executable */
+
+#define VKI_KERN_SYSVIPC_INFO       1       /* struct: number of valid kern ids */
+#define VKI_KERN_SYSVIPC_MSG        2       /* int: SysV message queue support */
+#define VKI_KERN_SYSVIPC_SEM        3       /* int: SysV semaphore support */                                                                                    
+#define VKI_KERN_SYSVIPC_SHM        4       /* int: SysV shared memory support */
+#define VKI_KERN_SYSVIPC_SHMMAX     5       /* int: max shared memory segment size (bytes) */
+#define VKI_KERN_SYSVIPC_SHMMNI     6       /* int: max number of shared memory identifiers */
+#define VKI_KERN_SYSVIPC_SHMSEG     7       /* int: max shared memory segments per process */
+#define VKI_KERN_SYSVIPC_SHMMAXPGS  8       /* int: max amount of shared memory (pages) */
+#define VKI_KERN_SYSVIPC_SHMUSEPHYS 9       /* int: physical memory usage */
+
+#define VKI_KERN_SYSVIPC_MSG_INFO           4       /* msginfo and msgid_ds */
+#define VKI_KERN_SYSVIPC_SEM_INFO           5       /* seminfo and semid_ds */
+#define VKI_KERN_SYSVIPC_SHM_INFO           6       /* shminfo and shmid_ds */
+
+#define VKI_KERN_TKSTAT_NIN                 1       /* total input character */
+#define VKI_KERN_TKSTAT_NOUT                2       /* total output character */
+#define VKI_KERN_TKSTAT_CANCC               3       /* canonical input character */
+#define VKI_KERN_TKSTAT_RAWCC               4       /* raw input character */
+
+struct vki_kinfo_drivers {
+        vki_devmajor_t      d_cmajor;
+        vki_devmajor_t      d_bmajor;
+        char            d_name[24];
+};
+
+#define VKI_KERN_BUF_ALL    0               /* all buffers */
+
+struct vki_buf_sysctl {
+        vki_uint32_t b_flags;       /* LONG: B_* flags */
+        vki_int32_t  b_error;       /* INT: Errno value */
+        vki_int32_t  b_prio;        /* INT: Hint for buffer queue discipline */                                                                                  
+        vki_uint32_t b_dev;         /* DEV_T: Device associated with buffer */
+        vki_uint64_t b_bufsize;     /* LONG: Allocated buffer size */
+        vki_uint64_t b_bcount;      /* LONG: Valid bytes in buffer */
+        vki_uint64_t b_resid;       /* LONG: Remaining I/O */
+        vki_uint64_t b_addr;        /* CADDR_T: Memory, superblocks, indirect... */
+        vki_uint64_t b_blkno;       /* DADDR_T: Underlying physical block number */
+        vki_uint64_t b_rawblkno;    /* DADDR_T: Raw underlying physical block */
+        vki_uint64_t b_iodone;      /* PTR: Function called upon completion */
+        vki_uint64_t b_proc;        /* PTR: Associated proc if B_PHYS set */                                                                                     
+        vki_uint64_t b_vp;          /* PTR: File vnode */
+        vki_uint64_t b_saveaddr;    /* PTR: Original b_addr for physio */
+        vki_uint64_t b_lblkno;      /* DADDR_T: Logical block number */
+};
+
+struct vki_kinfo_file {
+        vki_uint64_t        ki_fileaddr;    /* PTR: address of struct file */
+        vki_uint32_t        ki_flag;        /* INT: flags (see fcntl.h) */
+        vki_uint32_t        ki_iflags;      /* INT: internal flags */                                                                                            
+        vki_uint32_t        ki_ftype;       /* INT: descriptor type */
+        vki_uint32_t        ki_count;       /* UINT: reference count */
+        vki_uint32_t        ki_msgcount;    /* UINT: references from msg queue */
+        vki_uint32_t        ki_usecount;    /* INT: number active users */
+        vki_uint64_t        ki_fucred;      /* PTR: creds for descriptor */
+        vki_uint32_t        ki_fuid;        /* UID_T: descriptor credentials */
+        vki_uint32_t        ki_fgid;        /* GID_T: descriptor credentials */
+        vki_uint64_t        ki_fops;        /* PTR: address of fileops */
+        vki_uint64_t        ki_foffset;     /* OFF_T: offset */                                                                                                  
+        vki_uint64_t        ki_fdata;       /* PTR: descriptor data */
+
+        /* vnode information to glue this file to something */
+        vki_uint64_t        ki_vun;         /* PTR: socket, specinfo, etc */
+        vki_uint64_t        ki_vsize;       /* OFF_T: size of file */
+        vki_uint32_t        ki_vtype;       /* ENUM: vnode type */
+        vki_uint32_t        ki_vtag;        /* ENUM: type of underlying data */
+        vki_uint64_t        ki_vdata;       /* PTR: private data for fs */
+        /* process information when retrieved via KERN_FILE_BYPID */
+        vki_uint32_t        ki_pid;         /* PID_T: process id */
+        vki_int32_t         ki_fd;          /* INT: descriptor number */
+        vki_uint32_t        ki_ofileflags;  /* CHAR: open file flags */
+        vki_uint32_t        _ki_padto64bits;
+};
+
+#define VKI_KERN_FILE_BYFILE        1
+#define VKI_KERN_FILE_BYPID         2                                                                                                                            
+#define VKI_KERN_FILESLOP           10
+
+struct vki_evcnt_sysctl {                                                                                                                                        
+        vki_uint64_t        ev_count;               /* current count */
+        vki_uint64_t        ev_addr;                /* kernel address of evcnt */
+        vki_uint64_t        ev_parent;              /* kernel address of parent */
+        vki_uint8_t         ev_type;                /* EVCNT_TRAP_* */
+        vki_uint8_t         ev_grouplen;            /* length of group with NUL */
+        vki_uint8_t         ev_namelen;             /* length of name with NUL */
+        vki_uint8_t         ev_len;                 /* multiply by 8 */
+        /*
+         * Now the group and name strings follow (both include the trailing                                                                                  
+         * NUL).  ev_name start at &ev_strings[ev_grouplen+1]
+         */
+        char            ev_strings[0];
+};
+
+#define VKI_KERN_EVCNT_COUNT_ANY            0
+#define VKI_KERN_EVCNT_COUNT_NONZERO        1
+
+#define VKI_KVME_TYPE_NONE          0
+#define VKI_KVME_TYPE_OBJECT        1
+#define VKI_KVME_TYPE_VNODE         2
+#define VKI_KVME_TYPE_KERN          3
+#define VKI_KVME_TYPE_DEVICE        4
+#define VKI_KVME_TYPE_ANON          5
+#define VKI_KVME_TYPE_SUBMAP        6
+#define VKI_KVME_TYPE_UNKNOWN       255
+
+#define VKI_KVME_PROT_READ          0x00000001
+#define VKI_KVME_PROT_WRITE         0x00000002                                                                                                                   
+#define VKI_KVME_PROT_EXEC          0x00000004
+
+#define VKI_KVME_FLAG_COW           0x00000001
+#define VKI_KVME_FLAG_NEEDS_COPY    0x00000002
+#define VKI_KVME_FLAG_NOCOREDUMP    0x00000004
+#define VKI_KVME_FLAG_PAGEABLE      0x00000008
+#define VKI_KVME_FLAG_GROWS_UP      0x00000010
+#define VKI_KVME_FLAG_GROWS_DOWN    0x00000020
+
+                                                                                                                                                             
+struct vki_kinfo_vmentry {
+        vki_uint64_t kve_start;                     /* Starting address. */
+        vki_uint64_t kve_end;                       /* Finishing address. */
+        vki_uint64_t kve_offset;                    /* Mapping offset in object */
+
+        vki_uint32_t kve_type;                      /* Type of map entry. */
+        vki_uint32_t kve_flags;                     /* Flags on map entry. */
+        vki_uint32_t kve_count;                     /* Number of pages/entries */                                                                                
+        vki_uint32_t kve_wired_count;               /* Number of wired pages */
+
+        vki_uint32_t kve_advice;                    /* Advice */
+        vki_uint32_t kve_attributes;                /* Map attribute */
+
+        vki_uint32_t kve_protection;                /* Protection bitmask. */
+        vki_uint32_t kve_max_protection;            /* Max protection bitmask */
+
+        vki_uint32_t kve_ref_count;                 /* VM obj ref count. */                                                                                      
+        vki_uint32_t kve_inheritance;               /* Inheritance */
+
+        vki_uint64_t kve_vn_fileid;                 /* inode number if vnode */
+        vki_uint64_t kve_vn_size;                   /* File size. */
+        vki_uint64_t kve_vn_fsid;                   /* dev_t of vnode location */
+        vki_uint64_t kve_vn_rdev;                   /* Device id if device. */
+
+        vki_uint32_t kve_vn_type;                   /* Vnode type. */
+        vki_uint32_t kve_vn_mode;                   /* File mode. */
+
+        char     kve_path[VKI_PATH_MAX];            /* Path to VM obj, if any. */
+};
+
+#define VKI_HW_MACHINE       1              /* string: machine class */
+#define VKI_HW_MODEL         2              /* string: specific machine model */                                                                                 
+#define VKI_HW_NCPU          3              /* int: number of cpus */
+#define VKI_HW_BYTEORDER     4              /* int: machine byte order */
+#define VKI_HW_PHYSMEM       5              /* int: total memory (bytes) */
+#define VKI_HW_USERMEM       6              /* int: non-kernel memory (bytes) */
+#define VKI_HW_PAGESIZE      7              /* int: software page size */
+#define VKI_HW_DISKNAMES     8              /* string: disk drive names */
+#define VKI_HW_IOSTATS       9              /* struct: iostats[] */
+#define VKI_HW_MACHINE_ARCH 10              /* string: machine architecture */
+#define VKI_HW_ALIGNBYTES   11              /* int: ALIGNBYTES for the kernel */                                                                                 
+#define VKI_HW_CNMAGIC      12              /* string: console magic sequence(s) */
+#define VKI_HW_PHYSMEM64    13              /* quad: total memory (bytes) */
+#define VKI_HW_USERMEM64    14              /* quad: non-kernel memory (bytes) */
+#define VKI_HW_IOSTATNAMES  15              /* string: iostat names */
+#define VKI_HW_NCPUONLINE   16              /* number CPUs online */
+
+/*
+ * CTL_USER definitions
+ */                                                                                                                                                          
+#define VKI_USER_CS_PATH             1      /* string: _CS_PATH */
+#define VKI_USER_BC_BASE_MAX         2      /* int: BC_BASE_MAX */
+#define VKI_USER_BC_DIM_MAX          3      /* int: BC_DIM_MAX */
+#define VKI_USER_BC_SCALE_MAX        4      /* int: BC_SCALE_MAX */
+#define VKI_USER_BC_STRING_MAX       5      /* int: BC_STRING_MAX */
+#define VKI_USER_COLL_WEIGHTS_MAX    6      /* int: COLL_WEIGHTS_MAX */
+#define VKI_USER_EXPR_NEST_MAX       7      /* int: EXPR_NEST_MAX */
+#define VKI_USER_LINE_MAX            8      /* int: LINE_MAX */
+#define VKI_USER_RE_DUP_MAX          9      /* int: RE_DUP_MAX */                                                                                                
+#define VKI_USER_POSIX2_VERSION     10      /* int: POSIX2_VERSION */
+#define VKI_USER_POSIX2_C_BIND      11      /* int: POSIX2_C_BIND */
+#define VKI_USER_POSIX2_C_DEV       12      /* int: POSIX2_C_DEV */
+#define VKI_USER_POSIX2_CHAR_TERM   13      /* int: POSIX2_CHAR_TERM */
+#define VKI_USER_POSIX2_FORT_DEV    14      /* int: POSIX2_FORT_DEV */
+#define VKI_USER_POSIX2_FORT_RUN    15      /* int: POSIX2_FORT_RUN */
+#define VKI_USER_POSIX2_LOCALEDEF   16      /* int: POSIX2_LOCALEDEF */
+#define VKI_USER_POSIX2_SW_DEV      17      /* int: POSIX2_SW_DEV */
+#define VKI_USER_POSIX2_UPE         18      /* int: POSIX2_UPE */                                                                                                
+#define VKI_USER_STREAM_MAX         19      /* int: POSIX2_STREAM_MAX */
+#define VKI_USER_TZNAME_MAX         20      /* int: _POSIX_TZNAME_MAX */
+#define VKI_USER_ATEXIT_MAX         21      /* int: {ATEXIT_MAX} */
+
+#define VKI_DDBCTL_RADIX            1       /* int: Input and output radix */
+#define VKI_DDBCTL_MAXOFF           2       /* int: max symbol offset */                                                                                         
+#define VKI_DDBCTL_MAXWIDTH         3       /* int: width of the display line */
+#define VKI_DDBCTL_LINES            4       /* int: number of display lines */
+#define VKI_DDBCTL_TABSTOPS         5       /* int: tab width */
+#define VKI_DDBCTL_ONPANIC          6       /* int: DDB on panic if non-zero */
+#define VKI_DDBCTL_FROMCONSOLE      7       /* int: DDB via console if non-zero */
+
+#define VKI_CTL_DEBUG_NAME          0       /* string: variable name */
+#define VKI_CTL_DEBUG_VALUE         1       /* int: variable value */
+
+#define VKI_PROC_CURPROC    (~((vki_u_int)1 << 31))
+
+#define VKI_PROC_PID_CORENAME       1                                                                                                                            
+#define VKI_PROC_PID_LIMIT          2
+#define VKI_PROC_PID_STOPFORK       3
+#define VKI_PROC_PID_STOPEXEC       4
+#define VKI_PROC_PID_STOPEXIT       5
+#define VKI_PROC_PID_PAXFLAGS       6
+
+#define VKI_PROC_PID_LIMIT_CPU      (VKI_RLIMIT_CPU+1)
+#define VKI_PROC_PID_LIMIT_FSIZE    (VKI_RLIMIT_FSIZE+1)                                                                                                             
+#define VKI_PROC_PID_LIMIT_DATA     (VKI_RLIMIT_DATA+1)
+#define VKI_PROC_PID_LIMIT_STACK    (VKI_RLIMIT_STACK+1)
+#define VKI_PROC_PID_LIMIT_CORE     (VKI_RLIMIT_CORE+1)
+#define VKI_PROC_PID_LIMIT_RSS      (VKI_RLIMIT_RSS+1)
+#define VKI_PROC_PID_LIMIT_MEMLOCK  (VKI_RLIMIT_MEMLOCK+1)
+#define VKI_PROC_PID_LIMIT_NPROC    (VKI_RLIMIT_NPROC+1)
+#define VKI_PROC_PID_LIMIT_NOFILE   (VKI_RLIMIT_NOFILE+1)
+#define VKI_PROC_PID_LIMIT_SBSIZE   (VKI_RLIMIT_SBSIZE+1)
+#define VKI_PROC_PID_LIMIT_AS       (VKI_RLIMIT_AS+1)                                                                                                                
+#define VKI_PROC_PID_LIMIT_NTHR     (VKI_RLIMIT_NTHR+1)
+
+/* for each type, either hard or soft value */ 
+#define VKI_PROC_PID_LIMIT_TYPE_SOFT        1
+#define VKI_PROC_PID_LIMIT_TYPE_HARD        2
+
+/*
+ * Export PAX flag definitions to userland.
+ *
+ * XXX These are duplicated from sys/pax.h but that header is not
+ * XXX installed.
+ */
+#define VKI_CTL_PROC_PAXFLAGS_ASLR          0x01
+#define VKI_CTL_PROC_PAXFLAGS_MPROTECT      0x02
+#define VKI_CTL_PROC_PAXFLAGS_GUARD         0x04
+
+#define VKI_EMUL_LINUX      1
+#define VKI_EMUL_LINUX32    5
+
+#endif // __VKI_NETBSD_H
+
+/*--------------------------------------------------------------------*/
+/*--- end                                                          ---*/
+/*--------------------------------------------------------------------*/
