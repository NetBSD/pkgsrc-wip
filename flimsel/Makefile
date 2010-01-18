# $NetBSD: Makefile,v 1.6 2010/01/18 09:38:21 thomasklausner Exp $
#

DISTNAME=	flimsel-0.0.6
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/flimsel.html
COMMENT=	Fast Light Image Selector
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/epeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
