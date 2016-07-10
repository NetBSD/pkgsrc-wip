$NetBSD$

--- include/VBox/vmm/pdmthread.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/pdmthread.h
@@ -123,7 +123,7 @@ typedef FNPDMTHREADDRV *PFNPDMTHREADDRV;
  * @param   pVM         The cross context VM structure.
  * @param   pThread     The PDM thread data.
  */
-typedef DECLCALLBACK(int) FNPDMTHREADINT(PVM pVM, PPDMTHREAD pThread);
+typedef DECLCALLBACK(int) FNPDMTHREADINT(vbox_PVM pVM, PPDMTHREAD pThread);
 /** Pointer to a FNPDMTHREADINT(). */
 typedef FNPDMTHREADINT *PFNPDMTHREADINT;
 
@@ -179,7 +179,7 @@ typedef FNPDMTHREADWAKEUPDRV *PFNPDMTHRE
  * @param   pVM         The cross context VM structure.
  * @param   pThread     The PDM thread data.
  */
-typedef DECLCALLBACK(int) FNPDMTHREADWAKEUPINT(PVM pVM, PPDMTHREAD pThread);
+typedef DECLCALLBACK(int) FNPDMTHREADWAKEUPINT(vbox_PVM pVM, PPDMTHREAD pThread);
 /** Pointer to a FNPDMTHREADWAKEUPINT(). */
 typedef FNPDMTHREADWAKEUPINT *PFNPDMTHREADWAKEUPINT;
 
@@ -279,9 +279,9 @@ typedef struct PDMTHREAD
 #define PDMTHREAD_VERSION                       PDM_VERSION_MAKE(0xefff, 1, 0)
 
 #ifdef IN_RING3
-VMMR3DECL(int) PDMR3ThreadCreate(PVM pVM, PPPDMTHREAD ppThread, void *pvUser, PFNPDMTHREADINT pfnThread,
+VMMR3DECL(int) PDMR3ThreadCreate(vbox_PVM pVM, PPPDMTHREAD ppThread, void *pvUser, PFNPDMTHREADINT pfnThread,
                                  PFNPDMTHREADWAKEUPINT pfnWakeUp, size_t cbStack, RTTHREADTYPE enmType, const char *pszName);
-VMMR3DECL(int) PDMR3ThreadCreateExternal(PVM pVM, PPPDMTHREAD ppThread, void *pvUser, PFNPDMTHREADEXT pfnThread,
+VMMR3DECL(int) PDMR3ThreadCreateExternal(vbox_PVM pVM, PPPDMTHREAD ppThread, void *pvUser, PFNPDMTHREADEXT pfnThread,
                                          PFNPDMTHREADWAKEUPEXT pfnWakeUp, size_t cbStack, RTTHREADTYPE enmType, const char *pszName);
 VMMR3DECL(int) PDMR3ThreadDestroy(PPDMTHREAD pThread, int *pRcThread);
 VMMR3DECL(int) PDMR3ThreadIAmSuspending(PPDMTHREAD pThread);
