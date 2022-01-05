$NetBSD$

* support demangling on systems that have cxxabi.h

--- libcaf_core/src/detail/pretty_type_name.cpp.orig	2022-01-05 17:43:07.354119301 +0000
+++ libcaf_core/src/detail/pretty_type_name.cpp
@@ -6,7 +6,7 @@
 
 #include "caf/config.hpp"
 
-#if defined(CAF_LINUX) || defined(CAF_MACOS)
+#if defined(CAF_POSIX) && __has_include(<cxxabi.h>)
 #  include <cxxabi.h>
 #  include <sys/types.h>
 #  include <unistd.h>
@@ -43,7 +43,7 @@ void prettify_type_name(std::string& cla
 }
 
 void prettify_type_name(std::string& class_name, const char* c_class_name) {
-#if defined(CAF_LINUX) || defined(CAF_MACOS)
+#if defined(CAF_POSIX) && __has_include(<cxxabi.h>)
   int stat = 0;
   std::unique_ptr<char, decltype(free)*> real_class_name{nullptr, free};
   auto tmp = abi::__cxa_demangle(c_class_name, nullptr, nullptr, &stat);
