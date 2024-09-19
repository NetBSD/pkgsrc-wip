# $NetBSD$

DISTNAME=	libexact-1.0
CATEGORIES=	math
MASTER_SITES=	http://pottonen.kapsi.fi/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pottonen.kapsi.fi/libexact.html
COMMENT=	Solve combinatorial exact covering problems
LICENSE=	gnu-gpl-v2

TEST_TARGET=		check
INSTALLATION_DIRS=	bin include lib share/doc/libexact

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/solve ${DESTDIR}${PREFIX}/bin/solve-libexact
	${INSTALL_DATA} ${WRKSRC}/exact.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libexact.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/guide.pdf ${DESTDIR}${PREFIX}/share/doc/libexact

.include "../../mk/bsd.pkg.mk"
