# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.i2pd

PKG_SUPPORTED_OPTIONS=	debug upnp aesni i2lua websockets
PKG_SUGGESTED_OPTIONS=	upnp

.include "../../mk/bsd.options.mk"

###
### Select build profile
###
.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.else
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
.endif

###
### Enable UPnP support
###
.if !empty(PKG_OPTIONS:Mupnp)
CMAKE_ARGS+=	-DWITH_UPNP=yes
.include "../../net/miniupnpc/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_UPNP=no
.endif

###
### Enable AES-NI support
###
.if !empty(PKG_OPTIONS:Maesni)
CMAKE_ARGS+=	-DWITH_AESNI=ON
.else
CMAKE_ARGS+=	-DWITH_AESNI=OFF
.endif
