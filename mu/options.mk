# $NetBSD: options.mk,v 1.3 2015/07/12 00:38:17 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mu
PKG_SUPPORTED_OPTIONS=	mu-emacs guile
PKG_SUGGESTED_OPTIONS=	mu-emacs guile

.include "../../mk/bsd.options.mk"

PLIST_SRC=	PLIST

.if !empty(PKG_OPTIONS:Mmu-emacs)
.include "../../editors/emacs/modules.mk"
INFO_FILES=	yes
USE_TOOLS+=	makeinfo
PLIST_SRC+=	PLIST.emacs
.else
CONFIGURE_ARGS+= --disable-mu4e
.endif

# needs gtk3 and webkit-gtk-3
.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk3/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mguile)
.include "../../lang/guile22/buildlink3.mk"
PLIST_SRC+=	PLIST.guile
CONFIGURE_ENV+= ac_cv_path_GUILE=guile
USE_TOOLS+= makeinfo
.else
CONFIGURE_ARGS+= --disable-guile
.endif
