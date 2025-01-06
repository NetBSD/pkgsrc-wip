$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/web_contents/web_contents_view_aura_unittest.cc.orig	2024-10-18 12:34:14.058566800 +0000
+++ content/browser/web_contents/web_contents_view_aura_unittest.cc
@@ -97,7 +97,7 @@ class TestDragDropClient : public aura::
     drag_drop_data_ = std::move(data);
     return DragOperation::kCopy;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void UpdateDragImage(const gfx::ImageSkia& image,
                        const gfx::Vector2d& offset) override {}
 #endif
