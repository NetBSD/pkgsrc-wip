# $NetBSD: Makefile,v 1.1.1.1 2003/07/12 13:48:46 poppnk Exp $
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
ALL_TARGET=	picasm

USE_GMAKE=	yes
USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picasm ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/picasm/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/picasm/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/picasm
	${INSTALL_DATA} ${WRKSRC}/picasm.doc ${PREFIX}/share/doc/picasm

.include "../../mk/bsd.pkg.mk"
