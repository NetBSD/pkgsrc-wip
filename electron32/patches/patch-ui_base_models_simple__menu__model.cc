$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/models/simple_menu_model.cc.orig	2024-10-18 12:35:12.372410800 +0000
+++ ui/base/models/simple_menu_model.cc
@@ -53,6 +53,11 @@ std::u16string SimpleMenuModel::Delegate
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
@@ -338,6 +343,11 @@ void SimpleMenuModel::SetLabel(size_t in
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
@@ -429,6 +439,12 @@ std::u16string SimpleMenuModel::GetLabel
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
