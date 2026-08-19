$NetBSD$

Replace ranges::views::chunk_by with manual grouping — range-v3 0.10.0
(pkgsrc version) does not have chunk_by, added in range-v3 0.11.0.

--- Telegram/lib_spellcheck/spellcheck/third_party/hunspell_controller.cpp.orig	2026-08-02 18:36:14.504239967 +0300
+++ Telegram/lib_spellcheck/spellcheck/third_party/hunspell_controller.cpp	2026-08-02 19:04:17.716375191 +0300
@@ -574,13 +574,21 @@
 	});
 
 	// {{"a"}, {"β"}};
-	auto groupedWords = ranges::views::all(
-		filteredWords
-	) | ranges::views::chunk_by([](auto &a, auto &b) {
-		return WordScript(a) == WordScript(b);
-	}) | ranges::views::transform([](auto &&rng) {
-		return rng | ranges::to_vector;
-	}) | ranges::to_vector;
+	auto groupedWordsVec = filteredWords | ranges::to_vector;
+	std::vector<std::vector<QString>> groupedWordsResult;
+	if (!groupedWordsVec.empty()) {
+		auto currentGroup = std::vector<QString>{ groupedWordsVec.front() };
+		for (auto it = std::next(groupedWordsVec.begin()); it != groupedWordsVec.end(); ++it) {
+			if (WordScript(*std::prev(it)) == WordScript(*it)) {
+				currentGroup.push_back(*it);
+			} else {
+				groupedWordsResult.push_back(std::move(currentGroup));
+				currentGroup = std::vector<QString>{ *it };
+			}
+		}
+		groupedWordsResult.push_back(std::move(currentGroup));
+	}
+	auto &groupedWords = groupedWordsResult;
 
 	// {QChar::Script_Latin, QChar::Script_Greek};
 	auto scripts = ranges::views::all(
