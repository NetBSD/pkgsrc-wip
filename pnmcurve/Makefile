# $NetBSD: Makefile,v 1.7 2012/11/15 19:03:30 othyro Exp $
#

DISTNAME=	pnmcurve-0.0.4
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/
COMMENT=	Apply tone curves to pnm images

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../math/gsl/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
