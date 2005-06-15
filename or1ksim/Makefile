# $NetBSD: Makefile,v 1.1.1.1 2005/06/15 10:57:26 jmmv Exp $
#

DISTNAME=	or1k_or1ksim-stable_0_1_x
PKGNAME=	or1ksim-0.1.x
CATEGORIES=	wip emulators
DYNAMIC_MASTER_SITES=YES

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.opencores.org/projects.cgi/web/or1k/architectural_simulator
COMMENT=	OpenRISC emulator

BUILD_DEPENDS+= wget>=1.9.1nb2:../../net/wget

PKG_INSTALLATION_TYPES= overwrite pkgviews

WRKSRC=       ${WRKDIR}/or1k/or1ksim

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES
GNU_CONFIGURE=  YES

CONFIGURE_ENV+=	OR1KSIM_CPU="or32"

post-build:
	${MV} ${WRKSRC}/sim ${WRKSRC}/or1ksim
	${MV} ${WRKSRC}/sim.cfg ${WRKSRC}/or1ksim.cfg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/or1ksim ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
.for f in AUTHORS BUGS COPYING INSTALL ChangeLog NEWS README README.gdb TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PKGBASE}
.endfor
.for f in or1ksim.cfg virtex.tim
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/${PKGBASE}
.endfor

.include "../../mk/bsd.pkg.mk"

