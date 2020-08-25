$NetBSD$

--- gdbserver/linux-low.h.orig	2020-08-18 00:00:07.000000000 +0000
+++ gdbserver/linux-low.h
@@ -177,6 +177,8 @@ public:
 
   void request_interrupt () override;
 
+  int read_auxv (CORE_ADDR offset, unsigned char *myaddr, unsigned int len) override;
+  
   bool supports_read_auxv () override;
 
   int read_auxv (CORE_ADDR offset, unsigned char *myaddr,
