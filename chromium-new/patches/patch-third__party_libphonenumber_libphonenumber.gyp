$NetBSD$

--- third_party/libphonenumber/libphonenumber.gyp.orig	2016-06-24 01:02:48.000000000 +0000
+++ third_party/libphonenumber/libphonenumber.gyp
@@ -11,6 +11,7 @@
       # generated protocol headers to be available with "phonenumbers" include
       # path, e.g. #include "phonenumbers/foo.pb.h".
       '<(SHARED_INTERMEDIATE_DIR)/protoc_out/third_party/libphonenumber',
+      '<(prefix_dir)/include',
     ],
     'defines': [
       'I18N_PHONENUMBERS_USE_ALTERNATE_FORMATS=1',
