# $NetBSD: Makefile,v 1.1.1.1 2006/12/03 00:38:43 dhowland Exp $
#

DISTNAME=	vpr-4.30
CATEGORIES=	cad
MASTER_SITES=	http://www.eecg.toronto.edu/~vaughn/vpr/downloadfiles/

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://www.eecg.toronto.edu/~vaughn/vpr/vpr.html
COMMENT=	Classic place and route tool for FPGAs

DISTFILES=	vpr_430_tar.gz
EXTRACT_OPTS+=	-d ${WRKSRC}

BUILD_DIRS=	t-vpack vpr
MAKE_FILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/t-vpack/t-vpack ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vpr/vpr ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vpr
	${INSTALL_DATA} ${WRKSRC}/README_430.txt ${PREFIX}/share/doc/vpr
	${INSTALL_DATA} ${WRKSRC}/manual_430.pdf ${PREFIX}/share/doc/vpr
	${INSTALL_DATA} ${WRKSRC}/manual_430.ps ${PREFIX}/share/doc/vpr

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
