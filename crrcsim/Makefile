# $NetBSD: Makefile,v 1.1.1.1 2010/10/26 15:27:58 hfath Exp $
#

DISTNAME=	crrcsim-0.9.11
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/crrcsim/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://crrcsim.berlios.de/wiki/
COMMENT=	Crrcsim is a model-airplane flight simulation program
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../audio/portaudio/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
# No pkgsrc package, yet
##.include "../../math/cgal/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
