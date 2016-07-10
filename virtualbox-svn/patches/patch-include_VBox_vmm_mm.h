$NetBSD$

--- include/VBox/vmm/mm.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/mm.h
@@ -145,20 +145,20 @@ typedef enum MMTAG
 /** @defgroup grp_mm_hyper  Hypervisor Memory Management
  * @{ */
 
-VMMDECL(RTR3PTR)    MMHyperR0ToR3(PVM pVM, RTR0PTR R0Ptr);
-VMMDECL(RTRCPTR)    MMHyperR0ToRC(PVM pVM, RTR0PTR R0Ptr);
+VMMDECL(RTR3PTR)    MMHyperR0ToR3(vbox_PVM pVM, RTR0PTR R0Ptr);
+VMMDECL(RTRCPTR)    MMHyperR0ToRC(vbox_PVM pVM, RTR0PTR R0Ptr);
 #ifndef IN_RING0
-VMMDECL(void *)     MMHyperR0ToCC(PVM pVM, RTR0PTR R0Ptr);
+VMMDECL(void *)     MMHyperR0ToCC(vbox_PVM pVM, RTR0PTR R0Ptr);
 #endif
-VMMDECL(RTR0PTR)    MMHyperR3ToR0(PVM pVM, RTR3PTR R3Ptr);
-VMMDECL(RTRCPTR)    MMHyperR3ToRC(PVM pVM, RTR3PTR R3Ptr);
-VMMDECL(RTR3PTR)    MMHyperRCToR3(PVM pVM, RTRCPTR RCPtr);
-VMMDECL(RTR0PTR)    MMHyperRCToR0(PVM pVM, RTRCPTR RCPtr);
+VMMDECL(RTR0PTR)    MMHyperR3ToR0(vbox_PVM pVM, RTR3PTR R3Ptr);
+VMMDECL(RTRCPTR)    MMHyperR3ToRC(vbox_PVM pVM, RTR3PTR R3Ptr);
+VMMDECL(RTR3PTR)    MMHyperRCToR3(vbox_PVM pVM, RTRCPTR RCPtr);
+VMMDECL(RTR0PTR)    MMHyperRCToR0(vbox_PVM pVM, RTRCPTR RCPtr);
 
 #ifndef IN_RING3
-VMMDECL(void *)     MMHyperR3ToCC(PVM pVM, RTR3PTR R3Ptr);
+VMMDECL(void *)     MMHyperR3ToCC(vbox_PVM pVM, RTR3PTR R3Ptr);
 #else
-DECLINLINE(void *)  MMHyperR3ToCC(PVM pVM, RTR3PTR R3Ptr)
+DECLINLINE(void *)  MMHyperR3ToCC(vbox_PVM pVM, RTR3PTR R3Ptr)
 {
     NOREF(pVM);
     return R3Ptr;
@@ -167,9 +167,9 @@ DECLINLINE(void *)  MMHyperR3ToCC(PVM pV
 
 
 #ifndef IN_RC
-VMMDECL(void *)     MMHyperRCToCC(PVM pVM, RTRCPTR RCPtr);
+VMMDECL(void *)     MMHyperRCToCC(vbox_PVM pVM, RTRCPTR RCPtr);
 #else
-DECLINLINE(void *)  MMHyperRCToCC(PVM pVM, RTRCPTR RCPtr)
+DECLINLINE(void *)  MMHyperRCToCC(vbox_PVM pVM, RTRCPTR RCPtr)
 {
     NOREF(pVM);
     return (void *)RCPtr;
@@ -177,9 +177,9 @@ DECLINLINE(void *)  MMHyperRCToCC(PVM pV
 #endif
 
 #ifndef IN_RING3
-VMMDECL(RTR3PTR)    MMHyperCCToR3(PVM pVM, void *pv);
+VMMDECL(RTR3PTR)    MMHyperCCToR3(vbox_PVM pVM, void *pv);
 #else
-DECLINLINE(RTR3PTR) MMHyperCCToR3(PVM pVM, void *pv)
+DECLINLINE(RTR3PTR) MMHyperCCToR3(vbox_PVM pVM, void *pv)
 {
     NOREF(pVM);
     return pv;
@@ -187,9 +187,9 @@ DECLINLINE(RTR3PTR) MMHyperCCToR3(PVM pV
 #endif
 
 #ifndef IN_RING0
-VMMDECL(RTR0PTR)    MMHyperCCToR0(PVM pVM, void *pv);
+VMMDECL(RTR0PTR)    MMHyperCCToR0(vbox_PVM pVM, void *pv);
 #else
-DECLINLINE(RTR0PTR) MMHyperCCToR0(PVM pVM, void *pv)
+DECLINLINE(RTR0PTR) MMHyperCCToR0(vbox_PVM pVM, void *pv)
 {
     NOREF(pVM);
     return pv;
@@ -197,9 +197,9 @@ DECLINLINE(RTR0PTR) MMHyperCCToR0(PVM pV
 #endif
 
 #ifndef IN_RC
-VMMDECL(RTRCPTR)    MMHyperCCToRC(PVM pVM, void *pv);
+VMMDECL(RTRCPTR)    MMHyperCCToRC(vbox_PVM pVM, void *pv);
 #else
-DECLINLINE(RTRCPTR) MMHyperCCToRC(PVM pVM, void *pv)
+DECLINLINE(RTRCPTR) MMHyperCCToRC(vbox_PVM pVM, void *pv)
 {
     NOREF(pVM);
     return (RTRCPTR)pv;
@@ -207,26 +207,26 @@ DECLINLINE(RTRCPTR) MMHyperCCToRC(PVM pV
 #endif
 
 
-VMMDECL(int)        MMHyperAlloc(PVM pVM, size_t cb, uint32_t uAlignment, MMTAG enmTag, void **ppv);
-VMMDECL(int)        MMHyperDupMem(PVM pVM, const void *pvSrc, size_t cb, unsigned uAlignment, MMTAG enmTag, void **ppv);
-VMMDECL(int)        MMHyperFree(PVM pVM, void *pv);
-VMMDECL(void)       MMHyperHeapCheck(PVM pVM);
-VMMDECL(int)        MMR3LockCall(PVM pVM);
+VMMDECL(int)        MMHyperAlloc(vbox_PVM pVM, size_t cb, uint32_t uAlignment, MMTAG enmTag, void **ppv);
+VMMDECL(int)        MMHyperDupMem(vbox_PVM pVM, const void *pvSrc, size_t cb, unsigned uAlignment, MMTAG enmTag, void **ppv);
+VMMDECL(int)        MMHyperFree(vbox_PVM pVM, void *pv);
+VMMDECL(void)       MMHyperHeapCheck(vbox_PVM pVM);
+VMMDECL(int)        MMR3LockCall(vbox_PVM pVM);
 #ifdef DEBUG
-VMMDECL(void)       MMHyperHeapDump(PVM pVM);
+VMMDECL(void)       MMHyperHeapDump(vbox_PVM pVM);
 #endif
-VMMDECL(size_t)     MMHyperHeapGetFreeSize(PVM pVM);
-VMMDECL(size_t)     MMHyperHeapGetSize(PVM pVM);
-VMMDECL(void *)     MMHyperHeapOffsetToPtr(PVM pVM, uint32_t offHeap);
-VMMDECL(uint32_t)   MMHyperHeapPtrToOffset(PVM pVM, void *pv);
-VMMDECL(RTGCPTR)    MMHyperGetArea(PVM pVM, size_t *pcb);
-VMMDECL(bool)       MMHyperIsInsideArea(PVM pVM, RTGCPTR GCPtr);
+VMMDECL(size_t)     MMHyperHeapGetFreeSize(vbox_PVM pVM);
+VMMDECL(size_t)     MMHyperHeapGetSize(vbox_PVM pVM);
+VMMDECL(void *)     MMHyperHeapOffsetToPtr(vbox_PVM pVM, uint32_t offHeap);
+VMMDECL(uint32_t)   MMHyperHeapPtrToOffset(vbox_PVM pVM, void *pv);
+VMMDECL(RTGCPTR)    MMHyperGetArea(vbox_PVM pVM, size_t *pcb);
+VMMDECL(bool)       MMHyperIsInsideArea(vbox_PVM pVM, RTGCPTR GCPtr);
 
 
-VMMDECL(RTHCPHYS)   MMPage2Phys(PVM pVM, void *pvPage);
-VMMDECL(void *)     MMPagePhys2Page(PVM pVM, RTHCPHYS HCPhysPage);
-VMMDECL(int)        MMPagePhys2PageEx(PVM pVM, RTHCPHYS HCPhysPage, void **ppvPage);
-VMMDECL(int)        MMPagePhys2PageTry(PVM pVM, RTHCPHYS HCPhysPage, void **ppvPage);
+VMMDECL(RTHCPHYS)   MMPage2Phys(vbox_PVM pVM, void *pvPage);
+VMMDECL(void *)     MMPagePhys2Page(vbox_PVM pVM, RTHCPHYS HCPhysPage);
+VMMDECL(int)        MMPagePhys2PageEx(vbox_PVM pVM, RTHCPHYS HCPhysPage, void **ppvPage);
+VMMDECL(int)        MMPagePhys2PageTry(vbox_PVM pVM, RTHCPHYS HCPhysPage, void **ppvPage);
 
 
 /** @def MMHYPER_RC_ASSERT_RCPTR
@@ -249,81 +249,81 @@ VMMDECL(int)        MMPagePhys2PageTry(P
  */
 
 VMMR3DECL(int)      MMR3InitUVM(PUVM pUVM);
-VMMR3DECL(int)      MMR3Init(PVM pVM);
-VMMR3DECL(int)      MMR3InitPaging(PVM pVM);
-VMMR3DECL(int)      MMR3HyperInitFinalize(PVM pVM);
-VMMR3DECL(int)      MMR3Term(PVM pVM);
+VMMR3DECL(int)      MMR3Init(vbox_PVM pVM);
+VMMR3DECL(int)      MMR3InitPaging(vbox_PVM pVM);
+VMMR3DECL(int)      MMR3HyperInitFinalize(vbox_PVM pVM);
+VMMR3DECL(int)      MMR3Term(vbox_PVM pVM);
 VMMR3DECL(void)     MMR3TermUVM(PUVM pUVM);
-VMMR3_INT_DECL(bool) MMR3IsInitialized(PVM pVM);
-VMMR3DECL(int)      MMR3ReserveHandyPages(PVM pVM, uint32_t cHandyPages);
-VMMR3DECL(int)      MMR3IncreaseBaseReservation(PVM pVM, uint64_t cAddBasePages);
-VMMR3DECL(int)      MMR3AdjustFixedReservation(PVM pVM, int32_t cDeltaFixedPages, const char *pszDesc);
-VMMR3DECL(int)      MMR3UpdateShadowReservation(PVM pVM, uint32_t cShadowPages);
+VMMR3_INT_DECL(bool) MMR3IsInitialized(vbox_PVM pVM);
+VMMR3DECL(int)      MMR3ReserveHandyPages(vbox_PVM pVM, uint32_t cHandyPages);
+VMMR3DECL(int)      MMR3IncreaseBaseReservation(vbox_PVM pVM, uint64_t cAddBasePages);
+VMMR3DECL(int)      MMR3AdjustFixedReservation(vbox_PVM pVM, int32_t cDeltaFixedPages, const char *pszDesc);
+VMMR3DECL(int)      MMR3UpdateShadowReservation(vbox_PVM pVM, uint32_t cShadowPages);
 
-VMMR3DECL(int)      MMR3HCPhys2HCVirt(PVM pVM, RTHCPHYS HCPhys, void **ppv);
+VMMR3DECL(int)      MMR3HCPhys2HCVirt(vbox_PVM pVM, RTHCPHYS HCPhys, void **ppv);
 
 /** @defgroup grp_mm_r3_hyper  Hypervisor Memory Manager (HC R3 Portion)
  * @{ */
-VMMR3DECL(int)      MMR3HyperAllocOnceNoRel(PVM pVM, size_t cb, uint32_t uAlignment, MMTAG enmTag, void **ppv);
-VMMR3DECL(int)      MMR3HyperAllocOnceNoRelEx(PVM pVM, size_t cb, uint32_t uAlignment, MMTAG enmTag, uint32_t fFlags, void **ppv);
-VMMR3DECL(int)      MMR3HyperRealloc(PVM pVM, void *pv, size_t cb, unsigned uAlignmentNew, MMTAG enmTagNew, size_t cbNew, void **ppv);
+VMMR3DECL(int)      MMR3HyperAllocOnceNoRel(vbox_PVM pVM, size_t cb, uint32_t uAlignment, MMTAG enmTag, void **ppv);
+VMMR3DECL(int)      MMR3HyperAllocOnceNoRelEx(vbox_PVM pVM, size_t cb, uint32_t uAlignment, MMTAG enmTag, uint32_t fFlags, void **ppv);
+VMMR3DECL(int)      MMR3HyperRealloc(vbox_PVM pVM, void *pv, size_t cb, unsigned uAlignmentNew, MMTAG enmTagNew, size_t cbNew, void **ppv);
 /** @name  MMR3HyperAllocOnceNoRelEx flags
  * @{ */
 /** Must have kernel mapping.
  * If not specified, the R0 pointer may point to the user process mapping. */
 #define MMHYPER_AONR_FLAGS_KERNEL_MAPPING   RT_BIT(0)
 /** @} */
-VMMR3DECL(int)      MMR3HyperSetGuard(PVM pVM, void *pvStart, size_t cb, bool fSet);
-VMMR3DECL(int)      MMR3HyperMapHCPhys(PVM pVM, void *pvR3, RTR0PTR pvR0, RTHCPHYS HCPhys, size_t cb, const char *pszDesc, PRTGCPTR pGCPtr);
-VMMR3DECL(int)      MMR3HyperMapGCPhys(PVM pVM, RTGCPHYS GCPhys, size_t cb, const char *pszDesc, PRTGCPTR pGCPtr);
-VMMR3DECL(int)      MMR3HyperMapMMIO2(PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS off, RTGCPHYS cb, const char *pszDesc, PRTRCPTR pRCPtr);
-VMMR3DECL(int)      MMR3HyperMapPages(PVM pVM, void *pvR3, RTR0PTR pvR0, size_t cPages, PCSUPPAGE paPages, const char *pszDesc, PRTGCPTR pGCPtr);
-VMMR3DECL(int)      MMR3HyperReserve(PVM pVM, unsigned cb, const char *pszDesc, PRTGCPTR pGCPtr);
-VMMR3DECL(RTHCPHYS) MMR3HyperHCVirt2HCPhys(PVM pVM, void *pvHC);
-VMMR3DECL(int)      MMR3HyperHCVirt2HCPhysEx(PVM pVM, void *pvHC, PRTHCPHYS pHCPhys);
-VMMR3DECL(void *)   MMR3HyperHCPhys2HCVirt(PVM pVM, RTHCPHYS HCPhys);
-VMMR3DECL(int)      MMR3HyperHCPhys2HCVirtEx(PVM pVM, RTHCPHYS HCPhys, void **ppv);
-VMMR3_INT_DECL(int) MMR3HyperQueryInfoFromHCPhys(PVM pVM, RTHCPHYS HCPhys, char *pszWhat, size_t cbWhat, uint32_t *pcbAlloc);
-VMMR3DECL(int)      MMR3HyperReadGCVirt(PVM pVM, void *pvDst, RTGCPTR GCPtr, size_t cb);
+VMMR3DECL(int)      MMR3HyperSetGuard(vbox_PVM pVM, void *pvStart, size_t cb, bool fSet);
+VMMR3DECL(int)      MMR3HyperMapHCPhys(vbox_PVM pVM, void *pvR3, RTR0PTR pvR0, RTHCPHYS HCPhys, size_t cb, const char *pszDesc, PRTGCPTR pGCPtr);
+VMMR3DECL(int)      MMR3HyperMapGCPhys(vbox_PVM pVM, RTGCPHYS GCPhys, size_t cb, const char *pszDesc, PRTGCPTR pGCPtr);
+VMMR3DECL(int)      MMR3HyperMapMMIO2(vbox_PVM pVM, PPDMDEVINS pDevIns, uint32_t iRegion, RTGCPHYS off, RTGCPHYS cb, const char *pszDesc, PRTRCPTR pRCPtr);
+VMMR3DECL(int)      MMR3HyperMapPages(vbox_PVM pVM, void *pvR3, RTR0PTR pvR0, size_t cPages, PCSUPPAGE paPages, const char *pszDesc, PRTGCPTR pGCPtr);
+VMMR3DECL(int)      MMR3HyperReserve(vbox_PVM pVM, unsigned cb, const char *pszDesc, PRTGCPTR pGCPtr);
+VMMR3DECL(RTHCPHYS) MMR3HyperHCVirt2HCPhys(vbox_PVM pVM, void *pvHC);
+VMMR3DECL(int)      MMR3HyperHCVirt2HCPhysEx(vbox_PVM pVM, void *pvHC, PRTHCPHYS pHCPhys);
+VMMR3DECL(void *)   MMR3HyperHCPhys2HCVirt(vbox_PVM pVM, RTHCPHYS HCPhys);
+VMMR3DECL(int)      MMR3HyperHCPhys2HCVirtEx(vbox_PVM pVM, RTHCPHYS HCPhys, void **ppv);
+VMMR3_INT_DECL(int) MMR3HyperQueryInfoFromHCPhys(vbox_PVM pVM, RTHCPHYS HCPhys, char *pszWhat, size_t cbWhat, uint32_t *pcbAlloc);
+VMMR3DECL(int)      MMR3HyperReadGCVirt(vbox_PVM pVM, void *pvDst, RTGCPTR GCPtr, size_t cb);
 /** @} */
 
 
 /** @defgroup grp_mm_phys   Guest Physical Memory Manager
  * @todo retire this group, elimintating or moving MMR3PhysGetRamSize to PGMPhys.
  * @{ */
-VMMR3DECL(uint64_t) MMR3PhysGetRamSize(PVM pVM);
+VMMR3DECL(uint64_t) MMR3PhysGetRamSize(vbox_PVM pVM);
 /** @} */
 
 
 /** @defgroup grp_mm_page   Physical Page Pool
  * @{ */
-VMMR3DECL(void *)   MMR3PageAlloc(PVM pVM);
-VMMR3DECL(RTHCPHYS) MMR3PageAllocPhys(PVM pVM);
-VMMR3DECL(void)     MMR3PageFree(PVM pVM, void *pvPage);
-VMMR3DECL(void *)   MMR3PageAllocLow(PVM pVM);
-VMMR3DECL(void)     MMR3PageFreeLow(PVM pVM, void *pvPage);
-VMMR3DECL(void)     MMR3PageFreeByPhys(PVM pVM, RTHCPHYS HCPhysPage);
-VMMR3DECL(void *)   MMR3PageDummyHCPtr(PVM pVM);
-VMMR3DECL(RTHCPHYS) MMR3PageDummyHCPhys(PVM pVM);
+VMMR3DECL(void *)   MMR3PageAlloc(vbox_PVM pVM);
+VMMR3DECL(RTHCPHYS) MMR3PageAllocPhys(vbox_PVM pVM);
+VMMR3DECL(void)     MMR3PageFree(vbox_PVM pVM, void *pvPage);
+VMMR3DECL(void *)   MMR3PageAllocLow(vbox_PVM pVM);
+VMMR3DECL(void)     MMR3PageFreeLow(vbox_PVM pVM, void *pvPage);
+VMMR3DECL(void)     MMR3PageFreeByPhys(vbox_PVM pVM, RTHCPHYS HCPhysPage);
+VMMR3DECL(void *)   MMR3PageDummyHCPtr(vbox_PVM pVM);
+VMMR3DECL(RTHCPHYS) MMR3PageDummyHCPhys(vbox_PVM pVM);
 /** @} */
 
 
 /** @defgroup grp_mm_heap   Heap Manager
  * @{ */
-VMMR3DECL(void *)   MMR3HeapAlloc(PVM pVM, MMTAG enmTag, size_t cbSize);
+VMMR3DECL(void *)   MMR3HeapAlloc(vbox_PVM pVM, MMTAG enmTag, size_t cbSize);
 VMMR3DECL(void *)   MMR3HeapAllocU(PUVM pUVM, MMTAG enmTag, size_t cbSize);
-VMMR3DECL(int)      MMR3HeapAllocEx(PVM pVM, MMTAG enmTag, size_t cbSize, void **ppv);
+VMMR3DECL(int)      MMR3HeapAllocEx(vbox_PVM pVM, MMTAG enmTag, size_t cbSize, void **ppv);
 VMMR3DECL(int)      MMR3HeapAllocExU(PUVM pUVM, MMTAG enmTag, size_t cbSize, void **ppv);
-VMMR3DECL(void *)   MMR3HeapAllocZ(PVM pVM, MMTAG enmTag, size_t cbSize);
+VMMR3DECL(void *)   MMR3HeapAllocZ(vbox_PVM pVM, MMTAG enmTag, size_t cbSize);
 VMMR3DECL(void *)   MMR3HeapAllocZU(PUVM pUVM, MMTAG enmTag, size_t cbSize);
-VMMR3DECL(int)      MMR3HeapAllocZEx(PVM pVM, MMTAG enmTag, size_t cbSize, void **ppv);
+VMMR3DECL(int)      MMR3HeapAllocZEx(vbox_PVM pVM, MMTAG enmTag, size_t cbSize, void **ppv);
 VMMR3DECL(int)      MMR3HeapAllocZExU(PUVM pUVM, MMTAG enmTag, size_t cbSize, void **ppv);
 VMMR3DECL(void *)   MMR3HeapRealloc(void *pv, size_t cbNewSize);
-VMMR3DECL(char *)   MMR3HeapStrDup(PVM pVM, MMTAG enmTag, const char *psz);
+VMMR3DECL(char *)   MMR3HeapStrDup(vbox_PVM pVM, MMTAG enmTag, const char *psz);
 VMMR3DECL(char *)   MMR3HeapStrDupU(PUVM pUVM, MMTAG enmTag, const char *psz);
-VMMR3DECL(char *)   MMR3HeapAPrintf(PVM pVM, MMTAG enmTag, const char *pszFormat, ...) RT_IPRT_FORMAT_ATTR(3, 4);
+VMMR3DECL(char *)   MMR3HeapAPrintf(vbox_PVM pVM, MMTAG enmTag, const char *pszFormat, ...) RT_IPRT_FORMAT_ATTR(3, 4);
 VMMR3DECL(char *)   MMR3HeapAPrintfU(PUVM pUVM, MMTAG enmTag, const char *pszFormat, ...) RT_IPRT_FORMAT_ATTR(3, 4);
-VMMR3DECL(char *)   MMR3HeapAPrintfV(PVM pVM, MMTAG enmTag, const char *pszFormat, va_list va) RT_IPRT_FORMAT_ATTR(3, 0);
+VMMR3DECL(char *)   MMR3HeapAPrintfV(vbox_PVM pVM, MMTAG enmTag, const char *pszFormat, va_list va) RT_IPRT_FORMAT_ATTR(3, 0);
 VMMR3DECL(char *)   MMR3HeapAPrintfVU(PUVM pUVM, MMTAG enmTag, const char *pszFormat, va_list va) RT_IPRT_FORMAT_ATTR(3, 0);
 VMMR3DECL(void)     MMR3HeapFree(void *pv);
 /** @} */
@@ -333,11 +333,11 @@ VMMR3DECL(void)     MMR3HeapFree(void *p
  * The memory is safely accessible from kernel context as well as user land.
  *
  * @{ */
-VMMR3DECL(void *)   MMR3UkHeapAlloc(PVM pVM, MMTAG enmTag, size_t cbSize, PRTR0PTR pR0Ptr);
-VMMR3DECL(int)      MMR3UkHeapAllocEx(PVM pVM, MMTAG enmTag, size_t cbSize, void **ppv, PRTR0PTR pR0Ptr);
-VMMR3DECL(void *)   MMR3UkHeapAllocZ(PVM pVM, MMTAG enmTag, size_t cbSize, PRTR0PTR pR0Ptr);
-VMMR3DECL(int)      MMR3UkHeapAllocZEx(PVM pVM, MMTAG enmTag, size_t cbSize, void **ppv, PRTR0PTR pR0Ptr);
-VMMR3DECL(void)     MMR3UkHeapFree(PVM pVM, void *pv, MMTAG enmTag);
+VMMR3DECL(void *)   MMR3UkHeapAlloc(vbox_PVM pVM, MMTAG enmTag, size_t cbSize, PRTR0PTR pR0Ptr);
+VMMR3DECL(int)      MMR3UkHeapAllocEx(vbox_PVM pVM, MMTAG enmTag, size_t cbSize, void **ppv, PRTR0PTR pR0Ptr);
+VMMR3DECL(void *)   MMR3UkHeapAllocZ(vbox_PVM pVM, MMTAG enmTag, size_t cbSize, PRTR0PTR pR0Ptr);
+VMMR3DECL(int)      MMR3UkHeapAllocZEx(vbox_PVM pVM, MMTAG enmTag, size_t cbSize, void **ppv, PRTR0PTR pR0Ptr);
+VMMR3DECL(void)     MMR3UkHeapFree(vbox_PVM pVM, void *pv, MMTAG enmTag);
 /** @} */
 
 /** @} */
@@ -350,15 +350,15 @@ VMMR3DECL(void)     MMR3UkHeapFree(PVM p
  * @{
  */
 
-VMMRCDECL(void)     MMGCRamRegisterTrapHandler(PVM pVM);
-VMMRCDECL(void)     MMGCRamDeregisterTrapHandler(PVM pVM);
+VMMRCDECL(void)     MMGCRamRegisterTrapHandler(vbox_PVM pVM);
+VMMRCDECL(void)     MMGCRamDeregisterTrapHandler(vbox_PVM pVM);
 VMMRCDECL(int)      MMGCRamReadNoTrapHandler(void *pDst, void *pSrc, size_t cb);
 /**
  * @deprecated Don't use this as it doesn't check the page state.
  */
 VMMRCDECL(int)      MMGCRamWriteNoTrapHandler(void *pDst, void *pSrc, size_t cb);
-VMMRCDECL(int)      MMGCRamRead(PVM pVM, void *pDst, void *pSrc, size_t cb);
-VMMRCDECL(int)      MMGCRamWrite(PVM pVM, void *pDst, void *pSrc, size_t cb);
+VMMRCDECL(int)      MMGCRamRead(vbox_PVM pVM, void *pDst, void *pSrc, size_t cb);
+VMMRCDECL(int)      MMGCRamWrite(vbox_PVM pVM, void *pDst, void *pSrc, size_t cb);
 
 /** @} */
 #endif /* IN_RC || DOXYGEN_RUNNING */
@@ -368,4 +368,3 @@ RT_C_DECLS_END
 
 
 #endif
-
