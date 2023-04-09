$NetBSD$

Upstream patch for boost deprecations:
https://github.com/prusa3d/PrusaSlicer/commit/408e56f0390f20aaf793e0aa0c70c4d9544401d4

--- src/hints/HintsToPot.cpp.orig	2023-03-13 13:20:26.000000000 +0000
+++ src/hints/HintsToPot.cpp
@@ -9,7 +9,7 @@
 
 bool write_to_pot(boost::filesystem::path path, const std::vector<std::pair<std::string, std::string>>& data)
 {
-	boost::filesystem::ofstream file(std::move(path), std::ios_base::app);
+	boost::nowide::ofstream file(path.string(), std::ios_base::app);
 	for (const auto& element : data)
 	{
 		//Example of .pot element 
