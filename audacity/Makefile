# $NetBSD$

DISTNAME=	audacity-sources-3.7.5
PKGNAME=	${DISTNAME:S/-sources//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=audacity/}
GITHUB_PROJECT=	audacity
GITHUB_RELEASE=	Audacity-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.audacityteam.org/
COMMENT=	Audio editing and recording app
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 # AND Creative Commons-Attribution 3.0 Unported (CC-BY 3.0)

TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-Daudacity_conan_enabled=OFF
#CMAKE_CONFIGURE_ARGS+=	-Daudacity_use_zlib=system
CMAKE_CONFIGURE_ARGS+=	-Daudacity_lib_preference=system
CMAKE_CONFIGURE_ARGS+=	-DPortAudio_INCLUDE_DIR=${BUILDLINK_DIR.portaudio}/include/portaudio2
CMAKE_CONFIGURE_ARGS+=	-DPortAudio_LIBRARIES=${BUILDLINK_DIR.portaudio}/lib/portaudio2/libportaudio.so

PKGCONFIG_OVERRIDE+=	lib-src/libsbsms/sbsms.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/libscorealign/scorealign.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/libsoxr/src/soxr-lsr.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/libsoxr/src/soxr.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/libvamp/pkgconfig/vamp-hostsdk.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/libvamp/pkgconfig/vamp-sdk.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/libvamp/pkgconfig/vamp.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/lv2/lilv/lilv.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/lv2/lv2/lv2.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/lv2/serd/serd.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/lv2/sord/sord.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/lv2/sratom/sratom.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/lv2/suil/suil.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/portsmf/portSMF.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/soundtouch/soundtouch-1.4.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/soundtouch/soundtouch.pc.in
PKGCONFIG_OVERRIDE+=	lib-src/twolame/twolame.pc.in

.include "../../lang/python/tool.mk"
.include "../../devel/cmake/build.mk"

# ========= Using system version of PortMidi ==========
# ========= Using system version of vst3sdk ==========

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
