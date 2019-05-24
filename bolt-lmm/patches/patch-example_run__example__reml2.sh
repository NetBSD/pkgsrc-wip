$NetBSD$

# Run from installation instead of build dir

--- example/run_example_reml2.sh.orig	2019-05-24 15:12:23.021935693 +0000
+++ example/run_example_reml2.sh
@@ -1,4 +1,6 @@
-../bolt \
+#!/bin/sh -e
+
+bolt \
     --bfile=EUR_subset \
     --phenoFile=EUR_subset.pheno2.covars \
     --exclude=EUR_subset.exclude2 \
