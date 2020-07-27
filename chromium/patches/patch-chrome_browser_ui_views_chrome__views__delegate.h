$NetBSD$

--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -44,7 +44,7 @@ class ChromeViewsDelegate : public views
   HICON GetSmallWindowIcon() const override;
   int GetAppbarAutohideEdges(HMONITOR monitor,
                              base::OnceClosure callback) override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
