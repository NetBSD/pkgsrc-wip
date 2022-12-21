# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.avidemux

PKG_OPTIONS_OPTIONAL_GROUPS=	qt
PKG_OPTIONS_GROUP.qt=		qt4 qt5 qt6

################################################################################
PKG_SUPPORTED_OPTIONS=		aften aom cli dca faac faad fdk-aac fontconfig \
				freetype fribidi jack lame libvpx opencore-amr \
				opus twolame vorbis x264 x265 xvid
PKG_SUGGESTED_OPTIONS=		cli faac faad fontconfig freetype fribidi lame \
				qt5 vorbis x264 x265 xvid

PLIST_VARS+=			${PKG_SUPPORTED_OPTIONS} ${PKG_OPTIONS_GROUP.qt}

# Add VDPAU if it is available
.include "../../multimedia/libvdpau/available.mk"
.if ${VDPAU_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+= vdpau
PKG_SUGGESTED_OPTIONS+=	vdpau
.endif

# Add VAAPI if it is available
.include "../../multimedia/libva/available.mk"
.if ${VAAPI_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+= vaapi
PKG_SUGGESTED_OPTIONS+=	vaapi
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maften)
PLIST.aften=		yes
.include "../../audio/aften/buildlink3.mk"
.else
CMAKE_ARGS+=		-DAFTEN:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Maom)
PLIST.aom=		yes
.include "../../multimedia/libaom/buildlink3.mk"
.else
CMAKE_ARGS+=		-DAOMDEC:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mcli)
PLIST.cli=		yes
.endif

.if !empty(PKG_OPTIONS:Mdca)
PLIST.dca=		yes
.include "../../audio/libdca/buildlink3.mk"
.else
CMAKE_ARGS+=		-DLIBDCA:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mfaac)
PLIST.faac=		yes
.include "../../audio/faac/buildlink3.mk"
.else
CMAKE_ARGS+=		-DFAAC:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mfaad)
PLIST.faad=		yes
.include "../../audio/faad2/buildlink3.mk"
CMAKE_PREFIX_PATH+=	${PREFIX}/${BUILDLINK_INCDIRS.faad2}
.else
CMAKE_ARGS+=		-DFAAD:BOOL=OFF -DNeAAC:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mfdk-aac)
PLIST.fdk-aac=		yes
.include "../../audio/fdk-aac/buildlink3.mk"
.else
CMAKE_ARGS+=		-DFDK_AAC:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mfontconfig)
PLIST.fontconfig=	yes
.include "../../fonts/fontconfig/buildlink3.mk"
.else
CMAKE_ARGS+=		-DFONTCONFIG:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
PLIST.freetype=		yes
.include "../../graphics/freetype2/buildlink3.mk"
.else
CMAKE_ARGS+=		-DFREETYPE2:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mfribidi)
PLIST.fribidi=		yes
.  if empty(PKG_OPTIONS:Mfontconfig)
PKG_OPTIONS+=		fontconfig
.  endif
.include "../../converters/fribidi/buildlink3.mk"
.else
CMAKE_ARGS+=		-DFRIBIDI:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
PLIST.jack=		yes
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=		-DJACK:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mlame)
PLIST.lame=		yes
.include "../../audio/lame/buildlink3.mk"
.else
CMAKE_ARGS+=		-DLAME:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mlibvpx)
PLIST.libvpx=		yes
.include "../../multimedia/libvpx/buildlink3.mk"
.else
CMAKE_ARGS+=		-DVPXDEC:BOOL=OFF -DVPXENC:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mopencore-amr)
PLIST.opencore-amr=	yes
.include "../../audio/opencore-amr/buildlink3.mk"
.else
CMAKE_ARGS+=		-DOPENCORE-AMRNB:BOOL=OFF
CMAKE_ARGS+=		-DOPENCORE-AMRWB:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mopus)
PLIST.opus=		yes
.include "../../audio/libopus/buildlink3.mk"
.else
CMAKE_ARGS+=		-DOPUS:BOOL=OFF -DOPUS_ENCODER:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mqt4)
PLIST.qt4=		yes
CMAKE_ARGS+=		-DENABLE_QT4:BOOL=ON
.include "../../x11/qt4-libs/buildlink3.mk"
.else
CMAKE_ARGS+=		-DQT4:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.qt5=		yes
CMAKE_ARGS+=		-DENABLE_QT5:BOOL=ON
.include "../../x11/qt5-qtbase/buildlink3.mk"
.else
CMAKE_ARGS+=		-DQT5:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mqt6)
PLIST.qt6=		yes
CMAKE_ARGS+=		-DENABLE_QT6:BOOL=ON
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtwolame)
PLIST.twolame=		yes
.include "../../audio/twolame/buildlink3.mk"
.else
CMAKE_ARGS+=		-DTWOLAME:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mvaapi)
PLIST.vaapi=		yes
.include "../../multimedia/libva/buildlink3.mk"
.else
CMAKE_ARGS+=		-DVAAPI:BOOL=OFF -DLIBVA:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mvdpau)
PLIST.vdpau=		yes
.include "../../multimedia/libvdpau/buildlink3.mk"
.else
CMAKE_ARGS+=		-DVDPAU:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
PLIST.vorbis=		yes
.include "../../audio/libvorbis/buildlink3.mk"
.else
CMAKE_ARGS+=		-DLIBVORBIS:BOOL=OFF -DVORBIS:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mx264)
PLIST.x264=		yes
.include "../../multimedia/x264/buildlink3.mk"
.else
CMAKE_ARGS+=		-DX264:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mx265)
PLIST.x265=		yes
.include "../../multimedia/x265/buildlink3.mk"
.else
CMAKE_ARGS+=		-DX265:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mxvid)
PLIST.xvid=		yes
.include "../../multimedia/xvidcore/buildlink3.mk"
.else
CMAKE_ARGS+=		-DXVID:BOOL=OFF
.endif
