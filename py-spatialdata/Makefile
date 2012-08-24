# $NetBSD: Makefile,v 1.2 2012/08/24 10:36:21 jihbed Exp $
#

DISTNAME=	spatialdata-1.8.0
CATEGORIES=	science
MASTER_SITES=	http://www.geodynamics.org/cig/software/pylith/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.geodynamics.org/cig/software/pylith/
COMMENT=	Spatialdata provides transformations among coordinate systems
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

CHECK_PORTABILITY_SKIP= configure
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
