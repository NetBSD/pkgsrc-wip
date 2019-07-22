$NetBSD$

--- vm/src/i386/prims/asmPrims_i386.S.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/i386/prims/asmPrims_i386.S
@@ -17,10 +17,10 @@
             leal   C_SYM(VMString), %eax
         
         # if defined(__APPLE__) \
-         || (defined(__linux__) && defined(__clang__) && !defined(NO_INTEGRATED_AS_clang))
+         || ((defined(__linux__) || defined(__NetBSD__)) && defined(__clang__) && !defined(NO_INTEGRATED_AS_clang))
             movl   $0(%eax), %eax
         
-        # elif defined(__linux__) || (defined(SOLARIS) && SOLARIS)
+        # elif defined(__linux__) || (defined(SOLARIS) && SOLARIS) || defined(__NetBSD__)
             movl   \error_code(%eax), %eax
         
         # else
@@ -37,7 +37,7 @@ ret_overflow: ret_prim_error overflowOff
          
         MACRO(setup_arith_prim, name rcreg argreg)
         # if defined(__APPLE__) \
-        || (defined(__linux__) && defined(__clang__) && !defined(NO_INTEGRATED_AS_clang))
+        || ((defined(__linux__) || defined(__NetBSD__)) && defined(__clang__) && !defined(NO_INTEGRATED_AS_clang))
             start_exported_function $0
              movl    8(%esp), $2
              testl   $(Tag_Mask), $2
@@ -45,7 +45,7 @@ ret_overflow: ret_prim_error overflowOff
              movl    4(%esp), $1
              testl   $(Tag_Mask), $1
              jne     ret_bad_type
-        # elif defined(__linux__) || (defined(SOLARIS) && SOLARIS)
+        # elif defined(__linux__) || (defined(SOLARIS) && SOLARIS) || defined(__NetBSD__)
             start_exported_function \name
              movl    8(%esp), \argreg
              testl   $(Tag_Mask), \argreg
