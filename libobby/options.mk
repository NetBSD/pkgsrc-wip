# $NetBSD: options.mk,v 1.2 2005/09/11 05:46:34 udontknow Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.libobby
PKG_SUPPORTED_OPTIONS=  zeroconf

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzeroconf)
CONFIGURE_ARGS+=	--with-howl
.include "../../net/howl/buildlink3.mk"
PLIST_SRC=		${PKGDIR}/PLIST.zeroconf
.endif
