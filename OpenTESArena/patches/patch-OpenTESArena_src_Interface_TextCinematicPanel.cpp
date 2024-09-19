$NetBSD$

Work around std::ceil not defined.

--- OpenTESArena/src/Interface/TextCinematicPanel.cpp.orig	2017-12-28 01:36:36.000000000 +0000
+++ OpenTESArena/src/Interface/TextCinematicPanel.cpp
@@ -43,7 +43,7 @@ TextCinematicPanel::TextCinematicPanel(G
 
 		// Group up to three text lines per text box.
 		std::vector<std::unique_ptr<TextBox>> textBoxes;
-		int textBoxesToMake = static_cast<int>(std::ceil(newLineCount / 3)) + 1;
+		int textBoxesToMake = static_cast<int>(ceil(newLineCount / 3)) + 1;
 		for (int i = 0; i < textBoxesToMake; i++)
 		{
 			std::string textBoxText;
