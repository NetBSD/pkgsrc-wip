$NetBSD$

--- include/VBox/vmm/pdmqueue.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/pdmqueue.h
@@ -111,7 +111,7 @@ typedef FNPDMQUEUEDRV *PFNPDMQUEUEDRV;
  * @remarks No locks will be held, but for now it's safe to assume that only one
  *          EMT will do queue callbacks at any one time.
  */
-typedef DECLCALLBACK(bool) FNPDMQUEUEINT(PVM pVM, PPDMQUEUEITEMCORE pItem);
+typedef DECLCALLBACK(bool) FNPDMQUEUEINT(vbox_PVM pVM, PPDMQUEUEITEMCORE pItem);
 /** Pointer to a FNPDMQUEUEINT(). */
 typedef FNPDMQUEUEINT *PFNPDMQUEUEINT;
 
@@ -130,18 +130,18 @@ typedef DECLCALLBACK(bool) FNPDMQUEUEEXT
 typedef FNPDMQUEUEEXT *PFNPDMQUEUEEXT;
 
 #ifdef VBOX_IN_VMM
-VMMR3_INT_DECL(int)  PDMR3QueueCreateDevice(PVM pVM, PPDMDEVINS pDevIns, size_t cbItem, uint32_t cItems, uint32_t cMilliesInterval,
+VMMR3_INT_DECL(int)  PDMR3QueueCreateDevice(vbox_PVM pVM, PPDMDEVINS pDevIns, size_t cbItem, uint32_t cItems, uint32_t cMilliesInterval,
                                             PFNPDMQUEUEDEV pfnCallback, bool fRZEnabled, const char *pszName, PPDMQUEUE *ppQueue);
-VMMR3_INT_DECL(int)  PDMR3QueueCreateDriver(PVM pVM, PPDMDRVINS pDrvIns, size_t cbItem, uint32_t cItems, uint32_t cMilliesInterval,
+VMMR3_INT_DECL(int)  PDMR3QueueCreateDriver(vbox_PVM pVM, PPDMDRVINS pDrvIns, size_t cbItem, uint32_t cItems, uint32_t cMilliesInterval,
                                             PFNPDMQUEUEDRV pfnCallback, const char *pszName, PPDMQUEUE *ppQueue);
-VMMR3_INT_DECL(int)  PDMR3QueueCreateInternal(PVM pVM, size_t cbItem, uint32_t cItems, uint32_t cMilliesInterval,
+VMMR3_INT_DECL(int)  PDMR3QueueCreateInternal(vbox_PVM pVM, size_t cbItem, uint32_t cItems, uint32_t cMilliesInterval,
                                               PFNPDMQUEUEINT pfnCallback, bool fGCEnabled, const char *pszName, PPDMQUEUE *ppQueue);
-VMMR3_INT_DECL(int)  PDMR3QueueCreateExternal(PVM pVM, size_t cbItem, uint32_t cItems, uint32_t cMilliesInterval,
+VMMR3_INT_DECL(int)  PDMR3QueueCreateExternal(vbox_PVM pVM, size_t cbItem, uint32_t cItems, uint32_t cMilliesInterval,
                                               PFNPDMQUEUEEXT pfnCallback, void *pvUser, const char *pszName, PPDMQUEUE *ppQueue);
 VMMR3_INT_DECL(int)  PDMR3QueueDestroy(PPDMQUEUE pQueue);
-VMMR3_INT_DECL(int)  PDMR3QueueDestroyDevice(PVM pVM, PPDMDEVINS pDevIns);
-VMMR3_INT_DECL(int)  PDMR3QueueDestroyDriver(PVM pVM, PPDMDRVINS pDrvIns);
-VMMR3_INT_DECL(void) PDMR3QueueFlushAll(PVM pVM);
+VMMR3_INT_DECL(int)  PDMR3QueueDestroyDevice(vbox_PVM pVM, PPDMDEVINS pDevIns);
+VMMR3_INT_DECL(int)  PDMR3QueueDestroyDriver(vbox_PVM pVM, PPDMDRVINS pDrvIns);
+VMMR3_INT_DECL(void) PDMR3QueueFlushAll(vbox_PVM pVM);
 #endif /* VBOX_IN_VMM */
 
 VMMDECL(PPDMQUEUEITEMCORE)    PDMQueueAlloc(PPDMQUEUE pQueue);
@@ -156,4 +156,3 @@ VMMDECL(bool)                 PDMQueueFl
 RT_C_DECLS_END
 
 #endif
-
