# $NetBSD: Makefile,v 1.2 2005/02/15 00:52:44 dillo Exp $
#

DISTNAME=		scare-1.3.3
CATEGORIES=		games
MASTER_SITES=		http://www.geocities.com/legion_if/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.geocities.com/legion_if/scare.html
COMMENT=		Interpreter for interactive fiction written in Adrift

USE_BUILDLINK3=		yes
BUILD_TARGET=		glkscare
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

DOCDIR=			${LOCALBASE}/share/doc/scare

.include "../../wip/glkterm/buildlink3.mk"
#.include "../../wip/gtkglk/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glkscare ${LOCALBASE}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/DEBUGGER ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RUNNING ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
