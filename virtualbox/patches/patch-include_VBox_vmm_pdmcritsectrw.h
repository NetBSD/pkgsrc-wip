$NetBSD$

--- include/VBox/vmm/pdmcritsectrw.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/pdmcritsectrw.h
@@ -50,7 +50,7 @@ typedef union PDMCRITSECTRW
 #endif
 } PDMCRITSECTRW;
 
-VMMR3DECL(int)      PDMR3CritSectRwInit(PVM pVM, PPDMCRITSECTRW pCritSect, RT_SRC_POS_DECL,
+VMMR3DECL(int)      PDMR3CritSectRwInit(vbox_PVM pVM, PPDMCRITSECTRW pCritSect, RT_SRC_POS_DECL,
                                         const char *pszNameFmt, ...) RT_IPRT_FORMAT_ATTR(6, 7);
 VMMR3DECL(int)      PDMR3CritSectRwDelete(PPDMCRITSECTRW pCritSect);
 VMMR3DECL(const char *) PDMR3CritSectRwName(PCPDMCRITSECTRW pCritSect);
@@ -95,4 +95,3 @@ VMMDECL(bool)       PDMCritSectRwIsIniti
 RT_C_DECLS_END
 
 #endif
-
