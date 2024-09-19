$NetBSD$

include <memory> for std::shared_ptr

--- src/engine/resource/format/lytreader.h.orig	2021-06-04 19:50:21.000000000 +0000
+++ src/engine/resource/format/lytreader.h
@@ -17,6 +17,7 @@
 
 #pragma once
 
+#include <memory>
 #include <boost/filesystem.hpp>
 #include <boost/noncopyable.hpp>
 
