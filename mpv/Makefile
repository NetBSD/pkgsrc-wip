# $NetBSD: Makefile,v 1.1 2014/08/06 20:53:46 thomasklausner Exp $

DISTNAME=	mpv-${VERSION}
VERSION=	0.4.2
CATEGORIES=	multimedia
MASTER_SITES=	-https://codeload.github.com/mpv-player/mpv/zip/v${VERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mpv.io/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v2

WAF_ENV=	PATH=${PATH} CC=${CC:Q} CXX=${CXX:Q} PREFIX=${PREFIX:Q} \
		CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q} \
		LINKFLAGS=${LDFLAGS:Q} DESTDIR=${DESTDIR:Q}

REPLACE_PYTHON=	waf
USE_TOOLS+=	perl pkg-config

.if defined(MAKE_JOBS)
WAF_ENV+=	JOBS=${MAKE_JOBS:Q}
.endif

SUBST_CLASSES+=		audio
SUBST_SED.audio+=	-e "s,/dev/dsp,${DEVOSSAUDIO},"
SUBST_FILES.audio+=	stream/audio_in.c waftools/checks/custom.py wscript
SUBST_STAGE.audio=	pre-configure
SUBST_MESSAGE.audio=	Fixing path to audio device.

#SUBST_CLASSES+=		etc
#SUBST_SED.etc+=		-e "s,etc/,share/examples/mpv,"
#SUBST_FILES.etc+=	wscript_build.py
#SUBST_STAGE.etc=	post-configure
#SUBST_MESSAGE.etc=	Fixing configuration file installation path.

post-extract:
	#cd ${WRKSRC} && ${PYTHONBIN} bootstrap.py
	cp ${FILESDIR}/waf ${WRKSRC}
	chmod 555 ${WRKSRC}/waf

do-configure:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf configure

do-build:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf

do-install:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf install

.include "../../lang/python/application.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
