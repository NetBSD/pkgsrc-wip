$NetBSD$

Include the missed out utility header.

--- src/netbsd/btop_collect.cpp.orig	2024-08-05 06:52:28.642345988 +0000
+++ src/netbsd/btop_collect.cpp
@@ -64,6 +64,7 @@ tab-size = 4
 #include <regex>
 #include <string>
 #include <memory>
+#include <utility>
 
 #include "../btop_config.hpp"
 #include "../btop_shared.hpp"
