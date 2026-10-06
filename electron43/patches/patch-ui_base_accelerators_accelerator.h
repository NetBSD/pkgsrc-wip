$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/accelerators/accelerator.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/base/accelerators/accelerator.h
@@ -16,6 +16,7 @@
 #include <utility>
 
 #include "base/component_export.h"
+#include "third_party/abseil-cpp/absl/types/optional.h"
 #include "base/time/time.h"
 #include "build/build_config.h"
 #include "ui/events/event_constants.h"
@@ -132,6 +133,8 @@ class COMPONENT_EXPORT(UI_BASE) Accelera
     return interrupted_by_mouse_event_;
   }
 
+  absl::optional<char16_t> shifted_char;
+
  private:
   friend class AcceleratorTestMac;
   std::u16string ApplyLongFormModifiers(const std::u16string& shortcut) const;
