$NetBSD$

Substitute a tab character for \t, as \t is generally not special.

--- src/gen.preload.conf.sh.orig	2008-10-23 01:08:21.000000000 +0000
+++ src/gen.preload.conf.sh
@@ -3,7 +3,7 @@
 IN="$1"
 KEYS="$2"
 
-I='[ \t]*\([^, \t]*\)[ \t]*'
+I='[ 	]*\([^, 	]*\)[ 	]*'
 SEDSCRIPT=`sed -e "s/confkey($I,$I,$I,$I,$I)/s@default_\3@\4@g; s@unit_\3@\5@g;/;" < "$KEYS"`
 
 sed -e "$SEDSCRIPT" "$IN"
