$NetBSD: patch-webkit_plugins_ppapi_ppb__pdf__impl.cc,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- webkit/plugins/ppapi/ppb_pdf_impl.cc.orig	2011-04-13 08:01:07.000000000 +0000
+++ webkit/plugins/ppapi/ppb_pdf_impl.cc
@@ -25,7 +25,7 @@
 namespace webkit {
 namespace ppapi {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 class PrivateFontFile : public Resource {
  public:
   PrivateFontFile(PluginInstance* instance, int fd)
@@ -145,7 +145,7 @@ PP_Resource GetFontFileWithFallback(
     PP_Instance instance_id,
     const PP_FontDescription_Dev* description,
     PP_PrivateFontCharset charset) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   PluginInstance* instance = ResourceTracker::Get()->GetInstance(instance_id);
   if (!instance)
     return 0;
@@ -176,7 +176,7 @@ bool GetFontTableForPrivateFontFile(PP_R
                                     uint32_t table,
                                     void* output,
                                     uint32_t* output_length) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   scoped_refptr<PrivateFontFile> font(
       Resource::GetAs<PrivateFontFile>(font_file));
   if (!font.get())
@@ -301,7 +301,7 @@ const PPB_PDF* PPB_PDF_Impl::GetInterfac
   return &ppb_pdf;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool PrivateFontFile::GetFontTable(uint32_t table,
                                    void* output,
                                    uint32_t* output_length) {
