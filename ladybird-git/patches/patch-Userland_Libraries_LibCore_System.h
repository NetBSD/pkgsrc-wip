$NetBSD$

Fix coredump on NetBSD.
https://github.com/SerenityOS/serenity/issues/23375

--- Userland/Libraries/LibCore/System.h.orig	2024-05-09 21:15:38.476631953 +0000
+++ Userland/Libraries/LibCore/System.h
@@ -263,7 +263,7 @@ private:
     }
 
     struct AddrInfoDeleter {
-        void operator()(struct addrinfo* ptr) { ::freeaddrinfo(ptr); }
+        void operator()(struct addrinfo* ptr) { if (ptr) ::freeaddrinfo(ptr); }
     };
 
     Vector<struct addrinfo> m_addresses {};
