$NetBSD: patch-Network_HTTP_Lucu_Chunk.hs,v 1.1 2013/10/01 14:20:17 phonohawk Exp $

Workaround for breakage on recent libraries.

--- Network/HTTP/Lucu/Chunk.hs.orig	2013-10-01 14:00:18.000000000 +0000
+++ Network/HTTP/Lucu/Chunk.hs
@@ -11,7 +11,7 @@ import           Network.HTTP.Lucu.Parse
 import           Numeric
 
 
-chunkHeaderP :: Num a => Parser a
+chunkHeaderP :: (Num a, Eq a) => Parser a
 chunkHeaderP = do hexLen <- many1 hexDigit
                   _      <- extension
                   _      <- crlf
