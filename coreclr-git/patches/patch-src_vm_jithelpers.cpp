$NetBSD$

--- src/vm/jithelpers.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/jithelpers.cpp
@@ -3413,7 +3413,7 @@ OBJECTREF allocNewMDArr(TypeHandle typeH
     }
 #else
     // create an array where fwdArgList[0] == arg[0] ...
-    fwdArgList = (INT32*) _alloca(dwNumArgs * sizeof(INT32));
+    fwdArgList = (INT32*) Alloca(dwNumArgs * sizeof(INT32));
     for (unsigned i = 0; i < dwNumArgs; i++)
     {
         fwdArgList[i] = va_arg(args, INT32);
@@ -6822,7 +6822,7 @@ void F_CALL_VA_CONV JIT_TailCall(PCODE c
         //     where our buffer 'starts' is off by 8, so make sure our buffer is
         //     off by 8.
         //
-        pvTempStack = (BYTE*)_alloca(cbTempStack + STACK_ADJUST_FOR_RETURN_ADDRESS) + STACK_ADJUST_FOR_RETURN_ADDRESS;
+        pvTempStack = (BYTE*)Alloca(cbTempStack + STACK_ADJUST_FOR_RETURN_ADDRESS) + STACK_ADJUST_FOR_RETURN_ADDRESS;
     }
 
     _ASSERTE(((size_t)pvTempStack & STACK_ALIGN_MASK) == STACK_ADJUST_FOR_RETURN_ADDRESS);
