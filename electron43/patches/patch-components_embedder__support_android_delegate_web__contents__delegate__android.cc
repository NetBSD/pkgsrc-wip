$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/embedder_support/android/delegate/web_contents_delegate_android.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/embedder_support/android/delegate/web_contents_delegate_android.cc
@@ -185,14 +185,13 @@ bool WebContentsDelegateAndroid::IsWebCo
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   JNIEnv* env = AttachCurrentThread();
   ScopedJavaLocalRef<jobject> obj = GetJavaDelegate(env);
   if (obj.is_null())
     return false;
   ScopedJavaLocalRef<jobject> java_gurl =
-      url::GURLAndroid::FromNativeGURL(env, target_url);
+      url::GURLAndroid::FromNativeGURL(env, params.target_url.spec());
   return !Java_WebContentsDelegateAndroid_shouldCreateWebContents(env, obj,
                                                                   java_gurl);
 }
