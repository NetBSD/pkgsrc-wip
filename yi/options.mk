# $NetBSD: options.mk,v 1.1.1.1 2011/07/12 23:07:44 phonohawk Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.yi
PKG_OPTIONS_NONEMPTY_SETS+=	frontend
PKG_OPTIONS_SET.frontend=	pango vte vty
PKG_SUGGESTED_OPTIONS=		pango vte vty

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	pango vte vty

# Build with Pango frontend
.if !empty(PKG_OPTIONS:Mpango)
CONFIGURE_ARGS+= -fpango
PLIST.pango= yes
.include "../../wip/hs-glib/buildlink3.mk"
.include "../../wip/hs-gtk/buildlink3.mk"
.include "../../wip/hs-pango/buildlink3.mk"
.else
CONFIGURE_ARGS+= -f-pango
.endif

# Build with Vte frontend
.if !empty(PKG_OPTIONS:Mvte)
CONFIGURE_ARGS+= -fvte
PLIST.vte= yes
.include "../../wip/hs-glib/buildlink3.mk"
.include "../../wip/hs-gtk/buildlink3.mk"
.include "../../wip/hs-pango/buildlink3.mk"
.include "../../wip/hs-vte/buildlink3.mk"
.include "../../wip/hs-executable-path/buildlink3.mk"
.else
CONFIGURE_ARGS+= -f-vte
.endif

# Build with Vty frontend
.if !empty(PKG_OPTIONS:Mvty)
CONFIGURE_ARGS+= -fvty
PLIST.vty= yes
.include "../../wip/hs-vty/buildlink3.mk"
.else
CONFIGURE_ARGS+= -f-vty
.endif
