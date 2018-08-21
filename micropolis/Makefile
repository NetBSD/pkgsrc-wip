# $NetBSD$

DISTNAME=	micropolis-activity-source
PKGNAME=	micropolis-1530263971
CATEGORIES=	games
MASTER_SITES=	http://www.donhopkins.com/home/micropolis/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.donhopkins.com/home/micropolis/
COMMENT=	City-building simulation
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	bash:run pkg-config

PATCH_SITES=	http://git.zerfleddert.de/micropolis/patches/
PATCHFILES=	micropolis_git-1530263971-cc31822e4ebe54c0109623ac0c5cdf0e3acad755.patch
PATCH_DIST_STRIP=       -p1

WRKSRC=		${WRKDIR}/micropolis-activity

MAKE_JOBS_SAFE=	no

SUBST_CLASSES+=		fix-path
SUBST_STAGE.fix-path=	pre-configure
SUBST_MESSAGE.fix-path=	Fixing absolute path.
SUBST_FILES.fix-path=	Makefile src/sim/makefile src/tclx/config.mk src/tk/tkint.h src/tcl/makefile
SUBST_SED.fix-path=	-e 's|/usr/local|${PREFIX}|g'

SUBST_CLASSES+=			fix-x11-ldflags
SUBST_STAGE.fix-x11-ldflags=	pre-configure
SUBST_MESSAGE.fix-x11-ldflags=	Fixing X11 ldflags.
SUBST_FILES.fix-x11-ldflags=	src/sim/makefile src/tclx/config.mk src/tk/makefile
SUBST_SED.fix-x11-ldflags=	-e 's|-L/usr/X11R6/lib|${X11_LDFLAGS}|g'

REPLACE_BASH=	res/sounds/player

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
