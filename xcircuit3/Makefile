# $NetBSD: Makefile,v 1.2 2003/07/21 16:09:38 bubuchka Exp $

DISTNAME=	xcircuit-3.1.17
CATEGORIES=	cad graphics
MASTER_SITES=	http://xcircuit.ece.jhu.edu/archive/	\
		http://bach.ece.jhu.edu/~tim/programs/xcircuit/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mishka@terabyte.com.ua
HOMEPAGE=	http://xcircuit.ece.jhu.edu/
COMMENT=	Drawing program for X11 (especially for electric circuits)

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_X11BASE=	yes

post-extract:
	${RM} -fr ${WRKSRC}/examples/CVS
	${MV} -f ${WRKSRC}/examples/.xcircuitrc ${WRKSRC}/examples/xcircuitrc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xcircuit/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/xcircuit/

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
