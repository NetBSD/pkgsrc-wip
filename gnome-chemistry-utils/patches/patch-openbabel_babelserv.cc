$NetBSD: patch-openbabel_babelserv.cc,v 1.2 2011/03/15 19:16:03 ryo-on Exp $

* For the platform that does not support POLLRDHUP. This is workaround.

--- openbabel/babelserv.cc.orig	2011-02-20 06:40:58.000000000 +0000
+++ openbabel/babelserv.cc
@@ -112,7 +112,11 @@ int main (int argc, char *argv[])
 					return -5;
 				}
 				_fds.fd = service_socket;
+#ifdef POLLRDHUP
 				_fds.events = POLLIN | POLLRDHUP;
+#else
+				_fds.events = POLLIN;
+#endif
 				_fds.revents = 0;
 				fds.push_back (_fds);
 				sockets[service_socket] = new BabelSocket (service_socket);
@@ -127,11 +131,13 @@ int main (int argc, char *argv[])
 						deleted.insert (i);
 					}
 				}
+#ifdef POLLRDHUP
 				if (fds[i].revents & POLLRDHUP) {
 					delete sockets[fds[i].fd];
 					sockets.erase (fds[i].fd);
 					deleted.insert (i);
 				}
+#endif
 				fds[i].revents = 0;
 			}
 			// remove closed sockets
