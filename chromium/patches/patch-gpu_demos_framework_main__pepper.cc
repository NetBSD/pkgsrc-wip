$NetBSD: patch-gpu_demos_framework_main__pepper.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- gpu/demos/framework/main_pepper.cc.orig	2011-04-13 08:01:09.000000000 +0000
+++ gpu/demos/framework/main_pepper.cc
@@ -97,7 +97,7 @@ NPError NPP_GetValue(NPP instance, NPPVa
   NPError err = NPERR_NO_ERROR;
 
   switch (variable) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case NPPVpluginNameString:
       *(static_cast<const char**>(value)) = "Pepper GPU Demo";
       break;
@@ -153,14 +153,14 @@ EXPORT NPError API_CALL NP_GetEntryPoint
 }
 
 EXPORT NPError API_CALL NP_Initialize(NPNetscapeFuncs* browser_funcs
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                      , NPPluginFuncs* plugin_funcs
 #endif  // OS_LINUX
                                      ) {
   gpu::demos::g_browser = browser_funcs;
   pglInitialize();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   NP_GetEntryPoints(plugin_funcs);
 #endif  // OS_LINUX
   return NPERR_NO_ERROR;
@@ -170,7 +170,7 @@ EXPORT void API_CALL NP_Shutdown() {
   pglTerminate();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 EXPORT NPError API_CALL NP_GetValue(NPP instance, NPPVariable variable,
                                     void* value) {
   return gpu::demos::NPP_GetValue(instance, variable, value);
