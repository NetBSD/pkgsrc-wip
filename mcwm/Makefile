# $NetBSD: Makefile,v 1.7 2014/08/21 20:23:59 yrmt Exp $
#

DISTNAME=	mcwm-20130209
CATEGORIES=	wm
MASTER_SITES=	http://www.hack.org/mc/hacks/mcwm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.hack.org/mc/hacks/mcwm/
COMMENT=	Window manager for the X Window System written entirely with XCB
LICENSE=	isc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mcwm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mcwm.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mcwm.1

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
