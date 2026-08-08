$NetBSD$

--- ext/openssl/ossl_x509name.c.orig	2010-06-21 09:18:59.000000000 +0000
+++ ext/openssl/ossl_x509name.c
@@ -135,7 +135,7 @@ ossl_x509name_initialize(int argc, VALUE *argv, VALUE 
 	    rb_block_call(tmp, rb_intern("each"), 0, 0, ossl_x509name_init_i, args);
 	}
 	else{
-	    unsigned char *p;
+	    const unsigned char *p;
 	    VALUE str = ossl_to_der_if_possible(arg);
 	    X509_NAME *x;
 	    StringValue(str);
@@ -167,7 +167,7 @@ VALUE ossl_x509name_add_entry(int argc, VALUE *argv, V
     if(NIL_P(type)) type = rb_aref(OBJECT_TYPE_TEMPLATE, oid);
     GetX509Name(self, name);
     if (!X509_NAME_add_entry_by_txt(name, RSTRING_PTR(oid), NUM2INT(type),
-		RSTRING_PTR(value), RSTRING_LEN(value), -1, 0)) {
+		(unsigned char *)RSTRING_PTR(value), RSTRING_LEN(value), -1, 0)) {
 	ossl_raise(eX509NameError, NULL);
     }
 
@@ -248,7 +248,7 @@ ossl_x509name_to_a(VALUE self)
 	}
 	short_name = OBJ_nid2sn(OBJ_ln2nid(long_name));
 	ary = rb_ary_new3(3, rb_str_new2(short_name),
-        		  rb_str_new(entry->value->data, entry->value->length),
+        		  rb_str_new((const char *)entry->value->data, entry->value->length),
         		  INT2FIX(entry->value->type));
 	rb_ary_push(ret, ary);
     }
@@ -343,7 +343,7 @@ ossl_x509name_to_der(VALUE self)
     if((len = i2d_X509_NAME(name, NULL)) <= 0)
 	ossl_raise(eX509NameError, NULL);
     str = rb_str_new(0, len);
-    p = RSTRING_PTR(str);
+    p = (unsigned char *)RSTRING_PTR(str);
     if(i2d_X509_NAME(name, &p) <= 0)
 	ossl_raise(eX509NameError, NULL);
     ossl_str_adjust(str, p);
