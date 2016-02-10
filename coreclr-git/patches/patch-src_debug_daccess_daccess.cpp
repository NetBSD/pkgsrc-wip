$NetBSD$

--- src/debug/daccess/daccess.cpp.orig	2016-02-10 22:49:42.000000000 +0000
+++ src/debug/daccess/daccess.cpp
@@ -7227,7 +7227,7 @@ ClrDataAccess::GetDacGlobals()
         return E_INVALIDARG;
     }
 #endif
-    ULONG64 dacTableAddress = m_globalBase + DAC_TABLE_RVA;
+    ULONG64 dacTableAddress = m_globalBase;
     if (FAILED(ReadFromDataTarget(m_pTarget, dacTableAddress, (BYTE*)&g_dacGlobals, sizeof(g_dacGlobals))))
     {
         return CORDBG_E_MISSING_DEBUGGER_EXPORTS;
