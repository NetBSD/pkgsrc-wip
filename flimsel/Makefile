# $NetBSD: Makefile,v 1.10 2012/06/03 23:07:35 othyro Exp $
#

DISTNAME=	flimsel-0.0.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/flimsel.html
COMMENT=	Fast Light Image Selector
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

.include "../../graphics/epeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
