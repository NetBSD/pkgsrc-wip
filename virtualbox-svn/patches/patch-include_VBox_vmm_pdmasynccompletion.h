$NetBSD$

--- include/VBox/vmm/pdmasynccompletion.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/pdmasynccompletion.h
@@ -100,11 +100,11 @@ typedef FNPDMASYNCCOMPLETEUSB *PFNPDMASY
  * @param   pvUser2     User argument for the template.
  * @param   rc          The status code of the completed request.
  */
-typedef DECLCALLBACK(void) FNPDMASYNCCOMPLETEINT(PVM pVM, void *pvUser, void *pvUser2, int rc);
+typedef DECLCALLBACK(void) FNPDMASYNCCOMPLETEINT(vbox_PVM pVM, void *pvUser, void *pvUser2, int rc);
 /** Pointer to a FNPDMASYNCCOMPLETEINT(). */
 typedef FNPDMASYNCCOMPLETEINT *PFNPDMASYNCCOMPLETEINT;
 
-VMMR3DECL(int) PDMR3AsyncCompletionTemplateCreateInternal(PVM pVM, PPPDMASYNCCOMPLETIONTEMPLATE ppTemplate,
+VMMR3DECL(int) PDMR3AsyncCompletionTemplateCreateInternal(vbox_PVM pVM, PPPDMASYNCCOMPLETIONTEMPLATE ppTemplate,
                                                           PFNPDMASYNCCOMPLETEINT pfnCompleted, void *pvUser2, const char *pszDesc);
 VMMR3DECL(int) PDMR3AsyncCompletionTemplateDestroy(PPDMASYNCCOMPLETIONTEMPLATE pTemplate);
 VMMR3DECL(int) PDMR3AsyncCompletionEpCreateForFile(PPPDMASYNCCOMPLETIONENDPOINT ppEndpoint,
@@ -146,4 +146,3 @@ VMMR3DECL(int) PDMR3AsyncCompletionBwMgr
 RT_C_DECLS_END
 
 #endif
-
