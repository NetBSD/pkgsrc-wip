$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/resources/pdf/pdf_viewer.ts.orig	2024-10-18 12:34:02.144941800 +0000
+++ chrome/browser/resources/pdf/pdf_viewer.ts
@@ -1012,7 +1012,15 @@ export class PdfViewerElement extends Pd
       dataArray = [result.dataToSave];
     }
 
+    const a = document.createElement('a');
+    a.download = this.attachments_[index].name;
     const blob = new Blob(dataArray);
+    // <if expr="not _google_chrome">
+    a.href = URL.createObjectURL(blob);
+    a.click();
+    URL.revokeObjectURL(a.href);
+    // </if>
+    // <if expr="_google_chrome">
     const fileName = this.attachments_[index].name;
     chrome.fileSystem.chooseEntry(
         {type: 'saveFile', suggestedName: fileName},
@@ -1034,6 +1042,7 @@ export class PdfViewerElement extends Pd
             // </if>
           });
         });
+    // </if>
   }
 
   /**
@@ -1157,7 +1166,15 @@ export class PdfViewerElement extends Pd
     }
 
     // Create blob before callback to avoid race condition.
+    const a = document.createElement('a');
+    a.download = fileName;
     const blob = new Blob([result.dataToSave], {type: 'application/pdf'});
+    // <if expr="not _google_chrome">
+    a.href = URL.createObjectURL(blob);
+    a.click();
+    URL.revokeObjectURL(a.href);
+    // </if>
+    // <if expr="_google_chrome">
     chrome.fileSystem.chooseEntry(
         {
           type: 'saveFile',
@@ -1182,6 +1199,7 @@ export class PdfViewerElement extends Pd
             // </if>
           });
         });
+    // </if>
 
     // <if expr="enable_pdf_ink2">
     // Ink2 doesn't need to exit annotation mode after save.
