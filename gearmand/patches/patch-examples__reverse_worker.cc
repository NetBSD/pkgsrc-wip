$NetBSD: patch-examples__reverse_worker.cc,v 1.1 2012/04/25 09:07:50 fhajny Exp $

Fix build with GCC 4.7.
--- examples/reverse_worker.cc.orig	2011-07-07 00:31:27.000000000 +0000
+++ examples/reverse_worker.cc
@@ -46,6 +46,7 @@
 #include <cstring>
 #include <iostream>
 #include <signal.h>
+#include "unistd.h"
 
 #include <libgearman/gearman.h>
 #include <boost/program_options.hpp>
