$NetBSD$

--- Telegram/lib_lottie/lottie/lottie_animation.cpp.orig	2021-02-28 21:30:27.481815450 +0000
+++ Telegram/lib_lottie/lottie/lottie_animation.cpp
@@ -143,10 +143,7 @@ std::unique_ptr<rlottie::Animation> Crea
 		string,
 		std::string(),
 		std::string(),
-		false,
-		(replacements
-			? replacements->replacements
-			: std::vector<std::pair<std::uint32_t, std::uint32_t>>()));
+		false);
 #else
 	auto result = rlottie::Animation::loadFromData(
 		string,
