$NetBSD: patch-editors_sc-ide_widgets_code__editor_autocompleter.cpp,v 1.1 2014/09/06 22:22:36 thomasklausner Exp $

QGtkStyle is not a public symbol.

--- editors/sc-ide/widgets/code_editor/autocompleter.cpp.orig	2013-11-27 12:54:02.000000000 +0000
+++ editors/sc-ide/widgets/code_editor/autocompleter.cpp
@@ -187,24 +187,10 @@ public:
         mLabel->setTextFormat( Qt::RichText );
         mLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
 
-#ifdef Q_WS_X11
-        QStyle *style = this->style();
-        if (QProxyStyle *proxyStyle = qobject_cast<QProxyStyle*>(style))
-            style = proxyStyle->baseStyle();
-        if ( qobject_cast<QGtkStyle*>(style) ) {
-            QPalette p;
-            p.setColor( QPalette::Window, QColor(255, 255, 220) );
-            p.setColor( QPalette::WindowText, Qt::black );
-            setPalette(p);
-        }
-        else
-#endif
-        {
-            QPalette p( palette() );
-            p.setColor( QPalette::Window, p.color(QPalette::ToolTipBase) );
-            setPalette(p);
-            mLabel->setForegroundRole(QPalette::ToolTipText);
-        }
+        QPalette p( palette() );
+        p.setColor( QPalette::Window, p.color(QPalette::ToolTipBase) );
+        setPalette(p);
+        mLabel->setForegroundRole(QPalette::ToolTipText);
     }
 
     void showMethod( const AutoCompleter::MethodCall & methodCall,
