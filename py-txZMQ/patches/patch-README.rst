$NetBSD$

Encoding of file not defined, gives read error during installation
with python-3.x.

--- README.rst.orig	2014-04-17 21:00:47.000000000 +0000
+++ README.rst
@@ -16,10 +16,10 @@ Twisted bindings for 0MQ
 Introduction
 ------------
 
-txZMQ allows to integrate easily `ØMQ <http://zeromq.org>`_ sockets into
+txZMQ allows to integrate easily `zeroMQ <http://zeromq.org>`_ sockets into
 Twisted event loop (reactor).
 
-txZMQ supports both CPython and PyPy and ØMQ library version 2.2.x or 3.2.x.
+txZMQ supports both CPython and PyPy and zeroMQ library version 2.2.x or 3.2.x.
 Preliminary support for Python 3.x is available.
 
 Documentation is available at `ReadTheDocs <http://txzmq.readthedocs.org>`_ and
@@ -31,7 +31,7 @@ Requirements
 
 C library required:
 
-* ØMQ library 2.2.x or 3.2.x
+* zeroMQ library 2.2.x or 3.2.x
 
 Python packages required:
 
@@ -46,8 +46,8 @@ txZMQ introduces support for general 0MQ
 that can do basic event loop integration, sending-receiving messages in
 non-blocking manner, scatter-gather for multipart messages.
 
-txZMQ uses ØMQ APIs to get file descriptor that is used to signal pending
-actions from ØMQ library IO thread running in separate thread. This is used in
+txZMQ uses zeroMQ APIs to get file descriptor that is used to signal pending
+actions from zeroMQ library IO thread running in separate thread. This is used in
 a custom file descriptor reader, which is then added to the Twisted reactor.
 
 
