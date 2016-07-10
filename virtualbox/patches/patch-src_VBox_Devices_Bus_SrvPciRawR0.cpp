$NetBSD$

--- src/VBox/Devices/Bus/SrvPciRawR0.cpp.orig	2016-03-04 19:25:48.000000000 +0000
+++ src/VBox/Devices/Bus/SrvPciRawR0.cpp
@@ -169,7 +169,7 @@ PCIRAWR0DECL(void) PciRawR0Term(void)
 /**
  * Per-VM R0 module init.
  */
-PCIRAWR0DECL(int)  PciRawR0InitVM(PVM pVM)
+PCIRAWR0DECL(int)  PciRawR0InitVM(vbox_PVM pVM)
 {
     PRAWPCIFACTORY pFactory = NULL;
     int            rc;
@@ -194,7 +194,7 @@ PCIRAWR0DECL(int)  PciRawR0InitVM(PVM pV
 /**
  * Per-VM R0 module termination routine.
  */
-PCIRAWR0DECL(void)  PciRawR0TermVM(PVM pVM)
+PCIRAWR0DECL(void)  PciRawR0TermVM(vbox_PVM pVM)
 {
     PRAWPCIFACTORY pFactory = NULL;
     int            rc;
@@ -518,7 +518,7 @@ static DECLCALLBACK(void) pcirawr0DevObj
 
 
 static int pcirawr0OpenDevice(PSUPDRVSESSION   pSession,
-                              PVM              pVM,
+                              vbox_PVM              pVM,
                               uint32_t         HostDevice,
                               uint32_t         fFlags,
                               PCIRAWDEVHANDLE *pHandle,
@@ -925,7 +925,7 @@ static int pcirawr0PowerStateChange(PSUP
  *
  * @returns VBox status code.
  */
-PCIRAWR0DECL(int) PciRawR0ProcessReq(PSUPDRVSESSION pSession, PVM pVM, PPCIRAWSENDREQ pReq)
+PCIRAWR0DECL(int) PciRawR0ProcessReq(PSUPDRVSESSION pSession, vbox_PVM pVM, PPCIRAWSENDREQ pReq)
 {
     LogFlow(("PciRawR0ProcessReq: %d for %x\n", pReq->iRequest, pReq->TargetDevice));
     int rc = VINF_SUCCESS;
