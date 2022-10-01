$NetBSD$

* put inclusion of asiolonk first so that map from net/if.h on illumos 
  won't confict with std::map

--- src/bin/dhcp6/tests/parser_unittest.cc.orig 2022-07-26 06:08:02.000000000 +0000
+++ src/bin/dhcp6/tests/parser_unittest.cc
@@ -6,8 +6,8 @@

 #include <config.h>

-#include <dhcp6/parser_context.h>
 #include <dhcpsrv/parsers/simple_parser6.h>
+#include <dhcp6/parser_context.h>
 #include <testutils/io_utils.h>
 #include <testutils/log_utils.h>
 #include <testutils/user_context_utils.h>
