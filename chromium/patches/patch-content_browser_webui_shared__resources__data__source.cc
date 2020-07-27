$NetBSD$

--- content/browser/webui/shared_resources_data_source.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ content/browser/webui/shared_resources_data_source.cc
@@ -135,7 +135,7 @@ const std::map<int, std::string> CreateM
         {IDR_MOJO_TEXT_DIRECTION_MOJOM_LITE_JS,
          "mojo/mojo/public/mojom/base/text_direction.mojom-lite.js"},
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
         {IDR_MOJO_TIME_MOJOM_HTML,
          "mojo/mojo/public/mojom/base/time.mojom.html"},
         {IDR_MOJO_TIME_MOJOM_LITE_JS,
