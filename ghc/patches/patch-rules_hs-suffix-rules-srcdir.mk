$NetBSD: patch-rules_hs-suffix-rules-srcdir.mk,v 1.1 2012/03/04 04:37:14 phonohawk Exp $

There is a missing ".hc -> .o" rule in this file, leading to a build
failure of Cabal.


--- rules/hs-suffix-rules-srcdir.mk.orig	2012-02-01 18:10:32.000000000 +0000
+++ rules/hs-suffix-rules-srcdir.mk
@@ -57,6 +57,9 @@ $1/$2/build/%.$$($3_osuf) : $1/$4/%.hc i
 $1/$2/build/%.$$($3_osuf) : $1/$2/build/%.hc includes/ghcautoconf.h includes/ghcplatform.h
 	"$$($1_$2_CC)" $$($1_$2_$3_ALL_CC_OPTS) -Iincludes -x c -c $$< -o $$@
 
+$1/$2/build/%.$$($3_osuf) : $1/$2/build/autogen/%.hc includes/ghcautoconf.h includes/ghcplatform.h
+	"$$($1_$2_CC)" $$($1_$2_$3_ALL_CC_OPTS) -Iincludes -x c -c $$< -o $$@
+
 # $1/$2/build/%.$$($3_osuf) : $1/$2/build/%.$$($3_way_)hc
 # 	"$$($1_$2_HC)" $$($1_$2_$3_ALL_HC_OPTS) -c $$< -o $$@
 #
