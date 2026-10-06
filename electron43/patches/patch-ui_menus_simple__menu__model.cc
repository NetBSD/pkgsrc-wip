$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/menus/simple_menu_model.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/menus/simple_menu_model.cc
@@ -54,6 +54,11 @@ std::u16string SimpleMenuModel::Delegate
   return std::u16string();
 }
 
+std::u16string SimpleMenuModel::Delegate::GetSecondaryLabelForCommandId(
+    int command_id) const {
+  return std::u16string();
+}
+
 ImageModel SimpleMenuModel::Delegate::GetIconForCommandId(
     int command_id) const {
   return ImageModel();
@@ -347,6 +352,11 @@ void SimpleMenuModel::SetAcceleratorAt(s
   MenuItemsChanged();
 }
 
+void SimpleMenuModel::SetSecondaryLabel(size_t index, const std::u16string& secondary_label) {
+  items_[ValidateItemIndex(index)].secondary_label = secondary_label;
+  MenuItemsChanged();
+}
+
 void SimpleMenuModel::SetMinorText(size_t index,
                                    const std::u16string& minor_text) {
   items_[ValidateItemIndex(index)].minor_text = minor_text;
@@ -453,6 +463,12 @@ std::u16string SimpleMenuModel::GetLabel
   return items_[ValidateItemIndex(index)].label;
 }
 
+std::u16string SimpleMenuModel::GetSecondaryLabelAt(size_t index) const {
+  if (IsItemDynamicAt(index))
+    return delegate_->GetSecondaryLabelForCommandId(GetCommandIdAt(index));
+  return items_[ValidateItemIndex(index)].secondary_label;
+}
+
 std::u16string SimpleMenuModel::GetMinorTextAt(size_t index) const {
   return items_[ValidateItemIndex(index)].minor_text;
 }
