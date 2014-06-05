# $NetBSD: Makefile,v 1.1 2014/06/05 12:38:49 yrmt Exp $

PKGNAME=	2bwm-0.1
CATEGORIES=	wm
GHCOMMIT=	52a097ca644eb571b22a135951c945fcca57a25c
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	https://github.com/venam/2bwm/archive/
FETCH_USING=	curl

WRKSRC=		${WRKDIR}/2bwm-${GHCOMMIT}

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	http://github.com/venam/2bwm
COMMENT=	Fast floating WM written over the XCB library and derived from mcwm
LICENSE=	isc

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
