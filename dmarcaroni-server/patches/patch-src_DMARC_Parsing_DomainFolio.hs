$NetBSD$

Fix build with base64 >= 1.0.

--- src/DMARC/Parsing/DomainFolio.hs.orig	2025-03-07 18:04:08.539526462 +0000
+++ src/DMARC/Parsing/DomainFolio.hs
@@ -17,6 +17,7 @@ import DMARC.XML.DomainFolio
 
 import Control.Monad (when)
 import Crypto.Hash.BLAKE2.BLAKE2sp
+import Data.Base64.Types (extractBase64)
 import Data.ByteString.Base64 (encodeBase64)
 import Data.Foldable ( foldlM )
 import Data.List (find, partition, sortOn)
@@ -85,7 +86,7 @@ newDomainFolio config ips name = DomainF
 -- | Generate hashed filename fo DomainFolio
 generateFolioFileName :: T.Text -> FilePath
 generateFolioFileName name = take 16 $ filter (\c -> c /= '/') encoded
-  where encoded = ( T.unpack .encodeBase64 ) hashed
+  where encoded = ( T.unpack . extractBase64 . encodeBase64 ) hashed
         hashed  = ( hash 20 B.empty . BC.pack . T.unpack ) name
 
 -- | Update DomainFolio with information from feedback: create new timewindows and update user ips and countries 
