$NetBSD$

* fix compilation with c++gsl 3.1.0

--- Interpreter/interpret.h.orig	2020-02-05 05:36:17.000000000 +0000
+++ Interpreter/interpret.h
@@ -6,6 +6,7 @@
 #include "Util/string_view.h"
 
 #include <gsl/span>
+#include <gsl/gsl_util>
 
 #include <deque>
 #include <memory>
