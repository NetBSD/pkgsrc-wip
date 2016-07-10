$NetBSD$

--- include/VBox/vmm/pdmdev.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/pdmdev.h
@@ -3524,7 +3524,7 @@ typedef struct PDMDEVHLPR3
      * @returns VM Handle.
      * @param   pDevIns             The device instance.
      */
-    DECLR3CALLBACKMEMBER(PVM, pfnGetVM,(PPDMDEVINS pDevIns));
+    DECLR3CALLBACKMEMBER(vbox_PVM, pfnGetVM,(PPDMDEVINS pDevIns));
 
     /**
      * Gets the VMCPU handle. Restricted API.
@@ -3847,7 +3847,7 @@ typedef struct PDMDEVHLPRC
      * @returns VM Handle.
      * @param   pDevIns         Device instance.
      */
-    DECLRCCALLBACKMEMBER(PVM, pfnGetVM,(PPDMDEVINS pDevIns));
+    DECLRCCALLBACKMEMBER(vbox_PVM, pfnGetVM,(PPDMDEVINS pDevIns));
 
     /**
      * Gets the VMCPU handle. Restricted API.
@@ -4076,7 +4076,7 @@ typedef struct PDMDEVHLPR0
      * @returns VM Handle.
      * @param   pDevIns         Device instance.
      */
-    DECLR0CALLBACKMEMBER(PVM, pfnGetVM,(PPDMDEVINS pDevIns));
+    DECLR0CALLBACKMEMBER(vbox_PVM, pfnGetVM,(PPDMDEVINS pDevIns));
 
     /**
      * Checks if our current CPU state allows for IO block emulation fallback to the recompiler
@@ -5218,7 +5218,7 @@ DECLINLINE(PUVM) PDMDevHlpGetUVM(PPDMDEV
 /**
  * @copydoc PDMDEVHLPR3::pfnGetVM
  */
-DECLINLINE(PVM) PDMDevHlpGetVM(PPDMDEVINS pDevIns)
+DECLINLINE(vbox_PVM) PDMDevHlpGetVM(PPDMDEVINS pDevIns)
 {
     return pDevIns->CTX_SUFF(pHlp)->pfnGetVM(pDevIns);
 }
