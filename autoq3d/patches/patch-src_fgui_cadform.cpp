$NetBSD: patch-src_fgui_cadform.cpp,v 1.1 2012/09/26 22:45:13 othyro Exp $

QColor and QString needs to be called directly.

--- src/fgui/cadform.cpp.orig	2010-06-06 21:12:50.000000000 +0000
+++ src/fgui/cadform.cpp
@@ -475,9 +475,9 @@ CadForm::CadForm()
 
 
 	QPalette newPalette = palette();
-	newPalette.setColor(QPalette::Background, QColor::QColor(170,170,255));
-	newPalette.setColor(QPalette::Foreground, QColor::QColor(0,0,0));
-	newPalette.setColor(QPalette::Base, QColor::QColor(170,170,255));
+	newPalette.setColor(QPalette::Background, QColor(170,170,255));
+	newPalette.setColor(QPalette::Foreground, QColor(0,0,0));
+	newPalette.setColor(QPalette::Base, QColor(170,170,255));
 
 
 
@@ -800,7 +800,7 @@ GLApp* CadForm::newViewPort()
 	w->GLThisArea->cscalari=hcmd->cscalari;
 	w->GLThisArea->View=View;
 
-	w->setWindowTitle(QString::QString(tr("ViewPort-%1")).arg(numDoc++));w->setWindowIcon( QPixmap(ProgramPath+"images/document.png") );
+	w->setWindowTitle(QString(tr("ViewPort-%1")).arg(numDoc++));w->setWindowIcon( QPixmap(ProgramPath+"images/document.png") );
 	w->show();
 	QWidgetList windoL=ws->windowList(QWorkspace::CreationOrder);
 	if ( windoL.count()==1){
