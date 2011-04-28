$NetBSD: patch-chrome_renderer_webplugin__delegate__pepper.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/webplugin_delegate_pepper.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/webplugin_delegate_pepper.cc
@@ -9,7 +9,7 @@
 #include <string>
 #include <vector>
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <unistd.h>
 #endif
 
@@ -39,7 +39,7 @@
 #include "chrome/renderer/pepper_widget.h"
 #include "chrome/renderer/render_thread.h"
 #include "chrome/renderer/render_view.h"
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/renderer/renderer_sandbox_support_linux.h"
 #endif
 #include "chrome/renderer/webplugin_delegate_proxy.h"
@@ -463,7 +463,7 @@ bool WebPluginDelegatePepper::SetCursor(
 NPError NPMatchFontWithFallback(NPP instance,
                                 const NPFontDescription* description,
                                 NPFontID* id) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int fd = renderer_sandbox_support::MatchFontWithFallback(
       description->face, description->weight >= 700, description->italic,
       description->charset);
@@ -482,7 +482,7 @@ NPError GetFontTable(NPP instance,
                      uint32_t table,
                      void* output,
                      size_t* output_length) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool rv = renderer_sandbox_support::GetFontTable(
       id, table, static_cast<uint8_t*>(output), output_length);
   return rv ? NPERR_NO_ERROR : NPERR_GENERIC_ERROR;
@@ -493,7 +493,7 @@ NPError GetFontTable(NPP instance,
 }
 
 NPError NPDestroyFont(NPP instance, NPFontID id) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   close(id);
   return NPERR_NO_ERROR;
 #else
@@ -1169,10 +1169,10 @@ int WebPluginDelegatePepper::PrintBegin(
       current_printer_dpi_ = printer_dpi;
     }
   }
-#if defined (OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   num_pages_ = num_pages;
   pdf_output_done_ = false;
-#endif  // (OS_LINUX)
+#endif  // OS_LINUX || OS_BSD
   return num_pages;
 }
 
@@ -1198,7 +1198,7 @@ bool WebPluginDelegatePepper::VectorPrin
   unsigned char* pdf_output = NULL;
   int32 output_size = 0;
   NPPrintPageNumberRange page_range;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux we will try and output all pages as PDF in the first call to
   // PrintPage. This is a temporary hack.
   // TODO(sanjeevr): Remove this hack and fix this by changing the print
@@ -1207,9 +1207,9 @@ bool WebPluginDelegatePepper::VectorPrin
     return pdf_output_done_;
   page_range.firstPageNumber = 0;
   page_range.lastPageNumber = num_pages_ - 1;
-#else  // defined(OS_LINUX)
+#else  // defined(OS_LINUX) || defined(OS_BSD)
   page_range.firstPageNumber = page_range.lastPageNumber = page_number;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   NPError err = print_extensions->printPagesAsPDF(instance()->npp(),
                                                   &page_range, 1,
                                                   &pdf_output, &output_size);
@@ -1217,7 +1217,7 @@ bool WebPluginDelegatePepper::VectorPrin
     return false;
 
   bool ret = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux we need to get the backing PdfPsMetafile and write the bits
   // directly.
   cairo_t* context = canvas->beginPlatformPaint();
@@ -1371,10 +1371,10 @@ void WebPluginDelegatePepper::PrintEnd()
   current_printer_dpi_ = -1;
 #if defined(OS_MACOSX)
   last_printed_page_ = SkBitmap();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   num_pages_ = 0;
   pdf_output_done_ = false;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 WebPluginDelegatePepper::WebPluginDelegatePepper(
@@ -1385,10 +1385,10 @@ WebPluginDelegatePepper::WebPluginDelega
       instance_(instance),
       nested_delegate_(NULL),
       current_printer_dpi_(-1),
-#if defined (OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       num_pages_(0),
       pdf_output_done_(false),
-#endif  // (OS_LINUX)
+#endif  // OS_LINUX || OS_BSD
 #if defined(ENABLE_GPU)
       command_buffer_(NULL),
       method_factory3d_(ALLOW_THIS_IN_INITIALIZER_LIST(this)),
