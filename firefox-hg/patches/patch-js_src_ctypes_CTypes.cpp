$NetBSD: patch-js_src_ctypes_CTypes.cpp,v 1.1 2015/01/09 10:01:41 thomasklausner Exp $

Fix build on NetBSD
https://bugzilla.mozilla.org/show_bug.cgi?id=1113379

--- js/src/ctypes/CTypes.cpp.orig	2015-01-09 02:12:41.000000000 +0000
+++ js/src/ctypes/CTypes.cpp
@@ -1276,7 +1276,8 @@ InitTypeClasses(JSContext* cx, HandleObj
       INT_TO_JSVAL(ffiType.alignment), &ffiType));                             \
   if (!typeObj_##name)                                                         \
     return false;
-#include "ctypes/typedefs.h"
+  CTYPES_FOR_EACH_TYPE(DEFINE_TYPE)
+#undef DEFINE_TYPE
 
   // Alias 'ctypes.unsigned' as 'ctypes.unsigned_int', since they represent
   // the same type in C.
@@ -1666,14 +1667,15 @@ jsvalToInteger(JSContext* cx, jsval val,
       // Check whether the source type is always representable, with exact
       // precision, by the target type. If it is, convert the value.
       switch (CType::GetTypeCode(typeObj)) {
-#define DEFINE_INT_TYPE(name, fromType, ffiType)                               \
+#define INTEGER_CASE(name, fromType, ffiType)                                  \
       case TYPE_##name:                                                        \
         if (!IsAlwaysExact<IntegerType, fromType>())                           \
           return false;                                                        \
         *result = IntegerType(*static_cast<fromType*>(data));                  \
         return true;
-#define DEFINE_WRAPPED_INT_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#include "ctypes/typedefs.h"
+      CTYPES_FOR_EACH_INT_TYPE(INTEGER_CASE)
+      CTYPES_FOR_EACH_WRAPPED_INT_TYPE(INTEGER_CASE)
+#undef INTEGER_CASE
       case TYPE_void_t:
       case TYPE_bool:
       case TYPE_float:
@@ -1755,15 +1757,16 @@ jsvalToFloat(JSContext *cx, jsval val, F
       // Check whether the source type is always representable, with exact
       // precision, by the target type. If it is, convert the value.
       switch (CType::GetTypeCode(typeObj)) {
-#define DEFINE_FLOAT_TYPE(name, fromType, ffiType)                             \
+#define NUMERIC_CASE(name, fromType, ffiType)                                  \
       case TYPE_##name:                                                        \
         if (!IsAlwaysExact<FloatType, fromType>())                             \
           return false;                                                        \
         *result = FloatType(*static_cast<fromType*>(data));                    \
         return true;
-#define DEFINE_INT_TYPE(x, y, z) DEFINE_FLOAT_TYPE(x, y, z)
-#define DEFINE_WRAPPED_INT_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#include "ctypes/typedefs.h"
+      CTYPES_FOR_EACH_FLOAT_TYPE(NUMERIC_CASE)
+      CTYPES_FOR_EACH_INT_TYPE(NUMERIC_CASE)
+      CTYPES_FOR_EACH_WRAPPED_INT_TYPE(NUMERIC_CASE)
+#undef NUMERIC_CASE
       case TYPE_void_t:
       case TYPE_bool:
       case TYPE_char:
@@ -2130,7 +2133,7 @@ ConvertToJS(JSContext* cx,
   case TYPE_bool:
     result.setBoolean(*static_cast<bool*>(data));
     break;
-#define DEFINE_INT_TYPE(name, type, ffiType)                                   \
+#define INT_CASE(name, type, ffiType)                                          \
   case TYPE_##name: {                                                          \
     type value = *static_cast<type*>(data);                                    \
     if (sizeof(type) < 4)                                                      \
@@ -2139,7 +2142,9 @@ ConvertToJS(JSContext* cx,
       result.setDouble(double(value));                                         \
     break;                                                                     \
   }
-#define DEFINE_WRAPPED_INT_TYPE(name, type, ffiType)                           \
+  CTYPES_FOR_EACH_INT_TYPE(INT_CASE)
+#undef INT_CASE
+#define WRAPPED_INT_CASE(name, type, ffiType)                                  \
   case TYPE_##name: {                                                          \
     /* Return an Int64 or UInt64 object - do not convert to a JS number. */    \
     uint64_t value;                                                            \
@@ -2165,19 +2170,24 @@ ConvertToJS(JSContext* cx,
     result.setObject(*obj);                                                    \
     break;                                                                     \
   }
-#define DEFINE_FLOAT_TYPE(name, type, ffiType)                                 \
+  CTYPES_FOR_EACH_WRAPPED_INT_TYPE(WRAPPED_INT_CASE)
+#undef WRAPPED_INT_CASE
+#define FLOAT_CASE(name, type, ffiType)                                        \
   case TYPE_##name: {                                                          \
     type value = *static_cast<type*>(data);                                    \
     result.setDouble(double(value));                                           \
     break;                                                                     \
   }
-#define DEFINE_CHAR_TYPE(name, type, ffiType)                                  \
+  CTYPES_FOR_EACH_FLOAT_TYPE(FLOAT_CASE)
+#undef FLOAT_CASE
+#define CHAR_CASE(name, type, ffiType)                                         \
   case TYPE_##name:                                                            \
     /* Convert to an integer. We have no idea what character encoding to */    \
     /* use, if any. */                                                         \
     result.setInt32(*static_cast<type*>(data));                                \
     break;
-#include "ctypes/typedefs.h"
+  CTYPES_FOR_EACH_CHAR_TYPE(CHAR_CASE)
+#undef CHAR_CASE
   case TYPE_char16_t: {
     // Convert the char16_t to a 1-character string.
     JSString* str = JS_NewUCStringCopyN(cx, static_cast<char16_t*>(data), 1);
@@ -2325,26 +2335,7 @@ ImplicitConvert(JSContext* cx,
     *static_cast<bool*>(buffer) = result;
     break;
   }
-#define DEFINE_INT_TYPE(name, type, ffiType)                                   \
-  case TYPE_##name: {                                                          \
-    /* Do not implicitly lose bits. */                                         \
-    type result;                                                               \
-    if (!jsvalToInteger(cx, val, &result))                                     \
-      return TypeError(cx, #name, val);                                        \
-    *static_cast<type*>(buffer) = result;                                      \
-    break;                                                                     \
-  }
-#define DEFINE_WRAPPED_INT_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_FLOAT_TYPE(name, type, ffiType)                                 \
-  case TYPE_##name: {                                                          \
-    type result;                                                               \
-    if (!jsvalToFloat(cx, val, &result))                                       \
-      return TypeError(cx, #name, val);                                        \
-    *static_cast<type*>(buffer) = result;                                      \
-    break;                                                                     \
-  }
-#define DEFINE_CHAR_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_CHAR16_TYPE(name, type, ffiType)                                \
+#define CHAR16_CASE(name, type, ffiType)                                       \
   case TYPE_##name: {                                                          \
     /* Convert from a 1-character string, regardless of encoding, */           \
     /* or from an integer, provided the result fits in 'type'. */              \
@@ -2363,7 +2354,35 @@ ImplicitConvert(JSContext* cx,
     *static_cast<type*>(buffer) = result;                                      \
     break;                                                                     \
   }
-#include "ctypes/typedefs.h"
+  CTYPES_FOR_EACH_CHAR16_TYPE(CHAR16_CASE)
+#undef CHAR16_CASE
+#define INTEGRAL_CASE(name, type, ffiType)                                     \
+  case TYPE_##name: {                                                          \
+    /* Do not implicitly lose bits. */                                         \
+    type result;                                                               \
+    if (!jsvalToInteger(cx, val, &result))                                     \
+      return TypeError(cx, #name, val);                                        \
+    *static_cast<type*>(buffer) = result;                                      \
+    break;                                                                     \
+  }
+  CTYPES_FOR_EACH_INT_TYPE(INTEGRAL_CASE)
+  CTYPES_FOR_EACH_WRAPPED_INT_TYPE(INTEGRAL_CASE)
+  // It's hard to believe ctypes.char16_t("f") should work yet ctypes.char("f")
+  // should not.  Ditto for ctypes.{un,}signed_char.  But this is how ctypes
+  // has always worked, so preserve these semantics, and don't switch to an
+  // algorithm similar to that in DEFINE_CHAR16_TYPE above, just yet.
+  CTYPES_FOR_EACH_CHAR_TYPE(INTEGRAL_CASE)
+#undef INTEGRAL_CASE
+#define FLOAT_CASE(name, type, ffiType)                                        \
+  case TYPE_##name: {                                                          \
+    type result;                                                               \
+    if (!jsvalToFloat(cx, val, &result))                                       \
+      return TypeError(cx, #name, val);                                        \
+    *static_cast<type*>(buffer) = result;                                      \
+    break;                                                                     \
+  }
+  CTYPES_FOR_EACH_FLOAT_TYPE(FLOAT_CASE)
+#undef FLOAT_CASE
   case TYPE_pointer: {
     if (val.isNull()) {
       // Convert to a null pointer.
@@ -2699,7 +2718,7 @@ ExplicitConvert(JSContext* cx, HandleVal
     *static_cast<bool*>(buffer) = ToBoolean(val);
     break;
   }
-#define DEFINE_INT_TYPE(name, type, ffiType)                                   \
+#define INTEGRAL_CASE(name, type, ffiType)                                     \
   case TYPE_##name: {                                                          \
     /* Convert numeric values with a C-style cast, and */                      \
     /* allow conversion from a base-10 or base-16 string. */                   \
@@ -2711,10 +2730,11 @@ ExplicitConvert(JSContext* cx, HandleVal
     *static_cast<type*>(buffer) = result;                                      \
     break;                                                                     \
   }
-#define DEFINE_WRAPPED_INT_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_CHAR_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_CHAR16_TYPE(x, y, z) DEFINE_CHAR_TYPE(x, y, z)
-#include "ctypes/typedefs.h"
+  CTYPES_FOR_EACH_INT_TYPE(INTEGRAL_CASE)
+  CTYPES_FOR_EACH_WRAPPED_INT_TYPE(INTEGRAL_CASE)
+  CTYPES_FOR_EACH_CHAR_TYPE(INTEGRAL_CASE)
+  CTYPES_FOR_EACH_CHAR16_TYPE(INTEGRAL_CASE)
+#undef INTEGRAL_CASE
   case TYPE_pointer: {
     // Convert a number, Int64 object, or UInt64 object to a pointer.
     uintptr_t result;
@@ -2867,9 +2887,9 @@ BuildTypeSource(JSContext* cx,
   // Walk the types, building up the toSource() string.
   switch (CType::GetTypeCode(typeObj)) {
   case TYPE_void_t:
-#define DEFINE_TYPE(name, type, ffiType)  \
-  case TYPE_##name:
-#include "ctypes/typedefs.h"
+#define CASE_FOR_TYPE(name, type, ffiType)  case TYPE_##name:
+  CTYPES_FOR_EACH_TYPE(CASE_FOR_TYPE)
+#undef CASE_FOR_TYPE
   {
     AppendString(result, "ctypes.");
     JSString* nameStr = CType::GetName(cx, typeObj);
@@ -3018,12 +3038,14 @@ BuildDataSource(JSContext* cx,
     else
       AppendString(result, "false");
     break;
-#define DEFINE_INT_TYPE(name, type, ffiType)                                   \
+#define INTEGRAL_CASE(name, type, ffiType)                                     \
   case TYPE_##name:                                                            \
     /* Serialize as a primitive decimal integer. */                            \
     IntegerToString(*static_cast<type*>(data), 10, result);                    \
     break;
-#define DEFINE_WRAPPED_INT_TYPE(name, type, ffiType)                           \
+  CTYPES_FOR_EACH_INT_TYPE(INTEGRAL_CASE)
+#undef INTEGRAL_CASE
+#define WRAPPED_INT_CASE(name, type, ffiType)                                  \
   case TYPE_##name:                                                            \
     /* Serialize as a wrapped decimal integer. */                              \
     if (!NumericLimits<type>::is_signed)                                       \
@@ -3034,7 +3056,9 @@ BuildDataSource(JSContext* cx,
     IntegerToString(*static_cast<type*>(data), 10, result);                    \
     AppendString(result, "\")");                                               \
     break;
-#define DEFINE_FLOAT_TYPE(name, type, ffiType)                                 \
+  CTYPES_FOR_EACH_WRAPPED_INT_TYPE(WRAPPED_INT_CASE)
+#undef WRAPPED_INT_CASE
+#define FLOAT_CASE(name, type, ffiType)                                        \
   case TYPE_##name: {                                                          \
     /* Serialize as a primitive double. */                                     \
     double fp = *static_cast<type*>(data);                                     \
@@ -3048,12 +3072,15 @@ BuildDataSource(JSContext* cx,
     result.append(str, strlen(str));                                           \
     break;                                                                     \
   }
-#define DEFINE_CHAR_TYPE(name, type, ffiType)                                  \
+  CTYPES_FOR_EACH_FLOAT_TYPE(FLOAT_CASE)
+#undef FLOAT_CASE
+#define CHAR_CASE(name, type, ffiType)                                         \
   case TYPE_##name:                                                            \
     /* Serialize as an integer. */                                             \
     IntegerToString(*static_cast<type*>(data), 10, result);                    \
     break;
-#include "ctypes/typedefs.h"
+  CTYPES_FOR_EACH_CHAR_TYPE(CHAR_CASE)
+#undef CHAR_CASE
   case TYPE_char16_t: {
     // Serialize as a 1-character JS string.
     JSString* str = JS_NewUCStringCopyN(cx, static_cast<char16_t*>(data), 1);
@@ -5931,18 +5958,19 @@ FunctionType::Call(JSContext* cx,
   // Small integer types get returned as a word-sized ffi_arg. Coerce it back
   // into the correct size for ConvertToJS.
   switch (typeCode) {
-#define DEFINE_INT_TYPE(name, type, ffiType)                                   \
+#define INTEGRAL_CASE(name, type, ffiType)                                     \
   case TYPE_##name:                                                            \
     if (sizeof(type) < sizeof(ffi_arg)) {                                      \
       ffi_arg data = *static_cast<ffi_arg*>(returnValue.mData);                \
       *static_cast<type*>(returnValue.mData) = static_cast<type>(data);        \
     }                                                                          \
     break;
-#define DEFINE_WRAPPED_INT_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_BOOL_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_CHAR_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_CHAR16_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#include "ctypes/typedefs.h"
+  CTYPES_FOR_EACH_INT_TYPE(INTEGRAL_CASE)
+  CTYPES_FOR_EACH_WRAPPED_INT_TYPE(INTEGRAL_CASE)
+  CTYPES_FOR_EACH_BOOL_TYPE(INTEGRAL_CASE)
+  CTYPES_FOR_EACH_CHAR_TYPE(INTEGRAL_CASE)
+  CTYPES_FOR_EACH_CHAR16_TYPE(INTEGRAL_CASE)
+#undef INTEGRAL_CASE
   default:
     break;
   }
@@ -6203,13 +6231,13 @@ CClosure::ClosureStub(ffi_cif* cif, void
   if (cif->rtype != &ffi_type_void) {
     rvSize = cif->rtype->size;
     switch (typeCode) {
-#define DEFINE_INT_TYPE(name, type, ffiType)                                   \
-    case TYPE_##name:
-#define DEFINE_WRAPPED_INT_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_BOOL_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_CHAR_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_CHAR16_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#include "ctypes/typedefs.h"
+#define INTEGRAL_CASE(name, type, ffiType)  case TYPE_##name:
+    CTYPES_FOR_EACH_INT_TYPE(INTEGRAL_CASE)
+    CTYPES_FOR_EACH_WRAPPED_INT_TYPE(INTEGRAL_CASE)
+    CTYPES_FOR_EACH_BOOL_TYPE(INTEGRAL_CASE)
+    CTYPES_FOR_EACH_CHAR_TYPE(INTEGRAL_CASE)
+    CTYPES_FOR_EACH_CHAR16_TYPE(INTEGRAL_CASE)
+#undef INTEGRAL_CASE
       rvSize = Align(rvSize, sizeof(ffi_arg));
       break;
     default:
@@ -6284,18 +6312,19 @@ CClosure::ClosureStub(ffi_cif* cif, void
   // Small integer types must be returned as a word-sized ffi_arg. Coerce it
   // back into the size libffi expects.
   switch (typeCode) {
-#define DEFINE_INT_TYPE(name, type, ffiType)                                   \
+#define INTEGRAL_CASE(name, type, ffiType)                                     \
   case TYPE_##name:                                                            \
     if (sizeof(type) < sizeof(ffi_arg)) {                                      \
       ffi_arg data = *static_cast<type*>(result);                              \
       *static_cast<ffi_arg*>(result) = data;                                   \
     }                                                                          \
     break;
-#define DEFINE_WRAPPED_INT_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_BOOL_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_CHAR_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#define DEFINE_CHAR16_TYPE(x, y, z) DEFINE_INT_TYPE(x, y, z)
-#include "ctypes/typedefs.h"
+    CTYPES_FOR_EACH_INT_TYPE(INTEGRAL_CASE)
+    CTYPES_FOR_EACH_WRAPPED_INT_TYPE(INTEGRAL_CASE)
+    CTYPES_FOR_EACH_BOOL_TYPE(INTEGRAL_CASE)
+    CTYPES_FOR_EACH_CHAR_TYPE(INTEGRAL_CASE)
+    CTYPES_FOR_EACH_CHAR16_TYPE(INTEGRAL_CASE)
+#undef INTEGRAL_CASE
   default:
     break;
   }
