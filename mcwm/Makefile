# $NetBSD: Makefile,v 1.6 2012/10/03 15:09:53 asau Exp $
#

DISTNAME=	mcwm-20111124
CATEGORIES=	wm
MASTER_SITES=	http://www.hack.org/mc/hacks/mcwm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hack.org/mc/hacks/mcwm/
COMMENT=	Window manager for the X Window System written entirely with XCB
LICENSE=	isc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		rpath
SUBST_SED.rpath=	-e "s,@@PREFIX@@,${BUILDLINK_PREFIX.libxcb},"
SUBST_FILES.rpath=	Makefile
SUBST_STAGE.rpath=	pre-build
SUBST_MESSAGE.rpath=	Fixing path to xcb.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mcwm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mcwm.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mcwm.1

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
