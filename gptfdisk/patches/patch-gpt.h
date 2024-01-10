$NetBSD$

Mutable device path prototyped

--- gpt.h.orig	2022-04-14 23:17:12.000000000 +0000
+++ gpt.h
@@ -114,7 +114,7 @@ public:
    int LoadMBR(const std::string & f) {return protectiveMBR.ReadMBRData(f);}
    int WriteProtectiveMBR(void) {return protectiveMBR.WriteMBRData(&myDisk);}
    void PartitionScan(void);
-   int LoadPartitions(const std::string & deviceFilename);
+   int LoadPartitions(std::string & deviceFilename);
    int ForceLoadGPTData(void);
    int LoadMainTable(void);
    int LoadSecondTableAsMain(void);
