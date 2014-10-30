# $NetBSD: module.mk,v 1.5 2014/10/30 16:16:53 nros Exp $
#
# This file should be included in the makefile of packages that install
# Qore modules.
#
# PLIST variables:
#
# QORE_VERSION 		 To be used by packages that install files in
# 			 ${QORE_MODULE_DIR}/${QORE_VERSION}/
#
# QORE_MODULE_API	 This should be used by packages that install
# 			 modules that uses the compatible module api
#			 version.
#
# QORE_MODULE_DIR	 The directory where binary modules are
#			 installed relative to ${PREFIX}.
#
#
# QORE_LATEST_MODULE_API This should be used by packages that install
#			 modules that uses the latest module api
#			 version.
#

.PHONY: qore-module
qore-module: post-install
qore-version=${PKG_INFO} -E qore | ${SED} -e s/qore-// -e s/nb.//
qore-module-api=qore --module-api
qore-module-dir=qore --module-dir
qore-latest-module-api=qore --latest-module-api
PLIST_SUBST+=QORE_VERSION="${qore-version:sh}"
PLIST_SUBST+=QORE_MODULE_API="${qore-module-api:sh}"
PLIST_SUBST+=QORE_MODULE_DIR="${qore-module-dir:sh:C,^${PREFIX}/,,W}"
PLIST_SUBST+=QORE_LATEST_MODULE_API="${qore-latest-module-api:sh}"
