# $NetBSD: Makefile,v 1.1 2015/08/19 19:21:33 yhardy Exp $

DISTNAME=	refkeen-src-20150313
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=NY00123/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	refkeen
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NY00123/refkeen/
COMMENT=	Port of Keen Dreams, Catacomb 3-D and The Catacomb Adventure Series
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

REFKEEN_PROGS+= refcat3d-100
REFKEEN_PROGS+= refcat3d-122
REFKEEN_PROGS+= refcatabyss-113
REFKEEN_PROGS+= refcatabyss-124
REFKEEN_PROGS+= refcatapoc-101
REFKEEN_PROGS+= refcatarm-102
REFKEEN_PROGS+= refkdreams-cga105
REFKEEN_PROGS+= refkdreams-reg193
REFKEEN_PROGS+= refkdreams-shar113
REFKEEN_PROGS+= refkdreams-shar120

INSTALLATION_DIRS=	bin share/doc/${PKGNAME}

do-install:
	for prog in ${REFKEEN_PROGS}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/src/$$prog ${DESTDIR}${PREFIX}/bin/; \
	done
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
