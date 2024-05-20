$NetBSD: patch-SPQR_Source_spqr__factorize.cpp,v 1.1.1.1 2012/03/27 16:19:22 outpaddling Exp $

--- SPQR/Source/spqr_factorize.cpp.orig	2024-03-26 21:14:00.000000000 +0000
+++ SPQR/Source/spqr_factorize.cpp
@@ -36,6 +36,7 @@
 // =============================================================================
 
 #include "spqr.hpp"
+#include <string>
 
 #define FCHUNK 32        // FUTURE: make a parameter; Householder block size
 
