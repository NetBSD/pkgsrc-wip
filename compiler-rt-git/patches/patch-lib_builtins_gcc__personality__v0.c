$NetBSD$

--- lib/builtins/gcc_personality_v0.c.orig	2017-06-03 23:53:58.000000000 +0000
+++ lib/builtins/gcc_personality_v0.c
@@ -24,6 +24,12 @@
 #include "unwind-ehabi-helpers.h"
 #endif
 
+#if defined(__NetBSD__)
+#define TYPE_UNWIND_PTR void*
+#else
+#define TYPE_UNWIND_PTR uintptr_t
+#endif
+
 /*
  * Pointer encodings documented at:
  *   http://refspecs.freestandards.org/LSB_1.3.0/gLSB/gLSB/ehframehdr.html
@@ -206,8 +212,8 @@ __gcc_personality_v0(int version, _Unwin
     if ( lsda == (uint8_t*) 0 )
         return continueUnwind(exceptionObject, context);
 
-    uintptr_t pc = _Unwind_GetIP(context)-1;
-    uintptr_t funcStart = _Unwind_GetRegionStart(context);
+    uintptr_t pc = (uintptr_t)_Unwind_GetIP(context) - 1;
+    uintptr_t funcStart = (uintptr_t)_Unwind_GetRegionStart(context);
     uintptr_t pcOffset = pc - funcStart;
 
     /* Parse LSDA header. */
@@ -239,9 +245,9 @@ __gcc_personality_v0(int version, _Unwin
              * to take two parameters in registers.
              */
             _Unwind_SetGR(context, __builtin_eh_return_data_regno(0),
-                          (uintptr_t)exceptionObject);
+                          (TYPE_UNWIND_PTR)exceptionObject);
             _Unwind_SetGR(context, __builtin_eh_return_data_regno(1), 0);
-            _Unwind_SetIP(context, (funcStart + landingPad));
+            _Unwind_SetIP(context, (TYPE_UNWIND_PTR)(funcStart + landingPad));
             return _URC_INSTALL_CONTEXT;
         }
     }
@@ -249,4 +255,3 @@ __gcc_personality_v0(int version, _Unwin
     /* No landing pad found, continue unwinding. */
     return continueUnwind(exceptionObject, context);
 }
-
