#$NetBSD: module.mk,v 1.1 2014/02/21 20:38:01 nros Exp $
#
# This file should be included in the makefile of packages that install
# Qore modules.
#
# PLIST variables:
#
# QORE_VERSION 		 To be used by packages that install files in
# 			 lib/qore-modules/${QORE_VERSION}/
# 			
# QORE_MODULE_API	 This should be used by packages that install
# 			 modules that uses the compatible module api
#			 version.
#
# QORE_LATEST_MODULE_API This should be used by packages that install
#			 modules that uses the latest module api
#			 version.
#			 

.PHONY: qore-module
qore-module: post-install
qore-version!=${PKG_INFO} -E qore | ${SED} -e s/qore-// -e s/nb.//
qore-module-api!=qore --module-api
qore-latest-module-api!=qore --latest-module-api
PLIST_SUBST+=QORE_VERSION="${qore-version}"
PLIST_SUBST+=QORE_MODULE_API="${qore-module-api}"
PLIST_SUBST+=QORE_LATEST_MODULE_API="${qore-latest-module-api}"
