$NetBSD: patch-webkit_plugins_ppapi_ppapi__plugin__instance.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- webkit/plugins/ppapi/ppapi_plugin_instance.cc.orig	2011-05-24 08:01:04.000000000 +0000
+++ webkit/plugins/ppapi/ppapi_plugin_instance.cc
@@ -64,7 +64,7 @@
 #include "printing/native_metafile_factory.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "printing/pdf_ps_metafile_cairo.h"
 #endif
 
@@ -328,7 +328,7 @@ PluginInstance::PluginInstance(PluginDel
       plugin_pdf_interface_(NULL),
       plugin_selection_interface_(NULL),
       plugin_zoom_interface_(NULL),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       canvas_(NULL),
 #endif  // defined(OS_LINUX)
       plugin_print_interface_(NULL),
@@ -360,7 +360,7 @@ PluginInstance::~PluginInstance() {
   module_->InstanceDeleted(this);
 
   ResourceTracker::Get()->InstanceDeleted(pp_instance_);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ranges_.clear();
 #endif  // defined(OS_LINUX)
 }
@@ -930,7 +930,7 @@ int PluginInstance::PrintBegin(const gfx
   if (!num_pages)
     return 0;
   current_print_settings_ = print_settings;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   canvas_ = NULL;
   ranges_.clear();
 #endif  // defined(OS_LINUX)
@@ -941,7 +941,7 @@ bool PluginInstance::PrintPage(int page_
   DCHECK(plugin_print_interface_);
   PP_PrintPageNumberRange_Dev page_range;
   page_range.first_page_number = page_range.last_page_number = page_number;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ranges_.push_back(page_range);
   canvas_ = canvas;
   return true;
@@ -976,7 +976,7 @@ bool PluginInstance::PrintPageHelper(PP_
 void PluginInstance::PrintEnd() {
   // Keep a reference on the stack. See NOTE above.
   scoped_refptr<PluginInstance> ref(this);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // This hack is here because all pages need to be written to PDF at once.
   if (!ranges_.empty())
     PrintPageHelper(&(ranges_.front()), ranges_.size(), canvas_);
@@ -1079,7 +1079,7 @@ bool PluginInstance::PrintPDFOutput(PP_R
 #endif  // defined(OS_WIN)
 
   bool ret = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux we need to get the backing PdfPsMetafile and write the bits
   // directly.
   cairo_t* context = canvas->beginPlatformPaint();
