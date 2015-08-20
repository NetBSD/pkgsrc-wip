$NetBSD: patch-pbdata_reads_HoleXY.hpp,v 1.1 2015/08/20 21:20:14 outpaddling Exp $

--- pbdata/reads/HoleXY.hpp.orig	2015-08-12 17:41:23 UTC
+++ pbdata/reads/HoleXY.hpp
@@ -2,6 +2,7 @@
 #define _BLASR_HOLE_XY_HPP_
 
 #include <stdlib.h>
+#include <stdint.h>
 
 class HoleXY {
 public:
