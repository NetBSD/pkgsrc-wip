# $NetBSD: Makefile,v 1.7 2005/11/02 18:00:14 thomasklausner Exp $
#

DISTNAME=		geos-2.0.0
CATEGORIES=		geography
MASTER_SITES=		http://geos.refractions.net/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://geos.refractions.net/
COMMENT=		C++ port of the Java Topology Suite (JTS)

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

USE_LANGUAGES+=		c++

.include "../../mk/bsd.pkg.mk"
