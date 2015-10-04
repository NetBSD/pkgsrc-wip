# $NetBSD$

DISTNAME=	FLIF-0.1alpha
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jonsneyers/}
GITHUB_TAG=	v0.1-alpha

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flif.info/
COMMENT=	Free Lossless Image Format
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/FLIF-0.1-alpha
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	flif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flif ${DESTDIR}${PREFIX}/bin

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
