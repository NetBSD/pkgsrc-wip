# $NetBSD: Makefile,v 1.1 2015/08/18 21:34:26 yhardy Exp $

GITHUB_PROJECT=	bstone
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-1.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=bibendovsky/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bibendovsky.github.io/bstone/
COMMENT=	Source port of Blake Stone game engines
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/bstone-1.1.1
USE_CMAKE=	yes
USE_LANGUAGES=	c++

INSTALLATION_DIRS+=	bin share/doc/${PKGNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bstone ${DESTDIR}${PREFIX}/bin/bstone
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/README

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
