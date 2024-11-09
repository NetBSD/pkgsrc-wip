# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.mtr085

PKG_SUPPORTED_OPTIONS+=		dns
PKG_SUPPORTED_OPTIONS+=		idn
PKG_SUPPORTED_OPTIONS+=		unicode
PKG_SUPPORTED_OPTIONS+=		ipinfo
PKG_SUPPORTED_OPTIONS+=		inet6
PKG_SUPPORTED_OPTIONS+=		mpls

PKG_SUGGESTED_OPTIONS+=	dns
PKG_SUGGESTED_OPTIONS+=	idn
PKG_SUGGESTED_OPTIONS+=	unicode
PKG_SUGGESTED_OPTIONS+=	ipinfo
PKG_SUGGESTED_OPTIONS+=	inet6
PKG_SUGGESTED_OPTIONS+=	mpls

PKG_OPTIONS_LEGACY_OPTS=	libidn:idn

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Minet6)
MESON_ARGS+=	-DIPV6=false
.endif

.if empty(PKG_OPTIONS:Mdns)
MESON_ARGS+=	-DDNS=false
.endif

.if empty(PKG_OPTIONS:Mmpls)
MESON_ARGS+=	-DMPLS=false
.endif

.if empty(PKG_OPTIONS:Mipinfo)
MESON_ARGS+=	-DIPINFO=false
.endif

.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn2/buildlink3.mk"
.endif

.if empty(PKG_OPTIONS:Municode)
MESON_ARGS+=	-DUNICODE=false
.endif
