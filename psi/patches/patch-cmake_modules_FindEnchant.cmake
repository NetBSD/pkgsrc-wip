$NetBSD$

Prefer enchant-2.

--- cmake/modules/FindEnchant.cmake.orig	2017-09-24 06:42:59.000000000 +0000
+++ cmake/modules/FindEnchant.cmake
@@ -32,7 +32,7 @@ endif ()
 
 if ( UNIX AND NOT( APPLE OR CYGWIN ) )
 	find_package( PkgConfig QUIET )
-	pkg_check_modules( PC_Enchant QUIET enchant )
+	pkg_check_modules( PC_Enchant QUIET enchant-2 )
 	set ( Enchant_DEFINITIONS 
 		${PC_Enchant_CFLAGS}
 		${PC_Enchant_CFLAGS_OTHER}
