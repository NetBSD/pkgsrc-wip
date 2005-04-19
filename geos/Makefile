# $NetBSD: Makefile,v 1.6 2005/04/19 22:41:22 daprice Exp $
#

DISTNAME=		geos-2.0.0
CATEGORIES=		wip
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
