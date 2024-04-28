# $NetBSD$

V=1.0.3
DISTNAME=	davegnukem-${V}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=davidjoffe/}
GITHUB_TAG=	${V}
GITHUB_PROJECT=	dave_gnukem
EXTRACT_USING=	bsdtar

# The game data is distributed as a separate file.
SITES.davegnukem-data-${V}.tar.gz= \
-https://github.com/davidjoffe/gnukem_data/archive/refs/tags/${V}.tar.gz
DISTFILES=	${DEFAULT_DISTFILES} davegnukem-data-${V}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://djoffe.com/gnukem/
COMMENT=	2D sidescrolling platform shooter
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	PREFIX=${PREFIX}
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
PLIST.bsd=	yes

# The Makefile install step expects to find the data files in data/
pre-configure:
	cd ${WRKSRC} && mv ../gnukem_data-${V} data

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man path
SUBST_FILES.man=	Makefile
SUBST_SED.man+=	-e 's,share/man,${PKGMANDIR},g'

BUILDLINK_API_DEPENDS.SDL2+=		SDL2>=2.0.7
.include "../../devel/SDL2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
