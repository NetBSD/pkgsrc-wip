$NetBSD$

--- src/recompiler/exec.c.orig	2016-03-04 19:31:10.000000000 +0000
+++ src/recompiler/exec.c
@@ -64,6 +64,7 @@
 #if defined(CONFIG_USER_ONLY)
 #include <qemu.h>
 #include <signal.h>
+
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #include <sys/param.h>
 #if __FreeBSD_version >= 700104
@@ -79,6 +80,13 @@
 #include <libutil.h>
 #endif
 #endif
+
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#include <sys/time.h>
+#include <sys/proc.h>
+#endif
+
 #endif
 
 //#define DEBUG_TB_INVALIDATE
@@ -603,7 +611,7 @@ static void code_gen_alloc(uintptr_t tb_
             exit(1);
         }
     }
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__)
     {
         int flags;
         void *addr = NULL;
