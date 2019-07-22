$NetBSD$

--- vm/src/i386/runtime/asmDefs_gcc_i386.hh.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/i386/runtime/asmDefs_gcc_i386.hh
@@ -20,7 +20,7 @@
   # define MACRO(name, ...) .macro name // __VA_ARGS__
   # define ENDMACRO .endmacro
   # define C_SYM(name) _##name
-# elif defined(__linux__) || (defined(SOLARIS) && SOLARIS)
+# elif defined(__linux__) || (defined(SOLARIS) && SOLARIS) || defined(__NetBSD__)
   # if defined(__clang__) && !defined(NO_INTEGRATED_AS_clang)
     # define MACRO(name, ...) .macro name // __VA_ARGS__
     # define ENDMACRO .endmacro
@@ -91,7 +91,7 @@ MACRO(start_exported_function, name)
   .globl C_SYM($0)
 C_SYM($0):
 
-# elif defined(__linux__) || (defined(SOLARIS) && SOLARIS)
+# elif defined(__linux__) || (defined(SOLARIS) && SOLARIS) || defined(__NetBSD__)
 
   .global C_SYM(\name)
 C_SYM(\name):
@@ -181,7 +181,7 @@ ENDMACRO
       ENDMACRO
 
 
-    # elif defined(__linux__) || (defined(SOLARIS) && SOLARIS)
+    # elif defined(__linux__) || (defined(SOLARIS) && SOLARIS) || defined(__NetBSD__)
       MACRO(jmp_reg, reg)
         jmp *\reg
       ENDMACRO
