$NetBSD$

--- ext/openssl/ossl_asn1.c.orig	2010-11-22 07:22:05.000000000 +0000
+++ ext/openssl/ossl_asn1.c
@@ -33,7 +33,7 @@ asn1time_to_time(ASN1_TIME *time)
 	
     switch (time->type) {
     case V_ASN1_UTCTIME:
-	if (sscanf(time->data, "%2d%2d%2d%2d%2d%2dZ", &tm.tm_year, &tm.tm_mon,
+	if (sscanf((const char *)time->data, "%2d%2d%2d%2d%2d%2dZ", &tm.tm_year, &tm.tm_mon,
     		&tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec) != 6) {
 	    ossl_raise(rb_eTypeError, "bad UTCTIME format");
 	} 
@@ -44,7 +44,7 @@ asn1time_to_time(ASN1_TIME *time)
 	}
 	break;
     case V_ASN1_GENERALIZEDTIME:
-	if (sscanf(time->data, "%4d%2d%2d%2d%2d%2dZ", &tm.tm_year, &tm.tm_mon,
+	if (sscanf((const char *)time->data, "%4d%2d%2d%2d%2d%2dZ", &tm.tm_year, &tm.tm_mon,
     		&tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec) != 6) {
 	    ossl_raise(rb_eTypeError, "bad GENERALIZEDTIME format" );
 	} 
@@ -80,7 +80,7 @@ asn1str_to_str(ASN1_STRING *str)
 VALUE
 asn1str_to_str(ASN1_STRING *str)
 {
-    return rb_str_new(str->data, str->length);
+    return rb_str_new((const char *)str->data, str->length);
 }
 
 /*
@@ -218,7 +218,7 @@ obj_to_asn1bstr(VALUE obj, long unused_bits)
     StringValue(obj);
     if(!(bstr = ASN1_BIT_STRING_new()))
 	ossl_raise(eASN1Error, NULL);
-    ASN1_BIT_STRING_set(bstr, RSTRING_PTR(obj), RSTRING_LEN(obj));
+    ASN1_BIT_STRING_set(bstr, (unsigned char *)RSTRING_PTR(obj), RSTRING_LEN(obj));
     bstr->flags &= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07); /* clear */
     bstr->flags |= ASN1_STRING_FLAG_BITS_LEFT|(unused_bits&0x07);
 
@@ -311,7 +311,7 @@ decode_bool(unsigned char* der, int length)
 decode_bool(unsigned char* der, int length)
 {
     int val;
-    unsigned char *p;
+    const unsigned char *p;
 
     p = der;
     if((val = d2i_ASN1_BOOLEAN(NULL, &p, length)) < 0)
@@ -324,7 +324,7 @@ decode_int(unsigned char* der, int length)
 decode_int(unsigned char* der, int length)
 {
     ASN1_INTEGER *ai;
-    unsigned char *p;
+    const unsigned char *p;
     VALUE ret; 
     int status = 0;
 
@@ -364,7 +364,7 @@ decode_enum(unsigned char* der, int length)
 decode_enum(unsigned char* der, int length)
 {
     ASN1_ENUMERATED *ai;
-    unsigned char *p;
+    const unsigned char *p;
     VALUE ret; 
     int status = 0;
 
@@ -383,7 +383,7 @@ decode_null(unsigned char* der, int length)
 decode_null(unsigned char* der, int length)
 {
     ASN1_NULL *null;
-    unsigned char *p;
+    const unsigned char *p;
 
     p = der;
     if(!(null = d2i_ASN1_NULL(NULL, &p, length)))
@@ -397,7 +397,7 @@ decode_obj(unsigned char* der, int length)
 decode_obj(unsigned char* der, int length)
 {
     ASN1_OBJECT *obj;
-    unsigned char *p;
+    const unsigned char *p;
     VALUE ret;
     int nid;
     BIO *bio;
@@ -426,7 +426,7 @@ decode_time(unsigned char* der, int length)
 decode_time(unsigned char* der, int length)
 {
     ASN1_TIME *time;
-    unsigned char *p;
+    const unsigned char *p;
     VALUE ret;
     int status = 0;
 
@@ -701,7 +701,7 @@ ossl_asn1data_to_der(VALUE self)
     if((length = ASN1_object_size(1, RSTRING_LEN(value), tag)) <= 0)
 	ossl_raise(eASN1Error, NULL);
     der = rb_str_new(0, length);
-    p = RSTRING_PTR(der);
+    p = (unsigned char *)RSTRING_PTR(der);
     ASN1_put_object(&p, is_cons, RSTRING_LEN(value), tag, tag_class);
     memcpy(p, RSTRING_PTR(value), RSTRING_LEN(value));
     p += RSTRING_LEN(value);
@@ -715,6 +715,7 @@ ossl_asn1_decode0(unsigned char **pp, long length, lon
 		  int once, int yield)
 {
     unsigned char *start, *p;
+    const unsigned char *p0;
     long len, off = *offset;
     int hlen, tag, tc, j;
     VALUE ary, asn1data, value, tag_class;
@@ -723,7 +724,9 @@ ossl_asn1_decode0(unsigned char **pp, long length, lon
     p = *pp;
     while(length > 0){
 	start = p;
-	j = ASN1_get_object(&p, &len, &tag, &tc, length);
+	p0 = p;
+	j = ASN1_get_object(&p0, &len, &tag, &tc, length);
+	p = (unsigned char *)p0;
 	if(j & 0x80) ossl_raise(eASN1Error, NULL);
 	hlen = p - start;
 	if(yield){
@@ -758,7 +761,7 @@ ossl_asn1_decode0(unsigned char **pp, long length, lon
 	    else value = ossl_asn1_decode0(&p, len, &off, depth+1, 0, yield);
 	}
 	else{
-	    value = rb_str_new(p, len);
+	    value = rb_str_new((const char *)p, len);
 	    p += len;
 	    off += len;
 	}
@@ -823,7 +826,7 @@ ossl_asn1_traverse(VALUE self, VALUE obj)
 
     obj = ossl_to_der_if_possible(obj);
     tmp = rb_str_new4(StringValue(obj));
-    p = RSTRING_PTR(tmp);
+    p = (unsigned char *)RSTRING_PTR(tmp);
     ossl_asn1_decode0(&p, RSTRING_LEN(tmp), &offset, 0, 0, 1);
 
     return Qnil;
@@ -839,7 +842,7 @@ ossl_asn1_decode(VALUE self, VALUE obj)
 
     obj = ossl_to_der_if_possible(obj);
     tmp = rb_str_new4(StringValue(obj));
-    p = RSTRING_PTR(tmp);
+    p = (unsigned char *)RSTRING_PTR(tmp);
     ary = ossl_asn1_decode0(&p, RSTRING_LEN(tmp), &offset, 0, 1, 0);
     ret = rb_ary_entry(ary, 0);
 
@@ -856,7 +859,7 @@ ossl_asn1_decode_all(VALUE self, VALUE obj)
 
     obj = ossl_to_der_if_possible(obj);
     tmp = rb_str_new4(StringValue(obj));
-    p = RSTRING_PTR(tmp);
+    p = (unsigned char *)RSTRING_PTR(tmp);
     ret = ossl_asn1_decode0(&p, RSTRING_LEN(tmp), &offset, 0, 0, 0);
 
     return ret;
@@ -951,7 +954,7 @@ ossl_asn1prim_to_der(VALUE self)
     ossl_ASN1_TYPE_free(asn1);
     reallen = p - buf;
     assert(reallen <= len);
-    str = ossl_buf2str(buf, reallen); /* buf will be free in ossl_buf2str */
+    str = ossl_buf2str((char *)buf, reallen); /* buf will be free in ossl_buf2str */
 
     return str;
 }
@@ -973,7 +976,7 @@ ossl_asn1cons_to_der(VALUE self)
     seq_len = ASN1_object_size(1, RSTRING_LEN(value), tag);
     length = ASN1_object_size(1, seq_len, tn);
     str = rb_str_new(0, length);
-    p = RSTRING_PTR(str);
+    p = (unsigned char *)RSTRING_PTR(str);
     if(tc == V_ASN1_UNIVERSAL)
 	ASN1_put_object(&p, 1, RSTRING_LEN(value), tn, tc);
     else{
