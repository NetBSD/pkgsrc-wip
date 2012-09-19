$NetBSD: patch-mashpodder.sh,v 1.1 2012/09/19 14:54:02 ahp-nils Exp $

Add pkgsrc paths compatibility

--- mashpodder.sh.orig	2012-09-19 13:16:31.000000000 +0000
+++ mashpodder.sh
@@ -23,7 +23,7 @@ DATESTRING='%Y%m%d'
 RSSFILE="$BASEDIR/mp.conf"
 
 #PARSE_ENCLOSURE: Location of parse_enclosure.xsl file.
-PARSE_ENCLOSURE="$BASEDIR/parse_enclosure.xsl"
+PARSE_ENCLOSURE="@PREFIX@/share/mashpodder/parse_enclosure.xsl"
 
 # FIRST_ONLY: Default '' means look to mp.conf on whether to download or
 # update; 1 will override mp.conf and download the newest episode.
