# $NetBSD: Makefile,v 1.1.1.1 2004/11/19 21:50:58 daprice Exp $
#

DISTNAME=		libgrass5-1.0.0
CATEGORIES=		geography
MASTER_SITES=		http://gdal.velocet.ca/projects/grass/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.velocet.ca/projects/grass/index.html
COMMENT=		Standalone shared library suitable for use by non-GRASS applications

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
