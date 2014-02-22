$NetBSD: patch-src_scripting_flash_utils_flashutils.h,v 1.1 2014/02/22 12:17:46 thomasklausner Exp $

C++ does not allow > > except as operator.

--- src/scripting/flash/utils/flashutils.h.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/scripting/flash/utils/flashutils.h
@@ -200,8 +200,8 @@ class Dictionary: public ASObject
 {
 friend class ABCVm;
 private:
-	typedef std::map<_R<ASObject>,_R<ASObject>,std::less<_R<ASObject>>,
-	       reporter_allocator<std::pair<const _R<ASObject>, _R<ASObject>>>> dictType;
+	typedef std::map<_R<ASObject>,_R<ASObject>,std::less<_R<ASObject> >,
+	       reporter_allocator<std::pair<const _R<ASObject>, _R<ASObject> > > > dictType;
 	dictType data;
 	dictType::iterator findKey(ASObject *);
 public:
