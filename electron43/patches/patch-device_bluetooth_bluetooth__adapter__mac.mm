$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- device/bluetooth/bluetooth_adapter_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ device/bluetooth/bluetooth_adapter_mac.mm
@@ -38,7 +38,9 @@
 #include "device/bluetooth/bluetooth_discovery_session_outcome.h"
 #include "device/bluetooth/bluetooth_socket_mac.h"
 #include "device/bluetooth/public/cpp/bluetooth_address.h"
+#include "electron/mas.h"
 
+#if !IS_MAS_BUILD()
 extern "C" {
 // Undocumented IOBluetooth Preference API [1]. Used by `blueutil` [2] and
 // `Karabiner` [3] to programmatically control the Bluetooth state. Calling the
@@ -52,6 +54,7 @@ extern "C" {
 // [4] https://support.apple.com/kb/PH25091
 void IOBluetoothPreferenceSetControllerPowerState(int state);
 }
+#endif
 
 // A simple helper class that forwards any Bluetooth device connect notification
 // to its wrapped |_adapter|.
@@ -161,8 +164,10 @@ BluetoothAdapterMac::BluetoothAdapterMac
     : controller_state_function_(
           base::BindRepeating(&BluetoothAdapterMac::GetHostControllerState,
                               base::Unretained(this))),
+#if !IS_MAS_BUILD()
       power_state_function_(
           base::BindRepeating(IOBluetoothPreferenceSetControllerPowerState)),
+#endif
       device_paired_status_callback_(
           base::BindRepeating(&IsDeviceSystemPaired)) {
 }
@@ -313,8 +318,12 @@ base::WeakPtr<BluetoothAdapter> Bluetoot
 }
 
 bool BluetoothAdapterMac::SetPoweredImpl(bool powered) {
+#if !IS_MAS_BUILD()
   power_state_function_.Run(base::strict_cast<int>(powered));
   return true;
+#else
+  return false;
+#endif
 }
 
 base::WeakPtr<BluetoothLowEnergyAdapterApple>
