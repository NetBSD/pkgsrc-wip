# $NetBSD: Makefile,v 1.4 2006/07/02 19:38:50 shattered Exp $
#

DISTNAME=		xgfe-2.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_TEX_CTAN=graphics/gnuplot/contrib}

MAINTAINER=		dprice@cs.nmsu.edu
COMMENT=		GUI front end for Gnuplot plotting package

WRKSRC=			${WRKDIR}/xgfe-2.1/source

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
