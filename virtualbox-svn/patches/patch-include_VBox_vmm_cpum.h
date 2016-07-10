$NetBSD$

--- include/VBox/vmm/cpum.h.orig	2016-07-10 19:42:15.000000000 +0000
+++ include/VBox/vmm/cpum.h
@@ -1077,8 +1077,8 @@ VMMDECL(void)       CPUMGetGuestCpuId(PV
 VMMDECL(uint64_t)   CPUMGetGuestEFER(PVMCPU pVCpu);
 VMMDECL(VBOXSTRICTRC)   CPUMQueryGuestMsr(PVMCPU pVCpu, uint32_t idMsr, uint64_t *puValue);
 VMMDECL(VBOXSTRICTRC)   CPUMSetGuestMsr(PVMCPU pVCpu, uint32_t idMsr, uint64_t uValue);
-VMMDECL(CPUMCPUVENDOR)  CPUMGetGuestCpuVendor(PVM pVM);
-VMMDECL(CPUMCPUVENDOR)  CPUMGetHostCpuVendor(PVM pVM);
+VMMDECL(CPUMCPUVENDOR)  CPUMGetGuestCpuVendor(vbox_PVM pVM);
+VMMDECL(CPUMCPUVENDOR)  CPUMGetHostCpuVendor(vbox_PVM pVM);
 /** @} */
 
 /** @name Guest Register Setters.
@@ -1381,7 +1381,7 @@ VMMDECL(uint32_t)       CPUMGetGuestCPL(
 VMMDECL(CPUMMODE)       CPUMGetGuestMode(PVMCPU pVCpu);
 VMMDECL(uint32_t)       CPUMGetGuestCodeBits(PVMCPU pVCpu);
 VMMDECL(DISCPUMODE)     CPUMGetGuestDisMode(PVMCPU pVCpu);
-VMMDECL(uint64_t)       CPUMGetGuestScalableBusFrequency(PVM pVM);
+VMMDECL(uint64_t)       CPUMGetGuestScalableBusFrequency(vbox_PVM pVM);
 
 /** @name Typical scalable bus frequency values.
  * @{ */
@@ -1425,18 +1425,18 @@ VMMR3DECL(const char *)     CPUMR3CpuIdU
 VMMR3DECL(CPUMCPUVENDOR)    CPUMR3CpuIdDetectVendorEx(uint32_t uEAX, uint32_t uEBX, uint32_t uECX, uint32_t uEDX);
 VMMR3DECL(const char *)     CPUMR3CpuVendorName(CPUMCPUVENDOR enmVendor);
 
-VMMR3DECL(int)              CPUMR3MsrRangesInsert(PVM pVM, PCCPUMMSRRANGE pNewRange);
+VMMR3DECL(int)              CPUMR3MsrRangesInsert(vbox_PVM pVM, PCCPUMMSRRANGE pNewRange);
 
 # if defined(VBOX_WITH_RAW_MODE) || defined(DOXYGEN_RUNNING)
 /** @name APIs for the CPUID raw-mode patch (legacy).
  * @{ */
-VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmDefRCPtr(PVM pVM);
-VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmStdMax(PVM pVM);
-VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmExtMax(PVM pVM);
-VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmCentaurMax(PVM pVM);
-VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmStdRCPtr(PVM pVM);
-VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmExtRCPtr(PVM pVM);
-VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmCentaurRCPtr(PVM pVM);
+VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmDefRCPtr(vbox_PVM pVM);
+VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmStdMax(vbox_PVM pVM);
+VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmExtMax(vbox_PVM pVM);
+VMMR3_INT_DECL(uint32_t)                   CPUMR3GetGuestCpuIdPatmCentaurMax(vbox_PVM pVM);
+VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmStdRCPtr(vbox_PVM pVM);
+VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmExtRCPtr(vbox_PVM pVM);
+VMMR3_INT_DECL(RCPTRTYPE(PCCPUMCPUID))     CPUMR3GetGuestCpuIdPatmCentaurRCPtr(vbox_PVM pVM);
 /** @} */
 # endif
 
@@ -1524,4 +1524,3 @@ RT_C_DECLS_END
 
 
 #endif
-
