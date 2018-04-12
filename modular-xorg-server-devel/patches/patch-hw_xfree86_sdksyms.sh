$NetBSD: patch-hw_xfree86_sdksyms.sh,v 1.1 2016/04/10 07:35:20 tnn Exp $

Kludge sdksyms.c generator to not fail on GetClientPid.
It returns pid_t which on NetBSD is #define pid_t __pid_t
This slightly alters the GCC preprocessor output which this fragile
code could not deal with when using GCC 5+


Ignore empty symbols, from Adam Jackson <ajax@redhat.com>

--- hw/xfree86/sdksyms.sh.orig	2018-04-10 19:46:09.000000000 +0000
+++ hw/xfree86/sdksyms.sh
@@ -373,6 +373,17 @@ BEGIN {
                n = 1;
             }
         }
+	# hack: pid_t becomes __pid_t on NetBSD.
+	# GCC 5 inserts additional lines around this.
+        if ($1 == "__pid_t" && NF == 1) {
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
@@ -415,7 +426,8 @@ BEGIN {
 	sub(/[^a-zA-Z0-9_].*/, "", symbol);
 
 	#print;
-	printf("    (void *) &%-50s /* %s:%s */\n", symbol ",", header, line);
+	if (symbol != "")
+	    printf("    (void *) &%-50s /* %s:%s */\n", symbol ",", header, line);
     }
 }
 
