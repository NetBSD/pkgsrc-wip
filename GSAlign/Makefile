# $NetBSD$

GITHUB_PROJECT=	GSAlign
GITHUB_TAG=	refs/tags/1.0.22
DISTNAME=	1.0.22
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=hsinnan75/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hsinnan75/GSAlign/
COMMENT=	Ultra-fast intra-species sequence alignment
LICENSE=	mit

WRKSRC=		${WRKDIR}/GSAlign-1.0.22
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/GSAlign ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bwt_index ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
