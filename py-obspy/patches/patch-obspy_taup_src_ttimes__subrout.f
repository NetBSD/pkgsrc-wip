$NetBSD: patch-obspy_taup_src_ttimes__subrout.f,v 1.1 2014/07/18 09:33:02 uccwen Exp $

--- obspy/taup/src/ttimes_subrout.f.orig	2014-07-18 17:16:38.000000000 +0000
+++ obspy/taup/src/ttimes_subrout.f
@@ -236,7 +236,8 @@ C           TREATS AS A NULL ENTRY.
 C       27 July 1993: Did input read through cstring so can have 
 C         comment lines
 C-
-        CHARACTER*1 DELIM/'$'/,CHARIN,BLANK/' '/
+        CHARACTER*1 DELIM,CHARIN,BLANK
+	DATA DELIM/'$'/,BLANK/' '/
         CHARACTER*3 TEST,UCY,LCY
         character*80 string_in
         CHARACTER*(*) MSG
