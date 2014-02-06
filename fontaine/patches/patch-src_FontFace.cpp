--- src/FontFace.cpp.orig	2012-06-26 10:46:34.000000000 -0500
+++ src/FontFace.cpp	2014-02-05 21:43:12.000000000 -0600
@@ -601,6 +601,8 @@
 	_checkOrthography(TaiViet::pData);
 	
 	_checkOrthography(OldSouthArabian::pData);
+
+	_checkOrthography(Emoticons::pData);
 	
 	
 }
