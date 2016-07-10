$NetBSD$

--- include/VBox/vmm/iom.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/iom.h
@@ -273,28 +273,28 @@ typedef DECLCALLBACK(int) FNIOMMMIOFILL(
 /** Pointer to a FNIOMMMIOFILL(). */
 typedef FNIOMMMIOFILL *PFNIOMMMIOFILL;
 
-VMMDECL(VBOXSTRICTRC)   IOMIOPortRead(PVM pVM, PVMCPU pVCpu, RTIOPORT Port, uint32_t *pu32Value, size_t cbValue);
-VMMDECL(VBOXSTRICTRC)   IOMIOPortWrite(PVM pVM, PVMCPU pVCpu, RTIOPORT Port, uint32_t u32Value, size_t cbValue);
-VMM_INT_DECL(VBOXSTRICTRC) IOMIOPortReadString(PVM pVM, PVMCPU pVCpu, RTIOPORT Port, void *pvDst,
+VMMDECL(VBOXSTRICTRC)   IOMIOPortRead(vbox_PVM pVM, PVMCPU pVCpu, RTIOPORT Port, uint32_t *pu32Value, size_t cbValue);
+VMMDECL(VBOXSTRICTRC)   IOMIOPortWrite(vbox_PVM pVM, PVMCPU pVCpu, RTIOPORT Port, uint32_t u32Value, size_t cbValue);
+VMM_INT_DECL(VBOXSTRICTRC) IOMIOPortReadString(vbox_PVM pVM, PVMCPU pVCpu, RTIOPORT Port, void *pvDst,
                                                uint32_t *pcTransfers, unsigned cb);
-VMM_INT_DECL(VBOXSTRICTRC) IOMIOPortWriteString(PVM pVM, PVMCPU pVCpu, RTIOPORT uPort, void const *pvSrc,
+VMM_INT_DECL(VBOXSTRICTRC) IOMIOPortWriteString(vbox_PVM pVM, PVMCPU pVCpu, RTIOPORT uPort, void const *pvSrc,
                                                 uint32_t *pcTransfers, unsigned cb);
-VMMDECL(VBOXSTRICTRC)   IOMInterpretINSEx(PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame, uint32_t uPort, uint32_t uPrefix, DISCPUMODE enmAddrMode, uint32_t cbTransfer);
-VMMDECL(VBOXSTRICTRC)   IOMInterpretOUTSEx(PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame, uint32_t uPort, uint32_t uPrefix, DISCPUMODE enmAddrMode, uint32_t cbTransfer);
-VMMDECL(VBOXSTRICTRC)   IOMMMIORead(PVM pVM, PVMCPU pVCpu, RTGCPHYS GCPhys, uint32_t *pu32Value, size_t cbValue);
-VMMDECL(VBOXSTRICTRC)   IOMMMIOWrite(PVM pVM, PVMCPU pVCpu, RTGCPHYS GCPhys, uint32_t u32Value, size_t cbValue);
-VMMDECL(VBOXSTRICTRC)   IOMMMIOPhysHandler(PVM pVM, PVMCPU pVCpu, RTGCUINT uErrorCode, PCPUMCTXCORE pCtxCore, RTGCPHYS GCPhysFault);
-VMMDECL(VBOXSTRICTRC)   IOMInterpretCheckPortIOAccess(PVM pVM, PCPUMCTXCORE pCtxCore, RTIOPORT Port, unsigned cb);
-VMMDECL(int)            IOMMMIOMapMMIO2Page(PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysRemapped, uint64_t fPageFlags);
-VMMDECL(int)            IOMMMIOMapMMIOHCPage(PVM pVM, PVMCPU pVCpu, RTGCPHYS GCPhys, RTHCPHYS HCPhys, uint64_t fPageFlags);
-VMMDECL(int)            IOMMMIOResetRegion(PVM pVM, RTGCPHYS GCPhys);
-VMMDECL(bool)           IOMIsLockWriteOwner(PVM pVM);
+VMMDECL(VBOXSTRICTRC)   IOMInterpretINSEx(vbox_PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame, uint32_t uPort, uint32_t uPrefix, DISCPUMODE enmAddrMode, uint32_t cbTransfer);
+VMMDECL(VBOXSTRICTRC)   IOMInterpretOUTSEx(vbox_PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame, uint32_t uPort, uint32_t uPrefix, DISCPUMODE enmAddrMode, uint32_t cbTransfer);
+VMMDECL(VBOXSTRICTRC)   IOMMMIORead(vbox_PVM pVM, PVMCPU pVCpu, RTGCPHYS GCPhys, uint32_t *pu32Value, size_t cbValue);
+VMMDECL(VBOXSTRICTRC)   IOMMMIOWrite(vbox_PVM pVM, PVMCPU pVCpu, RTGCPHYS GCPhys, uint32_t u32Value, size_t cbValue);
+VMMDECL(VBOXSTRICTRC)   IOMMMIOPhysHandler(vbox_PVM pVM, PVMCPU pVCpu, RTGCUINT uErrorCode, PCPUMCTXCORE pCtxCore, RTGCPHYS GCPhysFault);
+VMMDECL(VBOXSTRICTRC)   IOMInterpretCheckPortIOAccess(vbox_PVM pVM, PCPUMCTXCORE pCtxCore, RTIOPORT Port, unsigned cb);
+VMMDECL(int)            IOMMMIOMapMMIO2Page(vbox_PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysRemapped, uint64_t fPageFlags);
+VMMDECL(int)            IOMMMIOMapMMIOHCPage(vbox_PVM pVM, PVMCPU pVCpu, RTGCPHYS GCPhys, RTHCPHYS HCPhys, uint64_t fPageFlags);
+VMMDECL(int)            IOMMMIOResetRegion(vbox_PVM pVM, RTGCPHYS GCPhys);
+VMMDECL(bool)           IOMIsLockWriteOwner(vbox_PVM pVM);
 
 #ifdef IN_RC
 /** @defgroup grp_iom_rc    The IOM Raw-Mode Context API
  * @{
  */
-VMMRCDECL(VBOXSTRICTRC) IOMRCIOPortHandler(PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame, PDISCPUSTATE pCpu);
+VMMRCDECL(VBOXSTRICTRC) IOMRCIOPortHandler(vbox_PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame, PDISCPUSTATE pCpu);
 /** @} */
 #endif /* IN_RC */
 
@@ -304,38 +304,38 @@ VMMRCDECL(VBOXSTRICTRC) IOMRCIOPortHandl
 /** @defgroup grp_iom_r3    The IOM Host Context Ring-3 API
  * @{
  */
-VMMR3_INT_DECL(int)  IOMR3Init(PVM pVM);
-VMMR3_INT_DECL(void) IOMR3Reset(PVM pVM);
-VMMR3_INT_DECL(void) IOMR3Relocate(PVM pVM, RTGCINTPTR offDelta);
-VMMR3_INT_DECL(int)  IOMR3Term(PVM pVM);
-VMMR3_INT_DECL(int)  IOMR3IOPortRegisterR3(PVM pVM, PPDMDEVINS pDevIns, RTIOPORT PortStart, RTUINT cPorts, RTHCPTR pvUser,
+VMMR3_INT_DECL(int)  IOMR3Init(vbox_PVM pVM);
+VMMR3_INT_DECL(void) IOMR3Reset(vbox_PVM pVM);
+VMMR3_INT_DECL(void) IOMR3Relocate(vbox_PVM pVM, RTGCINTPTR offDelta);
+VMMR3_INT_DECL(int)  IOMR3Term(vbox_PVM pVM);
+VMMR3_INT_DECL(int)  IOMR3IOPortRegisterR3(vbox_PVM pVM, PPDMDEVINS pDevIns, RTIOPORT PortStart, RTUINT cPorts, RTHCPTR pvUser,
                                            R3PTRTYPE(PFNIOMIOPORTOUT) pfnOutCallback, R3PTRTYPE(PFNIOMIOPORTIN) pfnInCallback,
                                            R3PTRTYPE(PFNIOMIOPORTOUTSTRING) pfnOutStringCallback, R3PTRTYPE(PFNIOMIOPORTINSTRING) pfnInStringCallback,
                                            const char *pszDesc);
-VMMR3_INT_DECL(int)  IOMR3IOPortRegisterRC(PVM pVM, PPDMDEVINS pDevIns, RTIOPORT PortStart, RTUINT cPorts, RTRCPTR pvUser,
+VMMR3_INT_DECL(int)  IOMR3IOPortRegisterRC(vbox_PVM pVM, PPDMDEVINS pDevIns, RTIOPORT PortStart, RTUINT cPorts, RTRCPTR pvUser,
                                            RCPTRTYPE(PFNIOMIOPORTOUT) pfnOutCallback, RCPTRTYPE(PFNIOMIOPORTIN) pfnInCallback,
                                            RCPTRTYPE(PFNIOMIOPORTOUTSTRING) pfnOutStrCallback, RCPTRTYPE(PFNIOMIOPORTINSTRING) pfnInStrCallback,
                                            const char *pszDesc);
-VMMR3_INT_DECL(int)  IOMR3IOPortRegisterR0(PVM pVM, PPDMDEVINS pDevIns, RTIOPORT PortStart, RTUINT cPorts, RTR0PTR pvUser,
+VMMR3_INT_DECL(int)  IOMR3IOPortRegisterR0(vbox_PVM pVM, PPDMDEVINS pDevIns, RTIOPORT PortStart, RTUINT cPorts, RTR0PTR pvUser,
                                            R0PTRTYPE(PFNIOMIOPORTOUT) pfnOutCallback, R0PTRTYPE(PFNIOMIOPORTIN) pfnInCallback,
                                            R0PTRTYPE(PFNIOMIOPORTOUTSTRING) pfnOutStrCallback, R0PTRTYPE(PFNIOMIOPORTINSTRING) pfnInStrCallback,
                                            const char *pszDesc);
-VMMR3_INT_DECL(int)  IOMR3IOPortDeregister(PVM pVM, PPDMDEVINS pDevIns, RTIOPORT PortStart, RTUINT cPorts);
+VMMR3_INT_DECL(int)  IOMR3IOPortDeregister(vbox_PVM pVM, PPDMDEVINS pDevIns, RTIOPORT PortStart, RTUINT cPorts);
 
-VMMR3_INT_DECL(int)  IOMR3MmioRegisterR3(PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhysStart, uint32_t cbRange, RTHCPTR pvUser,
+VMMR3_INT_DECL(int)  IOMR3MmioRegisterR3(vbox_PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhysStart, uint32_t cbRange, RTHCPTR pvUser,
                                          R3PTRTYPE(PFNIOMMMIOWRITE) pfnWriteCallback,
                                          R3PTRTYPE(PFNIOMMMIOREAD)  pfnReadCallback,
                                          R3PTRTYPE(PFNIOMMMIOFILL)  pfnFillCallback,
                                          uint32_t fFlags, const char *pszDesc);
-VMMR3_INT_DECL(int)  IOMR3MmioRegisterR0(PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhysStart, uint32_t cbRange, RTR0PTR pvUser,
+VMMR3_INT_DECL(int)  IOMR3MmioRegisterR0(vbox_PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhysStart, uint32_t cbRange, RTR0PTR pvUser,
                                          R0PTRTYPE(PFNIOMMMIOWRITE) pfnWriteCallback,
                                          R0PTRTYPE(PFNIOMMMIOREAD)  pfnReadCallback,
                                          R0PTRTYPE(PFNIOMMMIOFILL)  pfnFillCallback);
-VMMR3_INT_DECL(int)  IOMR3MmioRegisterRC(PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhysStart, uint32_t cbRange, RTGCPTR pvUser,
+VMMR3_INT_DECL(int)  IOMR3MmioRegisterRC(vbox_PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhysStart, uint32_t cbRange, RTGCPTR pvUser,
                                          RCPTRTYPE(PFNIOMMMIOWRITE) pfnWriteCallback,
                                          RCPTRTYPE(PFNIOMMMIOREAD)  pfnReadCallback,
                                          RCPTRTYPE(PFNIOMMMIOFILL)  pfnFillCallback);
-VMMR3_INT_DECL(int)  IOMR3MmioDeregister(PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhysStart, uint32_t cbRange);
+VMMR3_INT_DECL(int)  IOMR3MmioDeregister(vbox_PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhysStart, uint32_t cbRange);
 
 /** @} */
 #endif /* IN_RING3 */
@@ -346,4 +346,3 @@ VMMR3_INT_DECL(int)  IOMR3MmioDeregister
 RT_C_DECLS_END
 
 #endif
-
