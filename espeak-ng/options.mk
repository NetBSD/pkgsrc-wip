# $NetBSD: $

PKG_OPTIONS_VAR=		PKG_OPTIONS.espeak-ng

PKG_SUPPORTED_OPTIONS+=		sonic


.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Msonic)
.  include "../../audio/sonic/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sonic
.else
CONFIGURE_ARGS+=	--without-sonic
.endif
