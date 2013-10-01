$NetBSD: patch-src_Text_XML_HXT_Parser_TagSoup.hs,v 1.1 2013/10/01 03:14:28 phonohawk Exp $

We want hxt-tagsoup to work with tagsoup 0.13. pkgsrc isn't good at
handling multiple package versions.

--- src/Text/XML/HXT/Parser/TagSoup.hs.orig	2012-01-05 12:28:52.000000000 +0000
+++ src/Text/XML/HXT/Parser/TagSoup.hs
@@ -244,7 +244,7 @@ extendNsEnv withNamespaces al1 env
 lookupEntity    :: Bool -> Bool -> (String, Bool) -> Tags
 lookupEntity withWarnings _asHtml (e0@('#':e), withSemicolon)
     = case lookupNumericEntity e of
-      Just c  -> (TagText [c])
+      Just c  -> (TagText c)
 		 : missingSemi
       Nothing -> ( TagText $ "&" ++ e0 ++ [';' | withSemicolon])
 		 : if withWarnings
