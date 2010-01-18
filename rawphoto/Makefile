# $NetBSD: Makefile,v 1.9 2010/01/18 09:38:31 thomasklausner Exp $

DISTNAME=	rawphoto.c
PKGNAME=	rawphoto-1.1.15
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.cybercom.net/~dcoffin/dcraw/
EXTRACT_SUFX=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cybercom.net/~dcoffin/dcraw/
COMMENT=	GIMP plugin for dcraw (digital camera raw file decoder)

# The dcraw program is executed by the plugin.
DEPENDS+=	dcraw>=1.208:../../graphics/dcraw

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

do-extract:
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTNAME} ${WRKSRC})

do-build:
	(cd ${WRKSRC} && gimptool-2.0 --build ${DISTNAME})

do-install:
	(cd ${WRKSRC} && gimptool-2.0 --install-admin-bin rawphoto)

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
