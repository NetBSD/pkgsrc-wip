$NetBSD$

Search default rules in "share/lib/dmake" and "usr/include/dmake".
(to make it clear that they are not associated with BSD make)

--- sunpro/Make/bin/make/common/read.cc.orig	2021-05-10 17:15:50.000000000 +0000
+++ sunpro/Make/bin/make/common/read.cc
@@ -229,14 +229,14 @@ read_simple_file(register Name makefile_
 						NOCATGETS("%s/../../share/lib/make"), run_dir);
 					} else {
 	                        		(void) sprintf(makerules_dir,
-						NOCATGETS("%s/../share/lib/make"), run_dir);
+						NOCATGETS("%s/../share/lib/dmake"), run_dir);
 					}
 					add_dir_to_path(makerules_dir,
 							&makefile_path,
 							-1);
 				}
 #ifdef INS_BASE
-				add_dir_to_path(NOCATGETS(INS_BASE "/share/lib/make"),
+				add_dir_to_path(NOCATGETS(INS_BASE "/share/lib/dmake"),
 						&makefile_path,
 						-1);
 #endif
