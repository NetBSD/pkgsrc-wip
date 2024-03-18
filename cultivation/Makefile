# $NetBSD$

DISTNAME=	Cultivation_9_UnixSource
PKGNAME=	cultivation-9
CATEGORIES=	games
MASTER_SITES=	https://sourceforge.net/projects/cultivation/files/cultivation/v9/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cultivation.sourceforge.net/
COMMENT=	Game about a community of gardeners
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/${DISTNAME}/game2

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--linux
#MAKE_FILE=		Makefile.GnuLinux

BUILD_DIRS=	${WRKSRC}/gameSource

USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	bin

#pre-build:
#	${RM} -rf ${WRKDIR}/${DISTNAME}/minorGems/sound/portaudio/pa_common

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gameSource/Cultivation ${DESTDIR}${PREFIX}/bin

.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
