# $NetBSD: Makefile,v 1.11 2012/11/25 23:32:29 othyro Exp $
#

DISTNAME=	picasm105
PKGNAME=	picasm-1.05
CATEGORIES=	devel
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/pic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hyvatti.iki.fi/~jaakko/pic/
COMMENT=	Assembler for Microchip PIC16Cxx microcontrollers

MAKE_FILE=	makefile.uni
BUILD_TARGET=	picasm
WRKSRC=		${WRKDIR}

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picasm ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/picasm/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/share/examples/picasm/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/picasm
	${INSTALL_DATA} ${WRKSRC}/picasm.doc ${DESTDIR}${PREFIX}/share/doc/picasm

.include "../../mk/bsd.pkg.mk"
