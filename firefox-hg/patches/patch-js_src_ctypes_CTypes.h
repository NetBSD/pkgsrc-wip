$NetBSD: patch-js_src_ctypes_CTypes.h,v 1.3 2015/01/09 10:01:41 thomasklausner Exp $

Fix build on NetBSD
https://bugzilla.mozilla.org/show_bug.cgi?id=1113379

--- js/src/ctypes/CTypes.h.orig	2015-01-09 02:12:41.000000000 +0000
+++ js/src/ctypes/CTypes.h
@@ -9,6 +9,7 @@
 #include "ffi.h"
 #include "jsalloc.h"
 #include "prlink.h"
+#include "typedefs.h"
 
 #include "js/HashTable.h"
 #include "js/Vector.h"
@@ -224,7 +225,8 @@ enum ABICode {
 enum TypeCode {
   TYPE_void_t,
 #define DEFINE_TYPE(name, type, ffiType) TYPE_##name,
-#include "ctypes/typedefs.h"
+  CTYPES_FOR_EACH_TYPE(DEFINE_TYPE)
+#undef DEFINE_TYPE
   TYPE_pointer,
   TYPE_function,
   TYPE_array,
