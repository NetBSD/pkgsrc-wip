$NetBSD$

--- src/vm/threadsuspend.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/threadsuspend.cpp
@@ -8445,23 +8445,23 @@ void PALAPI HandleGCSuspensionForInterru
         ClrFlsValueSwitch threadStackWalking(TlsIdx_StackWalkerWalkingThread, pThread);
 
         // Hijack the return address to point to the appropriate routine based on the method's return type.
-        void *pvHijackAddr = OnHijackScalarTripThread;
+        void *pvHijackAddr = reinterpret_cast<void*>(OnHijackScalarTripThread);
         MethodDesc *pMethodDesc = codeInfo.GetMethodDesc();
         MethodTable* pMT = NULL;
         MetaSig::RETURNTYPE type = pMethodDesc->ReturnsObject(INDEBUG_COMMA(false) &pMT);
         if (type == MetaSig::RETOBJ)
         {
-            pvHijackAddr = OnHijackObjectTripThread;
+            pvHijackAddr = reinterpret_cast<void*>(OnHijackObjectTripThread);
         }
         else if (type == MetaSig::RETBYREF)
         {
-            pvHijackAddr = OnHijackInteriorPointerTripThread;
+            pvHijackAddr = reinterpret_cast<void*>(OnHijackInteriorPointerTripThread);
         }
 #ifdef FEATURE_UNIX_AMD64_STRUCT_PASSING
         else if (type == MetaSig::RETVALUETYPE)
         {
             pThread->SetHijackReturnTypeClass(pMT->GetClass());
-            pvHijackAddr = OnHijackStructInRegsTripThread;
+            pvHijackAddr = reinterpret_cast<void*>(OnHijackStructInRegsTripThread);
         }
 #endif // FEATURE_UNIX_AMD64_STRUCT_PASSING
 
