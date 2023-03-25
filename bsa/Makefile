# $NetBSD$

DISTNAME=	bsa-2023.03.01
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=Edilbert/}
GITHUB_PROJECT=	BSA
GITHUB_TAG=	e72bc5005c3d3e311540f52ba76c65b0de8636d5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Edilbert/BSA
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
