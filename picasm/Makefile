# $NetBSD: Makefile,v 1.6 2005/04/11 21:14:46 tvierling Exp $
#

DISTNAME=	picasm105
PKGNAME=	picasm-1.05
CATEGORIES=	devel
MASTER_SITES=	http://www.iki.fi/hyvatti/pic/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.iki.fi/hyvatti/pic/picasm105/
COMMENT=	Assembler for Microchip PIC16Cxx microcontrollers

MAKEFILE=	makefile.uni
BUILD_TARGET=	picasm
WRKSRC=		${WRKDIR}

USE_GNU_TOOLS+=	make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picasm ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/picasm/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/picasm/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/picasm
	${INSTALL_DATA} ${WRKSRC}/picasm.doc ${PREFIX}/share/doc/picasm

.include "../../mk/bsd.pkg.mk"
