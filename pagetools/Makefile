# $NetBSD: Makefile,v 1.7 2014/09/08 21:24:08 thomasklausner Exp $

DISTNAME=	pagetools-0.1
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pagetools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pagetools.sourceforge.net/
COMMENT=	Automatic deskew and bounding box determination for scanned pages
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.netpbm}/lib
CPPFLAGS+=	-I${BUILDLINK_PREFIX.netpbm}/include/netpbm

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pbm_findskew/pbm_findskew ${DESTDIR}${PREFIX}/bin/pbm_findskew
	${INSTALL_SCRIPT} ${WRKSRC}/tiff_findskew/tiff_findskew ${DESTDIR}${PREFIX}/bin/tiff_findskew

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
