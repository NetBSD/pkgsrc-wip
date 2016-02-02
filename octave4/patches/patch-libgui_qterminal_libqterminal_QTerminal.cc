$NetBSD$

Changes for compiling with Qt5 instead of Qt4

--- libgui/qterminal/libqterminal/QTerminal.cc.orig	2015-05-23 14:21:53.000000000 +0000
+++ libgui/qterminal/libqterminal/QTerminal.cc
@@ -144,10 +144,10 @@ QTerminal::notice_settings (const QSetti
     copy = QKeySequence::Copy; // settings->value () does not work!
 
   //  dis- or enable extra interrupt action
-  QKeySequence ctrl;
+  Qt::KeyboardModifiers ctrl;
   ctrl = Qt::ControlModifier;
 
-  bool extra_ir_action = (copy != QKeySequence (ctrl + Qt::Key_C));
+  bool extra_ir_action = (copy != QKeySequence (ctrl | Qt::Key_C));
 
   _interrupt_action->setEnabled (extra_ir_action);
   has_extra_interrupt (extra_ir_action);
