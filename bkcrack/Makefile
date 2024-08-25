# $NetBSD$

DISTNAME=	bkcrack-1.3.5
CATEGORIES=	archivers security
MASTER_SITES=	${MASTER_SITE_GITHUB:=kimci86/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kimci86/bkcrack/
COMMENT=	Crack legacy zip encryption with a known-plaintext attack
LICENSE=	zlib

USE_CMAKE=	yes
USE_LANGUAGES=	c++

CMAKE_CONFIGURE_ARGS+=	-DBKCRACK_PARALLEL_MODE:BOOL=OFF

INSTALLATION_DIRS=	bin share/doc/bkcrack share/examples/bkcrack

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/bkcrack ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/example/* ${DESTDIR}${PREFIX}/share/examples/bkcrack
	${INSTALL_PROGRAM} ${WRKSRC}/license.txt ${DESTDIR}${PREFIX}/share/doc/bkcrack
	${INSTALL_PROGRAM} ${WRKSRC}/readme.md ${DESTDIR}${PREFIX}/share/doc/bkcrack
	${INSTALL_PROGRAM} ${WRKSRC}/tools/*.py ${DESTDIR}${PREFIX}/share/doc/bkcrack

.include "../../mk/bsd.pkg.mk"
