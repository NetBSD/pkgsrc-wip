# $NetBSD$

DISTNAME=	0.4.2
PKGNAME=	mepo-0.4.2
DIST_SUBDIR=	mepo
CATEGORIES=	geography
MASTER_SITES=	https://git.sr.ht/~mil/mepo/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sr.ht/~mil/Mepo/
COMMENT=	Fast, simple, and hackable OSM map viewer
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/mepo-0.4.2

.include "../../lang/zig/application.mk"
_ZIGBUILDINSTALLARGS+=	--search-prefix ${PREFIX}

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_gfx/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
