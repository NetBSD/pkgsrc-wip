$NetBSD: patch-webkit_plugins_ppapi_ppapi__plugin__instance.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- webkit/plugins/ppapi/ppapi_plugin_instance.h.orig	2011-04-13 08:01:07.000000000 +0000
+++ webkit/plugins/ppapi/ppapi_plugin_instance.h
@@ -297,7 +297,7 @@ class PluginInstance : public base::RefC
   // to keep the pixels valid until CGContextEndPage is called. We use this
   // variable to hold on to the pixels.
   scoped_refptr<PPB_ImageData_Impl> last_printed_page_;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, all pages need to be written to a PDF file in one shot. However,
   // when users print only a subset of all the pages, it is impossible to know
   // if a call to PrintPage() is the last call. Thus in PrintPage(), just store
