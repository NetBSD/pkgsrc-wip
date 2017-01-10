# $NetBSD$

DISTNAME=	lander-0.6.4
CATEGORIES=	games
MASTER_SITES=	http://www.nickg.me.uk/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.doof.me.uk/lunar-lander/
COMMENT=	Lunar Lander clone
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config xgettext

CONFIGURE_ARGS+=	--with-boost="${PREFIX}"\
			--with-boost-filesystem=boost_filesystem
#LDFLAGS=		-L${LOCALBASE}/lib

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
