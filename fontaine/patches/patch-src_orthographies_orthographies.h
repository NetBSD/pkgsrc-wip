$NetBSD$


--- src/orthographies/orthographies.h.orig	2012-06-26 10:46:34.000000000 -0500
+++ src/orthographies/orthographies.h	2015-01-23 11:57:04.000000000 -0600
@@ -20,10 +20,11 @@
 #include "Turkish.h"
 #include "CentralEuropean.h"
 #include "Romanian.h"
-#include "Vietnamese.h"
 #include "Dutch.h"
 #include "Afrikaans.h"
 #include "Pinyin.h"
+#include "Vietnamese.h"
+#include "AleutLatin.h"
 #include "IPA.h"
 #include "LatinLigatures.h"
 #include "ClaudianLetters.h"
@@ -83,6 +84,7 @@
 // Cyrillic and related:
 //
 #include "BasicCyrillic.h"
+#include "AleutCyrillic.h"
 
 //
 // The Rest:
@@ -101,8 +103,6 @@
 #include "Ogham.h"
 #include "Runic.h"
 #include "Khmer.h"
-#include "MathematicalOperators.h"
-#include "ChessSymbols.h"
 #include "Yi.h"
 
 //
@@ -175,3 +175,11 @@
 
 //#include "CJKA.h"
 
+#include "Astronomy.h"
+#include "ChessSymbols.h"
+#include "Emoticons.h"
+#include "Food.h"
+#include "MathematicalGreek.h"
+#include "MathematicalLatin.h"
+#include "MathematicalNumerals.h"
+#include "MathematicalOperators.h"
