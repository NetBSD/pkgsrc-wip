$NetBSD$

1. Pickup LANG/LC_MESSAGE from environment.
2. Disable multiprocess window support. Refer PR 53273

Original patch from ryoon, imported from www/firefox

--- mozilla-release/browser/app/profile/firefox.js.orig	2018-11-16 08:40:07.000000000 +0000
+++ mozilla-release/browser/app/profile/firefox.js
@@ -1796,3 +1796,9 @@ pref("toolkit.coverage.endpoint.base", "
 #if defined(NIGHTLY_BUILD) && defined(MOZ_LIBPRIO)
 pref("prio.enabled", true);
 #endif
+
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Disable multiprocess window support. Workaround for PR 53273.
+pref("browser.tabs.remote.autostart", false);
