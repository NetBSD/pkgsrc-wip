# $NetBSD: Makefile,v 1.6 2005/03/07 15:12:37 dillo Exp $
#

DISTNAME=	glulxe-035
PKGNAME=	glulxe-0.3.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IFARCHIVE:=programming/glulx/interpreters/glulxe/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.eblong.com/zarf/glulx/index.html
COMMENT=	Interpreter for Glulx text adventures

WRKSRC=		${WRKDIR}/glulxe
USE_BUILDLINK3=	yes
MAKE_ENV+=	BUILDLINK_DIR=${BUILDLINK_DIR}

.include "../../wip/glkloader/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glulxe ${LOCALBASE}/bin

.include "../../mk/bsd.pkg.mk"
