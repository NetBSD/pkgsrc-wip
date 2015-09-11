$NetBSD: patch-pbdata_reads_HoleXY.hpp,v 1.2 2015/09/11 16:48:33 outpaddling Exp $

--- pbdata/reads/HoleXY.hpp.orig	2015-08-12 17:41:23.000000000 +0000
+++ pbdata/reads/HoleXY.hpp
@@ -2,6 +2,7 @@
 #define _BLASR_HOLE_XY_HPP_
 
 #include <stdlib.h>
+#include <stdint.h>
 
 class HoleXY {
 public:
