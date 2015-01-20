# $NetBSD: Makefile,v 1.4 2015/01/20 14:42:14 yrmt Exp $

GHCOMMIT=	10195c7f9452e37605fd63061b1421c6dcbc425e
DISTNAME=	${GHCOMMIT}
PKGNAME=	2bwm-2014-8
CATEGORIES=	wm
MASTER_SITES=	https://github.com/venam/2bwm/archive/

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	http://github.com/venam/2bwm
COMMENT=	Fast floating WM written over the XCB library and derived from mcwm
LICENSE=	isc

WRKSRC=		${WRKDIR}/2bwm-${GHCOMMIT}

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
