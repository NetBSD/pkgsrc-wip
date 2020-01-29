# $NetBSD$

GITHUB_PROJECT=	cosmo-engine
GITHUB_TAG=	c9d6aeda06bb88388fda5e4a9e1c93e624a0ea44
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-0.0
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=yuv422/}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yuv422/cosmo-engine/
COMMENT=	Game engine to play Cosmo's Cosmic Adventure
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/cosmo-engine-c9d6aeda06bb88388fda5e4a9e1c93e624a0ea44
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cosmo_engine ${DESTDIR}${PREFIX}/bin

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
