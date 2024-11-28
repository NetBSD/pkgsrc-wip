$NetBSD$

# Unbreak build on macOS 15.0 aarch64

--- inst/include/Rcpp/exceptions/cpp11/exceptions.h.orig	2024-11-28 14:38:44.773960705 +0000
+++ inst/include/Rcpp/exceptions/cpp11/exceptions.h
@@ -48,7 +48,7 @@ inline void warning(const char* fmt, Arg
 }
 
 template <typename... Args>
-inline void NORET stop(const char* fmt, Args&&... args) {
+NORET inline void stop(const char* fmt, Args&&... args) {
     throw Rcpp::exception( tfm::format(fmt, std::forward<Args>(args)... ).c_str() );
 }
 
