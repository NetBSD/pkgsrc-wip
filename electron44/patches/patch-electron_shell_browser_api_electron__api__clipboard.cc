$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/browser/api/electron_api_clipboard.cc.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/shell/browser/api/electron_api_clipboard.cc
@@ -108,7 +108,7 @@ void EnumerateAvailableTypes(ui::Clipboa
   // clipboard) to discover them before finalizing.
   TypesCallback add_bookmark = base::BindOnce(
       [](TypesCallback finalize, std::vector<std::string> types) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
         ui::Clipboard::GetForCurrentThread()->ReadURL(
             /* data_dst = */ std::nullopt,
             base::BindOnce(
@@ -440,7 +440,7 @@ void Initialize(v8::Local<v8::Object> ex
   PopulateClipboardObject(isolate, context, exports,
                           ui::ClipboardBuffer::kCopyPaste);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto selection = v8::Object::New(isolate);
   PopulateClipboardObject(isolate, context, selection,
                           ui::ClipboardBuffer::kSelection);
