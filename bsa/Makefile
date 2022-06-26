# $NetBSD$

DISTNAME=	bsa-2022.03.19
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=Edilbert/}
GITHUB_PROJECT=	BSA
GITHUB_TAG=	2dcb832724cab15b452798cf1dbcc66ea73198b8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Edilbert/BSA
COMMENT=	Cross-assembler for 6502-like processors
#LICENSE=	unknown

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
