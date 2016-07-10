$NetBSD$

--- include/VBox/vmm/pdmpci.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/pdmpci.h
@@ -353,7 +353,7 @@ PCIRAWR0DECL(int)  PciRawR0Init(void);
 /**
  * Process request (in R0).
  */
-PCIRAWR0DECL(int)  PciRawR0ProcessReq(PSUPDRVSESSION pSession, PVM pVM, PPCIRAWSENDREQ pReq);
+PCIRAWR0DECL(int)  PciRawR0ProcessReq(PSUPDRVSESSION pSession, vbox_PVM pVM, PPCIRAWSENDREQ pReq);
 /**
  * Terminate R0 PCI module.
  */
@@ -362,12 +362,12 @@ PCIRAWR0DECL(void) PciRawR0Term(void);
 /**
  * Per-VM R0 module init.
  */
-PCIRAWR0DECL(int)  PciRawR0InitVM(PVM pVM);
+PCIRAWR0DECL(int)  PciRawR0InitVM(vbox_PVM pVM);
 
 /**
  * Per-VM R0 module termination routine.
  */
-PCIRAWR0DECL(void)  PciRawR0TermVM(PVM pVM);
+PCIRAWR0DECL(void)  PciRawR0TermVM(vbox_PVM pVM);
 
 /**
  * Flags returned by pfnPciDeviceConstructStart(), to notify device
