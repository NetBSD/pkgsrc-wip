# $NetBSD: options.mk,v 1.3 2008/11/24 02:11:24 makoto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wl
PKG_SUPPORTED_OPTIONS=	emacs-w3m-current
# note: emacs-w3m is not supported by wip/emacs-current

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Memacs-w3m-current)
.include "../../wip/emacs-w3m-current/buildlink3.mk"
PLIST_VARS+=			emacs-w3m-current
PLIST.emacs-w3m-current=	yes
.endif
