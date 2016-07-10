$NetBSD$

--- src/VBox/VMM/include/CPUMInternal.h.orig	2016-03-04 19:30:14.000000000 +0000
+++ src/VBox/VMM/include/CPUMInternal.h
@@ -506,24 +506,24 @@ typedef CPUMCPU *PCPUMCPU;
 #ifndef VBOX_FOR_DTRACE_LIB
 RT_C_DECLS_BEGIN
 
-PCPUMCPUIDLEAF      cpumCpuIdGetLeaf(PVM pVM, uint32_t uLeaf);
-PCPUMCPUIDLEAF      cpumCpuIdGetLeafEx(PVM pVM, uint32_t uLeaf, uint32_t uSubLeaf, bool *pfExactSubLeafHit);
+PCPUMCPUIDLEAF      cpumCpuIdGetLeaf(vbox_PVM pVM, uint32_t uLeaf);
+PCPUMCPUIDLEAF      cpumCpuIdGetLeafEx(vbox_PVM pVM, uint32_t uLeaf, uint32_t uSubLeaf, bool *pfExactSubLeafHit);
 
 #ifdef IN_RING3
-int                 cpumR3DbgInit(PVM pVM);
+int                 cpumR3DbgInit(vbox_PVM pVM);
 int                 cpumR3CpuIdExplodeFeatures(PCCPUMCPUIDLEAF paLeaves, uint32_t cLeaves, PCPUMFEATURES pFeatures);
-int                 cpumR3InitCpuIdAndMsrs(PVM pVM);
-void                cpumR3SaveCpuId(PVM pVM, PSSMHANDLE pSSM);
-int                 cpumR3LoadCpuId(PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion);
-int                 cpumR3LoadCpuIdPre32(PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion);
-DECLCALLBACK(void)  cpumR3CpuIdInfo(PVM pVM, PCDBGFINFOHLP pHlp, const char *pszArgs);
+int                 cpumR3InitCpuIdAndMsrs(vbox_PVM pVM);
+void                cpumR3SaveCpuId(vbox_PVM pVM, PSSMHANDLE pSSM);
+int                 cpumR3LoadCpuId(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion);
+int                 cpumR3LoadCpuIdPre32(vbox_PVM pVM, PSSMHANDLE pSSM, uint32_t uVersion);
+DECLCALLBACK(void)  cpumR3CpuIdInfo(vbox_PVM pVM, PCDBGFINFOHLP pHlp, const char *pszArgs);
 
 int                 cpumR3DbGetCpuInfo(const char *pszName, PCPUMINFO pInfo);
-int                 cpumR3MsrRangesInsert(PVM pVM, PCPUMMSRRANGE *ppaMsrRanges, uint32_t *pcMsrRanges, PCCPUMMSRRANGE pNewRange);
-int                 cpumR3MsrApplyFudge(PVM pVM);
-int                 cpumR3MsrRegStats(PVM pVM);
+int                 cpumR3MsrRangesInsert(vbox_PVM pVM, PCPUMMSRRANGE *ppaMsrRanges, uint32_t *pcMsrRanges, PCCPUMMSRRANGE pNewRange);
+int                 cpumR3MsrApplyFudge(vbox_PVM pVM);
+int                 cpumR3MsrRegStats(vbox_PVM pVM);
 int                 cpumR3MsrStrictInitChecks(void);
-PCPUMMSRRANGE       cpumLookupMsrRange(PVM pVM, uint32_t idMsr);
+PCPUMMSRRANGE       cpumLookupMsrRange(vbox_PVM pVM, uint32_t idMsr);
 #endif
 
 #ifdef IN_RC
@@ -551,4 +551,3 @@ RT_C_DECLS_END
 /** @} */
 
 #endif
-
