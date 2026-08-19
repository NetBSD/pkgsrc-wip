# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.telegram-desktop

PKG_SUPPORTED_OPTIONS=	enchant libressl

.include "../../mk/bsd.options.mk"

###
### Spell checking via Enchant (otherwise bundled Hunspell)
###
.if !empty(PKG_OPTIONS:Menchant)
CMAKE_CONFIGURE_ARGS+=              -DDESKTOP_APP_USE_ENCHANT=ON
.include "../../textproc/enchant2/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=              -DDESKTOP_APP_USE_ENCHANT=OFF
.endif

###
### LibreSSL
###
.if !empty(PKG_OPTIONS:Mlibressl)
.include "../../security/libressl/buildlink3.mk"
.else
.include "../../security/openssl/buildlink3.mk"
.endif
