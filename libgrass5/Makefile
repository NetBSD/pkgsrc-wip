# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:39 asau Exp $
#

DISTNAME=		libgrass5-1.0.0
CATEGORIES=		geography
MASTER_SITES=		http://gdal.velocet.ca/projects/grass/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.velocet.ca/projects/grass/index.html
COMMENT=		Standalone shared library suitable for use by non-GRASS applications


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
