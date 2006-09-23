# $NetBSD: Makefile,v 1.5 2006/09/23 18:21:05 gschwarz Exp $
#

DISTNAME=		e00pg-1.0.1
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=e00pg/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://e00pg.sourceforge.net/
COMMENT=		Converting ESRI-E00 coverages into PostgreSQL/PostGIS sql instructions

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
.if !empty(LOWER_OPSYS:Mirix5*)
# needs snprintf()
. include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
