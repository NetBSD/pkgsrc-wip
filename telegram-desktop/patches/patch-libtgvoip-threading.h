$NetBSD$

--- Telegram/ThirdParty/libtgvoip/threading.h.orig	2020-01-21 12:16:27.000000000 +0000
+++ Telegram/ThirdParty/libtgvoip/threading.h
@@ -9,8 +9,9 @@
 
 #include <functional>
 
-#if defined(_POSIX_THREADS) || defined(_POSIX_VERSION) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
+#if defined(_POSIX_THREADS) || defined(_POSIX_VERSION) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)) || defined(__NetBSD__)
 
+#include <cstring>
 #include <pthread.h>
 #include <semaphore.h>
 #include <sched.h>
@@ -53,9 +54,12 @@ namespace tgvoip{
 			name=NULL;
 			thread=0;
 		}
+		char *descr=NULL;
 
 		virtual ~Thread(){
-
+			if (this->descr != NULL){
+				free(this->descr);
+			}
 		}
 
 		void Start(){
@@ -71,6 +75,9 @@ namespace tgvoip{
 
 		void SetName(const char* name){
 			this->name=name;
+
+			this->descr = (char *) malloc(sizeof(char) * (strlen(this->name) + 1));
+			strcpy(this->descr, this->name);
 		}
 
 
@@ -92,8 +99,10 @@ namespace tgvoip{
 		static void* ActualEntryPoint(void* arg){
 			Thread* self=reinterpret_cast<Thread*>(arg);
 			if(self->name){
-#if !defined(__APPLE__) && !defined(__gnu_hurd__)
+#if !defined(__APPLE__) && !defined(__gnu_hurd__) && !defined(__NetBSD__)
 				pthread_setname_np(self->thread, self->name);
+#elif defined(__NetBSD__)
+				pthread_setname_np(self->thread, self->name, self->descr);
 #elif !defined(__gnu_hurd__)
 				pthread_setname_np(self->name);
 				if(self->maxPriority){
