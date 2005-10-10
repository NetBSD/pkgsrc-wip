# $NetBSD: Makefile,v 1.1 2005/10/10 17:46:00 mchittur Exp $
#

DISTNAME=		libopenmodeller-0.3.3
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openmodeller/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://openmodeller.sourceforge.net/
COMMENT=		Spatial distribution modelling library

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../textproc/expat/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../wip/gdal-lib/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
