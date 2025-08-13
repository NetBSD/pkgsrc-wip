# $NetBSD$

DISTNAME=	qsstv-0.0.0.72
PKGNAME=	${DISTNAME}
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=ON4QZ/}
GITHUB_PROJECT=	QSSTV
GITHUB_TAG=	85d92199b94c930d73ce94c31a29efe6b37d8590
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.zip

MAINTAINER=	dvollen@gmail.com
HOMEPAGE=	https://github.com/ON4QZ/QSSTV/
COMMENT=	SSTV encoder and decoder using Qt
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/QSSTV-85d92199b94c930d73ce94c31a29efe6b37d8590/src
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake -o Makefile PREFIX=${PREFIX}

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools


.include "../../math/fftw/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
#.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
# ALSA and PulseAudio may go here
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
