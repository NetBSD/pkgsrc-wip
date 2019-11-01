$NetBSD$

Upstream commit b811bd2172bc9796f42b87996f455d4e5e4382ba
Missing include.

--- src/nix/main.cc~
+++ src/nix/main.cc
@@ -15,6 +15,7 @@
 #include <sys/socket.h>
 #include <ifaddrs.h>
 #include <netdb.h>
+#include <netinet/in.h>
 
 extern std::string chrootHelperName;
 
