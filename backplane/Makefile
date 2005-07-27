# $NetBSD: Makefile,v 1.2 2005/07/27 16:25:02 thomasklausner Exp $
#

DISTNAME=		backplane-1.05
CATEGORIES=		databases
MASTER_SITES=		http://apollo.backplane.com/FreeBSDPorts/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.backplane.com/
COMMENT=		Innovative RDBMS database by Matthew Dillon

BUILD_DEPENDS+=		dxmake>=0:../../wip/dxmake

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=		INSTALLDIR="${PREFIX}/${PKGBASE}"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/dxmake \
		${MAKE_FLAGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/dxmake \
		${MAKE_FLAGS} install

.include "../../mk/bsd.pkg.mk"
