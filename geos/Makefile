# $NetBSD: Makefile,v 1.3 2005/03/30 16:37:55 daprice Exp $
#

DISTNAME=		geos-2.0.0
CATEGORIES=		wip
MASTER_SITES=		http://geos.refractions.net/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://geos.refractions.net/
COMMENT=		C++ port of the Java Topology Suite (JTS)

CONFLICTS=		geos-1.0.0

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
