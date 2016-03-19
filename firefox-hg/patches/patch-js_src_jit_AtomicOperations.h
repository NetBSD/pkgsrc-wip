$NetBSD$

# See https://bugzilla.mozilla.org/show_bug.cgi?id=1232150

diff -r c5da92c5b490 js/src/jit/AtomicOperations.h
--- js/src/jit/AtomicOperations.h.orig	2016-03-18 22:27:02.000000000 +0000
+++ js/src/jit/AtomicOperations.h
@@ -325,6 +325,8 @@ AtomicOperations::isLockfree(int32_t siz
 # include "jit/mips-shared/AtomicOperations-mips-shared.h"
 #elif defined(__ppc__) || defined(__PPC__)
 # include "jit/none/AtomicOperations-ppc.h"
+#elif defined(__sparc__)
+# include "jit/none/AtomicOperations-sparc.h"
 #elif defined(JS_CODEGEN_NONE)
   // You can disable the JIT with --disable-ion but you must still
   // provide the atomic operations that will be used by the JS engine.
