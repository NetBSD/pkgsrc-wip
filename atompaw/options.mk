# $NetBSD: options.mk,v 1.1 2012/09/16 09:45:47 jihbed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.atompaw
PKG_SUPPORTED_OPTIONS=	libxc linalg
PKG_SUGGESTED_OPTIONS=	libxc linalg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibxc)
CONFIGURE_ARGS+=	--with-libxc-incs
CONFIGURE_ARGS+=	--with-libxc-libs
.include "../../wip/libxc/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlinalg)
CONFIGURE_ARGS+=	--with-blas="-L${BUILDLINK_PREFIX.blas}/lib -lblas"
.include "../../mk/blas.buildlink3.mk"
.endif
