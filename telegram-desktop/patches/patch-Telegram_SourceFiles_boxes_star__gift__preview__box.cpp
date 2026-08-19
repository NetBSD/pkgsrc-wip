$NetBSD$

Replace ranges::copy with a simple for loop — range-v3 0.10.0 does not
support std::back_insert_iterator with ranges::copy.

--- Telegram/SourceFiles/boxes/star_gift_preview_box.cpp.orig	2026-08-03 04:35:53.639496971 +0300
+++ Telegram/SourceFiles/boxes/star_gift_preview_box.cpp	2026-08-03 04:35:53.685843992 +0300
@@ -1436,9 +1436,9 @@
 		void randomize() {
 			const auto choose = [](const auto &list, auto &indices) {
 				if (indices.empty()) {
-					ranges::copy(
-						ranges::views::ints(0, int(list.size())),
-						std::back_inserter(indices));
+					for (int i = 0; i < int(list.size()); ++i) {
+						indices.push_back(i);
+					}
 				}
 				const auto which = base::RandomIndex(indices.size());
 				const auto index = indices[which];
