$NetBSD$

--- support/examples/transactionlistener/transactionlistener.pro.orig	2016-07-31 09:44:06.521154782 +0000
+++ support/examples/transactionlistener/transactionlistener.pro
@@ -6,4 +6,5 @@ TEMPLATE    = lib
 HEADERS     = TransactionListenerPlugin.h
 SOURCES     = TransactionListenerPlugin.cpp
 DESTDIR     = ../../../plugins
-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}gui
+LIBS += ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL} \
+	../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}gui$${RLIBPOSTDLL}
