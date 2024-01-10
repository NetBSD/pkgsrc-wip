$NetBSD$

Switch from chosen block to raw (character) device automagically for the user on NetBSD

--- gpt.cc.orig	2022-04-14 23:17:12.000000000 +0000
+++ gpt.cc
@@ -828,11 +828,25 @@ void GPTData::PartitionScan(void) {
 } // GPTData::PartitionScan()
 
 // Read GPT data from a disk.
-int GPTData::LoadPartitions(const string & deviceFilename) {
+int GPTData::LoadPartitions(string & deviceFilename) {
    BSDData bsdDisklabel;
    int err, allOK = 1;
    MBRValidity mbrState;
 
+#ifdef		__NetBSD__	// Always use character device if given block
+   // Convert /dev/wd0 to /dev/rwd0
+   size_t start_pos = deviceFilename.find("/dev/");
+   if (start_pos == 0)
+   {
+      start_pos = deviceFilename.find("/dev/r");
+      if (start_pos == std::string::npos)
+      {
+         deviceFilename.replace(0, 5, string("/dev/r"));
+         cout << "Using raw device at " << deviceFilename.c_str() << "\n";
+      }
+   }
+#endif	//	__NetBSD__
+
    if (myDisk.OpenForRead(deviceFilename)) {
       err = myDisk.OpenForWrite(deviceFilename);
       if ((err == 0) && (!justLooking)) {
