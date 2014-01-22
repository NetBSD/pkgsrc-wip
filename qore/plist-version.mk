#$NetBSD: plist-version.mk,v 1.1 2014/01/22 22:09:03 nros Exp $
#
# This file should be included in the makefile of packages that install
# .qm files in lib/qore-modules/"the currently installed qore version"/
# and the qore version number in the PLIST replaced with ${QORE_VERSION}.
#

.PHONY: qore-version
qore-version: post-install
qore-version-cmd=${PKG_INFO} -E qore | ${SED} s/qore-//
PLIST_SUBST+=QORE_VERSION="${qore-version-cmd:sh}"
