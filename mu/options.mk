# $NetBSD: options.mk,v 1.1 2014/11/09 21:02:12 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mu
PKG_SUPPORTED_OPTIONS=	mu-emacs
PKG_SUGGESTED_OPTIONS=	mu-emacs

.include "../../mk/bsd.options.mk"

PLIST_SRC=	PLIST

.if !empty(PKG_OPTIONS:Mmu-emacs)
.include "../../editors/emacs/modules.mk"
INFO_FILES=	yes
USE_TOOLS+=	makeinfo
PLIST_SRC+=	PLIST.emacs
.endif

# needs gtk3 and webkit-gtk-3
.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk3/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.endif
