# $NetBSD: options.mk,v 1.5 2011/11/29 09:25:11 ddeus Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.cl-${SHORTNAME:S/^cl-//}
PKG_OPTIONS_REQUIRED_GROUPS=	lisp
PKG_OPTIONS_GROUP.lisp=		ecl sbcl clisp
PKG_SUGGESTED_OPTIONS+=		ecl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			${PKG_OPTIONS_GROUP.lisp}
.for opt in ${PKG_OPTIONS_GROUP.lisp}
.  if !empty(PKG_OPTIONS:M${opt})
PLIST.${opt}=			yes
COMMON_LISP_SYSTEM:=		${opt}
.  endif
.endfor
