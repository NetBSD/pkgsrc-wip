$NetBSD$

--- tests/unittests/test_all_stages.py.orig	2026-07-27 14:56:24.000000000 +0000
+++ tests/unittests/test_all_stages.py
@@ -5,9 +5,11 @@ from unittest import mock
 from threading import Thread
 from unittest import mock
 
+import pytest
+
 from cloudinit import socket as ci_socket
+from cloudinit.distros import uses_systemd
 
-
 class Sync:
     """A device to send and receive synchronization messages
 
@@ -47,6 +49,7 @@ class Timeout:
         signal.alarm(0)
 
 
+@pytest.mark.skipif(not uses_systemd(), reason="Tests comms with systemd")
 def test_all_stages_times_out(tmp_path, socket_attrs):
     """Verify that no "start" makes the protocol block"""
     with mock.patch.object(
@@ -70,6 +73,7 @@ def test_all_stages_times_out(tmp_path, socket_attrs):
             raise AssertionError("Expected the thing to timeout!")
 
 
+@pytest.mark.skipif(not uses_systemd(), reason="Tests comms with systemd")
 def test_all_stages(tmp_path, socket_attrs):
     """Verify that a socket can store "start" messages
 
@@ -108,6 +112,7 @@ def test_all_stages(tmp_path, socket_attrs):
         assert expected.format("third").encode() == third.receive()
 
 
+@pytest.mark.skipif(not uses_systemd(), reason="Tests comms with systemd")
 def test_all_stages_threaded(tmp_path, socket_attrs):
     """Verify that arbitrary "start" order works"""
 
@@ -181,6 +186,7 @@ def test_all_stages_threaded(tmp_path, socket_attrs):
         assert expected.format("fifth").encode() == sync_storage[5].receive()
 
 
+@pytest.mark.skipif(not uses_systemd(), reason="Tests comms with systemd")
 def test_all_stages_exception(tmp_path, socket_attrs):
     """Verify that exceptions log messages produce a valid warning message"""
     with mock.patch.object(
