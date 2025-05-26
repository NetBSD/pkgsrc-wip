$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/views/overlay/close_image_button.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/views/overlay/close_image_button.cc
@@ -4,9 +4,12 @@
 
 #include "chrome/browser/ui/views/overlay/close_image_button.h"
 
+#include "build/branding_buildflags.h"
 #include "chrome/browser/ui/color/chrome_color_id.h"
 #include "chrome/grit/generated_resources.h"
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #include "components/vector_icons/vector_icons.h"
+#endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/metadata/metadata_impl_macros.h"
 #include "ui/base/models/image_model.h"
@@ -26,7 +29,10 @@ CloseImageButton::CloseImageButton(Press
     : OverlayWindowImageButton(std::move(callback)) {
   SetSize(gfx::Size(kCloseButtonSize, kCloseButtonSize));
 
-  auto* icon = &vector_icons::kCloseChromeRefreshIcon;
+  auto* icon = &views::kIcCloseIcon;
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING)
+  icon = &vector_icons::kCloseChromeRefreshIcon;
+#endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
   SetImageModel(views::Button::STATE_NORMAL,
                 ui::ImageModel::FromVectorIcon(*icon, kColorPipWindowForeground,
                                                kCloseButtonIconSize));
