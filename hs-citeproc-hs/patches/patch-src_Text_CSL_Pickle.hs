$NetBSD: patch-src_Text_CSL_Pickle.hs,v 1.1 2013/08/22 22:02:07 szptvlfn Exp $

avoid USE_HEXPAT

--- src/Text/CSL/Pickle.hs.orig	2013-03-09 08:07:35.000000000 +0000
+++ src/Text/CSL/Pickle.hs
@@ -24,12 +24,12 @@ import Data.Maybe
 import System.Directory ( doesFileExist )
 import qualified Data.ByteString.Lazy as L
 
-#ifdef USE_HEXPAT
-import Text.CSL.Pickle.Hexpat
-#else
+-- #ifdef USE_HEXPAT
+-- import Text.CSL.Pickle.Hexpat
+-- #else
 import Text.CSL.Pickle.Xml
 import Text.XML.Light
-#endif
+-- #endif
 
 data St
     = St { attributes :: [Attr]
