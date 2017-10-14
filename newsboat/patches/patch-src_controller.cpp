$NetBSD$

Everything works, but native curses has no curses_version(), so rip out that bit.

--- src/controller.cpp.orig	2017-09-22 20:01:50.000000000 +0000
+++ src/controller.cpp
@@ -1167,7 +1167,11 @@ void controller::version_information(con
 #if defined(__GNUC__) && defined(__VERSION__)
 		std::cout << "Compiler: g++ " << __VERSION__ << std::endl;
 #endif
+#if defined(__NetBSD__)
+		std::cout << "Native NetBSD curses" << std::endl;
+#else
 		std::cout << "ncurses: " << curses_version() << " (compiled with " << NCURSES_VERSION << ")" << std::endl;
+#endif
 		std::cout << "libcurl: " << curl_version()  << " (compiled with " << LIBCURL_VERSION << ")" << std::endl;
 		std::cout << "SQLite: " << sqlite3_libversion() << " (compiled with " << SQLITE_VERSION << ")" << std::endl;
 		std::cout << "libxml2: compiled with " << LIBXML_DOTTED_VERSION << std::endl << std::endl;
