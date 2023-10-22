$NetBSD$

--- newsboat.cpp.orig	2023-09-24 20:34:30.000000000 +0000
+++ newsboat.cpp
@@ -196,9 +196,13 @@ void print_version(const std::string& ar
 #if defined(__GNUC__) && defined(__VERSION__)
 		ss << "Compiler: g++ " << __VERSION__ << std::endl;
 #endif
+#if defined(__NetBSD__)
+               std::cout << "Native NetBSD curses" << std::endl;
+#else
 		ss << "ncurses: " << curses_version()
 			<< " (compiled with " << NCURSES_VERSION << ")"
 			<< std::endl;
+#endif
 		ss << "libcurl: " << curl_version() << " (compiled with "
 			<< LIBCURL_VERSION << ")" << std::endl;
 		ss << "SQLite: " << sqlite3_libversion()
