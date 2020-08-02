# $NetBSD$

GITHUB_PROJECT=	avp
GITHUB_TAG=	2d5774781dd2ed959a83b2a98ab6f3f26e1dcc51
DISTNAME=	avp
PKGNAME=	avp-git
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=neuromancer/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	astr0b4by@gmail.com
HOMEPAGE=	https://github.com/neuromancer/avp/
COMMENT=	OpenSource Alien vs. Predator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/avp-2d5774781dd2ed959a83b2a98ab6f3f26e1dcc51
USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config cmake
USE_CMAKE+=	yes

CMAKE_ARGS+=	-DAVCODEC_LIBRARIES=/usr/pkg/lib/ffmpeg4/libavcodec.so
CMAKE_ARGS+=	-DSWSCALE_LIBRARIES=/usr/pkg/lib/ffmpeg4/libswscale.so
CMAKE_ARGS+=	-DAVDEVICE_LIBRARIES=/usr/pkg/lib/ffmpeg4/libavdevice.so
CMAKE_ARGS+=	-DAVFORMAT_LIBRARIES=/usr/pkg/lib/ffmpeg4/libavformat.so
CMAKE_ARGS+=	-DAVUTIL_LIBRARIES=/usr/pkg/lib/ffmpeg4/libavutil.so
CMAKE_ARGS+=	-DAVRESAMPLE_LIBRARIES=/usr/pkg/lib/ffmpeg4/libavresample.so
CMAKE_ARGS+=	-DAVFILTER_LIBRARIES=/usr/pkg/lib/ffmpeg4/libavfilter.so
CMAKE_ARGS+=	-DAVCODEC_INCLUDE_DIRS=/usr/pkg/include/ffmpeg4/libavcodec
CMAKE_ARGS+=	-DSWSCALE_INCLUDE_DIRS=/usr/pkg/include/ffmpeg4/libswscale
CMAKE_ARGS+=	-DAVDEVICE_INCLUDE_DIRS=/usr/pkg/include/ffmpeg4/libavdevice
CMAKE_ARGS+=	-DAVFORMAT_INCLUDE_DIRS=/usr/pkg/include/ffmpeg4/libavformat
CMAKE_ARGS+=	-DAVUTIL_INCLUDE_DIRS=/usr/pkg/include/ffmpeg4/libavutil
CMAKE_ARGS+=	-DAVRESAMPLE_INCLUDE_DIRS=/usr/pkg/include/ffmpeg4/libavresample
CMAKE_ARGS+=	-DAVFILTER_INCLUDE_DIRS=/usr/pkg/include/ffmpeg4/libavfilter

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avp ${DESTDIR}${PREFIX}/bin


.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
