$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/local_frame_mojo_handler.cc.orig	2024-10-18 12:34:35.416178700 +0000
+++ third_party/blink/renderer/core/frame/local_frame_mojo_handler.cc
@@ -959,6 +959,7 @@ void LocalFrameMojoHandler::JavaScriptEx
             std::move(callback).Run(value ? std::move(*value) : base::Value());
           },
           std::move(callback)),
+      base::NullCallback(),
       BackForwardCacheAware::kAllow,
       wants_result
           ? mojom::blink::WantResultOption::kWantResultDateAndRegExpAllowed
