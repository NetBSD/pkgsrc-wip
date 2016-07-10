$NetBSD$

--- include/VBox/vmm/stam.h.orig	2016-03-04 19:22:59.000000000 +0000
+++ include/VBox/vmm/stam.h
@@ -1106,7 +1106,7 @@ VMMR3DECL(int)  STAMR3InitUVM(PUVM pUVM)
 VMMR3DECL(void) STAMR3TermUVM(PUVM pUVM);
 VMMR3DECL(int)  STAMR3RegisterU(PUVM pUVM, void *pvSample, STAMTYPE enmType, STAMVISIBILITY enmVisibility,
                                 const char *pszName, STAMUNIT enmUnit, const char *pszDesc);
-VMMR3DECL(int)  STAMR3Register(PVM pVM, void *pvSample, STAMTYPE enmType, STAMVISIBILITY enmVisibility,
+VMMR3DECL(int)  STAMR3Register(vbox_PVM pVM, void *pvSample, STAMTYPE enmType, STAMVISIBILITY enmVisibility,
                                const char *pszName, STAMUNIT enmUnit, const char *pszDesc);
 
 /** @def STAM_REL_REG
@@ -1167,11 +1167,11 @@ VMMR3DECL(int)  STAMR3Register(PVM pVM, 
 
 VMMR3DECL(int)  STAMR3RegisterFU(PUVM pUVM, void *pvSample, STAMTYPE enmType, STAMVISIBILITY enmVisibility, STAMUNIT enmUnit,
                                  const char *pszDesc, const char *pszName, ...) RT_IPRT_FORMAT_ATTR(7, 8);
-VMMR3DECL(int)  STAMR3RegisterF(PVM pVM, void *pvSample, STAMTYPE enmType, STAMVISIBILITY enmVisibility, STAMUNIT enmUnit,
+VMMR3DECL(int)  STAMR3RegisterF(vbox_PVM pVM, void *pvSample, STAMTYPE enmType, STAMVISIBILITY enmVisibility, STAMUNIT enmUnit,
                                 const char *pszDesc, const char *pszName, ...) RT_IPRT_FORMAT_ATTR(7, 8);
 VMMR3DECL(int)  STAMR3RegisterVU(PUVM pUVM, void *pvSample, STAMTYPE enmType, STAMVISIBILITY enmVisibility, STAMUNIT enmUnit,
                                  const char *pszDesc, const char *pszName, va_list args) RT_IPRT_FORMAT_ATTR(7, 0);
-VMMR3DECL(int)  STAMR3RegisterV(PVM pVM, void *pvSample, STAMTYPE enmType, STAMVISIBILITY enmVisibility, STAMUNIT enmUnit,
+VMMR3DECL(int)  STAMR3RegisterV(vbox_PVM pVM, void *pvSample, STAMTYPE enmType, STAMVISIBILITY enmVisibility, STAMUNIT enmUnit,
                                 const char *pszDesc, const char *pszName, va_list args) RT_IPRT_FORMAT_ATTR(7, 0);
 
 /**
@@ -1179,7 +1179,7 @@ VMMR3DECL(int)  STAMR3RegisterV(PVM pVM,
  * @param   pVM         The cross context VM structure.
  * @param   pvSample    The sample registered using STAMR3RegisterCallback.
  */
-typedef void FNSTAMR3CALLBACKRESET(PVM pVM, void *pvSample);
+typedef void FNSTAMR3CALLBACKRESET(vbox_PVM pVM, void *pvSample);
 /** Pointer to a STAM sample reset callback. */
 typedef FNSTAMR3CALLBACKRESET *PFNSTAMR3CALLBACKRESET;
 
@@ -1191,14 +1191,14 @@ typedef FNSTAMR3CALLBACKRESET *PFNSTAMR3
  * @param   pszBuf      The buffer to print into.
  * @param   cchBuf      The size of the buffer.
  */
-typedef void FNSTAMR3CALLBACKPRINT(PVM pVM, void *pvSample, char *pszBuf, size_t cchBuf);
+typedef void FNSTAMR3CALLBACKPRINT(vbox_PVM pVM, void *pvSample, char *pszBuf, size_t cchBuf);
 /** Pointer to a STAM sample print callback. */
 typedef FNSTAMR3CALLBACKPRINT *PFNSTAMR3CALLBACKPRINT;
 
-VMMR3DECL(int)  STAMR3RegisterCallback(PVM pVM, void *pvSample, STAMVISIBILITY enmVisibility, STAMUNIT enmUnit,
+VMMR3DECL(int)  STAMR3RegisterCallback(vbox_PVM pVM, void *pvSample, STAMVISIBILITY enmVisibility, STAMUNIT enmUnit,
                                        PFNSTAMR3CALLBACKRESET pfnReset, PFNSTAMR3CALLBACKPRINT pfnPrint,
                                        const char *pszDesc, const char *pszName, ...) RT_IPRT_FORMAT_ATTR(8, 9);
-VMMR3DECL(int)  STAMR3RegisterCallbackV(PVM pVM, void *pvSample, STAMVISIBILITY enmVisibility, STAMUNIT enmUnit,
+VMMR3DECL(int)  STAMR3RegisterCallbackV(vbox_PVM pVM, void *pvSample, STAMVISIBILITY enmVisibility, STAMUNIT enmUnit,
                                         PFNSTAMR3CALLBACKRESET pfnReset, PFNSTAMR3CALLBACKPRINT pfnPrint,
                                         const char *pszDesc, const char *pszName, va_list args) RT_IPRT_FORMAT_ATTR(8, 0);
 VMMR3DECL(int)  STAMR3Deregister(PUVM pUVM, const char *pszPat);
@@ -1241,4 +1241,3 @@ VMMR3DECL(const char *) STAMR3GetUnit(ST
 RT_C_DECLS_END
 
 #endif
-
