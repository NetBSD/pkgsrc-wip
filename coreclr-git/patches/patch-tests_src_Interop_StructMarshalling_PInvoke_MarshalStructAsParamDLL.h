$NetBSD$

--- tests/src/Interop/StructMarshalling/PInvoke/MarshalStructAsParamDLL.h.orig	2016-05-03 01:25:01.000000000 +0000
+++ tests/src/Interop/StructMarshalling/PInvoke/MarshalStructAsParamDLL.h
@@ -787,7 +787,7 @@ void ChangeU(U* p)
 	p->uiPtr = (LPVOID)(64);
 	p->s = 32767;
 	p->us = 0;
-	p->b = 255;
+	p->b = -1;
 	p->sb = -128;
 	p->l = -1234567890;
 	p->ul = 0;
@@ -897,4 +897,4 @@ bool IsCorrectLongStructPack16Explicit(L
 	if(p->l1 != 32 || p->l2 != 32)
 		return false;
 	return true;
-}
\ No newline at end of file
+}
