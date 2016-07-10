$NetBSD$

--- include/VBox/vmm/pdmblkcache.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/pdmblkcache.h
@@ -230,7 +230,7 @@ typedef FNPDMBLKCACHEXFERENQUEUEDISCARDU
  * @param   pfnXferEnqueueDiscard    The discard request enqueue callback.
  * @param   pcszId                   Unique ID used to identify the user.
  */
-VMMR3DECL(int) PDMR3BlkCacheRetainDriver(PVM pVM, PPDMDRVINS pDrvIns, PPPDMBLKCACHE ppBlkCache,
+VMMR3DECL(int) PDMR3BlkCacheRetainDriver(vbox_PVM pVM, PPDMDRVINS pDrvIns, PPPDMBLKCACHE ppBlkCache,
                                          PFNPDMBLKCACHEXFERCOMPLETEDRV pfnXferComplete,
                                          PFNPDMBLKCACHEXFERENQUEUEDRV pfnXferEnqueue,
                                          PFNPDMBLKCACHEXFERENQUEUEDISCARDDRV pfnXferEnqueueDiscard,
@@ -248,7 +248,7 @@ VMMR3DECL(int) PDMR3BlkCacheRetainDriver
  * @param   pfnXferEnqueueDiscard    The discard request enqueue callback.
  * @param   pcszId                   Unique ID used to identify the user.
  */
-VMMR3DECL(int) PDMR3BlkCacheRetainDevice(PVM pVM, PPDMDEVINS pDevIns, PPPDMBLKCACHE ppBlkCache,
+VMMR3DECL(int) PDMR3BlkCacheRetainDevice(vbox_PVM pVM, PPDMDEVINS pDevIns, PPPDMBLKCACHE ppBlkCache,
                                          PFNPDMBLKCACHEXFERCOMPLETEDEV pfnXferComplete,
                                          PFNPDMBLKCACHEXFERENQUEUEDEV pfnXferEnqueue,
                                          PFNPDMBLKCACHEXFERENQUEUEDISCARDDEV pfnXferEnqueueDiscard,
@@ -266,7 +266,7 @@ VMMR3DECL(int) PDMR3BlkCacheRetainDevice
  * @param   pfnXferEnqueueDiscard    The discard request enqueue callback.
  * @param   pcszId                   Unique ID used to identify the user.
  */
-VMMR3DECL(int) PDMR3BlkCacheRetainUsb(PVM pVM, PPDMUSBINS pUsbIns, PPPDMBLKCACHE ppBlkCache,
+VMMR3DECL(int) PDMR3BlkCacheRetainUsb(vbox_PVM pVM, PPDMUSBINS pUsbIns, PPPDMBLKCACHE ppBlkCache,
                                       PFNPDMBLKCACHEXFERCOMPLETEUSB pfnXferComplete,
                                       PFNPDMBLKCACHEXFERENQUEUEUSB pfnXferEnqueue,
                                       PFNPDMBLKCACHEXFERENQUEUEDISCARDUSB pfnXferEnqueueDiscard,
@@ -284,7 +284,7 @@ VMMR3DECL(int) PDMR3BlkCacheRetainUsb(PV
  * @param   pfnXferEnqueueDiscard    The discard request enqueue callback.
  * @param   pcszId                   Unique ID used to identify the user.
  */
-VMMR3DECL(int) PDMR3BlkCacheRetainInt(PVM pVM, void *pvUser, PPPDMBLKCACHE ppBlkCache,
+VMMR3DECL(int) PDMR3BlkCacheRetainInt(vbox_PVM pVM, void *pvUser, PPPDMBLKCACHE ppBlkCache,
                                       PFNPDMBLKCACHEXFERCOMPLETEINT pfnXferComplete,
                                       PFNPDMBLKCACHEXFERENQUEUEINT pfnXferEnqueue,
                                       PFNPDMBLKCACHEXFERENQUEUEDISCARDINT pfnXferEnqueueDiscard,
@@ -305,7 +305,7 @@ VMMR3DECL(void) PDMR3BlkCacheRelease(PPD
  * @param   pVM             The cross context VM structure.
  * @param   pDevIns         The device instance.
  */
-VMMR3DECL(void) PDMR3BlkCacheReleaseDevice(PVM pVM, PPDMDEVINS pDevIns);
+VMMR3DECL(void) PDMR3BlkCacheReleaseDevice(vbox_PVM pVM, PPDMDEVINS pDevIns);
 
 /**
  * Releases all block cache handles for a driver instance.
@@ -314,7 +314,7 @@ VMMR3DECL(void) PDMR3BlkCacheReleaseDevi
  * @param   pVM             The cross context VM structure.
  * @param   pDrvIns         The driver instance.
  */
-VMMR3DECL(void) PDMR3BlkCacheReleaseDriver(PVM pVM, PPDMDRVINS pDrvIns);
+VMMR3DECL(void) PDMR3BlkCacheReleaseDriver(vbox_PVM pVM, PPDMDRVINS pDrvIns);
 
 /**
  * Releases all block cache handles for a USB device instance.
@@ -323,7 +323,7 @@ VMMR3DECL(void) PDMR3BlkCacheReleaseDriv
  * @param   pVM             The cross context VM structure.
  * @param   pUsbIns         The USB device instance.
  */
-VMMR3DECL(void) PDMR3BlkCacheReleaseUsb(PVM pVM, PPDMUSBINS pUsbIns);
+VMMR3DECL(void) PDMR3BlkCacheReleaseUsb(vbox_PVM pVM, PPDMUSBINS pUsbIns);
 
 /**
  * Creates a read task on the given endpoint.
@@ -418,4 +418,3 @@ VMMR3DECL(int) PDMR3BlkCacheClear(PPDMBL
 RT_C_DECLS_END
 
 #endif
-
