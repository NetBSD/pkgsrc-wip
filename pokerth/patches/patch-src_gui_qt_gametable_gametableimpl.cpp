$NetBSD$

--- src/gui/qt/gametable/gametableimpl.cpp.orig	2017-08-27 13:02:45.836007109 +0000
+++ src/gui/qt/gametable/gametableimpl.cpp
@@ -3859,7 +3859,7 @@ void gameTableImpl::triggerVoteOnKick(in
 	int playerCount = static_cast<int>(seatList->size());
 	if (id < playerCount) {
 		PlayerListIterator pos = seatList->begin();
-		advance(pos, id);
+		std::advance(pos, id);
 		myStartWindow->getSession()->startVoteKickPlayer((*pos)->getMyUniqueID());
 	}
 }
