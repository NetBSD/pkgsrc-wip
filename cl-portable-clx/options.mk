# $NetBSD: options.mk,v 1.1.1.1 2012/01/16 00:15:10 dukzcry Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.cl-${SHORTNAME:S/^cl-//}
PKG_OPTIONS_REQUIRED_GROUPS=	lisp
PKG_OPTIONS_GROUP.lisp=		sbcl
PKG_SUGGESTED_OPTIONS+=		sbcl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			${PKG_OPTIONS_GROUP.lisp}
.for opt in ${PKG_OPTIONS_GROUP.lisp}
.  if !empty(PKG_OPTIONS:M${opt})
PLIST.${opt}=			yes
COMMON_LISP_SYSTEM:=		${opt}
.  endif
.endfor
