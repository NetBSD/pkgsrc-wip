$NetBSD$

--- vlib/builtin/builtin_d_gcboehm.c.v.orig	2024-09-28 15:50:00.000000000 +0000
+++ vlib/builtin/builtin_d_gcboehm.c.v
@@ -33,6 +33,11 @@ $if dynamic_boehm ? {
 				#flag -I/usr/local/include
 				#flag -L/usr/local/lib
 			}
+			$if netbsd {
+				#flag -I@PREFIX@/include
+				#flag -L@PREFIX@/lib
+				#flag -Wl,-R,@PREFIX@/lib
+			}
 			$if freebsd {
 				#flag -lgc-threaded
 			} $else {
@@ -72,6 +77,23 @@ $if dynamic_boehm ? {
 			#flag -lgc-threaded
 		}
 		#flag -lpthread
+	} $else $if netbsd {
+		// Tested on NetBSD 10.0, with gcc
+		#flag -DGC_BUILTIN_ATOMIC=1
+		#flag -DBUS_PAGE_FAULT=T_PAGEFLT
+		#flag -I@PREFIX@/include
+		#flag $first_existing("@PREFIX@/lib/libgc.a", "@PREFIX@/lib/libgc.a")
+		$if !tinyc {
+			#flag -DUSE_MMAP
+			//#flag -I @VEXEROOT/thirdparty/libgc/include
+			//#flag @VEXEROOT/thirdparty/libgc/gc.o
+		}
+		$if tinyc {
+			//#flag -I/usr/local/include
+			//#flag $first_existing("/usr/local/lib/libgc-threaded.a", "/usr/lib/libgc-threaded.a")
+			//#flag -lgc-threaded
+		}
+		#flag -lpthread
 	} $else $if openbsd {
 		// Tested on OpenBSD 7.5, with clang, gcc and tcc
 		#flag -DGC_BUILTIN_ATOMIC=1
