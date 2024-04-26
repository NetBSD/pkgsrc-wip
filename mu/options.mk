# $NetBSD: options.mk,v 1.3 2015/07/12 00:38:17 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mu
PKG_SUPPORTED_OPTIONS=	mu-emacs guile
PKG_SUGGESTED_OPTIONS=	mu-emacs

.include "../../mk/bsd.options.mk"

PLIST_SRC=	PLIST

.if !empty(PKG_OPTIONS:Mmu-emacs)
.include "../../editors/emacs/modules.mk"
INFO_FILES=	yes
USE_TOOLS+=	makeinfo
PLIST_SRC+=	PLIST.emacs
.else
# TODO: update for meson
CONFIGURE_ARGS+= --disable-mu4e
.endif

.if !empty(PKG_OPTIONS:Mguile)
.include "../../lang/guile22/buildlink3.mk"
PLIST_SRC+=	PLIST.guile
# TODO: update for meson
CONFIGURE_ENV+= ac_cv_path_GUILE=guile
USE_TOOLS+= makeinfo
.else
# TODO: update for meson
CONFIGURE_ARGS+= --disable-guile
.endif
