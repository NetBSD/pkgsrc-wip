# $NetBSD: options.mk,v 1.1.1.1 2005/09/11 05:26:43 udontknow Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.obby
PKG_SUPPORTED_OPTIONS=  zeroconf

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzeroconf)
CONFIGURE_ARGS+=	--with-howl
.include "../../net/howl/buildlink3.mk"
PLIST_SRC=		${PKGDIR}/PLIST.zeroconf
.endif
