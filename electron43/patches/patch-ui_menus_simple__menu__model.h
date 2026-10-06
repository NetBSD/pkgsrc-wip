$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/menus/simple_menu_model.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/menus/simple_menu_model.h
@@ -99,6 +99,7 @@ class COMPONENT_EXPORT(UI_MENUS) SimpleM
     // Some command ids have labels and icons that change over time.
     virtual bool IsItemForCommandIdDynamic(int command_id) const;
     virtual std::u16string GetLabelForCommandId(int command_id) const;
+    virtual std::u16string GetSecondaryLabelForCommandId(int command_id) const;
     // Gets the icon for the item with the specified id.
     virtual ImageModel GetIconForCommandId(int command_id) const;
 
@@ -224,6 +225,9 @@ class COMPONENT_EXPORT(UI_MENUS) SimpleM
   // former is set).
   void SetAcceleratorAt(size_t index, const ui::Accelerator& accelerator);
 
+  // Sets the secondary_label for the item at |index|.
+  void SetSecondaryLabel(size_t index, const std::u16string& secondary_label);
+
   // Sets the minor text for the item at |index|.
   void SetMinorText(size_t index, const std::u16string& minor_text);
 
@@ -274,6 +278,7 @@ class COMPONENT_EXPORT(UI_MENUS) SimpleM
   ui::MenuSeparatorType GetSeparatorTypeAt(size_t index) const override;
   int GetCommandIdAt(size_t index) const override;
   std::u16string GetLabelAt(size_t index) const override;
+  std::u16string GetSecondaryLabelAt(size_t index) const override;
   std::u16string GetMinorTextAt(size_t index) const override;
   ImageModel GetMinorIconAt(size_t index) const override;
   bool IsItemDynamicAt(size_t index) const override;
@@ -321,6 +326,7 @@ class COMPONENT_EXPORT(UI_MENUS) SimpleM
     ItemType type = TYPE_COMMAND;
     std::u16string label;
     ui::Accelerator accelerator;
+    std::u16string secondary_label;
     std::u16string minor_text;
     ImageModel minor_icon;
     ImageModel icon;
