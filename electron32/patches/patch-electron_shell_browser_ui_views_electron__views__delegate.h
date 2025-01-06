$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/ui/views/electron_views_delegate.h.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/shell/browser/ui/views/electron_views_delegate.h
@@ -44,7 +44,7 @@ class ViewsDelegate : public views::View
   HICON GetSmallWindowIcon() const override;
   int GetAppbarAutohideEdges(HMONITOR monitor,
                              base::OnceClosure callback) override;
-#elif BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#elif (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
   std::unique_ptr<views::NonClientFrameView> CreateDefaultNonClientFrameView(
