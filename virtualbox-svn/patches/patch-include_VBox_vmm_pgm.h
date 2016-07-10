$NetBSD$

--- include/VBox/vmm/pgm.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/pgm.h
@@ -72,7 +72,7 @@ typedef enum PGMRELOCATECALL
  * @remark  The return value is no a failure indicator, it's an acceptance
  *          indicator. Relocation can not fail!
  */
-typedef DECLCALLBACK(bool) FNPGMRELOCATE(PVM pVM, RTGCPTR GCPtrOld, RTGCPTR GCPtrNew, PGMRELOCATECALL enmMode, void *pvUser);
+typedef DECLCALLBACK(bool) FNPGMRELOCATE(vbox_PVM pVM, RTGCPTR GCPtrOld, RTGCPTR GCPtrNew, PGMRELOCATECALL enmMode, void *pvUser);
 /** Pointer to a relocation callback function. */
 typedef FNPGMRELOCATE *PFNPGMRELOCATE;
 
@@ -178,7 +178,7 @@ typedef enum PGMACCESSTYPE
  * @param   pvUser      User argument.
  * @thread  EMT(pVCpu)
  */
-typedef DECLCALLBACK(VBOXSTRICTRC) FNPGMRZPHYSPFHANDLER(PVM pVM, PVMCPU pVCpu, RTGCUINT uErrorCode, PCPUMCTXCORE pRegFrame,
+typedef DECLCALLBACK(VBOXSTRICTRC) FNPGMRZPHYSPFHANDLER(vbox_PVM pVM, PVMCPU pVCpu, RTGCUINT uErrorCode, PCPUMCTXCORE pRegFrame,
                                                         RTGCPTR pvFault, RTGCPHYS GCPhysFault, void *pvUser);
 /** Pointer to PGM access callback. */
 typedef FNPGMRZPHYSPFHANDLER *PFNPGMRZPHYSPFHANDLER;
@@ -209,7 +209,7 @@ typedef FNPGMRZPHYSPFHANDLER *PFNPGMRZPH
  * @param   pvUser          User argument.
  * @thread  EMT(pVCpu)
  */
-typedef DECLCALLBACK(VBOXSTRICTRC) FNPGMPHYSHANDLER(PVM pVM, PVMCPU pVCpu, RTGCPHYS GCPhys, void *pvPhys, void *pvBuf, size_t cbBuf,
+typedef DECLCALLBACK(VBOXSTRICTRC) FNPGMPHYSHANDLER(vbox_PVM pVM, PVMCPU pVCpu, RTGCPHYS GCPhys, void *pvPhys, void *pvBuf, size_t cbBuf,
                                                     PGMACCESSTYPE enmAccessType, PGMACCESSORIGIN enmOrigin, void *pvUser);
 /** Pointer to PGM access callback. */
 typedef FNPGMPHYSHANDLER *PFNPGMPHYSHANDLER;
@@ -248,7 +248,7 @@ typedef enum PGMVIRTHANDLERKIND
  * @param   pvUser          User argument.
  * @thread  EMT(pVCpu)
  */
-typedef DECLCALLBACK(VBOXSTRICTRC) FNPGMRCVIRTPFHANDLER(PVM pVM, PVMCPU pVCpu, RTGCUINT uErrorCode, PCPUMCTXCORE pRegFrame,
+typedef DECLCALLBACK(VBOXSTRICTRC) FNPGMRCVIRTPFHANDLER(vbox_PVM pVM, PVMCPU pVCpu, RTGCUINT uErrorCode, PCPUMCTXCORE pRegFrame,
                                                         RTGCPTR pvFault, RTGCPTR pvRange, uintptr_t offRange, void *pvUser);
 /** Pointer to PGM access callback. */
 typedef FNPGMRCVIRTPFHANDLER *PFNPGMRCVIRTPFHANDLER;
@@ -274,7 +274,7 @@ typedef FNPGMRCVIRTPFHANDLER *PFNPGMRCVI
  * @param   pvUser          User argument.
  * @thread  EMT(pVCpu)
  */
-typedef DECLCALLBACK(VBOXSTRICTRC) FNPGMVIRTHANDLER(PVM pVM, PVMCPU pVCpu, RTGCPTR GCPtr, void *pvPtr, void *pvBuf, size_t cbBuf,
+typedef DECLCALLBACK(VBOXSTRICTRC) FNPGMVIRTHANDLER(vbox_PVM pVM, PVMCPU pVCpu, RTGCPTR GCPtr, void *pvPtr, void *pvBuf, size_t cbBuf,
                                                     PGMACCESSTYPE enmAccessType, PGMACCESSORIGIN enmOrigin, void *pvUser);
 /** Pointer to PGM access callback. */
 typedef FNPGMVIRTHANDLER *PFNPGMVIRTHANDLER;
@@ -292,7 +292,7 @@ typedef FNPGMVIRTHANDLER *PFNPGMVIRTHAND
  *          in r13179 (1.1) and stopped working with r13806 (PGMPool merge,
  *          v1.2), exactly a month later.
  */
-typedef DECLCALLBACK(int) FNPGMR3VIRTINVALIDATE(PVM pVM, PVMCPU pVCpu, RTGCPTR GCPtr, void *pvUser);
+typedef DECLCALLBACK(int) FNPGMR3VIRTINVALIDATE(vbox_PVM pVM, PVMCPU pVCpu, RTGCPTR GCPtr, void *pvUser);
 /** Pointer to PGM invalidation callback. */
 typedef FNPGMR3VIRTINVALIDATE *PFNPGMR3VIRTINVALIDATE;
 
@@ -306,7 +306,7 @@ typedef FNPGMR3VIRTINVALIDATE *PFNPGMR3V
  * @param   cbRange         Size of the dirty range in bytes.
  * @param   pvUser          User argument.
  */
-typedef DECLCALLBACK(int) FNPGMENUMDIRTYFTPAGES(PVM pVM, RTGCPHYS GCPhys, uint8_t *pRange, unsigned cbRange, void *pvUser);
+typedef DECLCALLBACK(int) FNPGMENUMDIRTYFTPAGES(vbox_PVM pVM, RTGCPHYS GCPhys, uint8_t *pRange, unsigned cbRange, void *pvUser);
 /** Pointer to PGMR3PhysEnumDirtyFTPages callback. */
 typedef FNPGMENUMDIRTYFTPAGES *PFNPGMENUMDIRTYFTPAGES;
 
@@ -364,31 +364,31 @@ typedef enum PGMMODE
       || (enmProt) == PGMROMPROT_READ_ROM_WRITE_RAM )
 
 
-VMMDECL(bool)           PGMIsLockOwner(PVM pVM);
+VMMDECL(bool)           PGMIsLockOwner(vbox_PVM pVM);
 
 VMMDECL(int)            PGMRegisterStringFormatTypes(void);
 VMMDECL(void)           PGMDeregisterStringFormatTypes(void);
 VMMDECL(RTHCPHYS)       PGMGetHyperCR3(PVMCPU pVCpu);
 VMMDECL(RTHCPHYS)       PGMGetNestedCR3(PVMCPU pVCpu, PGMMODE enmShadowMode);
-VMMDECL(RTHCPHYS)       PGMGetInterHCCR3(PVM pVM);
-VMMDECL(RTHCPHYS)       PGMGetInterRCCR3(PVM pVM, PVMCPU pVCpu);
-VMMDECL(RTHCPHYS)       PGMGetInter32BitCR3(PVM pVM);
-VMMDECL(RTHCPHYS)       PGMGetInterPaeCR3(PVM pVM);
-VMMDECL(RTHCPHYS)       PGMGetInterAmd64CR3(PVM pVM);
+VMMDECL(RTHCPHYS)       PGMGetInterHCCR3(vbox_PVM pVM);
+VMMDECL(RTHCPHYS)       PGMGetInterRCCR3(vbox_PVM pVM, PVMCPU pVCpu);
+VMMDECL(RTHCPHYS)       PGMGetInter32BitCR3(vbox_PVM pVM);
+VMMDECL(RTHCPHYS)       PGMGetInterPaeCR3(vbox_PVM pVM);
+VMMDECL(RTHCPHYS)       PGMGetInterAmd64CR3(vbox_PVM pVM);
 VMMDECL(int)            PGMTrap0eHandler(PVMCPU pVCpu, RTGCUINT uErr, PCPUMCTXCORE pRegFrame, RTGCPTR pvFault);
 VMMDECL(int)            PGMPrefetchPage(PVMCPU pVCpu, RTGCPTR GCPtrPage);
 VMMDECL(int)            PGMVerifyAccess(PVMCPU pVCpu, RTGCPTR Addr, uint32_t cbSize, uint32_t fAccess);
 VMMDECL(int)            PGMIsValidAccess(PVMCPU pVCpu, RTGCPTR Addr, uint32_t cbSize, uint32_t fAccess);
-VMMDECL(VBOXSTRICTRC)   PGMInterpretInstruction(PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame, RTGCPTR pvFault);
-VMMDECL(int)            PGMMap(PVM pVM, RTGCPTR GCPtr, RTHCPHYS HCPhys, uint32_t cbPages, unsigned fFlags);
-VMMDECL(int)            PGMMapGetPage(PVM pVM, RTGCPTR GCPtr, uint64_t *pfFlags, PRTHCPHYS pHCPhys);
-VMMDECL(int)            PGMMapSetPage(PVM pVM, RTGCPTR GCPtr, uint64_t cb, uint64_t fFlags);
-VMMDECL(int)            PGMMapModifyPage(PVM pVM, RTGCPTR GCPtr, size_t cb, uint64_t fFlags, uint64_t fMask);
+VMMDECL(VBOXSTRICTRC)   PGMInterpretInstruction(vbox_PVM pVM, PVMCPU pVCpu, PCPUMCTXCORE pRegFrame, RTGCPTR pvFault);
+VMMDECL(int)            PGMMap(vbox_PVM pVM, RTGCPTR GCPtr, RTHCPHYS HCPhys, uint32_t cbPages, unsigned fFlags);
+VMMDECL(int)            PGMMapGetPage(vbox_PVM pVM, RTGCPTR GCPtr, uint64_t *pfFlags, PRTHCPHYS pHCPhys);
+VMMDECL(int)            PGMMapSetPage(vbox_PVM pVM, RTGCPTR GCPtr, uint64_t cb, uint64_t fFlags);
+VMMDECL(int)            PGMMapModifyPage(vbox_PVM pVM, RTGCPTR GCPtr, size_t cb, uint64_t fFlags, uint64_t fMask);
 #ifndef IN_RING0
-VMMDECL(bool)           PGMMapHasConflicts(PVM pVM);
+VMMDECL(bool)           PGMMapHasConflicts(vbox_PVM pVM);
 #endif
 #ifdef VBOX_STRICT
-VMMDECL(void)           PGMMapCheck(PVM pVM);
+VMMDECL(void)           PGMMapCheck(vbox_PVM pVM);
 #endif
 VMMDECL(int)            PGMShwGetPage(PVMCPU pVCpu, RTGCPTR GCPtr, uint64_t *pfFlags, PRTHCPHYS pHCPhys);
 VMMDECL(int)            PGMShwMakePageReadonly(PVMCPU pVCpu, RTGCPTR GCPtr, uint32_t fFlags);
@@ -418,10 +418,10 @@ VMMDECL(int)        PGMChangeMode(PVMCPU
 VMMDECL(void)       PGMCr0WpEnabled(PVMCPU pVCpu);
 VMMDECL(PGMMODE)    PGMGetGuestMode(PVMCPU pVCpu);
 VMMDECL(PGMMODE)    PGMGetShadowMode(PVMCPU pVCpu);
-VMMDECL(PGMMODE)    PGMGetHostMode(PVM pVM);
+VMMDECL(PGMMODE)    PGMGetHostMode(vbox_PVM pVM);
 VMMDECL(const char *) PGMGetModeName(PGMMODE enmMode);
 VMM_INT_DECL(void)  PGMNotifyNxeChanged(PVMCPU pVCpu, bool fNxe);
-VMMDECL(bool)       PGMHasDirtyPages(PVM pVM);
+VMMDECL(bool)       PGMHasDirtyPages(vbox_PVM pVM);
 
 /** PGM physical access handler type registration handle (heap offset, valid
  * cross contexts without needing fixing up).  Callbacks and handler type is
@@ -431,22 +431,22 @@ typedef uint32_t PGMPHYSHANDLERTYPE;
 typedef PGMPHYSHANDLERTYPE *PPGMPHYSHANDLERTYPE;
 /** NIL value for PGM physical access handler type handle. */
 #define NIL_PGMPHYSHANDLERTYPE  UINT32_MAX
-VMMDECL(uint32_t)   PGMHandlerPhysicalTypeRelease(PVM pVM, PGMPHYSHANDLERTYPE hType);
-VMMDECL(uint32_t)   PGMHandlerPhysicalTypeRetain(PVM pVM, PGMPHYSHANDLERTYPE hType);
+VMMDECL(uint32_t)   PGMHandlerPhysicalTypeRelease(vbox_PVM pVM, PGMPHYSHANDLERTYPE hType);
+VMMDECL(uint32_t)   PGMHandlerPhysicalTypeRetain(vbox_PVM pVM, PGMPHYSHANDLERTYPE hType);
 
-VMMDECL(int)        PGMHandlerPhysicalRegister(PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysLast, PGMPHYSHANDLERTYPE hType,
+VMMDECL(int)        PGMHandlerPhysicalRegister(vbox_PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysLast, PGMPHYSHANDLERTYPE hType,
                                                RTR3PTR pvUserR3, RTR0PTR pvUserR0, RTRCPTR pvUserRC,
                                                R3PTRTYPE(const char *) pszDesc);
-VMMDECL(int)        PGMHandlerPhysicalModify(PVM pVM, RTGCPHYS GCPhysCurrent, RTGCPHYS GCPhys, RTGCPHYS GCPhysLast);
-VMMDECL(int)        PGMHandlerPhysicalDeregister(PVM pVM, RTGCPHYS GCPhys);
-VMMDECL(int)        PGMHandlerPhysicalChangeUserArgs(PVM pVM, RTGCPHYS GCPhys, RTR3PTR pvUserR3, RTR0PTR pvUserR0, RTRCPTR pvUserRC);
-VMMDECL(int)        PGMHandlerPhysicalSplit(PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysSplit);
-VMMDECL(int)        PGMHandlerPhysicalJoin(PVM pVM, RTGCPHYS GCPhys1, RTGCPHYS GCPhys2);
-VMMDECL(int)        PGMHandlerPhysicalPageTempOff(PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysPage);
-VMMDECL(int)        PGMHandlerPhysicalPageAlias(PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysPage, RTGCPHYS GCPhysPageRemap);
-VMMDECL(int)        PGMHandlerPhysicalPageAliasHC(PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysPage, RTHCPHYS HCPhysPageRemap);
-VMMDECL(int)        PGMHandlerPhysicalReset(PVM pVM, RTGCPHYS GCPhys);
-VMMDECL(bool)       PGMHandlerPhysicalIsRegistered(PVM pVM, RTGCPHYS GCPhys);
+VMMDECL(int)        PGMHandlerPhysicalModify(vbox_PVM pVM, RTGCPHYS GCPhysCurrent, RTGCPHYS GCPhys, RTGCPHYS GCPhysLast);
+VMMDECL(int)        PGMHandlerPhysicalDeregister(vbox_PVM pVM, RTGCPHYS GCPhys);
+VMMDECL(int)        PGMHandlerPhysicalChangeUserArgs(vbox_PVM pVM, RTGCPHYS GCPhys, RTR3PTR pvUserR3, RTR0PTR pvUserR0, RTRCPTR pvUserRC);
+VMMDECL(int)        PGMHandlerPhysicalSplit(vbox_PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysSplit);
+VMMDECL(int)        PGMHandlerPhysicalJoin(vbox_PVM pVM, RTGCPHYS GCPhys1, RTGCPHYS GCPhys2);
+VMMDECL(int)        PGMHandlerPhysicalPageTempOff(vbox_PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysPage);
+VMMDECL(int)        PGMHandlerPhysicalPageAlias(vbox_PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysPage, RTGCPHYS GCPhysPageRemap);
+VMMDECL(int)        PGMHandlerPhysicalPageAliasHC(vbox_PVM pVM, RTGCPHYS GCPhys, RTGCPHYS GCPhysPage, RTHCPHYS HCPhysPageRemap);
+VMMDECL(int)        PGMHandlerPhysicalReset(vbox_PVM pVM, RTGCPHYS GCPhys);
+VMMDECL(bool)       PGMHandlerPhysicalIsRegistered(vbox_PVM pVM, RTGCPHYS GCPhys);
 
 /** PGM virtual access handler type registration handle (heap offset, valid
  * cross contexts without needing fixing up).  Callbacks and handler type is
@@ -457,9 +457,9 @@ typedef PGMVIRTHANDLERTYPE *PPGMVIRTHAND
 /** NIL value for PGM virtual access handler type handle. */
 #define NIL_PGMVIRTHANDLERTYPE  UINT32_MAX
 #ifdef VBOX_WITH_RAW_MODE
-VMM_INT_DECL(uint32_t) PGMHandlerVirtualTypeRelease(PVM pVM, PGMVIRTHANDLERTYPE hType);
-VMM_INT_DECL(uint32_t) PGMHandlerVirtualTypeRetain(PVM pVM, PGMVIRTHANDLERTYPE hType);
-VMM_INT_DECL(bool)     PGMHandlerVirtualIsRegistered(PVM pVM, RTGCPTR GCPtr);
+VMM_INT_DECL(uint32_t) PGMHandlerVirtualTypeRelease(vbox_PVM pVM, PGMVIRTHANDLERTYPE hType);
+VMM_INT_DECL(uint32_t) PGMHandlerVirtualTypeRetain(vbox_PVM pVM, PGMVIRTHANDLERTYPE hType);
+VMM_INT_DECL(bool)     PGMHandlerVirtualIsRegistered(vbox_PVM pVM, RTGCPTR GCPtr);
 #endif
 
 
@@ -498,20 +498,20 @@ typedef enum PGMPAGETYPE
 } PGMPAGETYPE;
 AssertCompile(PGMPAGETYPE_END == 8);
 
-VMM_INT_DECL(PGMPAGETYPE) PGMPhysGetPageType(PVM pVM, RTGCPHYS GCPhys);
+VMM_INT_DECL(PGMPAGETYPE) PGMPhysGetPageType(vbox_PVM pVM, RTGCPHYS GCPhys);
 
-VMM_INT_DECL(int)   PGMPhysGCPhys2HCPhys(PVM pVM, RTGCPHYS GCPhys, PRTHCPHYS pHCPhys);
+VMM_INT_DECL(int)   PGMPhysGCPhys2HCPhys(vbox_PVM pVM, RTGCPHYS GCPhys, PRTHCPHYS pHCPhys);
 VMM_INT_DECL(int)   PGMPhysGCPtr2HCPhys(PVMCPU pVCpu, RTGCPTR GCPtr, PRTHCPHYS pHCPhys);
-VMM_INT_DECL(int)   PGMPhysGCPhys2CCPtr(PVM pVM, RTGCPHYS GCPhys, void **ppv, PPGMPAGEMAPLOCK pLock);
-VMM_INT_DECL(int)   PGMPhysGCPhys2CCPtrReadOnly(PVM pVM, RTGCPHYS GCPhys, void const **ppv, PPGMPAGEMAPLOCK pLock);
+VMM_INT_DECL(int)   PGMPhysGCPhys2CCPtr(vbox_PVM pVM, RTGCPHYS GCPhys, void **ppv, PPGMPAGEMAPLOCK pLock);
+VMM_INT_DECL(int)   PGMPhysGCPhys2CCPtrReadOnly(vbox_PVM pVM, RTGCPHYS GCPhys, void const **ppv, PPGMPAGEMAPLOCK pLock);
 VMM_INT_DECL(int)   PGMPhysGCPtr2CCPtr(PVMCPU pVCpu, RTGCPTR GCPtr, void **ppv, PPGMPAGEMAPLOCK pLock);
 VMM_INT_DECL(int)   PGMPhysGCPtr2CCPtrReadOnly(PVMCPU pVCpu, RTGCPTR GCPtr, void const **ppv, PPGMPAGEMAPLOCK pLock);
 
 VMMDECL(bool)       PGMPhysIsA20Enabled(PVMCPU pVCpu);
-VMMDECL(bool)       PGMPhysIsGCPhysValid(PVM pVM, RTGCPHYS GCPhys);
-VMMDECL(bool)       PGMPhysIsGCPhysNormal(PVM pVM, RTGCPHYS GCPhys);
+VMMDECL(bool)       PGMPhysIsGCPhysValid(vbox_PVM pVM, RTGCPHYS GCPhys);
+VMMDECL(bool)       PGMPhysIsGCPhysNormal(vbox_PVM pVM, RTGCPHYS GCPhys);
 VMMDECL(int)        PGMPhysGCPtr2GCPhys(PVMCPU pVCpu, RTGCPTR GCPtr, PRTGCPHYS pGCPhys);
-VMMDECL(void)       PGMPhysReleasePageMappingLock(PVM pVM, PPGMPAGEMAPLOCK pLock);
+VMMDECL(void)       PGMPhysReleasePageMappingLock(vbox_PVM pVM, PPGMPAGEMAPLOCK pLock);
 
 /** @def PGM_PHYS_RW_IS_SUCCESS
  * Check whether a PGMPhysRead, PGMPhysWrite, PGMPhysReadGCPtr or
@@ -595,26 +595,26 @@ VMMDECL(void)       PGMPhysReleasePageMa
     } while (0)
 #endif
 
-VMMDECL(VBOXSTRICTRC) PGMPhysRead(PVM pVM, RTGCPHYS GCPhys, void *pvBuf, size_t cbRead, PGMACCESSORIGIN enmOrigin);
-VMMDECL(VBOXSTRICTRC) PGMPhysWrite(PVM pVM, RTGCPHYS GCPhys, const void *pvBuf, size_t cbWrite, PGMACCESSORIGIN enmOrigin);
+VMMDECL(VBOXSTRICTRC) PGMPhysRead(vbox_PVM pVM, RTGCPHYS GCPhys, void *pvBuf, size_t cbRead, PGMACCESSORIGIN enmOrigin);
+VMMDECL(VBOXSTRICTRC) PGMPhysWrite(vbox_PVM pVM, RTGCPHYS GCPhys, const void *pvBuf, size_t cbWrite, PGMACCESSORIGIN enmOrigin);
 VMMDECL(VBOXSTRICTRC) PGMPhysReadGCPtr(PVMCPU pVCpu, void *pvDst, RTGCPTR GCPtrSrc, size_t cb, PGMACCESSORIGIN enmOrigin);
 VMMDECL(VBOXSTRICTRC) PGMPhysWriteGCPtr(PVMCPU pVCpu, RTGCPTR GCPtrDst, const void *pvSrc, size_t cb, PGMACCESSORIGIN enmOrigin);
 
-VMMDECL(int)        PGMPhysSimpleReadGCPhys(PVM pVM, void *pvDst, RTGCPHYS GCPhysSrc, size_t cb);
-VMMDECL(int)        PGMPhysSimpleWriteGCPhys(PVM pVM, RTGCPHYS GCPhysDst, const void *pvSrc, size_t cb);
+VMMDECL(int)        PGMPhysSimpleReadGCPhys(vbox_PVM pVM, void *pvDst, RTGCPHYS GCPhysSrc, size_t cb);
+VMMDECL(int)        PGMPhysSimpleWriteGCPhys(vbox_PVM pVM, RTGCPHYS GCPhysDst, const void *pvSrc, size_t cb);
 VMMDECL(int)        PGMPhysSimpleReadGCPtr(PVMCPU pVCpu, void *pvDst, RTGCPTR GCPtrSrc, size_t cb);
 VMMDECL(int)        PGMPhysSimpleWriteGCPtr(PVMCPU pVCpu, RTGCPTR GCPtrDst, const void *pvSrc, size_t cb);
 VMMDECL(int)        PGMPhysSimpleDirtyWriteGCPtr(PVMCPU pVCpu, RTGCPTR GCPtrDst, const void *pvSrc, size_t cb);
 VMMDECL(int)        PGMPhysInterpretedRead(PVMCPU pVCpu, PCPUMCTXCORE pCtxCore, void *pvDst, RTGCPTR GCPtrSrc, size_t cb);
 VMMDECL(int)        PGMPhysInterpretedReadNoHandlers(PVMCPU pVCpu, PCPUMCTXCORE pCtxCore, void *pvDst, RTGCUINTPTR GCPtrSrc, size_t cb, bool fRaiseTrap);
 VMMDECL(int)        PGMPhysInterpretedWriteNoHandlers(PVMCPU pVCpu, PCPUMCTXCORE pCtxCore, RTGCPTR GCPtrDst, void const *pvSrc, size_t cb, bool fRaiseTrap);
-VMM_INT_DECL(int)   PGMPhysIemGCPhys2Ptr(PVM pVM, PVMCPU pVCpu, RTGCPHYS GCPhys, bool fWritable, bool fByPassHandlers, void **ppv, PPGMPAGEMAPLOCK pLock);
-VMM_INT_DECL(int)   PGMPhysIemQueryAccess(PVM pVM, RTGCPHYS GCPhys, bool fWritable, bool fByPassHandlers);
+VMM_INT_DECL(int)   PGMPhysIemGCPhys2Ptr(vbox_PVM pVM, PVMCPU pVCpu, RTGCPHYS GCPhys, bool fWritable, bool fByPassHandlers, void **ppv, PPGMPAGEMAPLOCK pLock);
+VMM_INT_DECL(int)   PGMPhysIemQueryAccess(vbox_PVM pVM, RTGCPHYS GCPhys, bool fWritable, bool fByPassHandlers);
 
 #ifdef VBOX_STRICT
-VMMDECL(unsigned)   PGMAssertHandlerAndFlagsInSync(PVM pVM);
-VMMDECL(unsigned)   PGMAssertNoMappingConflicts(PVM pVM);
-VMMDECL(unsigned)   PGMAssertCR3(PVM pVM, PVMCPU pVCpu, uint64_t cr3, uint64_t cr4);
+VMMDECL(unsigned)   PGMAssertHandlerAndFlagsInSync(vbox_PVM pVM);
+VMMDECL(unsigned)   PGMAssertNoMappingConflicts(vbox_PVM pVM);
+VMMDECL(unsigned)   PGMAssertCR3(vbox_PVM pVM, PVMCPU pVCpu, uint64_t cr3, uint64_t cr4);
 #endif /* VBOX_STRICT */
 
 #if defined(IN_RC) || defined(VBOX_WITH_2X_4GB_ADDR_SPACE)
@@ -625,7 +625,7 @@ VMMDECL(uint32_t)   PGMRZDynMapPushAutoS
 VMMDECL(void)       PGMRZDynMapPopAutoSubset(PVMCPU pVCpu, uint32_t iPrevSubset);
 #endif
 
-VMMDECL(int)        PGMSetLargePageUsage(PVM pVM, bool fUseLargePages);
+VMMDECL(int)        PGMSetLargePageUsage(vbox_PVM pVM, bool fUseLargePages);
 
 /**
  * Query large page usage state
@@ -640,7 +640,7 @@ VMMDECL(int)        PGMSetLargePageUsage
 /** @defgroup grp_pgm_gc  The PGM Guest Context API
  * @{
  */
-VMMRCDECL(int)      PGMRCDynMapInit(PVM pVM);
+VMMRCDECL(int)      PGMRCDynMapInit(vbox_PVM pVM);
 /** @} */
 #endif /* IN_RC */
 
@@ -649,18 +649,18 @@ VMMRCDECL(int)      PGMRCDynMapInit(PVM 
 /** @defgroup grp_pgm_r0  The PGM Host Context Ring-0 API
  * @{
  */
-VMMR0_INT_DECL(int) PGMR0PhysAllocateHandyPages(PVM pVM, PVMCPU pVCpu);
-VMMR0_INT_DECL(int) PGMR0PhysFlushHandyPages(PVM pVM, PVMCPU pVCpu);
-VMMR0_INT_DECL(int) PGMR0PhysAllocateLargeHandyPage(PVM pVM, PVMCPU pVCpu);
-VMMR0_INT_DECL(int) PGMR0PhysSetupIommu(PVM pVM);
-VMMR0DECL(int)      PGMR0SharedModuleCheck(PVM pVM, PGVM pGVM, VMCPUID idCpu, PGMMSHAREDMODULE pModule, PCRTGCPTR64 paRegionsGCPtrs);
-VMMR0DECL(int)      PGMR0Trap0eHandlerNestedPaging(PVM pVM, PVMCPU pVCpu, PGMMODE enmShwPagingMode, RTGCUINT uErr, PCPUMCTXCORE pRegFrame, RTGCPHYS pvFault);
-VMMR0DECL(VBOXSTRICTRC) PGMR0Trap0eHandlerNPMisconfig(PVM pVM, PVMCPU pVCpu, PGMMODE enmShwPagingMode, PCPUMCTXCORE pRegFrame, RTGCPHYS GCPhysFault, uint32_t uErr);
+VMMR0_INT_DECL(int) PGMR0PhysAllocateHandyPages(vbox_PVM pVM, PVMCPU pVCpu);
+VMMR0_INT_DECL(int) PGMR0PhysFlushHandyPages(vbox_PVM pVM, PVMCPU pVCpu);
+VMMR0_INT_DECL(int) PGMR0PhysAllocateLargeHandyPage(vbox_PVM pVM, PVMCPU pVCpu);
+VMMR0_INT_DECL(int) PGMR0PhysSetupIommu(vbox_PVM pVM);
+VMMR0DECL(int)      PGMR0SharedModuleCheck(vbox_PVM pVM, PGVM pGVM, VMCPUID idCpu, PGMMSHAREDMODULE pModule, PCRTGCPTR64 paRegionsGCPtrs);
+VMMR0DECL(int)      PGMR0Trap0eHandlerNestedPaging(vbox_PVM pVM, PVMCPU pVCpu, PGMMODE enmShwPagingMode, RTGCUINT uErr, PCPUMCTXCORE pRegFrame, RTGCPHYS pvFault);
+VMMR0DECL(VBOXSTRICTRC) PGMR0Trap0eHandlerNPMisconfig(vbox_PVM pVM, PVMCPU pVCpu, PGMMODE enmShwPagingMode, PCPUMCTXCORE pRegFrame, RTGCPHYS GCPhysFault, uint32_t uErr);
 # ifdef VBOX_WITH_2X_4GB_ADDR_SPACE
 VMMR0DECL(int)      PGMR0DynMapInit(void);
 VMMR0DECL(void)     PGMR0DynMapTerm(void);
-VMMR0DECL(int)      PGMR0DynMapInitVM(PVM pVM);
-VMMR0DECL(void)     PGMR0DynMapTermVM(PVM pVM);
+VMMR0DECL(int)      PGMR0DynMapInitVM(vbox_PVM pVM);
+VMMR0DECL(void)     PGMR0DynMapTermVM(vbox_PVM pVM);
 VMMR0DECL(int)      PGMR0DynMapAssertIntegrity(void);
 VMMR0DECL(bool)     PGMR0DynMapStartOrMigrateAutoSet(PVMCPU pVCpu);
 VMMR0DECL(void)     PGMR0DynMapMigrateAutoSet(PVMCPU pVCpu);
@@ -674,39 +674,39 @@ VMMR0DECL(void)     PGMR0DynMapMigrateAu
 /** @defgroup grp_pgm_r3  The PGM Host Context Ring-3 API
  * @{
  */
-VMMR3DECL(int)      PGMR3Init(PVM pVM);
-VMMR3DECL(int)      PGMR3InitDynMap(PVM pVM);
-VMMR3DECL(int)      PGMR3InitFinalize(PVM pVM);
-VMMR3_INT_DECL(int) PGMR3InitCompleted(PVM pVM, VMINITCOMPLETED enmWhat);
-VMMR3DECL(void)     PGMR3Relocate(PVM pVM, RTGCINTPTR offDelta);
-VMMR3DECL(void)     PGMR3ResetCpu(PVM pVM, PVMCPU pVCpu);
-VMMR3_INT_DECL(void)    PGMR3Reset(PVM pVM);
-VMMR3_INT_DECL(void)    PGMR3ResetNoMorePhysWritesFlag(PVM pVM);
-VMMR3_INT_DECL(void)    PGMR3MemSetup(PVM pVM, bool fReset);
-VMMR3DECL(int)      PGMR3Term(PVM pVM);
-VMMR3DECL(int)      PGMR3LockCall(PVM pVM);
-VMMR3DECL(int)      PGMR3ChangeMode(PVM pVM, PVMCPU pVCpu, PGMMODE enmGuestMode);
-
-VMMR3DECL(int)      PGMR3PhysRegisterRam(PVM pVM, RTGCPHYS GCPhys, RTGCPHYS cb, const char *pszDesc);
-VMMR3DECL(int)      PGMR3PhysChangeMemBalloon(PVM pVM, bool fInflate, unsigned cPages, RTGCPHYS *paPhysPage);
-VMMR3DECL(int)      PGMR3PhysWriteProtectRAM(PVM pVM);
-VMMR3DECL(int)      PGMR3PhysEnumDirtyFTPages(PVM pVM, PFNPGMENUMDIRTYFTPAGES pfnEnum, void *pvUser);
-VMMR3DECL(uint32_t) PGMR3PhysGetRamRangeCount(PVM pVM);
-VMMR3DECL(int)      PGMR3PhysGetRange(PVM pVM, uint32_t iRange, PRTGCPHYS pGCPhysStart, PRTGCPHYS pGCPhysLast,
+VMMR3DECL(int)      PGMR3Init(vbox_PVM pVM);
+VMMR3DECL(int)      PGMR3InitDynMap(vbox_PVM pVM);
+VMMR3DECL(int)      PGMR3InitFinalize(vbox_PVM pVM);
+VMMR3_INT_DECL(int) PGMR3InitCompleted(vbox_PVM pVM, VMINITCOMPLETED enmWhat);
+VMMR3DECL(void)     PGMR3Relocate(vbox_PVM pVM, RTGCINTPTR offDelta);
+VMMR3DECL(void)     PGMR3ResetCpu(vbox_PVM pVM, PVMCPU pVCpu);
+VMMR3_INT_DECL(void)    PGMR3Reset(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    PGMR3ResetNoMorePhysWritesFlag(vbox_PVM pVM);
+VMMR3_INT_DECL(void)    PGMR3MemSetup(vbox_PVM pVM, bool fReset);
+VMMR3DECL(int)      PGMR3Term(vbox_PVM pVM);
+VMMR3DECL(int)      PGMR3LockCall(vbox_PVM pVM);
+VMMR3DECL(int)      PGMR3ChangeMode(vbox_PVM pVM, PVMCPU pVCpu, PGMMODE enmGuestMode);
+
+VMMR3DECL(int)      PGMR3PhysRegisterRam(vbox_PVM pVM, RTGCPHYS GCPhys, RTGCPHYS cb, const char *pszDesc);
+VMMR3DECL(int)      PGMR3PhysChangeMemBalloon(vbox_PVM pVM, bool fInflate, unsigned cPages, RTGCPHYS *paPhysPage);
+VMMR3DECL(int)      PGMR3PhysWriteProtectRAM(vbox_PVM pVM);
+VMMR3DECL(int)      PGMR3PhysEnumDirtyFTPages(vbox_PVM pVM, PFNPGMENUMDIRTYFTPAGES pfnEnum, void *pvUser);
+VMMR3DECL(uint32_t) PGMR3PhysGetRamRangeCount(vbox_PVM pVM);
+VMMR3DECL(int)      PGMR3PhysGetRange(vbox_PVM pVM, uint32_t iRange, PRTGCPHYS pGCPhysStart, PRTGCPHYS pGCPhysLast,
                                       const char **ppszDesc, bool *pfIsMmio);
 VMMR3DECL(int)      PGMR3QueryMemoryStats(PUVM pUVM, uint64_t *pcbTotalMem, uint64_t *pcbPrivateMem, uint64_t *pcbSharedMem, uint64_t *pcbZeroMem);
 VMMR3DECL(int)      PGMR3QueryGlobalMemoryStats(PUVM pUVM, uint64_t *pcbAllocMem, uint64_t *pcbFreeMem, uint64_t *pcbBallonedMem, uint64_t *pcbSharedMem);
 
-VMMR3DECL(int)      PGMR3PhysMMIORegister(PVM pVM, RTGCPHYS GCPhys, RTGCPHYS cb, PGMPHYSHANDLERTYPE hType,
+VMMR3DECL(int)      PGMR3PhysMMIORegister(vbox_PVM pVM, RTGCPHYS GCPhys, RTGCPHYS cb, PGMPHYSHANDLERTYPE hType,
                                           RTR3PTR pvUserR3, RTR0PTR pvUserR0, RTRCPTR pvUserRC, const char *pszDesc);
-VMMR3DECL(int)      PGMR3PhysMMIODeregister(PVM pVM, RTGCPHYS GCPhys, RTGCPHYS cb);
-VMMR3DECL(int)      PGMR3PhysMMIO2Register(PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS cb, uint32_t fFlags, void **ppv, const char *pszDesc);
-VMMR3DECL(int)      PGMR3PhysMMIO2Deregister(PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion);
-VMMR3DECL(int)      PGMR3PhysMMIO2Map(PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS GCPhys);
-VMMR3DECL(int)      PGMR3PhysMMIO2Unmap(PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS GCPhys);
-VMMR3DECL(bool)     PGMR3PhysMMIO2IsBase(PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhys);
-VMMR3DECL(int)      PGMR3PhysMMIO2GetHCPhys(PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS off, PRTHCPHYS pHCPhys);
-VMMR3DECL(int)      PGMR3PhysMMIO2MapKernel(PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS off, RTGCPHYS cb, const char *pszDesc, PRTR0PTR pR0Ptr);
+VMMR3DECL(int)      PGMR3PhysMMIODeregister(vbox_PVM pVM, RTGCPHYS GCPhys, RTGCPHYS cb);
+VMMR3DECL(int)      PGMR3PhysMMIO2Register(vbox_PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS cb, uint32_t fFlags, void **ppv, const char *pszDesc);
+VMMR3DECL(int)      PGMR3PhysMMIO2Deregister(vbox_PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion);
+VMMR3DECL(int)      PGMR3PhysMMIO2Map(vbox_PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS GCPhys);
+VMMR3DECL(int)      PGMR3PhysMMIO2Unmap(vbox_PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS GCPhys);
+VMMR3DECL(bool)     PGMR3PhysMMIO2IsBase(vbox_PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhys);
+VMMR3DECL(int)      PGMR3PhysMMIO2GetHCPhys(vbox_PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS off, PRTHCPHYS pHCPhys);
+VMMR3DECL(int)      PGMR3PhysMMIO2MapKernel(vbox_PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS off, RTGCPHYS cb, const char *pszDesc, PRTR0PTR pR0Ptr);
 
 /** @name PGMR3PhysRegisterRom flags.
  * @{ */
@@ -717,102 +717,102 @@ VMMR3DECL(int)      PGMR3PhysMMIO2MapKer
 #define PGMPHYS_ROM_FLAGS_PERMANENT_BINARY  RT_BIT_32(1)
 /** @} */
 
-VMMR3DECL(int)      PGMR3PhysRomRegister(PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhys, RTGCPHYS cb,
+VMMR3DECL(int)      PGMR3PhysRomRegister(vbox_PVM pVM, PPDMDEVINS pDevIns, RTGCPHYS GCPhys, RTGCPHYS cb,
                                          const void *pvBinary, uint32_t cbBinary, uint32_t fFlags, const char *pszDesc);
-VMMR3DECL(int)      PGMR3PhysRomProtect(PVM pVM, RTGCPHYS GCPhys, RTGCPHYS cb, PGMROMPROT enmProt);
-VMMR3DECL(int)      PGMR3PhysRegister(PVM pVM, void *pvRam, RTGCPHYS GCPhys, size_t cb, unsigned fFlags, const SUPPAGE *paPages, const char *pszDesc);
+VMMR3DECL(int)      PGMR3PhysRomProtect(vbox_PVM pVM, RTGCPHYS GCPhys, RTGCPHYS cb, PGMROMPROT enmProt);
+VMMR3DECL(int)      PGMR3PhysRegister(vbox_PVM pVM, void *pvRam, RTGCPHYS GCPhys, size_t cb, unsigned fFlags, const SUPPAGE *paPages, const char *pszDesc);
 VMMDECL(void)       PGMR3PhysSetA20(PVMCPU pVCpu, bool fEnable);
 /** @name PGMR3MapPT flags.
  * @{ */
 /** The mapping may be unmapped later. The default is permanent mappings. */
 #define PGMR3MAPPT_FLAGS_UNMAPPABLE     RT_BIT(0)
 /** @} */
-VMMR3DECL(int)      PGMR3MapPT(PVM pVM, RTGCPTR GCPtr, uint32_t cb, uint32_t fFlags, PFNPGMRELOCATE pfnRelocate, void *pvUser, const char *pszDesc);
-VMMR3DECL(int)      PGMR3UnmapPT(PVM pVM, RTGCPTR GCPtr);
-VMMR3DECL(int)      PGMR3FinalizeMappings(PVM pVM);
-VMMR3DECL(int)      PGMR3MappingsSize(PVM pVM, uint32_t *pcb);
-VMMR3DECL(int)      PGMR3MappingsFix(PVM pVM, RTGCPTR GCPtrBase, uint32_t cb);
-VMMR3DECL(int)      PGMR3MappingsUnfix(PVM pVM);
-VMMR3DECL(bool)     PGMR3MappingsNeedReFixing(PVM pVM);
+VMMR3DECL(int)      PGMR3MapPT(vbox_PVM pVM, RTGCPTR GCPtr, uint32_t cb, uint32_t fFlags, PFNPGMRELOCATE pfnRelocate, void *pvUser, const char *pszDesc);
+VMMR3DECL(int)      PGMR3UnmapPT(vbox_PVM pVM, RTGCPTR GCPtr);
+VMMR3DECL(int)      PGMR3FinalizeMappings(vbox_PVM pVM);
+VMMR3DECL(int)      PGMR3MappingsSize(vbox_PVM pVM, uint32_t *pcb);
+VMMR3DECL(int)      PGMR3MappingsFix(vbox_PVM pVM, RTGCPTR GCPtrBase, uint32_t cb);
+VMMR3DECL(int)      PGMR3MappingsUnfix(vbox_PVM pVM);
+VMMR3DECL(bool)     PGMR3MappingsNeedReFixing(vbox_PVM pVM);
 #if defined(VBOX_WITH_RAW_MODE) || HC_ARCH_BITS == 32 /* (latter for 64-bit guests on 32-bit hosts) */
-VMMR3DECL(int)      PGMR3MapIntermediate(PVM pVM, RTUINTPTR Addr, RTHCPHYS HCPhys, unsigned cbPages);
+VMMR3DECL(int)      PGMR3MapIntermediate(vbox_PVM pVM, RTUINTPTR Addr, RTHCPHYS HCPhys, unsigned cbPages);
 #endif
-VMMR3DECL(int)      PGMR3MapRead(PVM pVM, void *pvDst, RTGCPTR GCPtrSrc, size_t cb);
+VMMR3DECL(int)      PGMR3MapRead(vbox_PVM pVM, void *pvDst, RTGCPTR GCPtrSrc, size_t cb);
 
-VMMR3_INT_DECL(int) PGMR3HandlerPhysicalTypeRegisterEx(PVM pVM, PGMPHYSHANDLERKIND enmKind,
+VMMR3_INT_DECL(int) PGMR3HandlerPhysicalTypeRegisterEx(vbox_PVM pVM, PGMPHYSHANDLERKIND enmKind,
                                                        PFNPGMPHYSHANDLER pfnHandlerR3,
                                                        R0PTRTYPE(PFNPGMPHYSHANDLER)     pfnHandlerR0,
                                                        R0PTRTYPE(PFNPGMRZPHYSPFHANDLER) pfnPfHandlerR0,
                                                        RCPTRTYPE(PFNPGMPHYSHANDLER)     pfnHandlerRC,
                                                        RCPTRTYPE(PFNPGMRZPHYSPFHANDLER) pfnPfHandlerRC,
                                                        const char *pszDesc, PPGMPHYSHANDLERTYPE phType);
-VMMR3DECL(int)      PGMR3HandlerPhysicalTypeRegister(PVM pVM, PGMPHYSHANDLERKIND enmKind,
+VMMR3DECL(int)      PGMR3HandlerPhysicalTypeRegister(vbox_PVM pVM, PGMPHYSHANDLERKIND enmKind,
                                                      R3PTRTYPE(PFNPGMPHYSHANDLER) pfnHandlerR3,
                                                      const char *pszModR0, const char *pszHandlerR0, const char *pszPfHandlerR0,
                                                      const char *pszModRC, const char *pszHandlerRC, const char *pszPfHandlerRC,
                                                      const char *pszDesc,
                                                      PPGMPHYSHANDLERTYPE phType);
 #ifdef VBOX_WITH_RAW_MODE
-VMMR3_INT_DECL(int) PGMR3HandlerVirtualTypeRegisterEx(PVM pVM, PGMVIRTHANDLERKIND enmKind, bool fRelocUserRC,
+VMMR3_INT_DECL(int) PGMR3HandlerVirtualTypeRegisterEx(vbox_PVM pVM, PGMVIRTHANDLERKIND enmKind, bool fRelocUserRC,
                                                       PFNPGMR3VIRTINVALIDATE pfnInvalidateR3,
                                                       PFNPGMVIRTHANDLER pfnHandlerR3,
                                                       RCPTRTYPE(FNPGMVIRTHANDLER) pfnHandlerRC,
                                                       RCPTRTYPE(FNPGMRCVIRTPFHANDLER) pfnPfHandlerRC,
                                                       const char *pszDesc, PPGMVIRTHANDLERTYPE phType);
-VMMR3_INT_DECL(int) PGMR3HandlerVirtualTypeRegister(PVM pVM, PGMVIRTHANDLERKIND enmKind, bool fRelocUserRC,
+VMMR3_INT_DECL(int) PGMR3HandlerVirtualTypeRegister(vbox_PVM pVM, PGMVIRTHANDLERKIND enmKind, bool fRelocUserRC,
                                                     PFNPGMR3VIRTINVALIDATE pfnInvalidateR3,
                                                     PFNPGMVIRTHANDLER pfnHandlerR3,
                                                     const char *pszHandlerRC, const char *pszPfHandlerRC, const char *pszDesc,
                                                     PPGMVIRTHANDLERTYPE phType);
-VMMR3_INT_DECL(int) PGMR3HandlerVirtualRegister(PVM pVM, PVMCPU pVCpu, PGMVIRTHANDLERTYPE hType, RTGCPTR GCPtr,
+VMMR3_INT_DECL(int) PGMR3HandlerVirtualRegister(vbox_PVM pVM, PVMCPU pVCpu, PGMVIRTHANDLERTYPE hType, RTGCPTR GCPtr,
                                                 RTGCPTR GCPtrLast, void *pvUserR3, RTRCPTR pvUserRC, const char *pszDesc);
-VMMR3_INT_DECL(int) PGMHandlerVirtualChangeType(PVM pVM, RTGCPTR GCPtr, PGMVIRTHANDLERTYPE hNewType);
-VMMR3_INT_DECL(int) PGMHandlerVirtualDeregister(PVM pVM, PVMCPU pVCpu, RTGCPTR GCPtr, bool fHypervisor);
+VMMR3_INT_DECL(int) PGMHandlerVirtualChangeType(vbox_PVM pVM, RTGCPTR GCPtr, PGMVIRTHANDLERTYPE hNewType);
+VMMR3_INT_DECL(int) PGMHandlerVirtualDeregister(vbox_PVM pVM, PVMCPU pVCpu, RTGCPTR GCPtr, bool fHypervisor);
 #endif
-VMMR3DECL(int)      PGMR3PoolGrow(PVM pVM);
+VMMR3DECL(int)      PGMR3PoolGrow(vbox_PVM pVM);
 
-VMMR3DECL(int)      PGMR3PhysTlbGCPhys2Ptr(PVM pVM, RTGCPHYS GCPhys, bool fWritable, void **ppv);
-VMMR3DECL(uint8_t)  PGMR3PhysReadU8(PVM pVM, RTGCPHYS GCPhys, PGMACCESSORIGIN enmOrigin);
-VMMR3DECL(uint16_t) PGMR3PhysReadU16(PVM pVM, RTGCPHYS GCPhys, PGMACCESSORIGIN enmOrigin);
-VMMR3DECL(uint32_t) PGMR3PhysReadU32(PVM pVM, RTGCPHYS GCPhys, PGMACCESSORIGIN enmOrigin);
-VMMR3DECL(uint64_t) PGMR3PhysReadU64(PVM pVM, RTGCPHYS GCPhys, PGMACCESSORIGIN enmOrigin);
-VMMR3DECL(void)     PGMR3PhysWriteU8(PVM pVM, RTGCPHYS GCPhys, uint8_t Value, PGMACCESSORIGIN enmOrigin);
-VMMR3DECL(void)     PGMR3PhysWriteU16(PVM pVM, RTGCPHYS GCPhys, uint16_t Value, PGMACCESSORIGIN enmOrigin);
-VMMR3DECL(void)     PGMR3PhysWriteU32(PVM pVM, RTGCPHYS GCPhys, uint32_t Value, PGMACCESSORIGIN enmOrigin);
-VMMR3DECL(void)     PGMR3PhysWriteU64(PVM pVM, RTGCPHYS GCPhys, uint64_t Value, PGMACCESSORIGIN enmOrigin);
-VMMR3DECL(int)      PGMR3PhysReadExternal(PVM pVM, RTGCPHYS GCPhys, void *pvBuf, size_t cbRead, PGMACCESSORIGIN enmOrigin);
-VMMR3DECL(int)      PGMR3PhysWriteExternal(PVM pVM, RTGCPHYS GCPhys, const void *pvBuf, size_t cbWrite, PGMACCESSORIGIN enmOrigin);
-VMMR3DECL(int)      PGMR3PhysGCPhys2CCPtrExternal(PVM pVM, RTGCPHYS GCPhys, void **ppv, PPGMPAGEMAPLOCK pLock);
-VMMR3DECL(int)      PGMR3PhysGCPhys2CCPtrReadOnlyExternal(PVM pVM, RTGCPHYS GCPhys, void const **ppv, PPGMPAGEMAPLOCK pLock);
-VMMR3DECL(int)      PGMR3PhysChunkMap(PVM pVM, uint32_t idChunk);
-VMMR3DECL(void)     PGMR3PhysChunkInvalidateTLB(PVM pVM);
-VMMR3DECL(int)      PGMR3PhysAllocateHandyPages(PVM pVM);
-VMMR3DECL(int)      PGMR3PhysAllocateLargeHandyPage(PVM pVM, RTGCPHYS GCPhys);
+VMMR3DECL(int)      PGMR3PhysTlbGCPhys2Ptr(vbox_PVM pVM, RTGCPHYS GCPhys, bool fWritable, void **ppv);
+VMMR3DECL(uint8_t)  PGMR3PhysReadU8(vbox_PVM pVM, RTGCPHYS GCPhys, PGMACCESSORIGIN enmOrigin);
+VMMR3DECL(uint16_t) PGMR3PhysReadU16(vbox_PVM pVM, RTGCPHYS GCPhys, PGMACCESSORIGIN enmOrigin);
+VMMR3DECL(uint32_t) PGMR3PhysReadU32(vbox_PVM pVM, RTGCPHYS GCPhys, PGMACCESSORIGIN enmOrigin);
+VMMR3DECL(uint64_t) PGMR3PhysReadU64(vbox_PVM pVM, RTGCPHYS GCPhys, PGMACCESSORIGIN enmOrigin);
+VMMR3DECL(void)     PGMR3PhysWriteU8(vbox_PVM pVM, RTGCPHYS GCPhys, uint8_t Value, PGMACCESSORIGIN enmOrigin);
+VMMR3DECL(void)     PGMR3PhysWriteU16(vbox_PVM pVM, RTGCPHYS GCPhys, uint16_t Value, PGMACCESSORIGIN enmOrigin);
+VMMR3DECL(void)     PGMR3PhysWriteU32(vbox_PVM pVM, RTGCPHYS GCPhys, uint32_t Value, PGMACCESSORIGIN enmOrigin);
+VMMR3DECL(void)     PGMR3PhysWriteU64(vbox_PVM pVM, RTGCPHYS GCPhys, uint64_t Value, PGMACCESSORIGIN enmOrigin);
+VMMR3DECL(int)      PGMR3PhysReadExternal(vbox_PVM pVM, RTGCPHYS GCPhys, void *pvBuf, size_t cbRead, PGMACCESSORIGIN enmOrigin);
+VMMR3DECL(int)      PGMR3PhysWriteExternal(vbox_PVM pVM, RTGCPHYS GCPhys, const void *pvBuf, size_t cbWrite, PGMACCESSORIGIN enmOrigin);
+VMMR3DECL(int)      PGMR3PhysGCPhys2CCPtrExternal(vbox_PVM pVM, RTGCPHYS GCPhys, void **ppv, PPGMPAGEMAPLOCK pLock);
+VMMR3DECL(int)      PGMR3PhysGCPhys2CCPtrReadOnlyExternal(vbox_PVM pVM, RTGCPHYS GCPhys, void const **ppv, PPGMPAGEMAPLOCK pLock);
+VMMR3DECL(int)      PGMR3PhysChunkMap(vbox_PVM pVM, uint32_t idChunk);
+VMMR3DECL(void)     PGMR3PhysChunkInvalidateTLB(vbox_PVM pVM);
+VMMR3DECL(int)      PGMR3PhysAllocateHandyPages(vbox_PVM pVM);
+VMMR3DECL(int)      PGMR3PhysAllocateLargeHandyPage(vbox_PVM pVM, RTGCPHYS GCPhys);
 
-VMMR3DECL(int)      PGMR3CheckIntegrity(PVM pVM);
+VMMR3DECL(int)      PGMR3CheckIntegrity(vbox_PVM pVM);
 
 VMMR3DECL(int)      PGMR3DbgR3Ptr2GCPhys(PUVM pUVM, RTR3PTR R3Ptr, PRTGCPHYS pGCPhys);
 VMMR3DECL(int)      PGMR3DbgR3Ptr2HCPhys(PUVM pUVM, RTR3PTR R3Ptr, PRTHCPHYS pHCPhys);
 VMMR3DECL(int)      PGMR3DbgHCPhys2GCPhys(PUVM pUVM, RTHCPHYS HCPhys, PRTGCPHYS pGCPhys);
-VMMR3_INT_DECL(int) PGMR3DbgReadGCPhys(PVM pVM, void *pvDst, RTGCPHYS GCPhysSrc, size_t cb, uint32_t fFlags, size_t *pcbRead);
-VMMR3_INT_DECL(int) PGMR3DbgWriteGCPhys(PVM pVM, RTGCPHYS GCPhysDst, const void *pvSrc, size_t cb, uint32_t fFlags, size_t *pcbWritten);
-VMMR3_INT_DECL(int) PGMR3DbgReadGCPtr(PVM pVM, void *pvDst, RTGCPTR GCPtrSrc, size_t cb, uint32_t fFlags, size_t *pcbRead);
-VMMR3_INT_DECL(int) PGMR3DbgWriteGCPtr(PVM pVM, RTGCPTR GCPtrDst, void const *pvSrc, size_t cb, uint32_t fFlags, size_t *pcbWritten);
-VMMR3_INT_DECL(int) PGMR3DbgScanPhysical(PVM pVM, RTGCPHYS GCPhys, RTGCPHYS cbRange, RTGCPHYS GCPhysAlign, const uint8_t *pabNeedle, size_t cbNeedle, PRTGCPHYS pGCPhysHit);
-VMMR3_INT_DECL(int) PGMR3DbgScanVirtual(PVM pVM, PVMCPU pVCpu, RTGCPTR GCPtr, RTGCPTR cbRange, RTGCPTR GCPtrAlign, const uint8_t *pabNeedle, size_t cbNeedle, PRTGCUINTPTR pGCPhysHit);
-VMMR3_INT_DECL(int) PGMR3DumpHierarchyShw(PVM pVM, uint64_t cr3, uint32_t fFlags, uint64_t u64FirstAddr, uint64_t u64LastAddr, uint32_t cMaxDepth, PCDBGFINFOHLP pHlp);
-VMMR3_INT_DECL(int) PGMR3DumpHierarchyGst(PVM pVM, uint64_t cr3, uint32_t fFlags, RTGCPTR FirstAddr, RTGCPTR LastAddr, uint32_t cMaxDepth, PCDBGFINFOHLP pHlp);
+VMMR3_INT_DECL(int) PGMR3DbgReadGCPhys(vbox_PVM pVM, void *pvDst, RTGCPHYS GCPhysSrc, size_t cb, uint32_t fFlags, size_t *pcbRead);
+VMMR3_INT_DECL(int) PGMR3DbgWriteGCPhys(vbox_PVM pVM, RTGCPHYS GCPhysDst, const void *pvSrc, size_t cb, uint32_t fFlags, size_t *pcbWritten);
+VMMR3_INT_DECL(int) PGMR3DbgReadGCPtr(vbox_PVM pVM, void *pvDst, RTGCPTR GCPtrSrc, size_t cb, uint32_t fFlags, size_t *pcbRead);
+VMMR3_INT_DECL(int) PGMR3DbgWriteGCPtr(vbox_PVM pVM, RTGCPTR GCPtrDst, void const *pvSrc, size_t cb, uint32_t fFlags, size_t *pcbWritten);
+VMMR3_INT_DECL(int) PGMR3DbgScanPhysical(vbox_PVM pVM, RTGCPHYS GCPhys, RTGCPHYS cbRange, RTGCPHYS GCPhysAlign, const uint8_t *pabNeedle, size_t cbNeedle, PRTGCPHYS pGCPhysHit);
+VMMR3_INT_DECL(int) PGMR3DbgScanVirtual(vbox_PVM pVM, PVMCPU pVCpu, RTGCPTR GCPtr, RTGCPTR cbRange, RTGCPTR GCPtrAlign, const uint8_t *pabNeedle, size_t cbNeedle, PRTGCUINTPTR pGCPhysHit);
+VMMR3_INT_DECL(int) PGMR3DumpHierarchyShw(vbox_PVM pVM, uint64_t cr3, uint32_t fFlags, uint64_t u64FirstAddr, uint64_t u64LastAddr, uint32_t cMaxDepth, PCDBGFINFOHLP pHlp);
+VMMR3_INT_DECL(int) PGMR3DumpHierarchyGst(vbox_PVM pVM, uint64_t cr3, uint32_t fFlags, RTGCPTR FirstAddr, RTGCPTR LastAddr, uint32_t cMaxDepth, PCDBGFINFOHLP pHlp);
 
 
 /** @name Page sharing
  * @{ */
-VMMR3DECL(int)     PGMR3SharedModuleRegister(PVM pVM, VBOXOSFAMILY enmGuestOS, char *pszModuleName, char *pszVersion,
+VMMR3DECL(int)     PGMR3SharedModuleRegister(vbox_PVM pVM, VBOXOSFAMILY enmGuestOS, char *pszModuleName, char *pszVersion,
                                              RTGCPTR GCBaseAddr, uint32_t cbModule,
                                              uint32_t cRegions, VMMDEVSHAREDREGIONDESC const *paRegions);
-VMMR3DECL(int)     PGMR3SharedModuleUnregister(PVM pVM, char *pszModuleName, char *pszVersion,
+VMMR3DECL(int)     PGMR3SharedModuleUnregister(vbox_PVM pVM, char *pszModuleName, char *pszVersion,
                                                RTGCPTR GCBaseAddr, uint32_t cbModule);
-VMMR3DECL(int)     PGMR3SharedModuleCheckAll(PVM pVM);
-VMMR3DECL(int)     PGMR3SharedModuleGetPageState(PVM pVM, RTGCPTR GCPtrPage, bool *pfShared, uint64_t *pfPageFlags);
+VMMR3DECL(int)     PGMR3SharedModuleCheckAll(vbox_PVM pVM);
+VMMR3DECL(int)     PGMR3SharedModuleGetPageState(vbox_PVM pVM, RTGCPTR GCPtrPage, bool *pfShared, uint64_t *pfPageFlags);
 /** @} */
 
 /** @} */
@@ -822,4 +822,3 @@ RT_C_DECLS_END
 
 /** @} */
 #endif
-
