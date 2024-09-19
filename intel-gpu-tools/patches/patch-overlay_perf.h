$NetBSD$

--- overlay/perf.h.orig	2015-08-06 15:22:11.000000000 +0000
+++ overlay/perf.h
@@ -1,7 +1,39 @@
 #ifndef I915_PERF_H
 #define I915_PERF_H
 
+#ifdef __linux__
 #include <linux/perf_event.h>
+#else
+/* stubs to make it compile */
+#define PERF_TYPE_TRACEPOINT 0
+#define PERF_FORMAT_ID 0
+#define PERF_RECORD_SAMPLE 0
+#define PERF_SAMPLE_RAW 0
+#define PERF_SAMPLE_TID 0
+#define PERF_SAMPLE_TIME 0
+#define PERF_SAMPLE_STREAM_ID 0
+#define PERF_FORMAT_GROUP 0
+#define PERF_EVENT_IOC_SET_OUTPUT 0
+#define PERF_FORMAT_TOTAL_TIME_ENABLED 0
+struct perf_event_attr {
+uint32_t type;
+uint32_t size;
+uint64_t config;
+uint64_t read_format;
+uint64_t sample_type;
+uint64_t sample_period;
+uint8_t exclude_guest;
+};
+struct perf_event_header {
+uint32_t  type;
+uint16_t misc;
+uint16_t size;
+};
+struct perf_event_mmap_page {
+uint64_t data_head;
+uint64_t data_tail;
+};
+#endif
 
 #define I915_SAMPLE_BUSY	0
 #define I915_SAMPLE_WAIT	1
