$NetBSD$

* put inclusion of asiolink on top so that std::map does not conlict with
  map in net/if.h on illumos

--- src/bin/dhcp4/tests/parser_unittest.cc.orig	2020-01-02 23:01:48.000000000 +0000
+++ src/bin/dhcp4/tests/parser_unittest.cc
@@ -6,9 +6,9 @@
 
 #include <config.h>
 
+#include <dhcpsrv/parsers/simple_parser4.h>
 #include <gtest/gtest.h>
 #include <dhcp4/parser_context.h>
-#include <dhcpsrv/parsers/simple_parser4.h>
 #include <testutils/io_utils.h>
 #include <testutils/user_context_utils.h>
 
