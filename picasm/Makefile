# $NetBSD: Makefile,v 1.4 2004/12/02 16:39:05 thomasklausner Exp $
#

DISTNAME=	picasm105
PKGNAME=	picasm-1.05
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=	http://www.iki.fi/hyvatti/pic/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.iki.fi/hyvatti/pic/picasm105/
COMMENT=	Assembler for Microchip PIC16Cxx microcontrollers

MAKEFILE=	makefile.uni
BUILD_TARGET=	picasm

USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picasm ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/picasm/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/picasm/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/picasm
	${INSTALL_DATA} ${WRKSRC}/picasm.doc ${PREFIX}/share/doc/picasm

.include "../../mk/bsd.pkg.mk"
