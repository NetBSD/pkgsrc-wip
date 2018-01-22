$NetBSD$

<stdlib.h> for exit()
unused variables

--- src/epoll.c.orig	2016-12-20 21:20:05.000000000 +0000
+++ src/epoll.c
@@ -11,6 +11,7 @@
 #include <signal.h>
 #include <stdio.h>
 #include <string.h>
+#include <stdlib.h>
 
 #if 1
 int epoll_create(int size)
@@ -51,7 +52,6 @@ epoll_kevent_set(int fd, uintptr_t ident
 static int
 epoll_ctl_add(int fd, int fd2, struct epoll_event *ev)
 {
-	struct kevent kev;
 	int ret = 0;
 	if(ev->events & EPOLLIN) {
 		ret = epoll_kevent_set(fd, fd2, EVFILT_READ, EV_ADD, 0, 0, ev->data.ptr);
@@ -75,7 +75,8 @@ epoll_ctl_del(int fd, int fd2, struct ep
 	// TODO: Check if event exist before attemt to delete. Is there an
 	// API for that or do we need to keep track of <ident,filter> events
 	// we added to the queue?
-	return 0;
+	ret = 0;
+	return ret;
 }
 
 int
@@ -94,16 +95,16 @@ epoll_ctl(int fd, int op, int fd2, struc
 			ret = epoll_ctl_del(fd, fd2, ev);
 		}
 	} else if (op == EPOLL_CTL_MOD) {
-		if(ev->events & EPOLLIN && ev->events & EPOLLOUT) {
+		if((ev->events & EPOLLIN) && (ev->events & EPOLLOUT)) {
 			// Adding both EVFILT_READ and EVFILT_WRITE
 			// Existing events will be modified.
 			ret = epoll_ctl_add(fd, fd2, ev);
-		} else if(ev->events & EPOLLOUT == 0) {
+		} else if((ev->events & EPOLLOUT) == 0) {
 			// Is it OK to assume this?
 			ret = epoll_kevent_set(fd, fd2, EVFILT_WRITE, EV_DELETE, 0, 0, 0);
 			// Returns -1 if event does not exist so ignore return value for now.
 			ret = 0;
-		} else if(ev->events & EPOLLIN == 0) {
+		} else if((ev->events & EPOLLIN) == 0) {
 			// Is it OK to assume this?
 			ret = epoll_kevent_set(fd, fd2, EVFILT_READ, EV_DELETE, 0, 0, 0);
 			// Returns -1 if event does not exist so ignore return value for now.
@@ -194,7 +195,7 @@ epoll_wait(int fd, struct epoll_event *e
 			events |= EPOLLHUP;
 		}
 		ev[i].events = events;
-		ev[i].data.ptr = evlist[i].udata;
+		ev[i].data.ptr = (void *) evlist[i].udata;
 	}
 	return ret;
 }
