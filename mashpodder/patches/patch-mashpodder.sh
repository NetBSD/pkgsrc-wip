$NetBSD: patch-mashpodder.sh,v 1.2 2013/01/25 08:50:06 ahp-nils Exp $

Add pkgsrc paths compatibility

--- mashpodder.sh.orig	2013-01-09 14:39:56.000000000 +0000
+++ mashpodder.sh
@@ -43,7 +43,7 @@ RSSFILE="$BASEDIR/mp.conf"
 
 # PARSE_ENCLOSURE: Location of parse_enclosure.xsl file.  Default is
 # "$BASEDIR/parse_enclosure.xsl".
-PARSE_ENCLOSURE="$BASEDIR/parse_enclosure.xsl"
+PARSE_ENCLOSURE="@PREFIX@/share/mashpodder/parse_enclosure.xsl"
 
 # PODLOG: This is a critical file.  This is the file that saves the name of
 # every file downloaded (or checked with the 'update' option in mp.conf.)  If
