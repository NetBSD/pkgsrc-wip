$NetBSD$

fix  error: no match for 'operator<<'

--- libxsd-frontend/xsd-frontend/semantic-graph/elements.cxx.orig	2014-07-16 08:14:03.000000000 +0000
+++ libxsd-frontend/xsd-frontend/semantic-graph/elements.cxx
@@ -2,6 +2,7 @@
 // copyright : Copyright (c) 2005-2014 Code Synthesis Tools CC
 // license   : GNU GPL v2 + exceptions; see accompanying LICENSE file
 
+#include <iostream>
 #include <algorithm>
 
 #include <cutl/compiler/type-info.hxx>
