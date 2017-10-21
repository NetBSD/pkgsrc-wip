$NetBSD$

--- src/output.cpp.orig	2017-06-03 12:45:13.000000000 +0000
+++ src/output.cpp
@@ -63,7 +63,7 @@ unsigned char index_for_color(rgb_color_
     return c.to_term256_index();
 }
 
-static bool write_color_escape(char *todo, unsigned char idx, bool is_fg) {
+static bool write_color_escape(const char *todo, unsigned char idx, bool is_fg) {
     if (term_supports_color_natively(idx)) {
         // Use tparm to emit color escape.
         writembs(tparm(todo, idx));
