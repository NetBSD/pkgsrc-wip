# $NetBSD: Makefile,v 1.2 2010/01/18 09:38:28 thomasklausner Exp $
#

DISTNAME=	pagetools-0.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pagetools/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://pagetools.sourceforge.net/
COMMENT=	Automatic deskew and bounding box determination for scanned pages
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c++
USE_TOOLS=	gmake

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pbm_findskew/pbm_findskew ${PREFIX}/bin/pbm_findskew
	${INSTALL_SCRIPT} ${WRKSRC}/tiff_findskew/tiff_findskew ${PREFIX}/bin/tiff_findskew

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
