$NetBSD$

# Unpoison macros on NetBSD

--- gcc/cp/cvt.cc.orig	2024-06-24 19:46:45.127464308 +0000
+++ gcc/cp/cvt.cc
@@ -25,6 +25,7 @@ along with GCC; see the file COPYING3.  
    but what kind of conversions it does will depend on the language.  */
 
 #include "config.h"
+#include "escaped_string.h"
 #include "system.h"
 #include "coretypes.h"
 #include "target.h"
@@ -35,7 +36,6 @@ along with GCC; see the file COPYING3.  
 #include "convert.h"
 #include "stringpool.h"
 #include "attribs.h"
-#include "escaped_string.h"
 
 static tree convert_to_pointer_force (tree, tree, tsubst_flags_t);
 static tree build_type_conversion (tree, tree);
