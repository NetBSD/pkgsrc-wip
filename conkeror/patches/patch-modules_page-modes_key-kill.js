$NetBSD$

From: John Foerch <jjfoerch@earthlink.net>
Date: Thu, 10 Nov 2016 01:21:34 +0000 (-0500)
Subject: key-kill.js: eliminate a strict mode warning
X-Git-Url: http://repo.or.cz/conkeror.git/commitdiff_plain/65fb97af472e0e91cec0a6279dfbe20e6a7715fd

key-kill.js: eliminate a strict mode warning
---

diff --git a/modules/page-modes/key-kill.js b/modules/page-modes/key-kill.js
index e426743..9f86e72 100644
--- modules/page-modes/key-kill.js
+++ modules/page-modes/key-kill.js
@@ -9,7 +9,7 @@ define_variable("key_kill_input_fields", false,
     "When true, key-kill-mode will operate in input fields and textareas.");
 
 { let mozilla_version_below_25 = version_compare(get_mozilla_version(), "25.0") < 0;
-  function key_kill_event_kill (event) {
+  var key_kill_event_kill = function key_kill_event_kill (event) {
       var elem = event.target;
       if (!key_kill_input_fields &&
           (elem instanceof Ci.nsIDOMHTMLInputElement ||
@@ -21,7 +21,7 @@ define_variable("key_kill_input_fields", false,
           event.preventDefault();
       }
       event.stopPropagation();
-  }
+  };
 }
 
 define_page_mode("key-kill-mode",
