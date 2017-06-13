$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_posix.h.orig	2017-06-12 15:01:29.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_posix.h
@@ -18,18 +18,31 @@
 #include "sanitizer_internal_defs.h"
 #include "sanitizer_platform.h"
 
+// FreeBSD's and NetBSD's dlopen() returns a pointer to an Obj_Entry structure
+// that incorporates the map structure.
 #if SANITIZER_FREEBSD
-// FreeBSD's dlopen() returns a pointer to an Obj_Entry structure that
-// incorporates the map structure.
 # define GET_LINK_MAP_BY_DLOPEN_HANDLE(handle) \
     ((link_map*)((handle) == nullptr ? nullptr : ((char*)(handle) + 544)))
-// Get sys/_types.h, because that tells us whether 64-bit inodes are
-// used in struct dirent below.
-#include <sys/_types.h>
+#elif SANITIZER_NETBSD
+#if defined(__x86_64__)
+# define GET_LINK_MAP_BY_DLOPEN_HANDLE(handle) \
+    ((link_map*)((handle) == nullptr ? nullptr : ((char*)(handle) + 608)))
+#elif defined(__i386__)
+# define GET_LINK_MAP_BY_DLOPEN_HANDLE(handle) \
+    ((link_map*)((handle) == nullptr ? nullptr : ((char*)(handle) + 324)))
+#else
+#error Port sanitizer_platform_limits_posix.h.
+#endif
 #else
 # define GET_LINK_MAP_BY_DLOPEN_HANDLE(handle) ((link_map*)(handle))
 #endif  // !SANITIZER_FREEBSD
 
+#if SANITIZER_FREEBSD
+// Get sys/_types.h, because that tells us whether 64-bit inodes are
+// used in struct dirent below.
+#include <sys/_types.h>
+#endif
+
 #ifndef __GLIBC_PREREQ
 #define __GLIBC_PREREQ(x, y) 0
 #endif
@@ -37,7 +50,7 @@
 namespace __sanitizer {
   extern unsigned struct_utsname_sz;
   extern unsigned struct_stat_sz;
-#if !SANITIZER_FREEBSD && !SANITIZER_IOS
+#if !SANITIZER_FREEBSD && !SANITIZER_IOS && !SANITIZER_NETBSD
   extern unsigned struct_stat64_sz;
 #endif
   extern unsigned struct_rusage_sz;
@@ -55,10 +68,14 @@ namespace __sanitizer {
   extern unsigned struct_itimerspec_sz;
   extern unsigned struct_sigevent_sz;
   extern unsigned struct_sched_param_sz;
+#if !SANITIZER_NETBSD
   extern unsigned struct_statfs64_sz;
+#endif
 
 #if !SANITIZER_ANDROID
+#if !SANITIZER_NETBSD
   extern unsigned struct_statfs_sz;
+#endif
   extern unsigned struct_sockaddr_sz;
   extern unsigned ucontext_t_sz;
 #endif // !SANITIZER_ANDROID
@@ -121,18 +138,21 @@ namespace __sanitizer {
 #endif  // SANITIZER_LINUX
 
 #if SANITIZER_LINUX || SANITIZER_FREEBSD
-
 #if defined(__powerpc64__) || defined(__s390__)
   const unsigned struct___old_kernel_stat_sz = 0;
 #elif !defined(__sparc__)
   const unsigned struct___old_kernel_stat_sz = 32;
 #endif
+#endif // SANITIZER_LINUX || SANITIZER_FREEBSD
+
+#if SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
 
   extern unsigned struct_rlimit_sz;
   extern unsigned struct_utimbuf_sz;
   extern unsigned struct_timespec_sz;
 
   struct __sanitizer_iocb {
+#if SANITIZER_LINUX || SANITIZER_FREEBSD
     u64   aio_data;
     u32   aio_key_or_aio_reserved1; // Simply crazy.
     u32   aio_reserved1_or_aio_key; // Luckily, we don't need these.
@@ -144,21 +164,53 @@ namespace __sanitizer {
     s64   aio_offset;
     u64   aio_reserved2;
     u64   aio_reserved3;
+#elif SANITIZER_NETBSD
+#if defined(__x86_64__)
+    u64   aio_offset;
+    u64   aio_buf;
+    u64   aio_nbytes;
+    u32   aio_fildes;
+    u32   aio_lio_opcode;
+    u64   aio_reqprio;
+    u8    aio_sigevent[32];
+    u32   _state;
+    u32   _errno;
+    u64   _retval;
+#elif defined(__i386__)
+    u64   aio_offset;
+    u32   aio_buf;
+    u32   aio_nbytes;
+    u32   aio_fildes;
+    u32   aio_lio_opcode;
+    u32   aio_reqprio;
+    u8    aio_sigevent[20];
+    u32   _state;
+    u32   _errno;
+    u32   _retval;
+#else
+#error port this to your platform
+#endif
+#endif
   };
 
+#if SANITIZER_LINUX || SANITIZER_FREEBSD
   struct __sanitizer_io_event {
     u64 data;
     u64 obj;
     u64 res;
     u64 res2;
   };
+#endif
 
+#if SANITIZER_LINUX || SANITIZER_FREEBSD
   const unsigned iocb_cmd_pread = 0;
   const unsigned iocb_cmd_pwrite = 1;
   const unsigned iocb_cmd_preadv = 7;
   const unsigned iocb_cmd_pwritev = 8;
+#endif
 
   struct __sanitizer___sysctl_args {
+#if SANITIZER_LINUX || SANITIZER_FREEBSD
     int *name;
     int nlen;
     void *oldval;
@@ -166,10 +218,32 @@ namespace __sanitizer {
     void *newval;
     uptr newlen;
     unsigned long ___unused[4];
+#else
+#if defined(__x86_64__)
+    u64   name;
+    u32   namelen;
+    u64   oldp;
+    u64   oldlenp;
+    u64   newp;
+    u64   newlen;
+#elif defined(__i386__)
+    u32   name;
+    u32   namelen;
+    u32   oldp;
+    u32   oldlenp;
+    u32   newp;
+    u32   newlen;
+#else
+#error port this
+#endif
+#endif
   };
 
+#if SANITIZER_LINUX || SANITIZER_FREEBSD
   const unsigned old_sigset_t_sz = sizeof(unsigned long);
+#endif
 
+#if SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
   struct __sanitizer_sem_t {
 #if SANITIZER_ANDROID && defined(_LP64)
     int data[4];
@@ -179,6 +253,14 @@ namespace __sanitizer {
     uptr data[4];
 #elif SANITIZER_FREEBSD
     u32 data[4];
+#elif SANITIZER_NETBSD
+#if defined(__x86_64__)
+    u8 data[40];
+#elif defined(__i386__)
+    u8 data[20];
+#else
+#error port this to your platform
+#endif
 #endif
   };
 #endif // SANITIZER_LINUX || SANITIZER_FREEBSD
@@ -303,7 +385,7 @@ namespace __sanitizer {
   #endif
 #endif
   };
-#elif SANITIZER_FREEBSD
+#elif SANITIZER_FREEBSD || SANITIZER_NETBSD
   struct __sanitizer_ipc_perm {
     unsigned int cuid;
     unsigned int cgid;
@@ -326,12 +408,12 @@ namespace __sanitizer {
   };
 #endif
 
-#if (SANITIZER_LINUX || SANITIZER_FREEBSD) && !SANITIZER_ANDROID
+#if (SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD) && !SANITIZER_ANDROID
   extern unsigned struct_msqid_ds_sz;
   extern unsigned struct_mq_attr_sz;
   extern unsigned struct_timex_sz;
   extern unsigned struct_statvfs_sz;
-#endif  // (SANITIZER_LINUX || SANITIZER_FREEBSD) && !SANITIZER_ANDROID
+#endif  // (SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD) && !SANITIZER_ANDROID
 
   struct __sanitizer_iovec {
     void *iov_base;
@@ -351,6 +433,9 @@ namespace __sanitizer {
 # endif
     void *ifa_dstaddr; // (struct sockaddr *)
     void *ifa_data;
+#if SANITIZER_NETBSD
+    unsigned int ifa_addrflags;
+#endif
   };
 #endif  // !SANITIZER_ANDROID
 
@@ -381,7 +466,7 @@ namespace __sanitizer {
     char *pw_passwd;
     int pw_uid;
     int pw_gid;
-#if SANITIZER_MAC || SANITIZER_FREEBSD
+#if SANITIZER_MAC || SANITIZER_FREEBSD || SANITIZER_NETBSD
     long pw_change;
     char *pw_class;
 #endif
@@ -390,7 +475,7 @@ namespace __sanitizer {
 #endif
     char *pw_dir;
     char *pw_shell;
-#if SANITIZER_MAC || SANITIZER_FREEBSD
+#if SANITIZER_MAC || SANITIZER_FREEBSD || SANITIZER_NETBSD
     long pw_expire;
 #endif
 #if SANITIZER_FREEBSD
@@ -405,7 +490,7 @@ namespace __sanitizer {
     char **gr_mem;
   };
 
-#if defined(__x86_64__) && !defined(_LP64)
+#if SANITIZER_NETBSD || (defined(__x86_64__) && !defined(_LP64))
   typedef long long __sanitizer_time_t;
 #else
   typedef long __sanitizer_time_t;
@@ -447,7 +532,7 @@ namespace __sanitizer {
   };
 #endif
 
-#if SANITIZER_MAC || SANITIZER_FREEBSD
+#if SANITIZER_MAC || SANITIZER_FREEBSD || SANITIZER_NETBSD
   struct __sanitizer_msghdr {
     void *msg_name;
     unsigned msg_namelen;
@@ -497,6 +582,16 @@ namespace __sanitizer {
     unsigned short d_reclen;
     // more fields that we don't care about
   };
+#elif SANITIZER_NETBSD
+  struct __sanitizer_dirent {
+    u64 d_fileno;
+    u16 d_reclen;
+#if 0 // not needed here?
+    u16 d_namlen;
+    u8  d_type;
+    u8  d_name[512];
+#endif
+  };
 #elif SANITIZER_ANDROID || defined(__x86_64__)
   struct __sanitizer_dirent {
     unsigned long long d_ino;
@@ -531,7 +626,7 @@ namespace __sanitizer {
   typedef long __sanitizer_clock_t;
 #endif
 
-#if SANITIZER_LINUX
+#if SANITIZER_LINUX || SANITIZER_NETBSD
   typedef int __sanitizer_clockid_t;
 #endif
 
@@ -562,8 +657,22 @@ namespace __sanitizer {
   typedef struct {
     unsigned long fds_bits[1024 / (8 * sizeof(long))];
   } __sanitizer___kernel_fd_set;
+#elif SANITIZER_NETBSD
+  typedef u32 __sanitizer___kernel_uid_t;
+  typedef u32 __sanitizer___kernel_gid_t;
+  typedef u64 __sanitizer___kernel_off_t;
+  typedef struct {
+    u32 fds_bits[8];
+  } __sanitizer___kernel_fd_set;
 #endif
 
+#if SANITIZER_NETBSD
+  typedef struct {
+    unsigned int pta_magic;
+    int pta_flags;
+    void *pta_private;
+  } __sanitizer_pthread_attr_t;
+#else
   // This thing depends on the platform. We are only interested in the upper
   // limit. Verified with a compiler assert in .cc.
   const int pthread_attr_t_max_sz = 128;
@@ -571,6 +680,7 @@ namespace __sanitizer {
     char size[pthread_attr_t_max_sz]; // NOLINT
     void *align;
   };
+#endif
 
 #if SANITIZER_ANDROID
 # if SANITIZER_MIPS
@@ -590,6 +700,10 @@ namespace __sanitizer {
      // uint32_t * 4
      unsigned int __bits[4];
   };
+#elif SANITIZER_NETBSD
+  struct __sanitizer_sigset_t {
+     u32 __bits[4];
+  };
 #endif
 
   // Linux system headers define the 'sa_handler' and 'sa_sigaction' macros.
@@ -631,7 +745,7 @@ namespace __sanitizer {
       void (*sigaction)(int sig, void *siginfo, void *uctx);
       void (*handler)(int sig);
     };
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
     int sa_flags;
     __sanitizer_sigset_t sa_mask;
 #else
@@ -670,7 +784,7 @@ namespace __sanitizer {
   };
 #endif // !SANITIZER_ANDROID
 
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
   typedef __sanitizer_sigset_t __sanitizer_kernel_sigset_t;
 #elif defined(__mips__)
   struct __sanitizer_kernel_sigset_t {
@@ -717,7 +831,7 @@ namespace __sanitizer {
   extern int af_inet6;
   uptr __sanitizer_in_addr_sz(int af);
 
-#if SANITIZER_LINUX || SANITIZER_FREEBSD
+#if SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
   struct __sanitizer_dl_phdr_info {
     uptr dlpi_addr;
     const char *dlpi_name;
@@ -733,7 +847,7 @@ namespace __sanitizer {
     int ai_family;
     int ai_socktype;
     int ai_protocol;
-#if SANITIZER_ANDROID || SANITIZER_MAC || SANITIZER_FREEBSD
+#if SANITIZER_ANDROID || SANITIZER_MAC || SANITIZER_FREEBSD || SANITIZER_NETBSD
     unsigned ai_addrlen;
     char *ai_canonname;
     void *ai_addr;
@@ -759,7 +873,7 @@ namespace __sanitizer {
     short revents;
   };
 
-#if SANITIZER_ANDROID || SANITIZER_MAC || SANITIZER_FREEBSD
+#if SANITIZER_ANDROID || SANITIZER_MAC || SANITIZER_FREEBSD || SANITIZER_NETBSD
   typedef unsigned __sanitizer_nfds_t;
 #else
   typedef unsigned long __sanitizer_nfds_t;
@@ -779,7 +893,7 @@ namespace __sanitizer {
     int (*gl_lstat)(const char *, void *);
     int (*gl_stat)(const char *, void *);
   };
-# elif SANITIZER_FREEBSD
+# elif SANITIZER_FREEBSD || SANITIZER_NETBSD
   struct __sanitizer_glob_t {
     uptr gl_pathc;
     uptr gl_matchc;
@@ -793,9 +907,9 @@ namespace __sanitizer {
     int (*gl_lstat)(const char*, void* /* struct stat* */);
     int (*gl_stat)(const char*, void* /* struct stat* */);
   };
-# endif  // SANITIZER_FREEBSD
+# endif  // SANITIZER_FREEBSD || SANITIZER_NETBSD
 
-# if SANITIZER_LINUX || SANITIZER_FREEBSD
+# if SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
   extern int glob_nomatch;
   extern int glob_altdirfunc;
 # endif
@@ -807,7 +921,7 @@ namespace __sanitizer {
     uptr we_wordc;
     char **we_wordv;
     uptr we_offs;
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
     char *we_strings;
     uptr we_nbytes;
 #endif
@@ -832,6 +946,37 @@ namespace __sanitizer {
     int _fileno;
   };
 # define SANITIZER_HAS_STRUCT_FILE 1
+#elif SANITIZER_NETBSD
+  struct __sanitizer_FILE {
+    unsigned char *_p;
+    int     _r;
+    int     _w;
+    unsigned short _flags;
+    short   _file;
+    struct  {
+        unsigned char *_base;
+        int     _size;
+    } _bf;
+    int     _lbfsize;
+    void    *_cookie;
+    int     (*_close)(void *);
+    u64 (*_read) (void *, void *, uptr);
+    u64 (*_seek) (void *, u64, int);
+    uptr (*_write)(void *, const void *, uptr);
+    struct {
+        unsigned char *_base;
+        int     _size;
+    } _ext;
+    unsigned char *_up;
+    int     _ur;
+    unsigned char _ubuf[3];
+    unsigned char _nbuf[1];
+    int     (*_flush)(void *);
+    char    _lb_unused[sizeof(uptr)];
+    int     _blksize;
+    u64 _offset;
+  };
+# define SANITIZER_HAS_STRUCT_FILE 1
 #else
   typedef void __sanitizer_FILE;
 # define SANITIZER_HAS_STRUCT_FILE 0
@@ -873,6 +1018,10 @@ namespace __sanitizer {
   extern int shmctl_shm_stat;
 #endif
 
+#if SANITIZER_NETBSD
+  extern unsigned struct_shminfo_sz;
+#endif
+
 #if !SANITIZER_MAC && !SANITIZER_FREEBSD
   extern unsigned struct_utmp_sz;
 #endif
@@ -923,6 +1072,7 @@ struct __sanitizer_cookie_io_functions_t
 };
 #endif
 
+#if !SANITIZER_NETBSD
 #define IOC_NRBITS 8
 #define IOC_TYPEBITS 8
 #if defined(__powerpc__) || defined(__powerpc64__) || defined(__mips__) || \
@@ -966,13 +1116,17 @@ struct __sanitizer_cookie_io_functions_t
 #else
 #define IOC_SIZE(nr) (((nr) >> IOC_SIZESHIFT) & IOC_SIZEMASK)
 #endif
+#endif
 
   extern unsigned struct_ifreq_sz;
   extern unsigned struct_termios_sz;
   extern unsigned struct_winsize_sz;
 
-#if SANITIZER_LINUX
+#if SANITIZER_LINUX || SANITIZER_NETBSD
   extern unsigned struct_arpreq_sz;
+#endif
+
+#if SANITIZER_LINUX
   extern unsigned struct_cdrom_msf_sz;
   extern unsigned struct_cdrom_multisession_sz;
   extern unsigned struct_cdrom_read_audio_sz;
@@ -1006,6 +1160,9 @@ struct __sanitizer_cookie_io_functions_t
   extern unsigned struct_copr_debug_buf_sz;
   extern unsigned struct_copr_msg_sz;
   extern unsigned struct_midi_info_sz;
+#endif
+
+#if SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
   extern unsigned struct_mtget_sz;
   extern unsigned struct_mtop_sz;
   extern unsigned struct_rtentry_sz;
@@ -1013,7 +1170,7 @@ struct __sanitizer_cookie_io_functions_t
   extern unsigned struct_seq_event_rec_sz;
   extern unsigned struct_synth_info_sz;
   extern unsigned struct_vt_mode_sz;
-#endif // SANITIZER_LINUX || SANITIZER_FREEBSD
+#endif // SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
 
 #if SANITIZER_LINUX && !SANITIZER_ANDROID
   extern unsigned struct_ax25_parms_struct_sz;
@@ -1035,10 +1192,10 @@ struct __sanitizer_cookie_io_functions_t
   extern unsigned struct_unimapinit_sz;
 #endif  // SANITIZER_LINUX && !SANITIZER_ANDROID
 
-#if (SANITIZER_LINUX || SANITIZER_FREEBSD) && !SANITIZER_ANDROID
+#if (SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD) && !SANITIZER_ANDROID
   extern unsigned struct_audio_buf_info_sz;
   extern unsigned struct_ppp_stats_sz;
-#endif  // (SANITIZER_LINUX || SANITIZER_FREEBSD) && !SANITIZER_ANDROID
+#endif  // (SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD) && !SANITIZER_ANDROID
 
 #if !SANITIZER_ANDROID && !SANITIZER_MAC
   extern unsigned struct_sioc_sg_req_sz;
@@ -1095,7 +1252,7 @@ struct __sanitizer_cookie_io_functions_t
   extern unsigned IOCTL_TIOCSPGRP;
   extern unsigned IOCTL_TIOCSTI;
   extern unsigned IOCTL_TIOCSWINSZ;
-#if (SANITIZER_LINUX || SANITIZER_FREEBSD) && !SANITIZER_ANDROID
+#if (SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD) && !SANITIZER_ANDROID
   extern unsigned IOCTL_SIOCGETSGCNT;
   extern unsigned IOCTL_SIOCGETVIFCNT;
 #endif
@@ -1258,10 +1415,10 @@ struct __sanitizer_cookie_io_functions_t
   extern unsigned IOCTL_VT_RESIZEX;
   extern unsigned IOCTL_VT_SENDSIG;
 #endif  // SANITIZER_LINUX
-#if SANITIZER_LINUX || SANITIZER_FREEBSD
+#if SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
   extern unsigned IOCTL_MTIOCGET;
   extern unsigned IOCTL_MTIOCTOP;
-  extern unsigned IOCTL_SIOCADDRT;
+  extern unsigned IOCTL_SIOCADDRT;//
   extern unsigned IOCTL_SIOCDELRT;
   extern unsigned IOCTL_SNDCTL_DSP_GETBLKSIZE;
   extern unsigned IOCTL_SNDCTL_DSP_GETFMTS;
@@ -1359,7 +1516,7 @@ struct __sanitizer_cookie_io_functions_t
   extern unsigned IOCTL_VT_RELDISP;
   extern unsigned IOCTL_VT_SETMODE;
   extern unsigned IOCTL_VT_WAITACTIVE;
-#endif  // SANITIZER_LINUX || SANITIZER_FREEBSD
+#endif  // SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
 
 #if SANITIZER_LINUX && !SANITIZER_ANDROID
   extern unsigned IOCTL_CYGETDEFTHRESH;
@@ -1448,24 +1605,32 @@ struct __sanitizer_cookie_io_functions_t
   extern unsigned IOCTL_TIOCSSERIAL;
 #endif  // SANITIZER_LINUX && !SANITIZER_ANDROID
 
-#if (SANITIZER_LINUX || SANITIZER_FREEBSD) && !SANITIZER_ANDROID
+#if (SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD) && !SANITIZER_ANDROID
+#if !SANITIZER_NETBSD
   extern unsigned IOCTL_GIO_SCRNMAP;
+#endif
   extern unsigned IOCTL_KDDISABIO;
   extern unsigned IOCTL_KDENABIO;
   extern unsigned IOCTL_KDGETLED;
+#if !SANITIZER_NETBSD
   extern unsigned IOCTL_KDGETMODE;
+#endif
   extern unsigned IOCTL_KDGKBMODE;
   extern unsigned IOCTL_KDGKBTYPE;
   extern unsigned IOCTL_KDMKTONE;
   extern unsigned IOCTL_KDSETLED;
   extern unsigned IOCTL_KDSETMODE;
   extern unsigned IOCTL_KDSKBMODE;
+#if !SANITIZER_NETBSD
   extern unsigned IOCTL_KIOCSOUND;
   extern unsigned IOCTL_PIO_SCRNMAP;
 #endif
+#endif
 
   extern const int errno_EINVAL;
+#if !SANITIZER_NETBSD
   extern const int errno_EOWNERDEAD;
+#endif
 
   extern const int si_SEGV_MAPERR;
   extern const int si_SEGV_ACCERR;
