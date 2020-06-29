# $NetBSD: Makefile,v 1.132 2020/04/16 21:54:06 nia Exp $

DISTNAME=	audacity-2.4.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=audacity/}
GITHUB_PROJECT=	Audacity
GITHUB_TAG=	Audacity-${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.audacityteam.org/
COMMENT=	Multi-track audio editor and recorder
LICENSE=	gnu-gpl-v2 # AND cc-by-v3.0-license

WRKSRC=		${WRKDIR}/audacity-${GITHUB_PROJECT}-${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config msgfmt msgmerge
USE_LANGUAGES=	c c++

# uses -std=gnu++14
GCC_REQD+=	4.9

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

#CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Debug"

CMAKE_ARGS+=	-DPYTHON=${PYTHONBIN}

CMAKE_ARGS+=	-Daudacity_use_expat=system
CMAKE_ARGS+=	-Daudacity_use_ffmpeg=linked
CMAKE_ARGS+=	-Daudacity_use_flac=system
CMAKE_ARGS+=	-Daudacity_use_id3tag=system
CMAKE_ARGS+=	-Daudacity_use_lame=system
CMAKE_ARGS+=	-Daudacity_use_lv2=system
CMAKE_ARGS+=	-Daudacity_use_mad=off
CMAKE_ARGS+=	-Daudacity_use_midi=local
CMAKE_ARGS+=	-Daudacity_use_nyquist=local
CMAKE_ARGS+=	-Daudacity_use_ogg=system
CMAKE_ARGS+=	-Daudacity_use_portaudio=system
CMAKE_ARGS+=	-Daudacity_use_portmixer=local
CMAKE_ARGS+=	-Daudacity_use_portsmf=local
CMAKE_ARGS+=	-Daudacity_use_sbsms=local
CMAKE_ARGS+=	-Daudacity_use_sndfile=system
CMAKE_ARGS+=	-Daudacity_use_soundtouch=system
CMAKE_ARGS+=	-Daudacity_use_soxr=system
CMAKE_ARGS+=	-Daudacity_use_twolame=system
CMAKE_ARGS+=	-Daudacity_use_vamp=system
CMAKE_ARGS+=	-Daudacity_use_vorbis=system
CMAKE_ARGS+=	-Daudacity_use_wxwidgets=system

CMAKE_ARGS+=	-DLIB_avcodec=${PREFIX}/lib/ffmpeg4/libavcodec.so
CMAKE_ARGS+=	-DLIB_avformat=${PREFIX}/lib/ffmpeg4/libavformat.so
CMAKE_ARGS+=	-DLIB_avutil=${PREFIX}/lib/ffmpeg4/libavutil.so

CFLAGS+=	-DHAVE_VISIBILITY=1 # ???

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
CMAKE_ARGS+=	-Daudacity_use_pa_oss=ON
CFLAGS+=	-DHAVE_SYS_SOUNDCARD_H=1
.endif

.if ${OPSYS} == "Linux"
CMAKE_ARGS+=	-Daudacity_use_pa_alsa=ON
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if ${OPSYS} == "Darwin"
CMAKE_ARGS+=	-Daudacity_use_pa_coreaudio=ON
.endif

.if ${MACHINE_ARCH} == "i386"
# 64 bit atomic ops are required
CXXFLAGS+=		-march=i586
.endif

CFLAGS.SunOS+=		-fPIC

PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		tool

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../audio/lilv/buildlink3.mk"
.include "../../audio/lv2/buildlink3.mk"
.include "../../audio/soundtouch/buildlink3.mk"
BUILDLINK_API_DEPENDS.twolame+=	twolame>=0.3.9
.include "../../audio/twolame/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libsoxr/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
BUILDLINK_API_DEPENDS.portaudio+=	portaudio>=190600.20161030nb2
.include "../../audio/portaudio/buildlink3.mk"
.include "../../audio/suil/buildlink3.mk"
.include "../../audio/vamp-plugin-sdk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.flac+=	flac>=1.3.0
.include "../../audio/flac/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
