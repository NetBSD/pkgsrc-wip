# $NetBSD: Makefile,v 1.5 2012/02/27 14:26:25 hfath Exp $
#

DISTNAME=	crrcsim-0.9.11
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/crrcsim/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://crrcsim.berlios.de/wiki/
COMMENT=	Crrcsim is a model-airplane flight simulation program
LICENSE=	gnu-gpl-v2

#USE_TOOLS+=	gmake

PKG_DESTDIR_SUPPORT=	user-destdir

CONFGURE_ARGS+=	--with-GLU

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../math/cgal/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
