# $NetBSD$

DISTNAME=	sc-im-0.7.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=andmarti1424/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ik@sjmulder.nl
HOMEPAGE=	https://github.com/andmarti1424/sc-im/
COMMENT=	Curses-based spreadsheet program based on sc
LICENSE=	original-bsd

BUILD_DIRS=	src
INSTALL_DIRS=	src

.include "../../mk/bsd.prefs.mk"

# pkg-config to avoid broken Makefile self-configuration
USE_TOOLS+=	gmake pkg-config yacc

# gnuplot is invoked through the shell, no need to check at compile time
CFLAGS+=	-DGNUPLOT

# it appears that DL_LIBS isn't otherwise handled by DL_AUTO_VARS
LDFLAGS+=	${DL_LIBS}

# defaults to scim
MAKE_FLAGS+=	name=sc-im
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

.include "options.mk"

.include "../../devel/ncursesw/buildlink3.mk"
DL_AUTO_VARS=	yes
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
