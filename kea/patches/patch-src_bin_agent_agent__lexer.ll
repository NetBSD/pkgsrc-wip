$NetBSD$

* put io_adress.h first so that map from net/if.h on solaris won't confict
  with std::map on illumos

--- src/bin/agent/agent_lexer.ll.orig   2022-09-30 18:57:27.637505322 +0000
+++ src/bin/agent/agent_lexer.ll
@@ -9,13 +9,13 @@
 /* Generated files do not make clang static analyser so happy */
 #ifndef __clang_analyzer__

+#include <asiolink/io_address.h>
 #include <cctype>
 #include <cerrno>
 #include <climits>
 #include <cstdlib>
 #include <string>
 #include <agent/parser_context.h>
-#include <asiolink/io_address.h>
 #include <boost/lexical_cast.hpp>
 #include <exceptions/exceptions.h>
 #include <cc/dhcp_config_error.h>
