$NetBSD$

--- vlib/builtin/builtin_d_gcboehm.c.v.orig	2023-07-01 15:24:08.744354932 +0000
+++ vlib/builtin/builtin_d_gcboehm.c.v
@@ -25,6 +25,11 @@ $if dynamic_boehm ? {
 				#flag -I/usr/local/include
 				#flag -L/usr/local/lib
 			}
+			$if netbsd {
+				#flag -I@PREFIX@/include
+				#flag -L@PREFIX@/lib
+				#flag -Wl,-R,@PREFIX@/lib
+			}
 			#flag -lgc
 		}
 	}
@@ -57,6 +62,11 @@ $if dynamic_boehm ? {
 			#flag -lgc
 		}
 		#flag -lpthread
+	} $else $if netbsd {
+		#flag -DGC_BUILTIN_ATOMIC=1
+		#flag -I@PREFIX@/include
+		#flag $first_existing("@PREFIX@/lib/libgc.a", "@PREFIX@/lib/libgc.a")
+		#flag -lpthread
 	} $else $if openbsd {
 		#flag -DGC_BUILTIN_ATOMIC=1
 		#flag -I/usr/local/include
