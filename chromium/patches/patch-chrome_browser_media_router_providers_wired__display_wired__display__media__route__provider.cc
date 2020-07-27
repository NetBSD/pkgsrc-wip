$NetBSD$

--- chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc
@@ -112,6 +112,12 @@ void WiredDisplayMediaRouteProvider::Cre
     bool off_the_record,
     CreateRouteCallback callback) {
   DCHECK(!base::Contains(presentations_, presentation_id));
+#if defined(OS_BSD)
+  std::move(callback).Run(base::nullopt, nullptr,
+                         std::string("Not implemented"),
+                         RouteRequestResult::UNKNOWN_ERROR);
+  return;
+#else
   base::Optional<Display> display = GetDisplayBySinkId(sink_id);
   if (!display) {
     std::move(callback).Run(base::nullopt, nullptr,
@@ -138,6 +144,7 @@ void WiredDisplayMediaRouteProvider::Cre
   std::move(callback).Run(route, nullptr, base::nullopt,
                           RouteRequestResult::OK);
   NotifyRouteObservers();
+#endif
 }
 
 void WiredDisplayMediaRouteProvider::JoinRoute(
