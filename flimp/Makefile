# $NetBSD: Makefile,v 1.3 2009/02/16 18:55:34 jh88 Exp $
#

DISTNAME=	flimp-0.0.8
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/flimp.html
COMMENT=	Generic GUI for image manipulation

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++

DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
DEPENDS+=	pnmcurve-[0-9]*:../../wip/pnmcurve

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
