$NetBSD: patch-openbabel_babelserv.cc,v 1.1 2011/03/13 11:00:17 ryo-on Exp $

* This is workaround.

--- openbabel/babelserv.cc.orig	2011-02-20 06:40:58.000000000 +0000
+++ openbabel/babelserv.cc
@@ -112,7 +112,7 @@ int main (int argc, char *argv[])
 					return -5;
 				}
 				_fds.fd = service_socket;
-				_fds.events = POLLIN | POLLRDHUP;
+				_fds.events = POLLIN | POLLHUP;
 				_fds.revents = 0;
 				fds.push_back (_fds);
 				sockets[service_socket] = new BabelSocket (service_socket);
@@ -127,7 +127,7 @@ int main (int argc, char *argv[])
 						deleted.insert (i);
 					}
 				}
-				if (fds[i].revents & POLLRDHUP) {
+				if (fds[i].revents & POLLHUP) {
 					delete sockets[fds[i].fd];
 					sockets.erase (fds[i].fd);
 					deleted.insert (i);
