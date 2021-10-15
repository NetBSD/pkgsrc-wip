$NetBSD$

Add null statement in #else branch. Otherwise a label is located at the end of
a block.

--- src/hardware/hw_main.c.orig	2021-10-15 10:34:51.000000000 +0000
+++ src/hardware/hw_main.c
@@ -3079,6 +3079,9 @@ bad_subsector:
         // Error situations, should not get here.
 #ifdef PARANOIA
         GenPrintf( EMSG_warn, "Bad BSP subsector: %i\n", subsecnum );
+#else
+       // [MB] Required for the label "bad_subsector" (block ends here)
+       ;  // [MB] null statement as defined in C99 Section 6.8.3
 #endif
     }
     return;
