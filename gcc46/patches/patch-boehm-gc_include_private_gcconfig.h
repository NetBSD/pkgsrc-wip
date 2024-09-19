$NetBSD: patch-boehm-gc_include_private_gcconfig.h,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- boehm-gc/include/private/gcconfig.h.orig	2012-03-02 18:21:41.000000000 +0000
+++ boehm-gc/include/private/gcconfig.h
@@ -62,7 +62,7 @@
 /* Determine the machine type: */
 # if defined(__arm__) || defined(__thumb__)
 #    define ARM32
-#    if !defined(LINUX) && !defined(NETBSD)
+#    if !defined(LINUX) && !defined(NETBSD) && !defined(OPENBSD)
 #      define NOSYS
 #      define mach_type_known
 #    endif
@@ -77,14 +77,18 @@
 #    define HP
 #    define mach_type_known
 # endif
-# if defined(OPENBSD) && defined(m68k)
-#    define M68K
-#    define mach_type_known
-# endif
 # if defined(OPENBSD) && defined(__sparc__)
 #    define SPARC
 #    define mach_type_known
 # endif
+# if defined(OPENBSD) && defined(__arm__)
+#    define ARM32
+#    define mach_type_known
+# endif
+# if defined(OPENBSD) && defined(__sh__)
+#    define SH
+#    define mach_type_known
+# endif
 # if defined(NETBSD) && (defined(m68k) || defined(__m68k__))
 #    define M68K
 #    define mach_type_known
@@ -101,7 +105,7 @@
 #    define SH
 #    define mach_type_known
 # endif
-# if defined(vax)
+# if defined(vax) || defined(__vax__)
 #    define VAX
 #    ifdef ultrix
 #	define ULTRIX
@@ -119,7 +123,7 @@
 #    if defined(nec_ews) || defined(_nec_ews)
 #      define EWS4800
 #    endif
-#    if !defined(LINUX) && !defined(EWS4800) && !defined(NETBSD)
+#    if !defined(LINUX) && !defined(EWS4800) && !defined(NETBSD) && !defined(OPENBSD)
 #      if defined(ultrix) || defined(__ultrix)
 #	 define ULTRIX
 #      else
@@ -210,7 +214,7 @@
 # if defined(_PA_RISC1_0) || defined(_PA_RISC1_1) || defined(_PA_RISC2_0) \
      || defined(hppa) || defined(__hppa__)
 #   define HP_PA
-#   if !defined(LINUX) && !defined(HPUX)
+#   if !defined(LINUX) && !defined(HPUX) && !defined(OPENBSD)
 #     define HPUX
 #   endif
 #   define mach_type_known
@@ -231,6 +235,10 @@
 #    define I386
 #    define mach_type_known
 # endif
+# if defined(OPENBSD) && defined(__amd64)
+#	define X86_64
+#	define mach_type_known
+# endif
 # if defined(LINUX) && defined(__x86_64__)
 #    define X86_64
 #    define mach_type_known
@@ -302,6 +310,11 @@
 #   define MACOS
 #   define mach_type_known
 # endif
+# if defined(__OpenBSD__) && defined(__powerpc__)
+#	define POWERPC
+#	define OPENBSD
+#	define mach_type_known
+# endif
 # if defined(macosx) || (defined(__APPLE__) && defined(__MACH__))
 #   define DARWIN
 #   if defined(__ppc__)  || defined(__ppc64__)
@@ -651,18 +664,6 @@
 # ifdef M68K
 #   define MACH_TYPE "M68K"
 #   define ALIGNMENT 2
-#   ifdef OPENBSD
-#	define OS_TYPE "OPENBSD"
-#	define HEURISTIC2
-#	ifdef __ELF__
-#	  define DATASTART GC_data_start
-#	  define DYNAMIC_LOADING
-#	else
-	  extern char etext[];
-#	  define DATASTART ((ptr_t)(etext))
-#       endif
-#       define USE_GENERIC_PUSH_REGS
-#   endif
 #   ifdef NETBSD
 #	define OS_TYPE "NETBSD"
 #	define HEURISTIC2
@@ -836,6 +837,24 @@
 	 should be looked into some more */
 #     define NO_PTHREAD_TRYLOCK
 #   endif
+#   ifdef OPENBSD
+#     define OS_TYPE "OPENBSD"
+#     define ALIGNMENT 4
+#     define SIG_SUSPEND SIGXFSZ
+#     define SIG_THR_RESTART SIGXCPU
+#     ifndef GC_OPENBSD_THREADS
+#       include <sys/param.h>
+#       include <uvm/uvm_extern.h>
+#       define STACKBOTTOM USRSTACK
+#     endif
+      extern int __data_start[];
+#     define DATASTART ((ptr_t)(__data_start))
+      extern char _end[];
+#     define DATAEND ((ptr_t)(&_end))
+#     define DYNAMIC_LOADING
+#     define USE_MMAP
+#     define USE_MMAP_ANON
+#   endif
 #   ifdef FREEBSD
 #       define ALIGNMENT 4
 #       define OS_TYPE "FREEBSD"
@@ -994,9 +1013,20 @@
 #   endif
 #   ifdef OPENBSD
 #     define OS_TYPE "OPENBSD"
-#     define STACKBOTTOM ((ptr_t) 0xf8000000)
-      extern int etext[];
-#     define DATASTART ((ptr_t)(etext))
+#     define SIG_SUSPEND SIGXFSZ
+#     define SIG_THR_RESTART SIGXCPU
+#     ifndef GC_OPENBSD_THREADS
+#       include <sys/param.h>
+#       include <uvm/uvm_extern.h>
+#       define STACKBOTTOM USRSTACK
+#     endif
+      extern int __data_start[];
+#     define DATASTART ((ptr_t)(__data_start))
+      extern char _end[];
+#     define DATAEND ((ptr_t)(&_end))
+#     define DYNAMIC_LOADING
+#     define USE_MMAP
+#     define USE_MMAP_ANON
 #   endif
 #   ifdef NETBSD
 #     define OS_TYPE "NETBSD"
@@ -1250,6 +1280,20 @@
 #   endif
 #   ifdef OPENBSD
 #	define OS_TYPE "OPENBSD"
+#    define SIG_SUSPEND SIGXFSZ
+#    define SIG_THR_RESTART SIGXCPU
+#    ifndef GC_OPENBSD_THREADS
+#       include <sys/param.h>
+#       include <uvm/uvm_extern.h>
+#       define STACKBOTTOM USRSTACK
+#    endif
+        extern int __data_start[];
+#       define DATASTART ((ptr_t)(__data_start))
+        extern char _end[];
+#       define DATAEND ((ptr_t)(&_end))
+#       define DYNAMIC_LOADING
+#       define USE_MMAP
+#       define USE_MMAP_ANON
 #   endif
 #   ifdef FREEBSD
 #	define OS_TYPE "FREEBSD"
@@ -1285,7 +1329,7 @@
 #   ifdef BSDI
 #	define OS_TYPE "BSDI"
 #   endif
-#   if defined(OPENBSD) || defined(NETBSD) \
+#   if defined(NETBSD) \
         || defined(THREE86BSD) || defined(BSDI)
 #	define HEURISTIC2
 	extern char etext[];
@@ -1475,6 +1519,24 @@
 #       define STACKBOTTOM ((ptr_t) 0x7ffff000)
 #     endif /* _ELF_ */
 #  endif
+#  ifdef OPENBSD
+#      define OS_TYPE "OPENBSD"
+#       define ALIGNMENT 4
+#    define SIG_SUSPEND SIGXFSZ
+#    define SIG_THR_RESTART SIGXCPU
+#    ifndef GC_OPENBSD_THREADS
+#       include <sys/param.h>
+#       include <uvm/uvm_extern.h>
+#       define STACKBOTTOM USRSTACK
+#    endif
+        extern int _fdata[];
+#       define DATASTART ((ptr_t)(_fdata))
+        extern char _end[];
+#       define DATAEND ((ptr_t)(&_end))
+#       define DYNAMIC_LOADING
+#       define USE_MMAP
+#       define USE_MMAP_ANON
+#  endif
 # endif
 
 # ifdef RS6000
@@ -1522,7 +1584,7 @@
 #     define ALIGNMENT 4
 #     define ALIGN_DOUBLE
 #   endif
-#   if !defined(GC_HPUX_THREADS) && !defined(GC_LINUX_THREADS)
+#   if !defined(GC_HPUX_THREADS) && !defined(GC_LINUX_THREADS) && !defined(OPENBSD)
 #     ifndef LINUX /* For now. */
 #       define MPROTECT_VDB
 #     endif
@@ -1574,6 +1636,23 @@
       extern int _end[];
 #     define DATAEND (&_end)
 #   endif /* LINUX */
+#  ifdef OPENBSD
+#      define OS_TYPE "OPENBSD"
+#    define SIG_SUSPEND SIGXFSZ
+#    define SIG_THR_RESTART SIGXCPU
+#    ifndef GC_OPENBSD_THREADS
+#       include <sys/param.h>
+#       include <uvm/uvm_extern.h>
+#       define STACKBOTTOM USRSTACK
+#    endif
+        extern int __data_start[];
+#       define DATASTART ((ptr_t)(__data_start))
+        extern char _end[];
+#       define DATAEND ((ptr_t)(&_end))
+#       define DYNAMIC_LOADING
+#       define USE_MMAP
+#       define USE_MMAP_ANON
+#  endif
 # endif /* HP_PA */
 
 # ifdef ALPHA
@@ -1598,15 +1677,21 @@
 #   endif
 #   ifdef OPENBSD
 #	define OS_TYPE "OPENBSD"
-#	define HEURISTIC2
-#   	ifdef __ELF__	/* since OpenBSD/Alpha 2.9 */
-#	   define DATASTART GC_data_start
-#   	   define ELFCLASS32 32
-#   	   define ELFCLASS64 64
-#   	   define ELF_CLASS ELFCLASS64
-#       else		/* ECOFF, until OpenBSD/Alpha 2.7 */
-#   	   define DATASTART ((ptr_t) 0x140000000)
-#   	endif
+#      define ELF_CLASS ELFCLASS64
+#    define SIG_SUSPEND SIGXFSZ
+#    define SIG_THR_RESTART SIGXCPU
+#    ifndef GC_OPENBSD_THREADS
+#       include <sys/param.h>
+#       include <uvm/uvm_extern.h>
+#       define STACKBOTTOM USRSTACK
+#    endif
+        extern int __data_start[];
+#       define DATASTART ((ptr_t)(__data_start))
+        extern char _end[];
+#       define DATAEND ((ptr_t)(&_end))
+#       define DYNAMIC_LOADING
+#       define USE_MMAP
+#       define USE_MMAP_ANON
 #   endif
 #   ifdef FREEBSD
 #	define OS_TYPE "FREEBSD"
@@ -1786,6 +1871,7 @@
 #   ifdef CX_UX
 #	define OS_TYPE "CX_UX"
 #       define DATASTART ((((word)etext + 0x3fffff) & ~0x3fffff) + 0x10000)
+#       define STACKBOTTOM ((char*)0xf0000000) /* determined empirically */
 #   endif
 #   ifdef  DGUX
 #	define OS_TYPE "DGUX"
@@ -1896,6 +1982,24 @@
 #     define OS_TYPE "MSWINCE"
 #     define DATAEND /* not needed */
 #   endif
+#   ifdef OPENBSD
+#     define ALIGNMENT 4
+#     define OS_TYPE "OPENBSD"
+#    define SIG_SUSPEND SIGXFSZ
+#    define SIG_THR_RESTART SIGXCPU
+#    ifndef GC_OPENBSD_THREADS
+#       include <sys/param.h>
+#       include <uvm/uvm_extern.h>
+#       define STACKBOTTOM USRSTACK
+#    endif
+        extern int __data_start[];
+#       define DATASTART ((ptr_t)(__data_start))
+        extern char _end[];
+#       define DATAEND ((ptr_t)(&_end))
+#       define DYNAMIC_LOADING
+#       define USE_MMAP
+#       define USE_MMAP_ANON
+#   endif
 #   ifdef NOSYS
       /* __data_start is usually defined in the target linker script.  */
       extern int __data_start[];
@@ -1943,6 +2047,23 @@
 #       define USE_GENERIC_PUSH_REGS
 #      define DYNAMIC_LOADING
 #   endif
+#   ifdef OPENBSD
+#      define OS_TYPE "OPENBSD"
+#    define SIG_SUSPEND SIGXFSZ
+#    define SIG_THR_RESTART SIGXCPU
+#    ifndef GC_OPENBSD_THREADS
+#       include <sys/param.h>
+#       include <uvm/uvm_extern.h>
+#       define STACKBOTTOM USRSTACK
+#    endif
+        extern int __data_start[];
+#       define DATASTART ((ptr_t)(__data_start))
+        extern char _end[];
+#       define DATAEND ((ptr_t)(&_end))
+#       define DYNAMIC_LOADING
+#       define USE_MMAP
+#       define USE_MMAP_ANON
+#   endif
 # endif
  
 # ifdef SH4
@@ -1976,6 +2097,24 @@
 #   ifndef HBLKSIZE
 #     define HBLKSIZE 4096
 #   endif
+#   ifdef OPENBSD
+#       define OS_TYPE "OPENBSD"
+#       define ELF_CLASS ELFCLASS64
+#    define SIG_SUSPEND SIGXFSZ
+#    define SIG_THR_RESTART SIGXCPU
+#    ifndef GC_OPENBSD_THREADS
+#       include <sys/param.h>
+#       include <uvm/uvm_extern.h>
+#       define STACKBOTTOM USRSTACK
+#    endif
+        extern int __data_start[];
+#       define DATASTART ((ptr_t)(__data_start))
+        extern char _end[];
+#       define DATAEND ((ptr_t)(&_end))
+#       define DYNAMIC_LOADING
+#       define USE_MMAP
+#       define USE_MMAP_ANON
+#   endif
 #   define CACHE_LINE_SIZE 64
 #   define USE_GENERIC_PUSH_REGS
 #   ifdef LINUX
