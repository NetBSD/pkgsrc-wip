$NetBSD$


--- src/FontFace.cpp.orig	2012-06-26 10:46:34.000000000 -0500
+++ src/FontFace.cpp	2015-01-23 11:57:18.000000000 -0600
@@ -341,7 +341,7 @@
 	// Spot check using "key" value first
 	// to avoid wasting time:
 	//
-	if(!hasUnicodeValue(pData->key)) return false;
+	//if(!hasUnicodeValue(pData->key)) return false;
 	
 	//
 	// Check all values in the orthography:
@@ -434,6 +434,7 @@
 		_checkOrthography(Dutch::pData);
 		_checkOrthography(Afrikaans::pData);
 		_checkOrthography(Pinyin::pData);
+		_checkOrthography(AleutLatin::pData);
 		_checkOrthography(IPA::pData);
 		_checkOrthography(LatinLigatures::pData);
 		_checkOrthography(ClaudianLetters::pData);
@@ -452,6 +453,7 @@
 	
 	// CYRILLIC:
 	_checkOrthography(BasicCyrillic::pData);
+	_checkOrthography(AleutCyrillic::pData);
 	
 	//
 	// Arabic:
@@ -532,14 +534,6 @@
 	_checkOrthography(Yi::pData);
 	
 	//
-	// Symbols -- Divide Unicode blocks
-	// into meaningful groups such as "chess symbols"
-	// as necessary.
-	//
-	_checkOrthography(MathematicalOperators::pData);
-	_checkOrthography(ChessSymbols::pData);
-	
-	//
 	// Indic:
 	//
 	_checkOrthography(Bengali::pData);
@@ -601,6 +595,21 @@
 	_checkOrthography(TaiViet::pData);
 	
 	_checkOrthography(OldSouthArabian::pData);
+
+	
+	//
+	// Symbols -- Divide Unicode blocks
+	// into meaningful groups such as "chess symbols"
+	// as necessary.
+	//
+	_checkOrthography(Astronomy::pData);
+	_checkOrthography(ChessSymbols::pData);
+	_checkOrthography(Emoticons::pData);
+	_checkOrthography(Food::pData);
+	_checkOrthography(MathematicalGreek::pData);
+	_checkOrthography(MathematicalLatin::pData);
+	_checkOrthography(MathematicalNumerals::pData);
+	_checkOrthography(MathematicalOperators::pData);
 	
 	
 }
