# $NetBSD: Makefile,v 1.4 2010/12/26 05:01:21 davesainty Exp $
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

# No pkgsrc package, yet
##.include "../../math/cgal/buildlink3.mk"
##.include "../../devel/boost-libs/buildlink3.mk"

.include "../../audio/portaudio/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
