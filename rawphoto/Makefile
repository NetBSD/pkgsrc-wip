# $NetBSD: Makefile,v 1.1.1.1 2004/10/24 13:18:05 lexort Exp $

DISTNAME=	rawphoto.c
PKGNAME=	rawphoto-1.1.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.cybercom.net/~dcoffin/dcraw/
EXTRACT_SUFX=

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cybercom.net/~dcoffin/dcraw/
COMMENT=	GIMP plugin for dcraw (digital camera raw file decoder)

# The dcraw program is executed by the plugin.
DEPENDS+=	dcraw>=1.208:../../graphics/dcraw

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
USE_BUILDLINK3=	yes

do-extract:
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTNAME} ${WRKSRC})

do-build:
	(cd ${WRKSRC} && gimptool-2.0 --build ${DISTNAME})

do-install:
	(cd ${WRKSRC} && gimptool-2.0 --install-admin-bin rawphoto)

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
