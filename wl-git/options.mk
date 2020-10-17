# $NetBSD: options.mk,v 1.4 2008/11/29 01:31:38 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wl
PKG_SUPPORTED_OPTIONS=	emacs-w3m-current
# note: emacs-w3m is not supported by wip/emacs-current

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			emacs-w3m-current

.if !empty(PKG_OPTIONS:Memacs-w3m-current)
.include "../../wip/emacs-w3m-cvs/buildlink3.mk"
PLIST.emacs-w3m-current=	yes
.endif
