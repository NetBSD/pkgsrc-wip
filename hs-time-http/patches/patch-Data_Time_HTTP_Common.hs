$NetBSD: patch-Data_Time_HTTP_Common.hs,v 1.1 2013/10/01 10:12:25 phonohawk Exp $

Workaround for an old assumption that (Integral a) is always (Show a).

--- Data/Time/HTTP/Common.hs.orig	2013-10-01 10:01:36.000000000 +0000
+++ Data/Time/HTTP/Common.hs
@@ -160,7 +160,7 @@ longMonthNameP
              , string "December"  >> return 12
              ]
 
-show4 :: Integral i => i -> String
+show4 :: (Integral i, Show i) => i -> String
 show4 i
     | i >= 0 && i < 10    = "000" ++ show i
     | i >= 0 && i < 100   = "00"  ++ show i
@@ -168,7 +168,7 @@ show4 i
     | i >= 0 && i < 10000 = show i
     | otherwise          = error ("show4: the integer i must satisfy 0 <= i < 10000: " ++ show i)
 
-show2 :: Integral i => i -> String
+show2 :: (Integral i, Show i) => i -> String
 show2 i
     | i >= 0 && i < 10  = '0' : show i
     | i >= 0 && i < 100 = show i
