$NetBSD$

--- include/VBox/vmm/cfgm.h.orig	2016-03-04 19:22:58.000000000 +0000
+++ include/VBox/vmm/cfgm.h
@@ -78,13 +78,13 @@ typedef enum CFGMCONFIGTYPE
  * @param   pVM         The cross context VM structure.
  * @param   pvUser      The argument supplied to VMR3Create().
  */
-typedef DECLCALLBACK(int) FNCFGMCONSTRUCTOR(PUVM pUVM, PVM pVM, void *pvUser);
+typedef DECLCALLBACK(int) FNCFGMCONSTRUCTOR(PUVM pUVM, vbox_PVM pVM, void *pvUser);
 /** Pointer to a FNCFGMCONSTRUCTOR(). */
 typedef FNCFGMCONSTRUCTOR *PFNCFGMCONSTRUCTOR;
 
-VMMR3DECL(int)          CFGMR3Init(PVM pVM, PFNCFGMCONSTRUCTOR pfnCFGMConstructor, void *pvUser);
-VMMR3DECL(int)          CFGMR3Term(PVM pVM);
-VMMR3DECL(int)          CFGMR3ConstructDefaultTree(PVM pVM);
+VMMR3DECL(int)          CFGMR3Init(vbox_PVM pVM, PFNCFGMCONSTRUCTOR pfnCFGMConstructor, void *pvUser);
+VMMR3DECL(int)          CFGMR3Term(vbox_PVM pVM);
+VMMR3DECL(int)          CFGMR3ConstructDefaultTree(vbox_PVM pVM);
 
 VMMR3DECL(PCFGMNODE)    CFGMR3CreateTree(PUVM pUVM);
 VMMR3DECL(int)          CFGMR3DestroyTree(PCFGMNODE pRoot);
@@ -190,10 +190,10 @@ VMMR3DECL(int)          CFGMR3QueryStrin
 /** @name Tree Navigation and Enumeration.
  * @{
  */
-VMMR3DECL(PCFGMNODE)    CFGMR3GetRoot(PVM pVM);
+VMMR3DECL(PCFGMNODE)    CFGMR3GetRoot(vbox_PVM pVM);
 VMMR3DECL(PCFGMNODE)    CFGMR3GetRootU(PUVM pUVM);
 VMMR3DECL(PCFGMNODE)    CFGMR3GetParent(PCFGMNODE pNode);
-VMMR3DECL(PCFGMNODE)    CFGMR3GetParentEx(PVM pVM, PCFGMNODE pNode);
+VMMR3DECL(PCFGMNODE)    CFGMR3GetParentEx(vbox_PVM pVM, PCFGMNODE pNode);
 VMMR3DECL(PCFGMNODE)    CFGMR3GetChild(PCFGMNODE pNode, const char *pszPath);
 VMMR3DECL(PCFGMNODE)    CFGMR3GetChildF(PCFGMNODE pNode, const char *pszPathFormat, ...) RT_IPRT_FORMAT_ATTR(2, 3);
 VMMR3DECL(PCFGMNODE)    CFGMR3GetChildFV(PCFGMNODE pNode, const char *pszPathFormat, va_list Args) RT_IPRT_FORMAT_ATTR(3, 0);
@@ -224,4 +224,3 @@ RT_C_DECLS_END
 /** @} */
 
 #endif
-
