# $NetBSD: Makefile,v 1.6 2010/01/18 09:38:35 thomasklausner Exp $
#

DISTNAME=		xgfe-2.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_TEX_CTAN=graphics/gnuplot/contrib}

MAINTAINER=		dprice@cs.nmsu.edu
COMMENT=		GUI front end for Gnuplot plotting package

WRKSRC=			${WRKDIR}/xgfe-2.1/source

USE_LANGUAGES=		c c++

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
