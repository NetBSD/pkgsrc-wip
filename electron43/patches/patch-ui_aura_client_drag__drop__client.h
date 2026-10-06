$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/aura/client/drag_drop_client.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/aura/client/drag_drop_client.h
@@ -44,7 +44,7 @@ class AURA_EXPORT DragDropClient {
       int allowed_operations,
       ui::mojom::DragEventSource source) = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Updates the drag image. An empty |image| may be used to hide a previously
   // set non-empty drag image, and a non-empty |image| shows the drag image
   // again if it was previously hidden.
