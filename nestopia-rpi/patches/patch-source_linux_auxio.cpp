$NetBSD: patch-source_linux_auxio.cpp,v 1.1 2014/11/02 08:36:13 nsloss Exp $

Remove dependency on gtk.
--- source/linux/auxio.cpp.orig	2008-06-25 02:41:55.000000000 +0000
+++ source/linux/auxio.cpp
@@ -26,28 +26,29 @@
 #include "unzip.h"
 
 extern "C" {
-#include <gtk/gtk.h>
+//#include <gtk/gtk.h>
 
 #include "7zCrc.h"
 #include "7zIn.h"
 #include "7zExtract.h"
 #include "7zAlloc.h"
 
-#include "interface.h"
-#include "support.h"
-#include "callbacks.h"
+//#include "interface.h"
+//#include "support.h"
+//#include "callbacks.h"
 }
 
 #define MAX_ITEMS	(512)
 
 extern Nes::Api::Emulator emulator;
-extern GtkWidget *mainwindow;
+//extern GtkWidget *mainwindow;
 extern char rootname[512];
 
 static std::ifstream *moviePlayFile, *fdsBiosFile, *nstDBFile;
 static std::ofstream *movieRecFile;
 
 static bool run_picker, cancelled;
+#if 0
 static GtkWidget *filepicker, *tree;
 static GtkTreeStore *treestore;
 static GtkTreeIter treeiters[MAX_ITEMS];
@@ -90,6 +91,7 @@ static gint check_list_double(GtkWidget 
 
 	return FALSE;
 }
+#endif
 
 void auxio_init(void)
 {
@@ -99,6 +101,7 @@ void auxio_init(void)
 	nstDBFile = NULL;
 }
 
+#if 0
 void auxio_do_state_save(void)
 {
 	Nes::Api::Machine machine( emulator );
@@ -264,6 +267,7 @@ void auxio_do_movie_load(void)
 
 	gtk_widget_destroy(dialog);
 }
+#endif
 
 void auxio_do_movie_stop(void)
 {
@@ -618,6 +622,7 @@ int auxio_load_archive(const char *filen
 
 			return auxio_load_archive(filename, dataout, datasize, dataoffset, fname, NULL); 
 		}
+		#if 0
 		else	// multiple files we can handle found, give the user a choice
 		{
 			int sel;
@@ -694,6 +699,7 @@ int auxio_load_archive(const char *filen
 				return auxio_load_archive(filename, dataout, datasize, dataoffset, fname, NULL); 
 			}
 		}
+		#endif
 	}
 
 	return 0;
