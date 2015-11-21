$NetBSD$

'//TRANSLIT' is only supported by GNU iconv.
https://github.com/netgusto/Baikal/issues/419

--- Core/Frameworks/Flake/Util/Tools.php.orig	2014-02-03 20:46:11.000000000 +0000
+++ Core/Frameworks/Flake/Util/Tools.php
@@ -493,7 +493,7 @@ TEST;
 		$sString = strtr($sString, ' -+_\'', $space . $space . $space . $space . $space); // convert spaces
 		
 		if(function_exists("iconv")) {
-			$sString = iconv('UTF-8', 'ASCII//TRANSLIT', $sString);
+			$sString = iconv('UTF-8', 'ASCII', $sString);
 		}
 		
 		$sString = strtolower($sString);
