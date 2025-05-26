$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/platform/wayland/host/wayland_input_method_context.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_input_method_context.cc
@@ -60,7 +60,7 @@ namespace {
 // Only enable the preedit string for sequence mode (i.e. when using dead keys
 // or the Compose key) on Linux ozone/wayland (see b/220370007).
 constexpr CharacterComposer::PreeditStringMode kPreeditStringMode =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     CharacterComposer::PreeditStringMode::kAlwaysEnabled;
 #else
     CharacterComposer::PreeditStringMode::kHexModeOnly;
@@ -552,6 +552,7 @@ void WaylandInputMethodContext::OnPreedi
     const gfx::Range& preedit_cursor) {
   CompositionText composition_text;
   composition_text.text = base::UTF8ToUTF16(text);
+  bool has_composition_style = false;
   for (const auto& span : spans) {
     auto start_offset = OffsetFromUTF8Offset(text, span.index);
     if (!start_offset)
@@ -562,9 +563,18 @@ void WaylandInputMethodContext::OnPreedi
     const auto& style = span.style;
     if (!style.has_value())
       continue;
+    if (style->type == ImeTextSpan::Type::kComposition) {
+      has_composition_style = true;
+    }
     composition_text.ime_text_spans.emplace_back(style->type, *start_offset,
                                                  *end_offset, style->thickness);
   }
+  if (!composition_text.text.empty() && !has_composition_style) {
+    // If no explicit composition style is specified, add default composition
+    // style to the composition text.
+    composition_text.ime_text_spans.emplace_back(
+        ImeTextSpan::Type::kComposition, 0, composition_text.text.length());
+  }
   if (!preedit_cursor.IsValid()) {
     // This is the case if a preceding preedit_cursor event in text-input-v1 was
     // not received or an explicit negative value was requested to hide the
