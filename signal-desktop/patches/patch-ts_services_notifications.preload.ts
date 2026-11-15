$NetBSD$

* Add Free- and NetBSD support

--- ts/services/notifications.preload.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/services/notifications.preload.ts
@@ -277,7 +277,7 @@ export class NotificationService extends
       this.#lastShown = { notification: null, data };
     } else {
       const notification = new window.Notification(title, {
-        body: OS.isLinux() ? filterNotificationBody(body) : body,
+        body: (OS.isLinux() || OS.isFreeBSD() || OS.isNetBSD()) ? filterNotificationBody(body) : body,
         icon: iconUrl ?? undefined,
         silent: true,
         tag: messageId,
