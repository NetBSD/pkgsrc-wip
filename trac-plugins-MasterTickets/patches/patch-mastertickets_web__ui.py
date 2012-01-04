$NetBSD: patch-mastertickets_web__ui.py,v 1.1 2012/01/04 21:43:54 lexort Exp $

linkifying ticket numbers fails due to a templating issue that I do not understand, but
cribbed from:

http://trac-hacks.org/ticket/7936
https://github.com/thmo/trac-mastertickets/commit/47a7aee54553fb718c376cfa9d7de4389a391e33

--- mastertickets/web_ui.py.orig	2011-11-15 17:27:44.000000000 +0000
+++ mastertickets/web_ui.py
@@ -32,7 +32,7 @@ class MasterTicketsModule(Component):
     use_gs = BoolOption('mastertickets', 'use_gs', default=False,
                         doc='If enabled, use ghostscript to produce nicer output.')
     
-    FIELD_XPATH = 'div[@id="ticket"]/table[@class="properties"]/td[@headers="h_%s"]/text()'
+    FIELD_XPATH = '//div[@id="ticket"]/table[@class="properties"]//td[@headers="h_%s"]/text()'
     fields = set(['blocking', 'blockedby'])
     
     # IRequestFilter methods
