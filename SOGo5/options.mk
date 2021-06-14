# $NetBSD$

PKG_OPTIONS_VAR=			PKG_OPTIONS.SOGo5

PKG_SUPPORTED_OPTIONS=			libsodium
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibsodium)
.include "../../security/libsodium/buildlink3.mk"
.else
CONFIGURE_ARGS+=			--disable-sodium
.endif
