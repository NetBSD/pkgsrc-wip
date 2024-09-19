$NetBSD$

Search the installation directories for data files.

--- src/TextMapper.cpp.orig	2015-10-29 08:36:26.000000000 +0000
+++ src/TextMapper.cpp
@@ -37,7 +37,7 @@ namespace tools
 	void TextMapper::LoadTextFile(const std::string & language)
 	{
 		// 1. open file
-		std::ifstream textFile("data/" + textFileName);
+		std::ifstream textFile(WITCHBLAST_DATA_DIR "data/" + textFileName);
 		if (!textFile)
 			std::cout << "[ERROR] No text file !";
 
