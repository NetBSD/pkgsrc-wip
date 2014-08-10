# $NetBSD: Makefile,v 1.2 2014/08/10 12:53:16 yrmt Exp $

PKGNAME=	bspwm-0.8.9
CATEGORIES=	wm
GHCOMMIT=	1e0a7c826e5f82e31b18bf4c6173add2ea9306bd
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

.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
