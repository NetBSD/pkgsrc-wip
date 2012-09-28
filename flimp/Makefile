# $NetBSD: Makefile,v 1.10 2012/09/28 23:21:48 asau Exp $
#

DISTNAME=	flimp-0.0.11
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/flimp.html
COMMENT=	Generic GUI for image manipulation
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++

DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
DEPENDS+=	pnmcurve-[0-9]*:../../wip/pnmcurve

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
