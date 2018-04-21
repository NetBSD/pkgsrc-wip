$NetBSD: patch-hw_xfree86_sdksyms.sh,v 1.1 2016/04/10 07:35:20 tnn Exp $

Kludge sdksyms.c generator to not fail on GetClientPid.
It returns pid_t which on NetBSD is #define pid_t __pid_t
This slightly alters the GCC preprocessor output which this fragile
code could not deal with when using GCC 5+

--- hw/xfree86/sdksyms.sh.orig	2018-04-10 19:46:09.000000000 +0000
+++ hw/xfree86/sdksyms.sh
@@ -373,6 +373,17 @@ BEGIN {
                n = 1;
             }
         }
+	# hack: pid_t becomes __pid_t on NetBSD, same for uint32_t -> __uint32_t.
+	# GCC 5 inserts additional lines around this.
+        if (($1 == "__pid_t" || $1 == "__uint32_t") && NF == 1) {
+            getline;
+            n++;
+            # skip line numbers GCC 5 adds (after typedef return type?)
+            while ($n == "" || $0 ~ /^# [0-9]+ "/) {
+               getline;
+               n = 1;
+            }
+	}
 
 	# type specifier may not be set, as in
 	#   extern _X_EXPORT unsigned name(...)
