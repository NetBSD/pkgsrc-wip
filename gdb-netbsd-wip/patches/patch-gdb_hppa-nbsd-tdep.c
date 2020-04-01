$NetBSD$

--- gdb/hppa-nbsd-tdep.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/hppa-nbsd-tdep.c
@@ -25,8 +25,8 @@
 #include "trad-frame.h"
 #include "tramp-frame.h"
 
-#include "hppa-tdep.h"
 #include "hppa-bsd-tdep.h"
+#include "hppa-tdep.h"
 #include "gdbarch.h"
 
 /* From <machine/mcontext.h>.  */
@@ -58,6 +58,19 @@ static int hppanbsd_mc_reg_offset[] =
   38 * 4,	/* sr1 */
   39 * 4,	/* sr2 */
   40 * 4,	/* sr3 */
+  -1,		/* 48 */
+  -1,		/* 49 */
+  -1,		/* 50 */
+  -1,		/* 51 */
+  -1,		/* 52 */
+  -1,		/* 53 */
+  -1,		/* 54 */
+  -1,		/* 55 */
+  -1,		/* 56 */
+  -1,		/* 57 CR24 */
+  -1,		/* 58 CR25 */
+  -1,		/* 59 CR26 */
+  43 * 4,	/* HPPA_CR27_REGNUM */
 
   /* more tbd */
 };
@@ -129,7 +142,7 @@ hppanbsd_sigtramp_cache_init (const stru
 /* Core file support.  */
 
 /* Sizeof `struct reg' in <machine/reg.h>.  */
-#define HPPANBSD_SIZEOF_GREGS	(44 * 4)
+#define HPPANBSD_SIZEOF_GREGS	(47 * 4)
 
 static int hppanbsd_reg_offset[] =
 {
@@ -153,6 +166,25 @@ static int hppanbsd_reg_offset[] =
   -1,		/* HPPA_ISR_REGNUM */
   -1,		/* HPPA_IOR_REGNUM */
   0 * 4,	/* HPPA_IPSW_REGNUM */
+  -1,		/* spare? */
+  41 * 4,	/* HPPA_SR4_REGNUM */
+  37 * 4,	/* sr0 */
+  38 * 4,	/* sr1 */
+  39 * 4,	/* sr2 */
+  40 * 4,	/* sr3 */
+  -1,		/* 48 */
+  -1,		/* 49 */
+  -1,		/* 50 */
+  -1,		/* 51 */
+  -1,		/* 52 */
+  -1,		/* 53 */
+  -1,		/* 54 */
+  -1,		/* 55 */
+  -1,		/* 56 */
+  -1,		/* 57 */
+  -1,		/* 58 */
+  -1,		/* 59 */
+  46 * 4,	/* HPPA_CR27_REGNUM */
 };
 
 /* Supply register REGNUM from the buffer specified by GREGS and LEN
