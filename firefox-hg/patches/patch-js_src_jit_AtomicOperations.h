# See https://bugzilla.mozilla.org/show_bug.cgi?id=1232150

diff -r c5da92c5b490 js/src/jit/AtomicOperations.h
--- js/src/jit/AtomicOperations.h	Thu Jan 21 14:38:56 2016 -0500
+++ js/src/jit/AtomicOperations.h	Fri Jan 22 08:52:19 2016 +0100
@@ -316,6 +316,8 @@
     || defined(__ppc64le__) || defined(__PPC64LE__) \
     || defined(__ppc__) || defined(__PPC__)
 # include "jit/none/AtomicOperations-ppc.h"
+#elif defined(__sparc__)
+# include "jit/none/AtomicOperations-sparc.h"
 #elif defined(JS_CODEGEN_NONE)
 # include "jit/none/AtomicOperations-none.h"
 #elif defined(JS_CODEGEN_X86) || defined(JS_CODEGEN_X64)
