# $NetBSD$

DISTNAME=	bsa-2024.02.06
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=MEGA65/}
GITHUB_PROJECT=	BSA
GITHUB_TAG=	a9382915244a26075a6797e78f110df337a3405b

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MEGA65/BSA
COMMENT=	Cross-assembler for 6502-like processors
LICENSE=	public-domain

USE_LANGUAGES=	c

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/bsa

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o bsa bsa.c
	cd ${WRKSRC} && sed -n -e '3,/\*\//p' <bsa.c >bsa.readme

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsa ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/bsa.readme ${DESTDIR}${PREFIX}/share/doc/bsa

.include "../../mk/bsd.pkg.mk"
