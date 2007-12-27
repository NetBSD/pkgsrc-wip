# $NetBSD: options.mk,v 1.1 2007/12/27 16:43:44 schnoebe Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.psi
PKG_SUPPORTED_OPTIONS=	aspell

.include "../../mk/bsd.options.mk"

# enable aspell
.if !empty(PKG_OPTIONS:Maspell)
CONFIGURE_ARGS+=	--with-aspell-inc=${BUILDLINK_PREFIX.aspell}/include
CONFIGURE_ARGS+=	--with-aspell-lib=${BUILDLINK_PREFIX.aspell}/lib
.include "../../textproc/aspell/buildlink3.mk"
.endif
