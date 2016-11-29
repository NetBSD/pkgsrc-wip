$NetBSD$

--- ipc/ipc_message_utils.cc.orig	2016-11-10 20:02:15.000000000 +0000
+++ ipc/ipc_message_utils.cc
@@ -423,7 +423,7 @@ void ParamTraits<unsigned int>::Log(cons
   l->append(base::UintToString(p));
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::Int64ToString(static_cast<int64_t>(p)));
