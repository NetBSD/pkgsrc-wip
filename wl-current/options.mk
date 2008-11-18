# $NetBSD: options.mk,v 1.1.1.1 2008/11/18 02:11:41 makoto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wl
PKG_SUPPORTED_OPTIONS.wl=	emacs-w3m emacs-w3m-current

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		emacs-w3m-current

.if !empty(PKG_OPTIONS:Memacs-w3m-current)
.include "../../www/emacs-w3m/buildlink3.mk"
PLIST.emacs-w3m-current=	yes
.endif
