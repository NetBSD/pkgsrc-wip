# $NetBSD: Makefile,v 1.2 2005/03/18 21:17:35 daprice Exp $
#

DISTNAME=		geos-1.0.0
CATEGORIES=		wip geography
MASTER_SITES=		http://geos.refractions.net/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://geos.refractions.net/
COMMENT=		C++ port of the Java Topology Suite (JTS)

WRKSRC=			${WRKDIR}/geos-1.0
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
