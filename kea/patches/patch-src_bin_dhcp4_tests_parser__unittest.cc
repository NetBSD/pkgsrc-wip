$NetBSD$

* put inclusion of asiolink on top so that std::map dos not conflict with 
  map in net/if.h on illumos

--- src/bin/dhcp4/tests/parser_unittest.cc.orig 2022-07-26 06:08:02.000000000 +0000
+++ src/bin/dhcp4/tests/parser_unittest.cc
@@ -6,8 +6,8 @@

 #include <config.h>

-#include <dhcp4/parser_context.h>
 #include <dhcpsrv/parsers/simple_parser4.h>
+#include <dhcp4/parser_context.h>
 #include <testutils/gtest_utils.h>
 #include <testutils/io_utils.h>
 #include <testutils/log_utils.h>
