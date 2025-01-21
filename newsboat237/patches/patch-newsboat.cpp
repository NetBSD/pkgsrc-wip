$NetBSD$

Avoid ncursesisms curses_version() and NCURSES_VERSION so this can
build against system curses.

--- newsboat.cpp.orig	2024-09-22 15:05:50.000000000 +0000
+++ newsboat.cpp
@@ -229,9 +229,13 @@ void print_version(const std::string& ar
 #if defined(__GNUC__) && defined(__VERSION__)
 		ss << "Compiler: g++ " << __VERSION__ << std::endl;
 #endif
+#ifdef __NetBSD__
+		ss << "Native NetBSD curses" << std::endl;
+#else
 		ss << "ncurses: " << curses_version()
 			<< " (compiled with " << NCURSES_VERSION << ")"
 			<< std::endl;
+#endif
 		ss << "libcurl: " << curl_version() << " (compiled with "
 			<< LIBCURL_VERSION << ")" << std::endl;
 		ss << "SQLite: " << sqlite3_libversion()
