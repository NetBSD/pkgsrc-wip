# $NetBSD$
#

DISTNAME=	crrcsim-0.9.13
#PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=crrcsim/}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://crrcsim.sourceforge.net/apps/mediawiki/crrcsim/
COMMENT=	Crrcsim is a model-airplane flight simulation program
LICENSE=	gnu-gpl-v2

#USE_TOOLS+=	gettext gmake

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
