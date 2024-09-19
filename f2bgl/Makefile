# $NetBSD$

GITHUB_PROJECT=	f2bgl
GITHUB_TAG=	0.3.1
DISTNAME=	0.3.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=cyxx/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cyxdown.free.fr/f2b/
COMMENT=	Re-implementation of the engine used in the game Fade To Black
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/f2bgl-0.3.1
USE_LANGUAGES=	c++

BUILD_TARGET=		f2bgl

INSTALLATION_DIRS=	bin share/doc/f2bgl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/f2bgl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${PREFIX}/share/doc/f2bgl

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libwildmidi/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
