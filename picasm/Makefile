# $NetBSD: Makefile,v 1.9 2006/09/09 02:49:33 obache Exp $
#

DISTNAME=	picasm105
PKGNAME=	picasm-1.05
CATEGORIES=	devel
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/pic/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://hyvatti.iki.fi/~jaakko/pic/
COMMENT=	Assembler for Microchip PIC16Cxx microcontrollers

MAKE_FILE=	makefile.uni
BUILD_TARGET=	picasm
WRKSRC=		${WRKDIR}

USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picasm ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/picasm/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/picasm/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/picasm
	${INSTALL_DATA} ${WRKSRC}/picasm.doc ${PREFIX}/share/doc/picasm

.include "../../mk/bsd.pkg.mk"
