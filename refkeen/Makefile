# $NetBSD: Makefile,v 1.1 2015/08/19 19:21:33 yhardy Exp $
https://github.com/NY00123/refkeen/archive/release-20170401.tar.gz

DISTNAME=	refkeen-20170814
GITHUB_PROJECT=	refkeen
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=NY00123/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NY00123/refkeen/
COMMENT=	Port of Keen Dreams, Catacomb 3-D and The Catacomb Adventure Series
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

REFKEEN_PROGS+= reflection-cat3d
REFKEEN_PROGS+= reflection-catabyss
REFKEEN_PROGS+= reflection-catapoc
REFKEEN_PROGS+= reflection-catarm
REFKEEN_PROGS+= reflection-kdreams

INSTALLATION_DIRS=	bin share/doc/${PKGNAME}

do-install:
	for prog in ${REFKEEN_PROGS}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/src/$$prog ${DESTDIR}${PREFIX}/bin/; \
	done
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/

.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
