# $NetBSD: Makefile,v 1.1 2015/08/19 19:21:33 yhardy Exp $

DISTNAME=	refkeen-20201225
GITHUB_PROJECT=	refkeen
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=NY00123/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NY00123/refkeen/
COMMENT=	Port of Keen Dreams, Catacomb 3-D and The Catacomb Adventure Series
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

REFKEEN_PROGS+=	reflection-catacomb
REFKEEN_PROGS+=	reflection-kdreams
REFKEEN_PROGS+=	reflection-wolf3d

INSTALLATION_DIRS=	bin share/doc/${PKGNAME}

do-install:
	for prog in ${REFKEEN_PROGS}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/$$prog ${DESTDIR}${PREFIX}/bin/; \
	done
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/

.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
