# $NetBSD$

DISTNAME=	restoHack-1.0.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Critlist/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	7dd3106cc4c4b63e0ee4d9b477ecebb9a1f63781

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Critlist/restoHack/
COMMENT=	Modern version of the original Hack
LICENSE=	public-domain AND modified-bsd

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man/man6,${PKGMANDIR}/man6,"
SUBST_FILES.man+=	CMakeLists.txt
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page installation path.

.include "../../devel/cmake/build.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
