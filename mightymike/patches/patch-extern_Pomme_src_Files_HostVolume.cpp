$NetBSD$

ends_with() should be available in C++20 but this still doesn't DTRT :\
--- extern/Pomme/src/Files/HostVolume.cpp.orig	2022-04-11 12:53:32.279806408 -0700
+++ extern/Pomme/src/Files/HostVolume.cpp	2022-04-11 12:53:38.633225776 -0700
@@ -186,12 +186,6 @@
 		auto f = FromU8(candidate.path().filename().u8string());
 #endif
 
-		// It might be an AppleDouble resource fork ("file.rsrc")
-		if (candidate.is_regular_file() && f.ends_with(".rsrc"))
-		{
-			f = f.substr(0, f.length() - 5);
-		}
-
 		if (ELEMENT == UppercaseCopy(f))
 		{
 			path /= AsU8(f);
