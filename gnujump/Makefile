# $NetBSD$

DISTNAME=	gnujump-1.0.8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=gnujump/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://gnujump.es.gnu.org/index.php/Main_Page
COMMENT=	GNUjump is a clone of the simple yet addictive game Xjump
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
