$NetBSD$

* fix compilation with c++gsl 4.0.0

--- Interpreter/interpret.h.orig	2020-02-05 05:36:17.000000000 +0000
+++ Interpreter/interpret.h
@@ -5,7 +5,9 @@
 #include "DataValue.h"
 #include "Util/string_view.h"
 
+#include <gsl/narrow>
 #include <gsl/span>
+#include <gsl/util>
 
 #include <deque>
 #include <memory>
