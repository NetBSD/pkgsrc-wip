$NetBSD: patch-src_net_common_ircthread.cpp,v 1.1 2013/12/05 21:30:19 thomasklausner Exp $

Fix incorrect include path.

--- src/net/common/ircthread.cpp.orig	2013-04-07 12:04:27.000000000 +0000
+++ src/net/common/ircthread.cpp
@@ -32,14 +32,14 @@
 #include <net/socket_helper.h>
 #include <net/ircthread.h>
 #include <net/socket_msg.h>
-#include <libircclient/libircclient.h>
+#include <libircclient.h>
 
 // We need to do the following to handle different versions of libircclient.
 // Sadly, libircclient doesn't have actual definitions for its versions in its headers.
 // However, we can use a definition that appeared in the same version we need
 // to check for. Hacky, but hey, it works.
 #ifdef LIBIRC_OPTION_SSL_NO_VERIFY
-#include <libircclient/libirc_rfcnumeric.h>
+#include <libirc_rfcnumeric.h>
 #endif
 
 #include <boost/algorithm/string/predicate.hpp>
