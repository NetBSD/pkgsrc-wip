$NetBSD$

Maybe a no-op in progress to mutable device path

--- gptcl.cc.orig	2022-04-14 19:17:12.000000000 -0400
+++ gptcl.cc
@@ -65,7 +65,7 @@
 // 8 = disk replication operation (-R) failed
 int GPTDataCL::DoOptions(int argc, char* argv[]) {
    GPTData secondDevice;
-   int opt, numOptions = 0, saveData = 0, neverSaveData = 0;
+   int opt, saveData = 0, neverSaveData = 0;
    int partNum = 0, newPartNum = -1, saveNonGPT = 1, retval = 0, pretend = 0;
    int byteSwapPartNum = 0;
    uint64_t low, high, startSector, endSector, sSize, mainTableLBA;
@@ -151,7 +151,6 @@
          default:
             break;
       } // switch
-      numOptions++;
    } // while
 
    // Assume first non-option argument is the device filename....
@@ -161,7 +160,8 @@
    if (device != NULL) {
       JustLooking(); // reset as necessary
       BeQuiet(); // Tell called functions to be less verbose & interactive
-      if (LoadPartitions((string) device)) {
+      string devstr = device;
+      if (LoadPartitions(devstr)) {
          if ((WhichWasUsed() == use_mbr) || (WhichWasUsed() == use_bsd))
             saveNonGPT = 0; // flag so we don't overwrite unless directed to do so
          sSize = GetBlockSize();
