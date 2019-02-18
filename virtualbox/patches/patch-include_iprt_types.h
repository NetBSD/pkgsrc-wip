$NetBSD$

--- include/iprt/types.h.orig	2018-12-18 12:51:38.000000000 +0000
+++ include/iprt/types.h
@@ -237,8 +237,6 @@ typedef _Bool bool;
       * For the kernel code <stdbool.h> is not available, but bool is
       * provided by <sys/types.h> included above.
       */
-#    include <stdbool.h>
-
      /*
       * ... but the story doesn't end here.  The C standard says that
       * <stdbool.h> defines preprocessor macro "bool" that expands to
