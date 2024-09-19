$NetBSD: patch-boehm-gc_os__dep.c,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- boehm-gc/os_dep.c.orig	2010-03-21 19:34:19.000000000 +0000
+++ boehm-gc/os_dep.c
@@ -380,7 +380,7 @@ static void *tiny_sbrk(ptrdiff_t increme
 #define sbrk tiny_sbrk
 # endif /* ECOS */
 
-#if (defined(NETBSD) || defined(OPENBSD)) && defined(__ELF__)
+#if defined(NETBSD) && defined(__ELF__)
   ptr_t GC_data_start;
 
   void GC_init_netbsd_elf()
@@ -393,6 +393,86 @@ static void *tiny_sbrk(ptrdiff_t increme
   }
 #endif
 
+#if defined(OPENBSD)
+  static struct sigaction old_segv_act;
+  sigjmp_buf GC_jmp_buf_openbsd;
+
+    /*ARGSUSED*/
+    void GC_fault_handler_openbsd(int sig)
+    {
+       siglongjmp(GC_jmp_buf_openbsd, 1);
+    }
+
+    /* Return the first nonaddressible location > p or bound   */
+    /* Requires allocation lock.                               */
+    ptr_t GC_find_limit_openbsd(ptr_t p, ptr_t bound)
+    {
+        static volatile ptr_t result;
+               /* Safer if static, since otherwise it may not be       */
+               /* preserved across the longjmp.  Can safely be         */
+               /* static since it's only called with the               */
+               /* allocation lock held.                                */
+        struct sigaction act;
+       size_t pgsz = (size_t)sysconf(_SC_PAGESIZE);
+
+       GC_ASSERT(I_HOLD_LOCK());
+
+        act.sa_handler = GC_fault_handler_openbsd;
+        sigemptyset(&act.sa_mask);
+        act.sa_flags = SA_NODEFER | SA_RESTART;
+        sigaction(SIGSEGV, &act, &old_segv_act);
+
+       if (sigsetjmp(GC_jmp_buf_openbsd, 1) == 0) {
+           result = (ptr_t)(((word)(p)) & ~(pgsz-1));
+           for (;;) {
+               result += pgsz;
+               if (result >= bound) {
+                   result = bound;
+                   break;
+               }
+               GC_noop1((word)(*result));
+           }
+       }
+
+       sigaction(SIGSEGV, &old_segv_act, 0);
+
+       return(result);
+    }
+
+    /* Return first addressable location > p or bound */
+    /* Requires allocation lock. */
+    ptr_t GC_skip_hole_openbsd(ptr_t p, ptr_t bound)
+    {
+        static volatile ptr_t result;
+        struct sigaction act;
+       size_t pgsz = (size_t)sysconf(_SC_PAGESIZE);
+       static volatile int firstpass;
+
+       GC_ASSERT(I_HOLD_LOCK());
+
+        act.sa_handler = GC_fault_handler_openbsd;
+        sigemptyset(&act.sa_mask);
+        act.sa_flags = SA_NODEFER | SA_RESTART;
+        sigaction(SIGSEGV, &act, &old_segv_act);
+
+       firstpass = 1;
+       result = (ptr_t)(((word)(p)) & ~(pgsz-1));
+       if (sigsetjmp(GC_jmp_buf_openbsd, 1) != 0 || firstpass) {
+           firstpass = 0;
+           result += pgsz;
+           if (result >= bound) {
+               result = bound;
+           } else
+               GC_noop1((word)(*result));
+        }
+
+       sigaction(SIGSEGV, &old_segv_act, 0);
+
+       return(result);
+    }
+#endif
+
+
 # ifdef OS2
 
 # include <stddef.h>
@@ -1009,7 +1089,8 @@ ptr_t GC_get_stack_base()
 #endif /* FREEBSD_STACKBOTTOM */
 
 #if !defined(BEOS) && !defined(AMIGA) && !defined(MSWIN32) \
-    && !defined(MSWINCE) && !defined(OS2) && !defined(NOSYS) && !defined(ECOS)
+    && !defined(MSWINCE) && !defined(OS2) && !defined(NOSYS) && !defined(ECOS) \
+    && !defined(GC_OPENBSD_THREADS)
 
 ptr_t GC_get_stack_base()
 {
@@ -1069,6 +1150,25 @@ ptr_t GC_get_stack_base()
 
 # endif /* ! AMIGA, !OS 2, ! MS Windows, !BEOS, !NOSYS, !ECOS */
 
+#if defined(GC_OPENBSD_THREADS)
+
+/* Find the stack using pthread_stackseg_np() */
+
+# include <sys/signal.h>
+# include <pthread.h>
+# include <pthread_np.h>
+
+#define HAVE_GET_STACK_BASE
+
+ptr_t GC_get_stack_base()
+{
+    stack_t stack;
+    pthread_stackseg_np(pthread_self(), &stack);
+    return stack.ss_sp;
+}
+#endif /* GC_OPENBSD_THREADS */
+
+
 /*
  * Register static data segment(s) as roots.
  * If more data segments are added later then they need to be registered
@@ -1440,6 +1540,32 @@ int * etext_addr;
 
 #else /* !OS2 && !Windows && !AMIGA */
 
+#if defined(OPENBSD)
+
+/*
+ * Depending on arch alignment there can be multiple holes
+ * between DATASTART & DATAEND. Scan from DATASTART - DATAEND
+ * and register each region.
+ */
+void GC_register_data_segments(void)
+{
+  ptr_t region_start, region_end;
+
+  region_start = DATASTART;
+
+  for(;;) {
+    region_end = GC_find_limit_openbsd(region_start, DATAEND);
+    GC_add_roots_inner(region_start, region_end, FALSE);
+    if (region_end < DATAEND)
+       region_start = GC_skip_hole_openbsd(region_end, DATAEND);
+    else
+       break;
+  }
+}
+
+# else /* !OS2 && !Windows && !AMIGA && !OPENBSD */
+
+
 void GC_register_data_segments()
 {
 #   if !defined(PCR) && !defined(SRC_M3) && !defined(MACOS)
@@ -1497,6 +1623,7 @@ void GC_register_data_segments()
     /* change.								*/
 }
 
+# endif  /* ! OPENBSD */
 # endif  /* ! AMIGA */
 # endif  /* ! MSWIN32 && ! MSWINCE*/
 # endif  /* ! OS2 */
