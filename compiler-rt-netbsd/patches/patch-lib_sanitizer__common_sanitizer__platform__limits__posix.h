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
@@ -55,10 +68,16 @@ namespace __sanitizer {
   extern unsigned struct_itimerspec_sz;
   extern unsigned struct_sigevent_sz;
   extern unsigned struct_sched_param_sz;
+#if !SANITIZER_NETBSD
   extern unsigned struct_statfs64_sz;
+#endif
 
 #if !SANITIZER_ANDROID
+#if SANITIZER_NETBSD
   extern unsigned struct_statfs_sz;
+#else
+  extern unsigned struct_statvfs_sz;
+#endif
   extern unsigned struct_sockaddr_sz;
   extern unsigned ucontext_t_sz;
 #endif // !SANITIZER_ANDROID
@@ -121,18 +140,21 @@ namespace __sanitizer {
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
@@ -144,21 +166,53 @@ namespace __sanitizer {
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
@@ -166,10 +220,32 @@ namespace __sanitizer {
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
@@ -179,6 +255,14 @@ namespace __sanitizer {
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
@@ -303,7 +387,7 @@ namespace __sanitizer {
   #endif
 #endif
   };
-#elif SANITIZER_FREEBSD
+#elif SANITIZER_FREEBSD || SANITIZER_NETBSD
   struct __sanitizer_ipc_perm {
     unsigned int cuid;
     unsigned int cgid;
@@ -351,6 +435,9 @@ namespace __sanitizer {
 # endif
     void *ifa_dstaddr; // (struct sockaddr *)
     void *ifa_data;
+#if SANITIZER_NETBSD
+    unsigned int ifa_addrflags;
+#endif
   };
 #endif  // !SANITIZER_ANDROID
 
@@ -381,7 +468,7 @@ namespace __sanitizer {
     char *pw_passwd;
     int pw_uid;
     int pw_gid;
-#if SANITIZER_MAC || SANITIZER_FREEBSD
+#if SANITIZER_MAC || SANITIZER_FREEBSD || SANITIZER_NETBSD
     long pw_change;
     char *pw_class;
 #endif
@@ -390,7 +477,7 @@ namespace __sanitizer {
 #endif
     char *pw_dir;
     char *pw_shell;
-#if SANITIZER_MAC || SANITIZER_FREEBSD
+#if SANITIZER_MAC || SANITIZER_FREEBSD || SANITIZER_NETBSD
     long pw_expire;
 #endif
 #if SANITIZER_FREEBSD
@@ -447,7 +534,7 @@ namespace __sanitizer {
   };
 #endif
 
-#if SANITIZER_MAC || SANITIZER_FREEBSD
+#if SANITIZER_MAC || SANITIZER_FREEBSD // XXX MARKER
   struct __sanitizer_msghdr {
     void *msg_name;
     unsigned msg_namelen;
