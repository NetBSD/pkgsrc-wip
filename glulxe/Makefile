# $NetBSD: Makefile,v 1.4 2004/05/23 23:19:13 dillo Exp $
#

DISTNAME=	glulxe-035
PKGNAME=	glulxe-0.3.5
WRKSRC=		${WRKDIR}/glulxe
CATEGORIES=	games
MASTER_SITES=	http://mirror.ifarchive.org/if-archive/programming/glulx/interpreters/glulxe/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.eblong.com/zarf/glulx/index.html
COMMENT=	Interpreter for Glulx text adventures

USE_BUILDLINK3=	yes
MAKE_ENV+=	BUILDLINK_DIR=${BUILDLINK_DIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glulxe ${LOCALBASE}/bin

#.include "../../wip/gtkglk/buildlink3.mk"
.include "../../wip/glkterm/buildlink3.mk"
#.include "../../wip/xglk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
