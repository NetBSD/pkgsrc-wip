$NetBSD$

--- plugins/Assembler/DialogAssembler.cpp.orig	2017-02-18 21:21:09.000000000 +0000
+++ plugins/Assembler/DialogAssembler.cpp
@@ -213,9 +213,11 @@ void DialogAssembler::on_buttonBox_accep
 						}
 					}
 				} else if(replacement_size==0) {
+#if 0
 					const auto stderr=process.readAllStandardError();
 					QMessageBox::warning(this, tr("Error In Code"), tr("Got zero bytes from the assembler")+
 																	(stderr.isEmpty()?"":tr(", here's what it has to say:\n\n")+stderr));
+#endif
 					return;
 				} else {
 					if(ui->keepSize->isChecked()) {
