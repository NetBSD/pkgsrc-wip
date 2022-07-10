$NetBSD$

* fix build with litehtml 0.6

--- src/assistant/qlitehtml/src/container_qpainter_p.h.orig	2022-07-09 11:07:09.195443730 +0000
+++ src/assistant/qlitehtml/src/container_qpainter_p.h
@@ -96,7 +96,7 @@ public: // document_container API
                    litehtml::uint_ptr hFont,
                    litehtml::web_color color,
                    const litehtml::position &pos) override;
-    int pt_to_px(int pt) override;
+    int pt_to_px(int pt) const override;
     int get_default_font_size() const override;
     const litehtml::tchar_t *get_default_font_name() const override;
     void draw_list_marker(litehtml::uint_ptr hdc, const litehtml::list_marker &marker) override;
