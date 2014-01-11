$NetBSD: patch-Swiften_EventLoop_EventLoop.cpp,v 1.1 2014/01/11 15:27:24 thomasklausner Exp $

Fix build with latest boost and clang.

--- Swiften/EventLoop/EventLoop.cpp.orig	2012-12-22 12:23:59.000000000 +0000
+++ Swiften/EventLoop/EventLoop.cpp
@@ -47,7 +47,7 @@ void EventLoop::handleEvent(const Event&
 
 	bool doCallback = false;
 	{
-		boost::lock_guard<boost::mutex> lock(eventsMutex_);
+		std::lock_guard<boost::mutex> lock(eventsMutex_);
 		std::list<Event>::iterator i = std::find(events_.begin(), events_.end(), event);
 		if (i != events_.end()) {
 			doCallback = true;
@@ -72,7 +72,7 @@ void EventLoop::handleEvent(const Event&
 void EventLoop::postEvent(boost::function<void ()> callback, boost::shared_ptr<EventOwner> owner) {
 	Event event(owner, callback);
 	{
-		boost::lock_guard<boost::mutex> lock(eventsMutex_);
+		std::lock_guard<boost::mutex> lock(eventsMutex_);
 		event.id = nextEventID_;
 		nextEventID_++;
 		events_.push_back(event);
@@ -82,7 +82,7 @@ void EventLoop::postEvent(boost::functio
 }
 
 void EventLoop::removeEventsFromOwner(boost::shared_ptr<EventOwner> owner) {
-		boost::lock_guard<boost::mutex> lock(eventsMutex_);
+		std::lock_guard<boost::mutex> lock(eventsMutex_);
 		events_.remove_if(HasOwner(owner));
 }
 
