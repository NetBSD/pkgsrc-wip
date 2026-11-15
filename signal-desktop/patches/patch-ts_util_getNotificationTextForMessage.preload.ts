$NetBSD$

* Add Free- and NetBSD support

--- ts/util/getNotificationTextForMessage.preload.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/util/getNotificationTextForMessage.preload.ts
@@ -61,7 +61,7 @@ export function getNotificationTextForMe
       });
     }
 
-    if (!window.Signal.OS.isLinux()) {
+    if (!(window.Signal.OS.isLinux() || window.Signal.OS.isFreeBSD() || window.Signal.OS.isNetBSD())) {
       return attributes.storyReaction.emoji;
     }
 
@@ -78,7 +78,7 @@ export function getNotificationTextForMe
 
   // Linux emoji support is mixed, so we disable it. (Note that this doesn't touch
   //   the `text`, which can contain emoji.)
-  const shouldIncludeEmoji = Boolean(emoji) && !window.Signal.OS.isLinux();
+  const shouldIncludeEmoji = Boolean(emoji) && !(window.Signal.OS.isLinux() || window.Signal.OS.isFreeBSD() || window.Signal.OS.isNetBSD());
   if (shouldIncludeEmoji) {
     return i18n('icu:message--getNotificationText--text-with-emoji', {
       text: result.body,
