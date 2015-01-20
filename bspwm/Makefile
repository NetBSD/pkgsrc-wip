# $NetBSD: Makefile,v 1.3 2015/01/20 14:45:39 yrmt Exp $

GHCOMMIT=	1e0a7c826e5f82e31b18bf4c6173add2ea9306bd
DISTNAME=	${GHCOMMIT}
PKGNAME=	bspwm-0.8.9
CATEGORIES=	wm
MASTER_SITES=	https://github.com/baskerville/bspwm/archive/

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	https://github.com/baskerville/bspwm
COMMENT=	Binary space partitioning window manager
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/bspwm-${GHCOMMIT}
USE_TOOLS+=	gmake

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,share/man,${PKGMANDIR},g'

.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
