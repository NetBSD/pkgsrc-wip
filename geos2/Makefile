# $NetBSD: Makefile,v 1.1.1.1 2005/03/28 14:47:51 lexort Exp $
#

DISTNAME=		geos-2.0.1
CATEGORIES=		wip geography
MASTER_SITES=		http://geos.refractions.net/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://geos.refractions.net/
COMMENT=		C++ port of the Java Topology Suite (JTS)

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
