# $NetBSD: Makefile,v 1.6 2012/10/05 11:31:52 asau Exp $
#

DISTNAME=	pnmcurve-0.0.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/
COMMENT=	Apply tone curves to pnm images

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../math/gsl/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
