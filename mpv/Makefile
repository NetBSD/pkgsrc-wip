# $NetBSD: Makefile,v 1.2 2014/08/07 01:55:56 leot1990 Exp $

DISTNAME=	mpv-0.4.2
CATEGORIES=	multimedia
MASTER_SITES=	-https://github.com/mpv-player/mpv/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mpv.io/
COMMENT=	Video player based on MPlayer and mplayer2
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

# XXX: MANDIR variable is ignored and so it should be specified via --mandir
WAF_ENV=	PATH=${PATH:Q} CC=${CC:Q} CXX=${CXX:Q} PREFIX=${PREFIX} \
		MANDIR=${PREFIX}/${PKGMANDIR} CFLAGS=${CFLAGS:Q} \
		CXXFLAGS=${CXXFLAGS:Q} LINKFLAGS=${LDFLAGS:Q} DESTDIR=${DESTDIR}
WAF_ARGS=	--mandir=${PREFIX}/${PKGMANDIR}

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-docutils

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

#SUBST_CLASSES+=	etc
#SUBST_SED.etc+=	-e "s,etc/,share/examples/mpv,"
#SUBST_FILES.etc+=	wscript_build.py
#SUBST_STAGE.etc=	post-configure
#SUBST_MESSAGE.etc=	Fixing configuration file installation path.

post-extract:
	#cd ${WRKSRC} && ${PYTHONBIN} bootstrap.py
	cp ${FILESDIR}/waf ${WRKSRC}
	chmod 555 ${WRKSRC}/waf

do-configure:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf ${WAF_ARGS} configure

do-build:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf ${WAF_ARGS}

do-install:
	cd ${WRKSRC} && env ${WAF_ENV} ./waf ${WAF_ARGS} install

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/application.mk"
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
