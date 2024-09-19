$NetBSD$

Everything works, but native curses has no curses_version(), so rip out that bit.

--- newsboat.cpp.orig	2018-09-22 16:56:08.000000000 +0000
+++ newsboat.cpp
@@ -134,9 +134,13 @@ void print_version(const std::string& ar
 #if defined(__GNUC__) && defined(__VERSION__)
 		ss << "Compiler: g++ " << __VERSION__ << std::endl;
 #endif
+#if defined(__NetBSD__)
+		std::cout << "Native NetBSD curses" << std::endl;
+#else
 		ss << "ncurses: " << curses_version()
 			  << " (compiled with " << NCURSES_VERSION << ")"
 			  << std::endl;
+#endif
 		ss << "libcurl: " << curl_version() << " (compiled with "
 			  << LIBCURL_VERSION << ")" << std::endl;
 		ss << "SQLite: " << sqlite3_libversion()
