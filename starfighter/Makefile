# $NetBSD$

DISTNAME=	starfighter-1.6-src
PKGNAME=	starfighter-1.6
CATEGORIES=	games
MASTER_SITES=	http://download.savannah.gnu.org/releases/starfighter/1.6/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starfighter.nongnu.org/
COMMENT=	Side-scrolling shoot 'em up space game
LICENSE=	gnu-gpl-v3 AND public-domain AND cc-by-sa-v3.0 AND cc0-1.0-universal

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

BUILD_MAKE_FLAGS+=	BINDIR=${PREFIX}/bin/
INSTALL_MAKE_FLAGS+=	BINDIR=${PREFIX}/bin/

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
