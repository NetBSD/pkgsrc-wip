$NetBSD$

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/aarch64/aarch64-tune.md
+++ gcc/config/aarch64/aarch64-tune.md
@@ -1,5 +1,5 @@
 ;; -*- buffer-read-only: t -*-
 ;; Generated automatically by gentune.sh from aarch64-cores.def
 (define_attr "tune"
-	"cortexa34,cortexa35,cortexa53,cortexa57,cortexa72,cortexa73,thunderx,thunderxt88p1,thunderxt88,octeontx,octeontxt81,octeontxt83,thunderxt81,thunderxt83,ampere1,ampere1a,ampere1b,emag,xgene1,falkor,qdf24xx,exynosm1,phecda,thunderx2t99p1,vulcan,thunderx2t99,cortexa55,cortexa75,cortexa76,cortexa76ae,cortexa77,cortexa78,cortexa78ae,cortexa78c,cortexa65,cortexa65ae,cortexx1,cortexx1c,neoversen1,ares,neoversee1,octeontx2,octeontx2t98,octeontx2t96,octeontx2t93,octeontx2f95,octeontx2f95n,octeontx2f95mm,a64fx,tsv110,thunderx3t110,neoversev1,zeus,neoverse512tvb,saphira,cortexa57cortexa53,cortexa72cortexa53,cortexa73cortexa35,cortexa73cortexa53,cortexa75cortexa55,cortexa76cortexa55,cortexr82,cortexa510,cortexa520,cortexa710,cortexa715,cortexa720,cortexx2,cortexx3,cortexx4,neoversen2,cobalt100,neoversev2,grace,demeter,generic,generic_armv8_a,generic_armv9_a"
+	"cortexa34,cortexa35,cortexa53,cortexa57,cortexa72,cortexa73,thunderx,thunderxt88p1,thunderxt88,octeontx,octeontxt81,octeontxt83,thunderxt81,thunderxt83,ampere1,ampere1a,ampere1b,emag,xgene1,falkor,qdf24xx,exynosm1,phecda,thunderx2t99p1,vulcan,thunderx2t99,cortexa55,cortexa75,cortexa76,cortexa76ae,cortexa77,cortexa78,cortexa78ae,cortexa78c,cortexa65,cortexa65ae,cortexx1,cortexx1c,neoversen1,ares,neoversee1,octeontx2,octeontx2t98,octeontx2t96,octeontx2t93,octeontx2f95,octeontx2f95n,octeontx2f95mm,a64fx,tsv110,thunderx3t110,neoversev1,zeus,neoverse512tvb,saphira,cortexa57cortexa53,cortexa72cortexa53,cortexa73cortexa35,cortexa73cortexa53,cortexa75cortexa55,cortexa76cortexa55,cortexr82,applea12,applem1,applem2,applem3,cortexa510,cortexa520,cortexa710,cortexa715,cortexa720,cortexx2,cortexx3,cortexx4,neoversen2,cobalt100,neoversev2,grace,demeter,generic,generic_armv8_a,generic_armv9_a"
 	(const (symbol_ref "((enum attr_tune) aarch64_tune)")))
