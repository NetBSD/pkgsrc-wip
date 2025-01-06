$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/renderer/pepper/chrome_renderer_pepper_host_factory.cc.orig	2024-10-18 12:34:04.087868700 +0000
+++ chrome/renderer/pepper/chrome_renderer_pepper_host_factory.cc
@@ -5,7 +5,9 @@
 #include "chrome/renderer/pepper/chrome_renderer_pepper_host_factory.h"
 
 #include "base/check_op.h"
+#if 0
 #include "chrome/renderer/pepper/pepper_uma_host.h"
+#endif
 #include "content/public/renderer/renderer_ppapi_host.h"
 #include "ppapi/host/ppapi_host.h"
 #include "ppapi/host/resource_host.h"
@@ -33,6 +35,7 @@ ChromeRendererPepperHostFactory::CreateR
   if (!host_->IsValidInstance(instance))
     return nullptr;
 
+#if 0
   // Permissions for the following interfaces will be checked at the
   // time of the corresponding instance's method calls.  Currently these
   // interfaces are available only for whitelisted apps which may not have
@@ -42,6 +45,7 @@ ChromeRendererPepperHostFactory::CreateR
       return std::make_unique<PepperUMAHost>(host_, instance, resource);
     }
   }
+#endif
 
   return nullptr;
 }
