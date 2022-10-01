$NetBSD$

* put io_adress.h first so that map from net/if.h on solaris won't confict
  with std::map

--- src/bin/dhcp6/dhcp6_lexer.ll.orig   2022-07-26 06:08:02.000000000 +0000
+++ src/bin/dhcp6/dhcp6_lexer.ll
@@ -9,13 +9,13 @@
 /* Generated files do not make clang static analyser so happy */
 #ifndef __clang_analyzer__

+#include <asiolink/io_address.h>
 #include <cctype>
 #include <cerrno>
 #include <climits>
 #include <cstdlib>
 #include <string>
 #include <dhcp6/parser_context.h>
-#include <asiolink/io_address.h>
 #include <boost/lexical_cast.hpp>
 #include <exceptions/exceptions.h>
