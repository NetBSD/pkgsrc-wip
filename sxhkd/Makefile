# $NetBSD: Makefile,v 1.2 2015/01/20 14:56:00 yrmt Exp $

GHCOMMIT=		e94452a2a0f40909e31d7b0b4ee83e05a4bd5e68
DISTNAME=		${GHCOMMIT}
PKGNAME=		sxhkd-0.5.4
CATEGORIES=		x11
MASTER_SITES=		http://github.com/baskerville/sxhkd/archive/

MAINTAINER=		youri.mout@gmail.com
HOMEPAGE=		https://github.com/baskerville/sxhkd
COMMENT=		Simple X hotkey daemon
LICENSE=		2-clause-bsd

WRKSRC=			${WRKDIR}/sxhkd-${GHCOMMIT}
USE_TOOLS+=		gmake

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,share/man,${PKGMANDIR},g'

.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
