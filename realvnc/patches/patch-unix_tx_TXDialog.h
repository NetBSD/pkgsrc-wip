$NetBSD: patch-unix_tx_TXDialog.h,v 1.1 2012/11/12 14:32:14 thomasklausner Exp $

select() prototype.

--- unix/tx/TXDialog.h.orig	2006-05-15 16:56:20.000000000 +0000
+++ unix/tx/TXDialog.h
@@ -30,6 +30,7 @@
 
 #include "TXWindow.h"
 #include <errno.h>
+#include <sys/select.h>
 
 class TXDialog : public TXWindow, public TXDeleteWindowCallback {
 public:
