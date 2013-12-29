# $NetBSD: Makefile,v 1.13 2013/12/29 06:08:44 othyro Exp $
#

DISTNAME=	flimsel-0.1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/flimsel.html
COMMENT=	Fast Light Image Selector
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/epeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
