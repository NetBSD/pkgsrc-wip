$NetBSD$

Add library dirs to the runtime search path

--- qb/qb.libs.sh.orig	2017-11-21 15:40:48.000000000 +0000
+++ qb/qb.libs.sh
@@ -17,7 +17,7 @@ add_include_dirs()
 }
 
 add_library_dirs()
-{	while [ "$1" ]; do LIBRARY_DIRS="$LIBRARY_DIRS -L$1"; shift; done
+{	while [ "$1" ]; do LIBRARY_DIRS="$LIBRARY_DIRS -Wl,-R$1 -L$1"; shift; done
 	LIBRARY_DIRS="${LIBRARY_DIRS# }"
 }
 
