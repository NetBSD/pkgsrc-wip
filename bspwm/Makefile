# $NetBSD: Makefile,v 1.1 2014/06/05 23:11:23 yrmt Exp $

PKGNAME=	bspwm-0.8.8
CATEGORIES=	wm
GHCOMMIT=	ff26c3426bda8fb1f88e25ec46f7516dcfb7427f
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	https://github.com/baskerville/bspwm/archive/

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	https://github.com/baskerville/bspwm
COMMENT= 	Binary space partitioning window manager	
LICENSE=	2-clause-bsd

DIST_SUBDIR=	bspwm
WRKSRC=		${WRKDIR}/bspwm-${GHCOMMIT}
USE_TOOLS+=	gmake

SUBST_CLASSES+=         makefile
SUBST_STAGE.makefile=   pre-build
SUBST_MESSAGE.makefile= Fixing makefile
SUBST_FILES.makefile=   Makefile
SUBST_SED.makefile=    -e 's,share/man,${PKGMANDIR},g'

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
