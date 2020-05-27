# $NetBSD: Makefile,v 1.4 2015/09/13 20:07:57 yhardy Exp $

DISTNAME=	bstone-1.2.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=bibendovsky/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bibendovsky.github.io/bstone/
COMMENT=	Source port of Blake Stone game engines
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/bstone-${PKGVERSION_NOREV}/src
USE_CMAKE=	yes
USE_LANGUAGES=	c++14
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin share/doc/${PKGNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bstone ${DESTDIR}${PREFIX}/bin/bstone
	${INSTALL_DATA} ${WRKSRC}/../README.md ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/README

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
