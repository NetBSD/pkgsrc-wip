$NetBSD$

Everything works, but native curses has no curses_version(), so rip out that bit.

--- src/controller.cpp.orig	2018-06-24 19:30:30.000000000 +0000
+++ src/controller.cpp
@@ -910,9 +910,13 @@ void controller::print_version_informati
 #if defined(__GNUC__) && defined(__VERSION__)
 		std::cout << "Compiler: g++ " << __VERSION__ << std::endl;
 #endif
+#if defined(__NetBSD__)
+		std::cout << "Native NetBSD curses" << std::endl;
+#else
 		std::cout << "ncurses: " << curses_version()
 			  << " (compiled with " << NCURSES_VERSION << ")"
 			  << std::endl;
+#endif
 		std::cout << "libcurl: " << curl_version() << " (compiled with "
 			  << LIBCURL_VERSION << ")" << std::endl;
 		std::cout << "SQLite: " << sqlite3_libversion()
