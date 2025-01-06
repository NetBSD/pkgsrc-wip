$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/models/simple_menu_model.h.orig	2024-10-18 12:35:12.372410800 +0000
+++ ui/base/models/simple_menu_model.h
@@ -99,6 +99,7 @@ class COMPONENT_EXPORT(UI_BASE) SimpleMe
     // Some command ids have labels and icons that change over time.
     virtual bool IsItemForCommandIdDynamic(int command_id) const;
     virtual std::u16string GetLabelForCommandId(int command_id) const;
+    virtual std::u16string GetSecondaryLabelForCommandId(int command_id) const;
     // Gets the icon for the item with the specified id.
     virtual ImageModel GetIconForCommandId(int command_id) const;
 
@@ -218,6 +219,9 @@ class COMPONENT_EXPORT(UI_BASE) SimpleMe
   // Sets the label for the item at |index|.
   void SetLabel(size_t index, const std::u16string& label);
 
+  // Sets the secondary_label for the item at |index|.
+  void SetSecondaryLabel(size_t index, const std::u16string& secondary_label);
+
   // Sets the minor text for the item at |index|.
   void SetMinorText(size_t index, const std::u16string& minor_text);
 
@@ -260,6 +264,7 @@ class COMPONENT_EXPORT(UI_BASE) SimpleMe
   ui::MenuSeparatorType GetSeparatorTypeAt(size_t index) const override;
   int GetCommandIdAt(size_t index) const override;
   std::u16string GetLabelAt(size_t index) const override;
+  std::u16string GetSecondaryLabelAt(size_t index) const override;
   std::u16string GetMinorTextAt(size_t index) const override;
   ImageModel GetMinorIconAt(size_t index) const override;
   bool IsItemDynamicAt(size_t index) const override;
@@ -299,6 +304,7 @@ class COMPONENT_EXPORT(UI_BASE) SimpleMe
     int command_id = 0;
     ItemType type = TYPE_COMMAND;
     std::u16string label;
+    std::u16string secondary_label;
     std::u16string minor_text;
     ImageModel minor_icon;
     ImageModel icon;
