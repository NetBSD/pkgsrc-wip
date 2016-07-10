$NetBSD$

--- include/VBox/rawpci.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/rawpci.h
@@ -532,7 +532,7 @@ typedef struct RAWPCIFACTORY
      * @param   pPciData    Pointer to PCI data.
      */
     DECLR0CALLBACKMEMBER(int, pfnInitVm,(PRAWPCIFACTORY       pFactory,
-                                         PVM                  pVM,
+                                         vbox_PVM                  pVM,
                                          PRAWPCIPERVM         pPciData));
 
     /**
@@ -545,7 +545,7 @@ typedef struct RAWPCIFACTORY
      * @param   pPciData    Pointer to PCI data.
      */
     DECLR0CALLBACKMEMBER(void, pfnDeinitVm,(PRAWPCIFACTORY       pFactory,
-                                            PVM                  pVM,
+                                            vbox_PVM                  pVM,
                                             PRAWPCIPERVM         pPciData));
 } RAWPCIFACTORY;
 
