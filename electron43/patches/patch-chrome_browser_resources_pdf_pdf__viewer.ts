$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/resources/pdf/pdf_viewer.ts.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/resources/pdf/pdf_viewer.ts
@@ -1086,28 +1086,27 @@ export class PdfViewerElement extends Pd
       dataArray = [result.dataToSave];
     }
 
-    const blob = new Blob(dataArray);
     const fileName = this.attachments_[index].name;
-    chrome.fileSystem.chooseEntry(
-        {type: 'saveFile', suggestedName: fileName},
-        (entry?: FileSystemFileEntry) => {
-          if (chrome.runtime.lastError) {
-            if (chrome.runtime.lastError.message !== 'User cancelled') {
-              console.error(
-                  'chrome.fileSystem.chooseEntry failed: ' +
-                  chrome.runtime.lastError.message);
-            }
-            return;
-          }
-          entry!.createWriter((writer: FileWriter) => {
-            writer.write(blob);
-            // <if expr="enable_ink">
-            // Unblock closing the window now that the user has saved
-            // successfully.
-            this.setShowBeforeUnloadDialog_(false);
-            // </if>
-          });
-        });
+    const blob = new Blob(dataArray);
+
+    try {
+      const fileHandle = await window.showSaveFilePicker({
+        suggestedName: fileName,
+      });
+
+      const writable = await fileHandle.createWritable();
+      await writable.write(blob);
+      await writable.close();
+      // <if expr="enable_ink">
+      // Unblock closing the window now that the user has saved
+      // successfully.
+      this.setShowBeforeUnloadDialog_(false);
+      // </if>
+    } catch (error: any) {
+      if (error.name !== 'AbortError') {
+        console.error('window.showSaveFilePicker failed: ' + error);
+      }
+    }
   }
 
   /**
@@ -1298,36 +1297,33 @@ export class PdfViewerElement extends Pd
       fileName = fileName + '.pdf';
     }
 
-    // Create blob before callback to avoid race condition.
     const blob = new Blob([result.dataToSave], {type: 'application/pdf'});
-    chrome.fileSystem.chooseEntry(
-        {
-          type: 'saveFile',
-          accepts: [{description: '*.pdf', extensions: ['pdf']}],
-          suggestedName: fileName,
-        },
-        (entry?: FileSystemFileEntry) => {
-          if (chrome.runtime.lastError) {
-            if (chrome.runtime.lastError.message !== 'User cancelled') {
-              console.error(
-                  'chrome.fileSystem.chooseEntry failed: ' +
-                  chrome.runtime.lastError.message);
-            }
-            return;
-          }
-          entry!.createWriter((writer: FileWriter) => {
-            writer.write(blob);
-            // <if expr="enable_ink or enable_pdf_ink2">
-            // Unblock closing the window now that the user has saved
-            // successfully.
-            this.setShowBeforeUnloadDialog_(false);
-            // </if>
-            // <if expr="enable_pdf_ink2">
-            this.hasSavedEdits_ =
-                this.hasSavedEdits_ || requestType === SaveRequestType.EDITED;
-            // </if>
-          });
-        });
+    try {
+      const fileHandle = await window.showSaveFilePicker({
+        suggestedName: fileName,
+        types: [{
+          description: 'PDF Files',
+          accept: { 'application/pdf': ['.pdf'] },
+        }],
+      });
+
+      const writable = await fileHandle.createWritable();
+      await writable.write(blob);
+      await writable.close();
+      // <if expr="enable_ink or enable_pdf_ink2">
+      // Unblock closing the window now that the user has saved
+      // successfully.
+      this.setShowBeforeUnloadDialog_(false);
+      // </if>
+      // <if expr="enable_pdf_ink2">
+      this.hasSavedEdits_ =
+        this.hasSavedEdits_ || requestType === SaveRequestType.EDITED;
+      // </if>
+    } catch (error: any) {
+      if (error.name !== 'AbortError') {
+        console.error('window.showSaveFilePicker failed: ' + error);
+      }
+    }
 
     // <if expr="enable_pdf_ink2">
     // Ink2 doesn't need to exit annotation mode after save.
@@ -1474,6 +1470,9 @@ declare global {
   interface HTMLElementTagNameMap {
     'pdf-viewer': PdfViewerElement;
   }
+  interface Window {
+    showSaveFilePicker(opts: unknown): Promise<FileSystemFileHandle>;
+  }
 }
 
 customElements.define(PdfViewerElement.is, PdfViewerElement);
