$NetBSD$

Fix boost 1.87 compatibility.
https://github.com/prusa3d/PrusaSlicer/issues/13799

--- src/slic3r/GUI/FirmwareDialog.cpp.orig	2025-04-06 03:05:16.783171575 +0000
+++ src/slic3r/GUI/FirmwareDialog.cpp
@@ -429,7 +429,7 @@ void FirmwareDialog::priv::avr109_wait_f
 
 void FirmwareDialog::priv::avr109_reboot(const SerialPortInfo &port)
 {
-	asio::io_service io;
+	asio::io_context io;
 	Serial serial(io, port.port, 1200);
 	std::this_thread::sleep_for(std::chrono::milliseconds(50));
 }
