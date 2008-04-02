# $NetBSD: options.mk,v 1.1.1.1 2008/04/02 18:32:28 rhialto Exp $

PKG_OPTIONS_VAR = PKG_OPTIONS.logjam
# gtkhtml does not actually seem to work
PKG_SUPPORTED_OPTIONS = gtkhtml gtkspell rsvg xmms
PKG_SUGGESTED_OPTIONS = gtkspell rsvg xmms
PKG_OPTIONS.logjam += gtkspell rsvg xmms

# Depend on xmms by default, only if it happens to be installed
.if exists(${VIEWBASE}/bin/xmms)
PKG_OPTIONS.logjam += xmms
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtkspell)
.include "../../textproc/gtkspell/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

.if !empty(PKG_OPTIONS:Mxmms)
.include "../../audio/xmms/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-xmms
.endif

.if !empty(PKG_OPTIONS:Mgtkhtml)
.include "../../www/gtkhtml38/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtkhtml
.endif

.if !empty(PKG_OPTIONS:Mrsvg)
.include "../../graphics/librsvg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-librsvg
.endif
