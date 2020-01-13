$NetBSD$

* put inclusion of asiolonk first so that map from net/if.h on illumos 
  won't confict with std::map

--- src/bin/dhcp6/tests/parser_unittest.cc.orig	2020-01-02 23:01:48.000000000 +0000
+++ src/bin/dhcp6/tests/parser_unittest.cc
@@ -6,9 +6,9 @@
 
 #include <config.h>
 
+#include <dhcpsrv/parsers/simple_parser6.h>
 #include <gtest/gtest.h>
 #include <dhcp6/parser_context.h>
-#include <dhcpsrv/parsers/simple_parser6.h>
 #include <testutils/io_utils.h>
 #include <testutils/user_context_utils.h>
 
