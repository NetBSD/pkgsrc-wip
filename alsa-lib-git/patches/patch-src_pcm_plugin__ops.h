$NetBSD$

--- src/pcm/plugin_ops.h.orig	2016-02-24 08:33:29.000000000 +0000
+++ src/pcm/plugin_ops.h
@@ -21,13 +21,13 @@
 
 #ifndef SX_INLINES
 #define SX_INLINES
-static inline u_int32_t sx24(u_int32_t x)
+static inline uint32_t sx24(uint32_t x)
 {
 	if(x&0x00800000)
 		return x|0xFF000000;
 	return x&0x00FFFFFF;
 }
-static inline u_int32_t sx24s(u_int32_t x)
+static inline uint32_t sx24s(uint32_t x)
 {
 	if(x&0x00008000)
 		return x|0x000000FF;
@@ -35,10 +35,10 @@ static inline u_int32_t sx24s(u_int32_t 
 }
 #endif
 
-#define as_u8(ptr) (*(u_int8_t*)(ptr))
-#define as_u16(ptr) (*(u_int16_t*)(ptr))
-#define as_u32(ptr) (*(u_int32_t*)(ptr))
-#define as_u64(ptr) (*(u_int64_t*)(ptr))
+#define as_u8(ptr) (*(uint8_t*)(ptr))
+#define as_u16(ptr) (*(uint16_t*)(ptr))
+#define as_u32(ptr) (*(uint32_t*)(ptr))
+#define as_u64(ptr) (*(uint64_t*)(ptr))
 #define as_s8(ptr) (*(int8_t*)(ptr))
 #define as_s16(ptr) (*(int16_t*)(ptr))
 #define as_s32(ptr) (*(int32_t*)(ptr))
@@ -46,10 +46,10 @@ static inline u_int32_t sx24s(u_int32_t 
 #define as_float(ptr) (*(float_t*)(ptr))
 #define as_double(ptr) (*(double_t*)(ptr))
 
-#define as_u8c(ptr) (*(const u_int8_t*)(ptr))
-#define as_u16c(ptr) (*(const u_int16_t*)(ptr))
-#define as_u32c(ptr) (*(const u_int32_t*)(ptr))
-#define as_u64c(ptr) (*(const u_int64_t*)(ptr))
+#define as_u8c(ptr) (*(const uint8_t*)(ptr))
+#define as_u16c(ptr) (*(const uint16_t*)(ptr))
+#define as_u32c(ptr) (*(const uint32_t*)(ptr))
+#define as_u64c(ptr) (*(const uint64_t*)(ptr))
 #define as_s8c(ptr) (*(const int8_t*)(ptr))
 #define as_s16c(ptr) (*(const int16_t*)(ptr))
 #define as_s32c(ptr) (*(const int32_t*)(ptr))
@@ -57,18 +57,18 @@ static inline u_int32_t sx24s(u_int32_t 
 #define as_floatc(ptr) (*(const float_t*)(ptr))
 #define as_doublec(ptr) (*(const double_t*)(ptr))
 
-#define _get_triple_le(ptr) (*(u_int8_t*)(ptr) | (u_int32_t)*((u_int8_t*)(ptr) + 1) << 8 | (u_int32_t)*((u_int8_t*)(ptr) + 2) << 16)
-#define _get_triple_be(ptr) ((u_int32_t)*(u_int8_t*)(ptr) << 16 | (u_int32_t)*((u_int8_t*)(ptr) + 1) << 8 | *((u_int8_t*)(ptr) + 2))
+#define _get_triple_le(ptr) (*(uint8_t*)(ptr) | (uint32_t)*((uint8_t*)(ptr) + 1) << 8 | (uint32_t)*((uint8_t*)(ptr) + 2) << 16)
+#define _get_triple_be(ptr) ((uint32_t)*(uint8_t*)(ptr) << 16 | (uint32_t)*((uint8_t*)(ptr) + 1) << 8 | *((uint8_t*)(ptr) + 2))
 #define _put_triple_le(ptr,val) do { \
-	u_int8_t *_tmp = (u_int8_t *)(ptr); \
-	u_int32_t _val = (val); \
+	uint8_t *_tmp = (uint8_t *)(ptr); \
+	uint32_t _val = (val); \
 	_tmp[0] = _val; \
 	_tmp[1] = _val >> 8; \
 	_tmp[2] = _val >> 16; \
 } while(0)
 #define _put_triple_be(ptr,val) do { \
-	u_int8_t *_tmp = (u_int8_t *)(ptr); \
-	u_int32_t _val = (val); \
+	uint8_t *_tmp = (uint8_t *)(ptr); \
+	uint32_t _val = (val); \
 	_tmp[0] = _val >> 16; \
 	_tmp[1] = _val >> 8; \
 	_tmp[2] = _val; \
@@ -243,45 +243,45 @@ static void *const conv_labels[4 * 2 * 2
 #ifdef CONV_END
 while(0) {
 conv_xxx1_xxx1: as_u8(dst) = as_u8c(src); goto CONV_END;
-conv_xxx1_xx10: as_u16(dst) = (u_int16_t)as_u8c(src) << 8; goto CONV_END;
-conv_xxx1_xx01: as_u16(dst) = (u_int16_t)as_u8c(src); goto CONV_END;
-conv_xxx1_x100: as_u32(dst) = sx24((u_int32_t)as_u8c(src) << 16); goto CONV_END;
-conv_xxx1_001x: as_u32(dst) = sx24s((u_int32_t)as_u8c(src) << 8); goto CONV_END;
-conv_xxx1_1000: as_u32(dst) = (u_int32_t)as_u8c(src) << 24; goto CONV_END;
-conv_xxx1_0001: as_u32(dst) = (u_int32_t)as_u8c(src); goto CONV_END;
+conv_xxx1_xx10: as_u16(dst) = (uint16_t)as_u8c(src) << 8; goto CONV_END;
+conv_xxx1_xx01: as_u16(dst) = (uint16_t)as_u8c(src); goto CONV_END;
+conv_xxx1_x100: as_u32(dst) = sx24((uint32_t)as_u8c(src) << 16); goto CONV_END;
+conv_xxx1_001x: as_u32(dst) = sx24s((uint32_t)as_u8c(src) << 8); goto CONV_END;
+conv_xxx1_1000: as_u32(dst) = (uint32_t)as_u8c(src) << 24; goto CONV_END;
+conv_xxx1_0001: as_u32(dst) = (uint32_t)as_u8c(src); goto CONV_END;
 conv_xxx1_xxx9: as_u8(dst) = as_u8c(src) ^ 0x80; goto CONV_END;
-conv_xxx1_xx90: as_u16(dst) = (u_int16_t)(as_u8c(src) ^ 0x80) << 8; goto CONV_END;
-conv_xxx1_xx09: as_u16(dst) = (u_int16_t)(as_u8c(src) ^ 0x80); goto CONV_END;
-conv_xxx1_x900: as_u32(dst) = sx24((u_int32_t)(as_u8c(src) ^ 0x80) << 16); goto CONV_END;
-conv_xxx1_009x: as_u32(dst) = sx24s((u_int32_t)(as_u8c(src) ^ 0x80) << 8); goto CONV_END;
-conv_xxx1_9000: as_u32(dst) = (u_int32_t)(as_u8c(src) ^ 0x80) << 24; goto CONV_END;
-conv_xxx1_0009: as_u32(dst) = (u_int32_t)(as_u8c(src) ^ 0x80); goto CONV_END;
+conv_xxx1_xx90: as_u16(dst) = (uint16_t)(as_u8c(src) ^ 0x80) << 8; goto CONV_END;
+conv_xxx1_xx09: as_u16(dst) = (uint16_t)(as_u8c(src) ^ 0x80); goto CONV_END;
+conv_xxx1_x900: as_u32(dst) = sx24((uint32_t)(as_u8c(src) ^ 0x80) << 16); goto CONV_END;
+conv_xxx1_009x: as_u32(dst) = sx24s((uint32_t)(as_u8c(src) ^ 0x80) << 8); goto CONV_END;
+conv_xxx1_9000: as_u32(dst) = (uint32_t)(as_u8c(src) ^ 0x80) << 24; goto CONV_END;
+conv_xxx1_0009: as_u32(dst) = (uint32_t)(as_u8c(src) ^ 0x80); goto CONV_END;
 conv_xx12_xxx1: as_u8(dst) = as_u16c(src) >> 8; goto CONV_END;
 conv_xx12_xx12: as_u16(dst) = as_u16c(src); goto CONV_END;
 conv_xx12_xx21: as_u16(dst) = bswap_16(as_u16c(src)); goto CONV_END;
-conv_xx12_x120: as_u32(dst) = sx24((u_int32_t)as_u16c(src) << 8); goto CONV_END;
-conv_xx12_021x: as_u32(dst) = sx24s((u_int32_t)bswap_16(as_u16c(src)) << 8); goto CONV_END;
-conv_xx12_1200: as_u32(dst) = (u_int32_t)as_u16c(src) << 16; goto CONV_END;
-conv_xx12_0021: as_u32(dst) = (u_int32_t)bswap_16(as_u16c(src)); goto CONV_END;
+conv_xx12_x120: as_u32(dst) = sx24((uint32_t)as_u16c(src) << 8); goto CONV_END;
+conv_xx12_021x: as_u32(dst) = sx24s((uint32_t)bswap_16(as_u16c(src)) << 8); goto CONV_END;
+conv_xx12_1200: as_u32(dst) = (uint32_t)as_u16c(src) << 16; goto CONV_END;
+conv_xx12_0021: as_u32(dst) = (uint32_t)bswap_16(as_u16c(src)); goto CONV_END;
 conv_xx12_xxx9: as_u8(dst) = (as_u16c(src) >> 8) ^ 0x80; goto CONV_END;
 conv_xx12_xx92: as_u16(dst) = as_u16c(src) ^ 0x8000; goto CONV_END;
 conv_xx12_xx29: as_u16(dst) = bswap_16(as_u16c(src)) ^ 0x80; goto CONV_END;
-conv_xx12_x920: as_u32(dst) = sx24((u_int32_t)(as_u16c(src) ^ 0x8000) << 8); goto CONV_END;
-conv_xx12_029x: as_u32(dst) = sx24s((u_int32_t)(bswap_16(as_u16c(src)) ^ 0x80) << 8); goto CONV_END;
-conv_xx12_9200: as_u32(dst) = (u_int32_t)(as_u16c(src) ^ 0x8000) << 16; goto CONV_END;
-conv_xx12_0029: as_u32(dst) = (u_int32_t)(bswap_16(as_u16c(src)) ^ 0x80); goto CONV_END;
+conv_xx12_x920: as_u32(dst) = sx24((uint32_t)(as_u16c(src) ^ 0x8000) << 8); goto CONV_END;
+conv_xx12_029x: as_u32(dst) = sx24s((uint32_t)(bswap_16(as_u16c(src)) ^ 0x80) << 8); goto CONV_END;
+conv_xx12_9200: as_u32(dst) = (uint32_t)(as_u16c(src) ^ 0x8000) << 16; goto CONV_END;
+conv_xx12_0029: as_u32(dst) = (uint32_t)(bswap_16(as_u16c(src)) ^ 0x80); goto CONV_END;
 conv_xx12_xxx2: as_u8(dst) = as_u16c(src) & 0xff; goto CONV_END;
-conv_xx12_x210: as_u32(dst) = sx24((u_int32_t)bswap_16(as_u16c(src)) << 8); goto CONV_END;
-conv_xx12_012x: as_u32(dst) = sx24s((u_int32_t)as_u16c(src) << 8); goto CONV_END;
-conv_xx12_2100: as_u32(dst) = (u_int32_t)bswap_16(as_u16c(src)) << 16; goto CONV_END;
-conv_xx12_0012: as_u32(dst) = (u_int32_t)as_u16c(src); goto CONV_END; 
+conv_xx12_x210: as_u32(dst) = sx24((uint32_t)bswap_16(as_u16c(src)) << 8); goto CONV_END;
+conv_xx12_012x: as_u32(dst) = sx24s((uint32_t)as_u16c(src) << 8); goto CONV_END;
+conv_xx12_2100: as_u32(dst) = (uint32_t)bswap_16(as_u16c(src)) << 16; goto CONV_END;
+conv_xx12_0012: as_u32(dst) = (uint32_t)as_u16c(src); goto CONV_END; 
 conv_xx12_xxxA: as_u8(dst) = (as_u16c(src) ^ 0x80) & 0xff; goto CONV_END;
 conv_xx12_xxA1: as_u16(dst) = bswap_16(as_u16c(src) ^ 0x80); goto CONV_END;
 conv_xx12_xx1A: as_u16(dst) = as_u16c(src) ^ 0x80; goto CONV_END;
-conv_xx12_xA10: as_u32(dst) = sx24((u_int32_t)bswap_16(as_u16c(src) ^ 0x80) << 8); goto CONV_END;
-conv_xx12_01Ax: as_u32(dst) = sx24s((u_int32_t)(as_u16c(src) ^ 0x80) << 8); goto CONV_END;
-conv_xx12_A100: as_u32(dst) = (u_int32_t)bswap_16(as_u16c(src) ^ 0x80) << 16; goto CONV_END;
-conv_xx12_001A: as_u32(dst) = (u_int32_t)(as_u16c(src) ^ 0x80); goto CONV_END;
+conv_xx12_xA10: as_u32(dst) = sx24((uint32_t)bswap_16(as_u16c(src) ^ 0x80) << 8); goto CONV_END;
+conv_xx12_01Ax: as_u32(dst) = sx24s((uint32_t)(as_u16c(src) ^ 0x80) << 8); goto CONV_END;
+conv_xx12_A100: as_u32(dst) = (uint32_t)bswap_16(as_u16c(src) ^ 0x80) << 16; goto CONV_END;
+conv_xx12_001A: as_u32(dst) = (uint32_t)(as_u16c(src) ^ 0x80); goto CONV_END;
 conv_x123_xxx1: as_u8(dst) = as_u32c(src) >> 16; goto CONV_END;
 conv_x123_xx12: as_u16(dst) = as_u32c(src) >> 8; goto CONV_END;
 conv_x123_xx21: as_u16(dst) = bswap_16(as_u32c(src) >> 8); goto CONV_END;
@@ -376,8 +376,8 @@ static void *const get16_labels[4 * 2 * 
 
 #ifdef GET16_END
 while(0) {
-get16_1_10: sample = (u_int16_t)as_u8c(src) << 8; goto GET16_END;
-get16_1_90: sample = (u_int16_t)(as_u8c(src) ^ 0x80) << 8; goto GET16_END;
+get16_1_10: sample = (uint16_t)as_u8c(src) << 8; goto GET16_END;
+get16_1_90: sample = (uint16_t)(as_u8c(src) ^ 0x80) << 8; goto GET16_END;
 get16_12_12: sample = as_u16c(src); goto GET16_END;
 get16_12_92: sample = as_u16c(src) ^ 0x8000; goto GET16_END;
 get16_12_21: sample = bswap_16(as_u16c(src)); goto GET16_END;
@@ -448,26 +448,26 @@ put16_12_12: as_u16(dst) = sample; goto 
 put16_12_92: as_u16(dst) = sample ^ 0x8000; goto PUT16_END;
 put16_12_21: as_u16(dst) = bswap_16(sample); goto PUT16_END;
 put16_12_29: as_u16(dst) = bswap_16(sample) ^ 0x80; goto PUT16_END;
-put16_12_0120: as_u32(dst) = sx24((u_int32_t)sample << 8); goto PUT16_END;
-put16_12_0920: as_u32(dst) = sx24((u_int32_t)(sample ^ 0x8000) << 8); goto PUT16_END;
-put16_12_0210: as_u32(dst) = sx24s((u_int32_t)bswap_16(sample) << 8); goto PUT16_END;
-put16_12_0290: as_u32(dst) = sx24s((u_int32_t)(bswap_16(sample) ^ 0x80) << 8); goto PUT16_END;
-put16_12_1200: as_u32(dst) = (u_int32_t)sample << 16; goto PUT16_END;
-put16_12_9200: as_u32(dst) = (u_int32_t)(sample ^ 0x8000) << 16; goto PUT16_END;
-put16_12_0021: as_u32(dst) = (u_int32_t)bswap_16(sample); goto PUT16_END;
-put16_12_0029: as_u32(dst) = (u_int32_t)bswap_16(sample) ^ 0x80; goto PUT16_END;
-put16_12_120: _put_triple(dst, (u_int32_t)sample << 8); goto PUT16_END;
-put16_12_920: _put_triple(dst, (u_int32_t)(sample ^ 0x8000) << 8); goto PUT16_END;
-put16_12_021: _put_triple_s(dst, (u_int32_t)sample << 8); goto PUT16_END;
-put16_12_029: _put_triple_s(dst, (u_int32_t)(sample ^ 0x8000) << 8); goto PUT16_END;
-put16_12_120_20: _put_triple(dst, (u_int32_t)sample << 4); goto PUT16_END;
-put16_12_920_20: _put_triple(dst, (u_int32_t)(sample ^ 0x8000) << 4); goto PUT16_END;
-put16_12_021_20: _put_triple_s(dst, (u_int32_t)sample << 4); goto PUT16_END;
-put16_12_029_20: _put_triple_s(dst, (u_int32_t)(sample ^ 0x8000) << 4); goto PUT16_END;
-put16_12_120_18: _put_triple(dst, (u_int32_t)sample << 2); goto PUT16_END;
-put16_12_920_18: _put_triple(dst, (u_int32_t)(sample ^ 0x8000) << 2); goto PUT16_END;
-put16_12_021_18: _put_triple_s(dst, (u_int32_t)sample << 2); goto PUT16_END;
-put16_12_029_18: _put_triple_s(dst, (u_int32_t)(sample ^ 0x8000) << 2); goto PUT16_END;
+put16_12_0120: as_u32(dst) = sx24((uint32_t)sample << 8); goto PUT16_END;
+put16_12_0920: as_u32(dst) = sx24((uint32_t)(sample ^ 0x8000) << 8); goto PUT16_END;
+put16_12_0210: as_u32(dst) = sx24s((uint32_t)bswap_16(sample) << 8); goto PUT16_END;
+put16_12_0290: as_u32(dst) = sx24s((uint32_t)(bswap_16(sample) ^ 0x80) << 8); goto PUT16_END;
+put16_12_1200: as_u32(dst) = (uint32_t)sample << 16; goto PUT16_END;
+put16_12_9200: as_u32(dst) = (uint32_t)(sample ^ 0x8000) << 16; goto PUT16_END;
+put16_12_0021: as_u32(dst) = (uint32_t)bswap_16(sample); goto PUT16_END;
+put16_12_0029: as_u32(dst) = (uint32_t)bswap_16(sample) ^ 0x80; goto PUT16_END;
+put16_12_120: _put_triple(dst, (uint32_t)sample << 8); goto PUT16_END;
+put16_12_920: _put_triple(dst, (uint32_t)(sample ^ 0x8000) << 8); goto PUT16_END;
+put16_12_021: _put_triple_s(dst, (uint32_t)sample << 8); goto PUT16_END;
+put16_12_029: _put_triple_s(dst, (uint32_t)(sample ^ 0x8000) << 8); goto PUT16_END;
+put16_12_120_20: _put_triple(dst, (uint32_t)sample << 4); goto PUT16_END;
+put16_12_920_20: _put_triple(dst, (uint32_t)(sample ^ 0x8000) << 4); goto PUT16_END;
+put16_12_021_20: _put_triple_s(dst, (uint32_t)sample << 4); goto PUT16_END;
+put16_12_029_20: _put_triple_s(dst, (uint32_t)(sample ^ 0x8000) << 4); goto PUT16_END;
+put16_12_120_18: _put_triple(dst, (uint32_t)sample << 2); goto PUT16_END;
+put16_12_920_18: _put_triple(dst, (uint32_t)(sample ^ 0x8000) << 2); goto PUT16_END;
+put16_12_021_18: _put_triple_s(dst, (uint32_t)sample << 2); goto PUT16_END;
+put16_12_029_18: _put_triple_s(dst, (uint32_t)(sample ^ 0x8000) << 2); goto PUT16_END;
 }
 #endif
 
@@ -517,12 +517,12 @@ static void *const get32_labels[4 * 2 * 
 
 #ifdef GET32_END
 while (0) {
-get32_1_1000: sample = (u_int32_t)as_u8c(src) << 24; goto GET32_END;
-get32_1_9000: sample = (u_int32_t)(as_u8c(src) ^ 0x80) << 24; goto GET32_END;
-get32_12_1200: sample = (u_int32_t)as_u16c(src) << 16; goto GET32_END;
-get32_12_9200: sample = (u_int32_t)(as_u16c(src) ^ 0x8000) << 16; goto GET32_END;
-get32_12_2100: sample = (u_int32_t)bswap_16(as_u16c(src)) << 16; goto GET32_END;
-get32_12_A100: sample = (u_int32_t)bswap_16(as_u16c(src) ^ 0x80) << 16; goto GET32_END;
+get32_1_1000: sample = (uint32_t)as_u8c(src) << 24; goto GET32_END;
+get32_1_9000: sample = (uint32_t)(as_u8c(src) ^ 0x80) << 24; goto GET32_END;
+get32_12_1200: sample = (uint32_t)as_u16c(src) << 16; goto GET32_END;
+get32_12_9200: sample = (uint32_t)(as_u16c(src) ^ 0x8000) << 16; goto GET32_END;
+get32_12_2100: sample = (uint32_t)bswap_16(as_u16c(src)) << 16; goto GET32_END;
+get32_12_A100: sample = (uint32_t)bswap_16(as_u16c(src) ^ 0x80) << 16; goto GET32_END;
 get32_0123_1230: sample = as_u32c(src) << 8; goto GET32_END;
 get32_0123_9230: sample = (as_u32c(src) << 8) ^ 0x80000000; goto GET32_END;
 get32_1230_3210: sample = bswap_32(as_u32c(src) >> 8); goto GET32_END;
@@ -786,18 +786,18 @@ static inline void _norms(const void *sr
 		s += (1U << (dst_wid - 1));
 	switch (dst_wid) {
 	case 8:
-		*(u_int8_t*)dst = s;
+		*(uint8_t*)dst = s;
 		break;
 	case 16:
 		if (dst_end)
 			s = bswap_16(s);
-		*(u_int16_t*)dst = s;
+		*(uint16_t*)dst = s;
 		break;
 	case 24:
 	case 32:
 		if (dst_end)
 			s = bswap_32(s);
-		*(u_int32_t*)dst = s;
+		*(uint32_t*)dst = s;
 		break;
 	}
 	return;
@@ -806,27 +806,27 @@ static inline void _norms(const void *sr
 	switch (dst_wid) {
 	case 8:
 		if (dst_sign)
-			*(u_int8_t*)dst = 0x80;
+			*(uint8_t*)dst = 0x80;
 		else
-			*(u_int8_t*)dst = 0;
+			*(uint8_t*)dst = 0;
 		break;
 	case 16:
 		if (dst_sign)
-			*(u_int16_t*)dst = dst_end ? 0x0080 : 0x8000;
+			*(uint16_t*)dst = dst_end ? 0x0080 : 0x8000;
 		else
-			*(u_int16_t*)dst = 0;
+			*(uint16_t*)dst = 0;
 		break;
 	case 24:
 		if (dst_sign)
-			*(u_int32_t*)dst = dst_end ? 0x00008000 : 0x00800000;
+			*(uint32_t*)dst = dst_end ? 0x00008000 : 0x00800000;
 		else
-			*(u_int32_t*)dst = 0;
+			*(uint32_t*)dst = 0;
 		break;
 	case 32:
 		if (dst_sign)
-			*(u_int32_t*)dst = dst_end ? 0x00000080 : 0x80000000;
+			*(uint32_t*)dst = dst_end ? 0x00000080 : 0x80000000;
 		else
-			*(u_int32_t*)dst = 0;
+			*(uint32_t*)dst = 0;
 		break;
 	default:
 		assert(0);
@@ -838,27 +838,27 @@ static inline void _norms(const void *sr
 	switch (dst_wid) {
 	case 8:
 		if (dst_sign)
-			*(u_int8_t*)dst = 0x7f;
+			*(uint8_t*)dst = 0x7f;
 		else
-			*(u_int8_t*)dst = 0xff;
+			*(uint8_t*)dst = 0xff;
 		break;
 	case 16:
 		if (dst_sign)
-			*(u_int16_t*)dst = dst_end ? 0xff7f : 0x7fff;
+			*(uint16_t*)dst = dst_end ? 0xff7f : 0x7fff;
 		else
-			*(u_int16_t*)dst = 0;
+			*(uint16_t*)dst = 0;
 		break;
 	case 24:
 		if (dst_sign)
-			*(u_int32_t*)dst = dst_end ? 0xffff7f00 : 0x007fffff;
+			*(uint32_t*)dst = dst_end ? 0xffff7f00 : 0x007fffff;
 		else
-			*(u_int32_t*)dst = 0;
+			*(uint32_t*)dst = 0;
 		break;
 	case 32:
 		if (dst_sign)
-			*(u_int32_t*)dst = dst_end ? 0xffffff7f : 0x7fffffff;
+			*(uint32_t*)dst = dst_end ? 0xffffff7f : 0x7fffffff;
 		else
-			*(u_int32_t*)dst = 0;
+			*(uint32_t*)dst = 0;
 		break;
 	default:
 		assert(0);
