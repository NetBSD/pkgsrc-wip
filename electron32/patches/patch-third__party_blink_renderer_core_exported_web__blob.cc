$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/exported/web_blob.cc.orig	2024-10-18 12:34:35.364202500 +0000
+++ third_party/blink/renderer/core/exported/web_blob.cc
@@ -41,6 +41,7 @@
 #include "third_party/blink/renderer/core/execution_context/execution_context.h"
 #include "third_party/blink/renderer/core/fileapi/blob.h"
 #include "third_party/blink/renderer/core/fileapi/file_backed_blob_factory_dispatcher.h"
+#include "third_party/blink/renderer/core/fileapi/file.h"
 #include "third_party/blink/renderer/platform/blob/blob_data.h"
 #include "third_party/blink/renderer/platform/file_metadata.h"
 #include "third_party/blink/renderer/platform/heap/garbage_collected.h"
@@ -84,6 +85,14 @@ WebString WebBlob::Uuid() {
   return private_->Uuid();
 }
 
+std::string WebBlob::Path() {
+  if (!private_.Get())
+    return "";
+  if (private_->IsFile() && private_->HasBackingFile())
+    return To<File>(private_.Get())->GetPath().Utf8();
+  return "";
+}
+
 v8::Local<v8::Value> WebBlob::ToV8Value(v8::Isolate* isolate) {
   if (!private_.Get())
     return v8::Local<v8::Value>();
