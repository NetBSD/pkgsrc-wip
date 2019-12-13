$NetBSD$

Parameter for FatalError() must be of type char*, not std::string.
Upstream Ticket #37.

--- src/m_events.cc.orig	2019-12-13 10:47:22.000000000 +0000
+++ src/m_events.cc
@@ -868,7 +868,7 @@ static void M_AddOperationMenu(std::stri
 {
 	if (menu->size() < 2)
 	{
-		FatalError("operations.cfg: no %s items.\n", context);
+		FatalError("operations.cfg: no %s items.\n", context.c_str());
 		return;
 	}
 
