$NetBSD$

--- src/debug/daccess/daccess.cpp.orig	2016-02-09 14:14:20.000000000 +0000
+++ src/debug/daccess/daccess.cpp
@@ -7223,7 +7223,7 @@ ClrDataAccess::GetDacGlobals()
         return E_INVALIDARG;
     }
 #endif
-#define DAC_TABLE_RVA 1
+#define  DAC_TABLE_RVA 1 
     ULONG64 dacTableAddress = m_globalBase + DAC_TABLE_RVA;
     if (FAILED(ReadFromDataTarget(m_pTarget, dacTableAddress, (BYTE*)&g_dacGlobals, sizeof(g_dacGlobals))))
     {
