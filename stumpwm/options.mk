# $NetBSD: options.mk,v 1.1 2012/01/16 01:35:56 dukzcry Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.stumpwm
PKG_OPTIONS_REQUIRED_GROUPS=	lisp
PKG_OPTIONS_GROUP.lisp=		clisp sbcl
PKG_SUGGESTED_OPTIONS+=		clisp

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			${PKG_OPTIONS_GROUP.lisp}
.for opt in ${PKG_OPTIONS_GROUP.lisp}
.  if !empty(PKG_OPTIONS:M${opt})
PLIST.${opt}=			yes
COMMON_LISP_SYSTEM:=		${opt}
.  endif
.endfor
