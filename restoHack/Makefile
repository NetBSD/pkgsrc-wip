# $NetBSD$

DISTNAME=	restoHack-1.0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Critlist/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Critlist/restoHack/
COMMENT=	Modern version of the original Hack
LICENSE=	public-domain AND modified-bsd

LIBS.NetBSD+=	-lcurses

.include "../../devel/cmake/build.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
