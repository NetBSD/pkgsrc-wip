# $NetBSD: options.mk,v 1.1.1.1 2010/03/11 14:37:19 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.coq
PKG_SUPPORTED_OPTIONS=	doc gui
PKG_SUGGESTED_OPTIONS=	gui

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
DEPENDS+=		hevea>=1.10:../../textproc/hevea
CONFIGURE_ARGS+=	-with-doc yes
.else
CONFIGURE_ARGS+=	-with-doc no
.endif

.if !empty(PKG_OPTIONS:Mgui)
.include "../../x11/lablgtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	-coqide no
.endif
