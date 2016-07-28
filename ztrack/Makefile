# $NetBSD$

DISTNAME=	ztrack-1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/arcade/}

MAINTAINER=	pkgsrc-users@NetBSD.org
# Nothing better available
HOMEPAGE=	${MASTER_SITE_SUNSITE:=games/arcade/}
COMMENT=	Simple curses-based pseudo-3D driving game
LICENSE=	public-domain

WRKSRC=	${WRKDIR}/ztrack

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS="-DHAVE_RANDOM \
			-I${BUILDLINK_PREFIX.curses}/${BUILDLINK_INCDIRS.curses}"
MAKE_FLAGS+=	LIBS="-lcurses \
			-L${BUILDLINK_PREFIX.curses}/${BUILDLINK_LIBDIRS.curses} \
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.curses}/${BUILDLINK_LIBDIRS.curses}"
MAKE_FLAGS+=	BINDIR=${PREFIX}/bin
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man6

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
