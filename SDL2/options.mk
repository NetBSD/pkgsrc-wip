# $NetBSD: options.mk,v 1.1 2012/12/28 04:23:54 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL2
PKG_SUPPORTED_OPTIONS=	alsa arts esound nas opengl oss pulseaudio
PKG_SUGGESTED_OPTIONS+=	oss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
CMAKE_ARGS+=		-DALSA=ON
.else
CMAKE_ARGS+=		-DALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Marts)
.include "../../audio/arts/buildlink3.mk"
CMAKE_ARGS+=            -DARTS=ON
.else
CMAKE_ARGS+=		-DARTS=OFF
.endif

.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
CMAKE_ARGS+=		-DESD=ON
.else
CMAKE_ARGS+=		-DESD=OFF
.endif

.if !empty(PKG_OPTIONS:Mnas)
.include "../../audio/nas/buildlink3.mk"
CMAKE_ARGS+=		-DNAS=ON
.else
CMAKE_ARGS+=		-DNAS=OFF
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
CMAKE_ARGS+=		-DVIDEO_OPENGL=ON
.else
CMAKE_ARGS+=		-DVIDEO_OPENGL=OFF
.endif

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
CMAKE_ARGS+=		-DOSS=ON
.else
CMAKE_ARGS+=		-DOSS=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CMAKE_ARGS+=		-DPULSEAUDIO=ON
.else
CMAKE_ARGS+=		-DPULSEAUDIO=OFF
.endif
