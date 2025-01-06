$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/platform/wayland/host/wayland_data_drag_controller.cc.orig	2024-10-18 12:35:12.760256000 +0000
+++ ui/ozone/platform/wayland/host/wayland_data_drag_controller.cc
@@ -54,6 +54,16 @@ namespace {
 using mojom::DragEventSource;
 using mojom::DragOperation;
 
+// Used for compatibility between W3C and Wayland drag-and-drop specifications.
+// Since wl_data_offer version >= 3, Wayland dnd sessions with no accepted mime
+// type always end as cancelled. W3C drag-and-drop spec on the other hand does
+// not require drag data to be set in order to proceed with drop and drag-end
+// events. Thus, the special mime type below is used to ensure such behavior is
+// supported by the Wayland backend. Further context can be found at
+// https://developer.mozilla.org/en-US/docs/Web/API/HTML_Drag_and_Drop_API and
+// https://wayland.app/protocols/wayland#wl_data_offer:request:accept.
+constexpr char kMimeTypeEmptyDragData[] = "chromium/x-empty-drag-data";
+
 DragOperation DndActionToDragOperation(uint32_t action) {
   // Prevent the usage of this function for an operation mask.
   DCHECK_LE(std::bitset<32>(action).count(), 1u);
@@ -158,9 +168,17 @@ bool WaylandDataDragController::StartSes
           << ", serial tracker=" << connection_->serial_tracker().ToString();
 
   // Create new data source and offers |data|.
-  SetOfferedExchangeDataProvider(data);
+  offered_exchange_data_provider_ = data.provider().Clone();
+  auto mime_types = GetOfferedExchangeDataProvider()->BuildMimeTypesList();
+  if (mime_types.empty()) {
+    // Add placeholder mime type to ensure the drag-and-drop session can end
+    // successfully, even if no drag data was set by the application. See
+    // `kMimeTypeEmptyDragData` declaration for more details.
+    mime_types.push_back(kMimeTypeEmptyDragData);
+  }
+
   data_source_ = data_device_manager_->CreateSource(this);
-  data_source_->Offer(GetOfferedExchangeDataProvider()->BuildMimeTypesList());
+  data_source_->Offer(mime_types);
   data_source_->SetDndActions(DragOperationsToDndActions(operations));
 
   // Create drag icon surface (if any) and store the data to be exchanged.
@@ -774,11 +792,6 @@ WaylandDataDragController::GetAndValidat
                      : std::nullopt;
 }
 
-void WaylandDataDragController::SetOfferedExchangeDataProvider(
-    const OSExchangeData& data) {
-  offered_exchange_data_provider_ = data.provider().Clone();
-}
-
 const WaylandExchangeDataProvider*
 WaylandDataDragController::GetOfferedExchangeDataProvider() const {
   DCHECK(offered_exchange_data_provider_);
