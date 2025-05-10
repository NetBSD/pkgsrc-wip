# $NetBSD$

DISTNAME=	bsa-2025.03.26
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=MEGA65/}
GITHUB_PROJECT=	BSA
GITHUB_TAG=	eaec1adc44ea2abda59df45d74855c9bf0f5a655

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
