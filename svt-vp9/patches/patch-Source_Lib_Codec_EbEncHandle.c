$NetBSD$

Avoid the need to port cpu-pinning code designed for linux

--- Source/Lib/Codec/EbEncHandle.c.orig	2020-10-30 01:51:10.000000000 +0000
+++ Source/Lib/Codec/EbEncHandle.c
@@ -378,7 +378,7 @@ EbErrorType init_thread_managment_params
     // Initialize eb_vp9_group_affinity structure with Current thread info
     GetThreadGroupAffinity(GetCurrentThread(), &eb_vp9_group_affinity);
     eb_vp9_num_groups = (uint8_t)GetActiveProcessorGroupCount();
-#else
+#elif __linux__
     const char* PROCESSORID = "processor";
     const char* PHYSICALID = "physical id";
     int processor_id_len = EB_STRLEN(PROCESSORID, 128);
