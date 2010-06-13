# $NetBSD: Makefile,v 1.5 2010/06/13 22:47:13 thomasklausner Exp $
#

DISTNAME=	pnmcurve-0.0.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/
COMMENT=	Apply tone curves to pnm images

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../math/gsl/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
