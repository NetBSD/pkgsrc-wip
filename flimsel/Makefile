# $NetBSD: Makefile,v 1.3 2009/03/05 00:35:07 othyro Exp $
#

DISTNAME=	flimsel-0.0.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/
COMMENT=	Minimalistic image browser

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/epeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
